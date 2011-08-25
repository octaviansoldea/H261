PROJECT(libh261common)

SET(SRCS
	./include/bitstream_reader.h
	./include/event_handler.h
	./include/h261_common.h
	./include/token.h
	./src/bitstream_reader.cpp
	./src/file_bitstream_reader.cpp
	./src/file_bitstream_reader.h
	./src/memory_bitstream_reader.cpp
	./src/memory_bitstream_reader.h
	./src/non_seek_file_bitstream_reader.cpp
	./src/non_seek_file_bitstream_reader.h
)

INCLUDE_DIRECTORIES(
	${CMAKE_SOURCE_DIR}/libh261common/include
)

ADD_LIBRARY(libh261common ${SRCS})

INSTALL(TARGETS libh261common DESTINATION lib)




