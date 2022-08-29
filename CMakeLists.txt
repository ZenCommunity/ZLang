cmake_minimum_required(VERSION 3.23)
project(Z)

set(CMAKE_CXX_STANDARD 23)

add_executable(Z main.cpp core/strings.h core/core.h core/headers.h core/singletons.h core/exceptions.h core/types.h core/variables.h core/output.h core/contexts.h core/functions.h core/app.h)
