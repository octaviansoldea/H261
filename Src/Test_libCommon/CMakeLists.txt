PROJECT(Test_libCommon)
 
INCLUDE_DIRECTORIES(${CMAKE_SOURCE_DIR}/libCommon/)

ADD_EXECUTABLE(Test_libCommon Test_libCommon.cpp)
TARGET_LINK_LIBRARIES(Test_libCommon libCommon) 
