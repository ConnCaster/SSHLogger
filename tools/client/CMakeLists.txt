add_executable(client main.cpp src/client.cpp includes/client.hpp)
target_include_directories(client PUBLIC includes)
target_link_libraries(client PUBLIC pthread Boost::regex Boost::filesystem Boost::program_options)

