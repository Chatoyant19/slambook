cmake_minimum_required( VERSION 2.8 )
project( leetcode )

# 添加c++ 11标准支持
set( CMAKE_CXX_FLAGS "-std=c++11" )

add_executable(my_sqrt my_sqrt.cpp)

add_executable(valid_kuohao valid_kuohao.cpp)

add_executable(taijie taijie.cpp)

add_executable(find_stone_pair find_stone_pair.cpp)

add_executable(find_minDiff_unordered_array find_minDiff_unordered_array.cpp)

add_executable(sort_algorithm sort_algorithm.cpp)

add_executable(test test.cpp)

add_executable(int_to_roman int_to_roman.cpp)

add_executable(find_number_in_2DArray find_number_in_2DArray.cpp)

add_executable(shared_ptr_use_xianjin shared_ptr_use_xianjin.cpp)

add_executable(find_median_sorted_arrays find_median_sorted_arrays.cpp)