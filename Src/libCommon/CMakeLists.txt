PROJECT(libCommon)

SET(SRCS
	BasicDefinitions.h
    Array.h Array.cpp
    BasicStringDefinitions.h BasicStringDefinitions.cpp
    BitFlip.h
    Factorial.h Factorial.cpp
    FileOperations.h FileOperations.cpp
    IniReader.h IniReader.cpp
    IniWriter.h IniWriter.cpp
    Log.h Log.cpp
    Singleton.h
    Trace.h Trace.cpp
)



ADD_LIBRARY(libCommon ${SRCS})

#FILE(GLOB files "${CMAKE_CURRENT_SOURCE_DIR}/*.h")
#INSTALL(FILES ${files} DESTINATION include/Called)


INSTALL(TARGETS libCommon DESTINATION lib)




