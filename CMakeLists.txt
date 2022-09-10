cmake_minimum_required(VERSION 3.23)
project(Z)

find_package(Boost 1.80 REQUIRED COMPONENTS program_options regex json)
include_directories(${Boost_INCLUDE_DIRS})

set(CMAKE_CXX_STANDARD 23)
set(MAIN main.cpp)
set(CORE_DIR core)
set(CORE ${CORE_DIR}/core.h)
set(NUMBERS ${CORE_DIR}/numbers.h)
set(STRINGS ${CORE_DIR}/strings.h)
set(BOOLEANS ${CORE_DIR}/booleans.h)
set(OBJECTS ${CORE_DIR}/objects.h)
set(HEADERS ${CORE_DIR}/headers.h)
set(EXCEPTIONS ${CORE_DIR}/exceptions.h)
set(TYPES ${CORE_DIR}/types.h)
set(CONTEXTS ${CORE_DIR}/contexts.h)
set(FUNCTIONS ${CORE_DIR}/functions.h)
set(INPUT ${CORE_DIR}/input.h)
set(OUTPUT ${CORE_DIR}/output.h)
set(ENGINE ${CORE_DIR}/engine.h)
set(APP ${CORE_DIR}/app.h)

add_executable(
        Z
        ${MAIN}
        ${CORE}
        ${NUMBERS}
        ${STRINGS}
        ${BOOLEANS}
        ${OBJECTS}
        ${HEADERS}
        ${EXCEPTIONS}
        ${TYPES}
        ${CONTEXTS}
        ${FUNCTIONS}
        ${INPUT}
        ${OUTPUT}
        ${ENGINE}
        ${APP}
)

target_link_libraries(Z ${Boost_LIBRARIES})