cmake_minimum_required(VERSION 3.19)

set(NETWORKING_SRC
        ServerSocket.cpp
        ServerSocket.h
        Socket.cpp
        Socket.h
        HTTPRequestType.h
        Request.cpp
        Request.h
        Response.cpp
        Response.h
)

add_library(networking STATIC ${NETWORKING_SRC})

target_link_libraries(networking pots)
set_property(TARGET networking PROPERTY INCLUDE_DIRECTORIES ${CMAKE_SOURCE_DIR}/pots)
target_include_directories(networking
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        )

#install(TARGETS networking DESTINATION lib)
#install(FILES ${NETWORKING_SRC} DESTINATION include)