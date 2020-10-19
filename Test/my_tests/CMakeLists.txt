include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(run_tests ../../Source/algorithms.h ../../Source/sequence.h ../../Source/string_algs.h
        ../../Source/unique_ptr_init_list.h ../../Source/meta.h sequence_tests.cpp unq_ptr_il_tests.cpp
        alg_tests.cpp strings_tests.cpp meta_tests.cpp)

target_link_libraries(run_tests gtest gtest_main)