add_executable(run_tests test_figures.cpp 
                           ../src/trapezoid.cpp 
                           ../src/rhombus.cpp 
                           ../src/pentagon.cpp)

target_link_libraries(run_tests PRIVATE GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(run_tests)