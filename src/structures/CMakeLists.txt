project(struct CXX)
	
add_library(struct LinkedQueue.h LinkedList.h Lista.h RingList.h just_compile.cpp)

target_include_directories(struct INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")


