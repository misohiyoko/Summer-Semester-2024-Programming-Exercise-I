cmake_minimum_required(VERSION 3.28)
project(programing_study C)
include(CMakePrintHelpers)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_FLAGS "-finput-charset=cp932 -fexec-charset=cp932")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")


find_package(Doxygen REQUIRED dot)


file(GLOB_RECURSE SOURCE_FILES "${CMAKE_SOURCE_DIR}/src" "*.c")
list(FILTER SOURCE_FILES EXCLUDE REGEX "${PROJECT_SOURCE_DIR}/cmake*/*" )



message("${CMAKE_SOURCE_DIR}/src")
cmake_print_variables(SOURCE_FILES)
foreach(SOURCE_FILE ${SOURCE_FILES})
    # ソースファイルのディレクトリを取得
    get_filename_component(DIR "${SOURCE_FILE}" DIRECTORY)




    # ソースファイルの名前を取得
    get_filename_component(FILENAME_WE "${SOURCE_FILE}" NAME_WE)
    cmake_print_variables(FILENAME_WE)
    cmake_print_variables(DIR)


    # 実行ファイルを生成
    add_executable(${FILENAME_WE} "${SOURCE_FILE}")

    # 出力ディレクトリを設定（ソースファイルと同じ場所に生成）
    set_target_properties(${FILENAME_WE} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${DIR})
endforeach()


