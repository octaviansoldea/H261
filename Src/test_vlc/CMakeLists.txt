PROJECT(test_vlc)
 
INCLUDE_DIRECTORIES(
	${CMAKE_SOURCE_DIR}/libCommon
	${CMAKE_SOURCE_DIR}/libh261Common/include
	${CMAKE_SOURCE_DIR}/libvlc/include
)

LINK_DIRECTORIES(
	$ENV{MEMORIES_FIXED_CODE}/C_FAMILY_LIBS/Install/lib
)

SET(
	SRCS
	test_vlc.cpp
)

ADD_EXECUTABLE(test_vlc ${SRCS})
TARGET_LINK_LIBRARIES(test_vlc
	libCommon
	libh261common
	libvlc
)

