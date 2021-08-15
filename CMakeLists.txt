CMAKE_MINIMUM_REQUIRED(VERSION 3.10.0)
project(jni)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 17)

set(LIB_BUILD_TYPE SHARED)
if (BUILD_STATIC)
    if (BUILD_STATIC EQUAL 1)
        set(LIB_BUILD_TYPE STATIC)
    endif()
endif ()

add_library(my-sqlite3 ${LIB_BUILD_TYPE} third_party/my-cpp-lib/third_party/sqlite3-single-c/sqlite3.c)

add_library(
        myLib ${LIB_BUILD_TYPE}
        third_party/my-cpp-lib/string.cpp
        third_party/my-cpp-lib/sqlite3.cpp
        third_party/my-cpp-lib/utf8.cpp
        third_party/my-cpp-lib/utils.cpp
        third_party/my-cpp-lib/exception.cpp
)

target_link_libraries(myLib my-sqlite3)

add_library(
        jni-lib SHARED
        src/sqlite3/sqlite3.cpp
        src/sqlite3/statement.cpp
        src/sqlite3/cursor.cpp
        src/struct/structMain.cpp
        src/jni_help.cpp
)

target_link_libraries(jni-lib myLib)