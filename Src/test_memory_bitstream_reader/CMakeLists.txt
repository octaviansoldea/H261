PROJECT(test_memory_bitstream_reader)
 
INCLUDE_DIRECTORIES(
	${CMAKE_SOURCE_DIR}/libh261Common/include
)

SET(SRCS
	test_memory_bitstream_reader.cpp
)

ADD_EXECUTABLE(test_memory_bitstream_reader ${SRCS})
TARGET_LINK_LIBRARIES(test_memory_bitstream_reader
	libh261common
)

