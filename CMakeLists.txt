cmake_minimum_required(VERSION 3.21)

option(cpp-template_DEVELOPER_MODE "Enable developer mode" ON)

# Enable/disable tests
option(cpp-template_BUILD_TESTS "Build tests" ${cpp-template_DEVELOPER_MODE})
if (cpp-template_BUILD_TESTS)
    list(APPEND VCPKG_MANIFEST_FEATURES "tests")
endif ()

# Set project name and language
project(
        cpp-template
        VERSION 0.1.0
        LANGUAGES CXX C
)

# Create project library
add_library(
        cpp-template_lib OBJECT
        src/cpp-template.h src/cpp-template.cpp
)

option(cpp-template_SANITIZE_ADDRESS "Enable address sanitizer" ${cpp-template_DEVELOPER_MODE})
if (cpp-template_SANITIZE_ADDRESS)
    target_compile_options(cpp-template_lib PUBLIC ${CXX_SANITIZE_ADDRESS})
endif ()

option(cpp-template_SANITIZE_UNDEFINED "Enable undefined behaviour sanitizer" ${cpp-template_DEVELOPER_MODE})
if (cpp-template_SANITIZE_UNDEFINED)
    target_compile_options(cpp-template_lib PUBLIC ${CXX_SANITIZE_UNDEFINED})
endif ()

target_include_directories(cpp-template_lib PUBLIC src)

target_compile_features(cpp-template_lib PUBLIC cxx_std_20)

find_package(fmt REQUIRED)
target_link_libraries(cpp-template_lib PRIVATE fmt::fmt)

# Create project executable
add_executable(cpp-template_exe src/main.cpp)
add_executable(cpp-template::exe ALIAS cpp-template_exe)

set_target_properties(cpp-template_exe PROPERTIES OUTPUT_NAME cpp-template)

target_link_libraries(cpp-template_exe PRIVATE cpp-template_lib)

# Developer mode
if (cpp-template_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif ()
