cmake_minimum_required(VERSION 3.28)
project(programing_study C CXX)
include(CMakePrintHelpers)
set(CMAKE_C_STANDARD 11)




file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src" "*.c")
list(FILTER SOURCE_FILES EXCLUDE REGEX "${PROJECT_SOURCE_DIR}/cmake*/*" )
list(FILTER SOURCE_FILES EXCLUDE REGEX ".*/1TE23014S.c" )



message("${CMAKE_SOURCE_DIR}/src")
cmake_print_variables(SOURCE_FILES)
foreach(SOURCE_FILE ${SOURCE_FILES})
    # ソースファイルのディレクトリを取得
    get_filename_component(DIR "${SOURCE_FILE}" DIRECTORY)




    # ソースファイルの名前を取得
    get_filename_component(FILENAME_WE "${SOURCE_FILE}" NAME_WE)
    cmake_print_variables(FILENAME_WE)
    cmake_print_variables(DIR)
    file(COPY_FILE "${SOURCE_FILE}" "${DIR}/1TE23014S.c")

    # 実行ファイルを生成
    add_executable(${FILENAME_WE} "${SOURCE_FILE}")

    # 出力ディレクトリを設定（ソースファイルと同じ場所に生成）
    set_target_properties(${FILENAME_WE} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${DIR})
endforeach()

message("CMAKE_C_END")

file(GLOB_RECURSE SOURCE_FILES_CXX "${CMAKE_SOURCE_DIR}/src" "*.cpp")

list(FILTER SOURCE_FILES_CXX EXCLUDE REGEX "${PROJECT_SOURCE_DIR}/cmake*/*" )
list(FILTER SOURCE_FILES_CXX EXCLUDE REGEX ".*/1TE23014S.cpp" )
message("${CMAKE_SOURCE_DIR}/src")
cmake_print_variables(SOURCE_FILES_CXX)
foreach(SOURCE_FILE ${SOURCE_FILES_CXX})
    # ソースファイルのディレクトリを取得
    get_filename_component(DIR "${SOURCE_FILE}" DIRECTORY)




    # ソースファイルの名前を取得
    get_filename_component(FILENAME_WE "${SOURCE_FILE}" NAME_WE)
    cmake_print_variables(FILENAME_WE)
    cmake_print_variables(DIR)
    file(COPY_FILE "${SOURCE_FILE}" "${DIR}/1TE23014S.cpp")

    # 実行ファイルを生成
    add_executable(${FILENAME_WE} "${SOURCE_FILE}")

    # 出力ディレクトリを設定（ソースファイルと同じ場所に生成）
    set_target_properties(${FILENAME_WE} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${DIR})
endforeach()


