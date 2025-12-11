# Godot 2.1 only passes platform. Godot 3+ build passes env, platform
def can_build(env, platform):
    return platform in ["ios"]


def configure(env):
    if env["platform"] == "ios":
        env.Append(CPPPATH=["#core"])
        env.Append(LINKFLAGS=["-ObjC", "-framework"])

    if env["platform"] == "android":
        env.Append(CPPPATH=["#core"])
