# Add tests using googletest
find_package(GTest REQUIRED)

function(add_test name)
    add_executable(${name} ${name}.cpp)
    target_link_libraries(${name} PRIVATE cpp-template_lib GTest::gtest_main)
    gtest_discover_tests(${name})
endfunction()

add_test(cpp-template)
