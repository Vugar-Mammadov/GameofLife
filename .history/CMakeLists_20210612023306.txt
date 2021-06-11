cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0076 NEW)
project(GameofLife)
add_subdirectory(console)
add_subdirectory(game)


set (SRC main.c)

add_executable(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PUBLIC ${SRC})
target_link_libraries(${PROJECT_NAME} PUBLIC game console) 
install(TARGETS ${PROJECT_NAME})

