project(app CXX)

set (
	APP_SRC
	App.cpp
	App.h
	Traffic.cpp
	)
	
add_executable(app ${APP_SRC})

target_link_libraries(app struct data)