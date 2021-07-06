cmake_minimum_required(VERSION 3.19)

include(additions/CMakeLists.txt)

set(POTS_SRC
        Pot.cpp
        Pot.h
        TeaPot.cpp
        TeaPot.h
        CoffeePot.cpp
        CoffeePot.h
        Cup.cpp
        Cup.h
        ${ADDITIONS_SRC}
)

add_library(pots STATIC ${POTS_SRC})

target_link_libraries(pots networking)
target_include_directories(pots
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}
        )

#install(TARGETS networking DESTINATION lib)
#install(FILES ${POTS_SRC} DESTINATION include)