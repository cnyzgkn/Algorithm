cmake_minimum_required(VERSION 3.13)

#project name
PROJECT(Graph)
 
add_definitions("-Wall")
 
#head file path
INCLUDE_DIRECTORIES(include)

#source directory
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

#add executable file
ADD_EXECUTABLE(Graph ${DIR_SRCS})
 
