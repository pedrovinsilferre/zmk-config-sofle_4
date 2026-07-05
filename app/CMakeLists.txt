# app/CMakeLists.txt
zephyr_library()

zephyr_library_sources(
  src/matrix_transform_default.c
  # se já houver outros src/*.c do app, mantenha-os na lista
)
