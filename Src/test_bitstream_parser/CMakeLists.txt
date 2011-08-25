PROJECT(test_bitstream_parser)
 
INCLUDE_DIRECTORIES(
	${CMAKE_SOURCE_DIR}/libh261Common/include
	${CMAKE_SOURCE_DIR}/libbitstreamparser/include
	${CMAKE_SOURCE_DIR}/libvlc/include
)

LINK_DIRECTORIES(
	$ENV{MEMORIES_FIXED_CODE}/C_FAMILY_LIBS/Install/lib
)

SET(
	SRCS
	xml_dump_event_handler.h xml_dump_event_handler.cpp
	test_bitstream_parser.cpp
)

ADD_EXECUTABLE(test_bitstream_parser ${SRCS})
TARGET_LINK_LIBRARIES(test_bitstream_parser
	libCommon
	libbitstreamparser
	libh261common
	libvlc
)
