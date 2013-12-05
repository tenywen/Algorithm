cmake_minimum_required(VERSION 2.8)
#project name
PROJECT(Alg)

SET(PATH /home/tenywen/my_work/Algorithm)

#head file path
INCLUDE_DIRECTORIES(${PATH}/include/common.h)


#source list
SET(SRC_LIST ${PATH}/src/InsertSort.c)

#set environment variable
#SET(TEST_MATH ${DIR_SRCS})

#set extern libraries
#ADD_EXECUTABLE(../bin/bin ${TEST_MATH})

MESSAGE(STATUS "this is SOURCE DIR " ${SRC_LIST})

#add link libray
#TARGET_LINK_LIBRARIES(../bin/bin m)

ADD_EXECUTABLE(Alg ${SRC_LIST})
