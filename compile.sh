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
  "${src_dir}/room.cpp"  # Agregar room.cpp
)
header_files=(
  "${include_dir}/fish_tank.h"
  "${include_dir}/keyboard.h"
  "${include_dir}/variables.h"
  "${include_dir}/room.h"  # Agregar room.h
)

# Opciones de compilación
compiler_flags="-I${include_dir} -lGL -lGLU -lglut"

# Crear el directorio binario si no existe
mkdir -p "${bin_dir}"

# Compilar los archivos fuente
g++ "${source_files[@]}" ${compiler_flags} -o "${bin_dir}/programa"


# Ruta de inclusión de irrKlang
irrklang_include_dir="externals/include"

# Ruta de enlace de irrKlang
irrklang_lib_dir="externals/lib"

# Opciones de compilación adicionales para irrKlang
compiler_flags+=" -I${irrklang_include_dir} -L${irrklang_lib_dir} -lirrklang"
