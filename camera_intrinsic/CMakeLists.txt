cmake_minimum_required( VERSION 2.8 )
project( camera_intrinsic )

# 添加c++ 11标准支持
set( CMAKE_CXX_FLAGS "-std=c++11" )

# 寻找OpenCV库
find_package( OpenCV 3 REQUIRED )
# 添加头文件
include_directories( ${OpenCV_INCLUDE_DIRS} )

find_package(Boost 1.58.0 REQUIRED COMPONENTS system filesystem)
if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  link_directories(${Boost_LIBRARY_DIRS})
  add_definitions(-DBOOST_ALL_DYN_LINK)
endif()

message("Boost_INCLUDE_DIRS: ${Boost_INCLUDE_DIRS}")
message("Boost_VERSION: ${Boost_VERSION}")

add_executable( camera_intrinsic intrinsic_calib.cpp )
# 链接OpenCV库
target_link_libraries( camera_intrinsic 
                       ${Boost_FILESYSTEM_LIBRARY}
                       ${Boost_PROGRAM_OPTIONS_LIBRARY}
                       ${Boost_SYSTEM_LIBRARY}
                       ${OpenCV_LIBS} )
