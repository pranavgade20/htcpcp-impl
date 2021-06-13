cmake_minimum_required(VERSION 3.20)
project(htcpcp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

add_subdirectory(networking)

include(pots/CMakeLists.txt)
set(SRC
        main.cpp
        ${POTS_SRC}
)

add_executable(htcpcp ${SRC})

target_link_libraries(htcpcp PUBLIC networking)
target_include_directories(htcpcp PUBLIC
        "${PROJECT_BINARY_DIR}"
        )

install(TARGETS htcpcp DESTINATION bin)
