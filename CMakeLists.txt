project(sharemem)
cmake_minimum_required(VERSION 3.10.2)

aux_source_directory(. SRC_LIST)
aux_source_directory(./src SRC_LIST)
SET(CMAKE_BUILD_TYPE Debug)
# 显示编译过程
set(CMAKE_VERBOSE_MAKEFILE ON)

INCLUDE_DIRECTORIES(./)
INCLUDE_DIRECTORIES(./src)
add_definitions("-Wall -ggdb3 -O0")

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
ADD_LIBRARY(${PROJECT_NAME} SHARED ${SRC_LIST})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} pthread)

link_directories(${PROJECT_SOURCE_DIR}/lib)


add_executable(tree ${PROJECT_SOURCE_DIR}/main/tree.c)
add_executable(queue ${PROJECT_SOURCE_DIR}/main/queue.c)
add_executable(list ${PROJECT_SOURCE_DIR}/main/list.c)
add_executable(array ${PROJECT_SOURCE_DIR}/main/array.c)
add_executable(hash ${PROJECT_SOURCE_DIR}/main/hash.c)
TARGET_LINK_LIBRARIES(${EXE_OBJ} ${PROJECT_NAME})
