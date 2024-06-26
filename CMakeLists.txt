CMAKE_MINIMUM_REQUIRED(VERSION 3.10.0)
project(jni)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 17)

set(LIB_BUILD_TYPE SHARED)
if (BUILD_STATIC)
    if (BUILD_STATIC EQUAL 1)
        set(LIB_BUILD_TYPE STATIC)
    endif ()
endif ()

add_compile_definitions(SQLITE_HAS_CODEC)
add_library(sqlite3 ${LIB_BUILD_TYPE} third_party/my-cpp-lib/third_party/sqlite3-single-c/sqlite3.c)

if (OPENSSL_LIBS_DIR AND OPENSSL_INCLUDE_DIR)
    if (NOT OPENSSL_CRYPTO_LINK_SONAME)
        set(OPENSSL_CRYPTO_LINK_SONAME crypto)
    endif ()
    if (NOT OPENSSL_SSL_LINK_SONAME)
        set(OPENSSL_SSL_LINK_SONAME ssl)
    endif ()

    message("openssl link_soname: ${OPENSSL_CRYPTO_LINK_SONAME}--${OPENSSL_SSL_LINK_SONAME}")

    message("openssl dir: ${OPENSSL_LIBS_DIR}--${OPENSSL_INCLUDE_DIR}")
    set(CMAKE_SKIP_BUILD_RPATH true)
    include_directories(${OPENSSL_INCLUDE_DIR})
    target_link_directories(sqlite3 PUBLIC ${OPENSSL_LIBS_DIR})
    if (__ANDROID__)
        target_link_libraries(sqlite3 ${OPENSSL_CRYPTO_LINK_SONAME} log)
    else ()
        target_link_libraries(sqlite3 ${OPENSSL_CRYPTO_LINK_SONAME})
    endif ()
elseif (NOT __ANDROID__)
    # OpenSSL
    find_package(OpenSSL REQUIRED)
    target_link_libraries(sqlite3 ${OPENSSL_LIBRARIES})
else ()
    message(FATAL_ERROR "Please define OPENSSL_LIBS_DIR and OPENSSL_INCLUDE_DIR for Android targets")
endif ()

add_library(
        myLib ${LIB_BUILD_TYPE}
        third_party/my-cpp-lib/string.cpp
        third_party/my-cpp-lib/sqlite3.cpp
        third_party/my-cpp-lib/utf8.cpp
        third_party/my-cpp-lib/utils.cpp
        third_party/my-cpp-lib/exception.cpp
)

target_link_libraries(myLib sqlite3)

add_library(
        jni-lib SHARED
        src/sqlite3/sqlite3.cpp
        src/sqlite3/statement.cpp
        src/sqlite3/cursor.cpp
        src/sqlite3/lib.cpp
        src/struct/structMain.cpp
        src/jni_help.cpp
)

target_link_libraries(jni-lib myLib)
