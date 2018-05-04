project(struct CXX)
	
add_library(struct INTERFACE)
target_sources(struct INTERFACE Lista.h Fila.h)

#target_sources(struct INTERFACE ${STRUCT_SRC})
#set_target_properties(struct PROPERTIES LINKER_LANGUAGE CXX)

target_include_directories(struct INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}")
#target_include_directories(struct INTERFACE)

