cmake_minimum_required(VERSION 3.5.0)

#プロジェクト名
project(a.out CXX)

#ディレクトリ設定
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/inc)

#コンパイラオプション
set(CMAKE_CXX_FLAGS "-Wall -O3 -std=c++11")

message("SRC_DIR : ${SRC_DIR}")
message("INC_DIR : ${INC_DIR}")
 
include_directories(
  ${INC_DIR}
)

add_executable(
  a.out
  ${SRC_DIR}/main.cpp
  ${SRC_DIR}/add_filter.cpp
  ${SRC_DIR}/box.cpp
  ${SRC_DIR}/context.cpp
  ${SRC_DIR}/parallel_context.cpp
  ${SRC_DIR}/serial_context.cpp
  ${SRC_DIR}/stream.cpp
  ${SRC_DIR}/wave_generator.cpp
  ${SRC_DIR}/sign_wave_generator.cpp
)
