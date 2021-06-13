cmake_minimum_required(VERSION 3.20)

include(pots/additions/CMakeLists.txt)

set(POTS_SRC
        pots/Pot.cpp
        pots/Pot.h
        ${ADDITIONS_SRC}
)