cmake_minimum_required(VERSION 3.23)
project(Z)

set(CMAKE_CXX_STANDARD 23)
set(MAIN main.cpp)
set(CORE_DIR core)
set(CORE ${CORE_DIR}/core.h)
set(STRINGS ${CORE_DIR}/strings.h)
set(BOOLEANS ${CORE_DIR}/booleans.h)
set(HEADERS ${CORE_DIR}/headers.h)
set(EXCEPTIONS ${CORE_DIR}/exceptions.h)
set(TYPES ${CORE_DIR}/types.h)
set(CONTEXTS ${CORE_DIR}/contexts.h)
set(FUNCTIONS ${CORE_DIR}/functions.h)
set(OUTPUT ${CORE_DIR}/output.h)
set(APP ${CORE_DIR}/app.h)

add_executable(
        Z
        ${MAIN}
        ${CORE}
        ${STRINGS}
        ${HEADERS}
        ${EXCEPTIONS}
        ${TYPES}
        ${CONTEXTS}
        ${FUNCTIONS}
        ${OUTPUT}
        ${APP}
)
