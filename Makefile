# Directory paths
src_dir := src
include_dir := include
bin_dir := bin

# Source and header files
source_files := $(src_dir)/main.cpp $(src_dir)/fish_tank.cpp $(src_dir)/keyboard.cpp $(src_dir)/variables.cpp $(src_dir)/fish.cpp $(src_dir)/room.cpp $(src_dir)/skybox.cpp $(src_dir)/camera.cpp
header_files := $(include_dir)/fish_tank.h $(include_dir)/keyboard.h $(include_dir)/variables.h $(include_dir)/room.h $(include_dir)/skybox.h $(include_dir)/camera.h

# Compilation options
compiler_flags := -I$(include_dir) -L/bin/linux-gcc-64 -L/externals/irrklang/lib/irrklang.lib -lGL -lGLU -lglut

# Set LD_LIBRARY_PATH variable
export LD_LIBRARY_PATH := externals/irrklang/lib:$(LD_LIBRARY_PATH)

# Create the binary directory if it doesn't exist
$(shell mkdir -p $(bin_dir))

# Target executable
target := $(bin_dir)/programa

# Default target
all: $(target)

# Rule for building the executable
$(target): $(source_files) $(header_files)
	@g++ $(source_files) $(compiler_flags) -o $(target)

# Clean rule
clean:
	@rm -rf $(bin_dir)

# Phony targets
.PHONY: all clean
