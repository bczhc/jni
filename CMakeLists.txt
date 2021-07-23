CMAKE_MINIMUM_REQUIRED(VERSION 3.10.0)
project(jni)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 20)

add_library(sqlite3 SHARED third_party/my-cpp-lib/third_party/sqlite3-single-c/sqlite3.c)

add_library(
        Main SHARED
        src/sqlite3/sqlite3.cpp
        src/sqlite3/statement.cpp
        src/sqlite3/cursor.cpp
        src/struct/structMain.cpp
)
