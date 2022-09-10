cmake_minimum_required(VERSION 3.23)
project(Z)

find_package(Boost 1.80 REQUIRED COMPONENTS program_options regex json)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 23)
set(MAIN main.cpp)
set(CORE_DIR core)
set(CORE ${CORE_DIR}/core.h ${CORE_DIR}/core.cpp)

add_executable(
        Z
        ${MAIN}
        ${CORE}
)

target_link_libraries(Z ${Boost_LIBRARIES})