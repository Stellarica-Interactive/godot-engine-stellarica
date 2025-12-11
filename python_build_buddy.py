import glfw
import imgui
from imgui.integrations.glfw import GlfwRenderer
from OpenGL.GL import *
import os
import subprocess

suffix_dir = "suffix_build_buddy"

def run_command(command):
    try:
        print(f"Running: {command}")
        process = subprocess.Popen(command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)

        # Print output line by line as it arrives
        for line in process.stdout:
            print(line, end='')

        process.wait()

        if process.returncode != 0:
            print(f"Command failed with return code {process.returncode}")

    except Exception as e:
        print(f"Error running command: {e}")

def build_editor():
    run_command("scons platform=macos target=editor")
    
def get_extra_args(suffix_file):
    result = ""
    if suffix_file != "None":
        path = os.path.join(suffix_dir, suffix_file)
        if os.path.isfile(path):
            with open(path, 'r') as file:
                result = file.read()
    return result

def build_android(suffix_file):
    build_suffix = get_extra_args(suffix_file)
    run_command("scons platform=android target=template_debug arch=arm32 " + build_suffix)
    run_command("scons platform=android target=template_debug arch=arm64 " + build_suffix)
    run_command("scons platform=android target=template_release arch=arm32 " + build_suffix)
    run_command("scons platform=android target=template_release arch=arm64 generate_apk=yes " + build_suffix)

def build_ios(suffix_file):
    build_suffix = get_extra_args(suffix_file)
    run_command("scons platform=ios target=template_debug arch=arm64 " + build_suffix)
    run_command("scons platform=ios target=template_release arch=arm64 generate_bundle=yes " + build_suffix)

def run_editor():
    editor_path = "bin/godot.macos.editor.arm64"
    if os.path.isfile(editor_path):
        run_command(f"./{editor_path}")
    else:
        print(f"Error: {editor_path} not found.")
        
def show_user_folder():
    user_path = os.path.expanduser("~/Library/Application Support/Godot")
    if os.path.exists(user_path):
        subprocess.run(["open", user_path])
    else:
        print(f"user:// path not found: {user_path}")

def main():
    if not glfw.init():
        print("Could not initialize OpenGL context")
        return
    glfw.window_hint(glfw.CONTEXT_VERSION_MAJOR, 3)
    glfw.window_hint(glfw.CONTEXT_VERSION_MINOR, 3)
    glfw.window_hint(glfw.OPENGL_PROFILE, glfw.OPENGL_CORE_PROFILE)
    
    #return
    window = glfw.create_window(800, 600, "Builder Buddy", None, None)
    
    print(window)
    glfw.make_context_current(window)

    imgui.create_context()
    impl = GlfwRenderer(window)
    print(glGetString(GL_VERSION))
    
    suffix_files = ["None"] + [f for f in os.listdir(suffix_dir) if os.path.isfile(os.path.join(suffix_dir, f))]
    selected_suffix_index = 0

    while not glfw.window_should_close(window):
        glfw.poll_events()
        impl.process_inputs()
        imgui.new_frame()

        imgui.begin("Builder Buddy")
        
        changed, selected_suffix_index = imgui.combo(
            "Build Suffix", selected_suffix_index, suffix_files
        )

        if imgui.button("Build Editor (macOS)"):
            build_editor()

        if imgui.button("Build Android Engine Library"):
            build_android(suffix_files[selected_suffix_index])

        if imgui.button("Build iOS Engine Library"):
            build_ios(suffix_files[selected_suffix_index])
            
        if imgui.button("Run Editor"):
            run_editor()
            
        if imgui.button("Show user:// in Finder"):
            show_user_folder()

        imgui.end()
        imgui.render()
        impl.render(imgui.get_draw_data())
        glfw.swap_buffers(window)

    impl.shutdown()
    glfw.terminate()


if __name__ == "__main__":
    main()
