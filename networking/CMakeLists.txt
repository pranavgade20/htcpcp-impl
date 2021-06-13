cmake_minimum_required(VERSION 3.20)

set(NETWORKING_SRC
        ServerSocket.cpp
        ServerSocket.h
        Socket.cpp
        Socket.h
)

add_library(networking ServerSocket.cpp Socket.cpp)

target_include_directories(networking
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        )

install(TARGETS networking DESTINATION lib)
install(FILES ${NETWORKING_SRC} DESTINATION include)