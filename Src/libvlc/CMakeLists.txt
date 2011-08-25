PROJECT(libvlc)

INCLUDE_DIRECTORIES(
	${CMAKE_SOURCE_DIR}/libCommon
	${CMAKE_SOURCE_DIR}/libvlc/include
	${CMAKE_SOURCE_DIR}/libh261Common/include
)
SET(SRCS
	./include/vlc_abstract_model.h
	./include/vlc_CBP.h
	./include/vlc_code_right_aligned.h
	./include/vlc_MBA.h
	./include/vlc_MTYPE.h
	./include/vlc_MVD.h
	./include/vlc_table.h
	./include/vlc_TCOEFF.h
	./include/vlc_tree.h
	./include/vlc_tree_node.h
	./src/vlc_abstract_model.cpp
	./src/vlc_CBP.cpp
	./src/vlc_code_right_aligned.cpp
	./src/vlc_MBA.cpp
	./src/vlc_MTYPE.cpp
	./src/vlc_MVD.cpp
	./src/vlc_table.cpp
	./src/vlc_TCOEFF.cpp
	./src/vlc_tree.cpp
)

ADD_LIBRARY(libvlc ${SRCS})

INSTALL(TARGETS libvlc DESTINATION lib)




