project(data CXX)

SET	(
	DATA_SRC
	Car.cpp
	Car.h
	CarQueue.h 
	Clock.cpp
	Clock.h
	CreationRoad.cpp
	CreationRoad.h
	DestroyerRoad.cpp
	DestroyerRoad.h
	Logger.h
	NeutralRoad.cpp
	NeutralRoad.h
	Road.cpp
	Road.h
	Semaphore.cpp
	Semaphore.h
	TextTable.h
	UserIO.cpp
	UserIO.h
	)
	
add_library(data ${DATA_SRC})

target_include_directories(data PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

target_link_libraries(data struct)