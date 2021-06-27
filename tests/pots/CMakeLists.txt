cmake_minimum_required(VERSION 3.20)

set(POTTESTS_SRC
        pots/PotTest.cpp
)

add_executable(potbrewtest PotBrewTest.cpp)
target_link_libraries(potbrewtest PRIVATE pots)
add_test(NAME potbrewtest COMMAND potbrewtest)

add_executable(potcuptest PotCupTest.cpp)
target_link_libraries(potcuptest PRIVATE pots)
add_test(NAME potcuptest COMMAND potcuptest)

