#!/bin/bash

# Directorios de origen y destino
src_dir="src"
include_dir="include"
bin_dir="bin"

# Archivos fuente y encabezados
source_files=(
  "${src_dir}/main.cpp"
  "${src_dir}/fish_tank.cpp"
  "${src_dir}/keyboard.cpp"
  "${src_dir}/variables.cpp"
  "${src_dir}/fish.cpp"
  "${src_dir}/room.cpp"
  "${src_dir}/skybox.cpp"
)
header_files=(
  "${include_dir}/fish_tank.h"
  "${include_dir}/keyboard.h"
  "${include_dir}/variables.h"
  "${include_dir}/room.h"
  "${include_dir}/skybox.h"
)

# Opciones de compilación
compiler_flags="-I${include_dir} -lGL -lGLU -lglut  -L/include/SOIL"  # Reemplaza /path/to/soil/library por la ruta correcta

# Crear el directorio binario si no existe
mkdir -p "${bin_dir}"

# Compilar los archivos fuente
g++ "${source_files[@]}" ${compiler_flags} -o "${bin_dir}/programa"
