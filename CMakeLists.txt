project("python-c-extension-module")
cmake_minimum_required(VERSION 3.22)

set(CMAKE_GENERATOR "Ninja")
set(CMAKE_EXPORT_COMPILE_COMMANDS "ON")

include_directories("/usr/include/python3.8")

add_executable(fputsmodule fputsmodule.c)

add_custom_command(
    TARGET fputsmodule POST_BUILD
    COMMAND sudo /usr/bin/python3 setup.py install
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Running setup.py install..."
)
