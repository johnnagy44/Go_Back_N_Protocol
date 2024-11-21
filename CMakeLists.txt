cmake_minimum_required(VERSION 3.22)
Project(GOBACKNPROTOCAL)
set(src_files 
${CMAKE_SOURCE_DIR}/src/main.cpp 
)

add_executable(appbinary ${src_files} )
target_include_directories(appbinary PUBLIC inc/)