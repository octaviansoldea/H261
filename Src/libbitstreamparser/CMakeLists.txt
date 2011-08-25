PROJECT(libbitstreamparser)

SET(SRCS
	./include/bitstream_parser.h
	./include/blockCoeffsMgr.h
	./src/bitstream_parser.cpp
	./src/block_layer_bitstream_parser.cpp
	./src/block_layer_bitstream_parser.h
	./src/blockCoeffsMgr.cpp
	./src/gob_layer_bitstream_parser.cpp
	./src/gob_layer_bitstream_parser.h
	./src/mb_layer_bitstream_parser.cpp
	./src/mb_layer_bitstream_parser.h
	./src/picture_layer_bitstream_parser.cpp
	./src/picture_layer_bitstream_parser.h
)

INCLUDE_DIRECTORIES(
	${CMAKE_SOURCE_DIR}/libbitstreamparser/include
    ${CMAKE_SOURCE_DIR}/libvlc/include
	${CMAKE_SOURCE_DIR}/libh261Common/include)

ADD_LIBRARY(libbitstreamparser ${SRCS})

#FILE(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
#INSTALL(FILES ${files} DESTINATION include/Called)


INSTALL(TARGETS libbitstreamparser DESTINATION lib)




