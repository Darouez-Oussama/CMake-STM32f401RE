set -e 
ACTION="${1:-build}"
# Build based on action
case "$ACTION" in
    "build")
        echo "Building..."
        mkdir build && cd build 
        cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain.cmake ..
        make
        ;;
    *)
        echo "Error: Invalid action '$ACTION'"
        echo "Valid actions: build, flash, monitor, flash_monitor"
        exit 1
        ;;
esac

echo "Done!" 