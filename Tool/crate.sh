#!/bin/bash
if [ -z "$1" ]; then
    echo "Please provide a directory name!"
    exit 1
fi

TARGET_DIR=$1
shift  # Remove directory name parameter, process remaining

ALT_MODE=0

# Process optional parameters
while [[ $# -gt 0 ]]; do
    case "$1" in
        --cf)
            ALT_MODE=1
            shift
            ;;
        *)
            echo "Unknown option: $1"
            exit 1
            ;;
    esac
done

# Find the AlgorithmSolutions/CodeTemplate directory
current_dir=$(pwd)
template_dir=""
while [[ "$current_dir" != "/" ]]; do
    if [[ -d "$current_dir/AlgorithmTemplate/CodeTemplate" ]]; then
        template_dir="$current_dir/AlgorithmTemplate/CodeTemplate"
        break
    fi
    current_dir=$(dirname "$current_dir")
done

if [[ -z "$template_dir" ]]; then
    echo "Could not find AlgorithmTemplate/CodeTemplate directory!"
    exit 1
fi

# Determine template file name
TEMPLATE_FILE="main.cpp"
if [ $ALT_MODE -eq 1 ]; then
    TEMPLATE_FILE="maincf.cpp"
fi

if [[ ! -f "$template_dir/$TEMPLATE_FILE" ]]; then
    echo "Template file $template_dir/$TEMPLATE_FILE does not exist!"
    exit 1
fi

# Create target directory and copy template
mkdir -p "$TARGET_DIR"
cp "$template_dir/$TEMPLATE_FILE" "$TARGET_DIR/main.cpp"

# Generate other files (unchanged)
cat <<EOL > "$TARGET_DIR/CMakeLists.txt"
cmake_minimum_required(VERSION 3.10.0)
project(Test)
add_executable(a main.cpp)
EOL

cat <<EOL > "$TARGET_DIR/open.sh"
termux-open main.cpp
EOL

chmod +x "$TARGET_DIR/open.sh"

mkdir -p "$TARGET_DIR/build"

cat <<EOL > "$TARGET_DIR/build/execute.sh"
#!/bin/bash
cmake .. && make && ./a
EOL

chmod +x "$TARGET_DIR/build/execute.sh"

echo "Directory created successfully!"
cd "$TARGET_DIR"