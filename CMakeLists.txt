cmake_minimum_required(VERSION 3.19)
project(htcpcp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(networking)
add_subdirectory(pots)

add_executable(htcpcp main.cpp)

target_link_libraries(htcpcp PRIVATE networking)
target_link_libraries(htcpcp PRIVATE pots)
target_compile_options (htcpcp PRIVATE -static -Wl,--whole-archive -lpthread -Wl,--no-whole-archive)
target_link_options (htcpcp PRIVATE -static -Wl,--whole-archive -lpthread -Wl,--no-whole-archive)
target_include_directories(htcpcp PUBLIC
        "${PROJECT_BINARY_DIR}"
        )

install(TARGETS htcpcp DESTINATION bin)

enable_testing()

add_subdirectory(tests)
