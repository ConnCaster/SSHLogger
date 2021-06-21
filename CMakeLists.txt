cmake_minimum_required(VERSION 3.10)
project(SSH_Logger)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

set(Boost_USE_STATIC_LIBS ON)
find_package(Boost 1.65 REQUIRED COMPONENTS filesystem regex program_options)

add_definitions(-DDEBUG=0)

# ------------- SSH_logger -------------
add_executable(SSH_Logger
        src/main.cpp
        src/strace.cpp
        src/ptrace.cpp
        src/parsing.cpp
        src/tracer.cpp
        src/process_logger.cpp
        src/process.cpp
        src/network/server.cpp
        src/network/connection.cpp
        )
target_include_directories(SSH_Logger
        PUBLIC
        includes
        dep/msgpack/include
        )
target_link_libraries(SSH_Logger PUBLIC pthread Boost::regex Boost::filesystem Boost::program_options)


# ------------- Client to send msgpack data to ssh_logger -------------------
add_executable(client
        tools/client/main.cpp
        tools/client/src/client.cpp
        )
target_include_directories(client
        PUBLIC
        tools/client/includes
        dep/msgpack/include
        )
target_link_libraries(client
        PUBLIC
        pthread
        )

#  ------------- Tests -------------
add_subdirectory(tests)
