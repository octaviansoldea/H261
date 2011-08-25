cmake_minimum_required(VERSION 2.6)

project(H261)

SET(CMAKE_DEBUG_POSTFIX "D")

SUBDIRS(
	libCommon
	Test_libCommon
	libbitstreamparser
	libh261common
	libvlc
	test_bitstream_parser
	test_file_bitstream_reader
	test_memory_bitstream_reader
	test_vlc
)