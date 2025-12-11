#!/bin/bash

# Build the Yodo1 MAS Android plugin AAR
# Run this script from anywhere to build the plugin

set -e  # Exit on error

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
GODOT_ROOT="$SCRIPT_DIR/../../.."
GRADLEW="$GODOT_ROOT/platform/android/java/gradlew"

echo "Building GodotYodo1Mas AAR..."

cd "$SCRIPT_DIR"

# Build the AAR
"$GRADLEW" assembleRelease

# Copy the AAR to the plugin directory
cp build/outputs/aar/GodotYodo1Mas.aar ./

echo "✓ Build successful!"
echo "✓ AAR copied to: $SCRIPT_DIR/GodotYodo1Mas.aar"
