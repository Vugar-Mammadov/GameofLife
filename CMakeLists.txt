cmake_minimum_required(VERSION 3.0)
cmake_policy(SET CMP0076 NEW)
project(GameofLife)
add_subdirectory(game)
add_subdirectory(console)

set (SRC main.c)

add_executable(${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PUBLIC ${SRC})
target_link_libraries(${PROJECT_NAME} PUBLIC game console) 
install(TARGETS ${PROJECT_NAME})

add_custom_target(dist ALL
        COMMAND realpath --relative-to=${CMAKE_CURRENT_SOURCE_DIR} ${DIST_TARGETS} | xargs tar -czf ${DIST}
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Compressing dist"
        VERBATIM)

find_package(doc)
if (DOXYGEN_FOUND)
    message("Building doc")

    add_custom_target(doc ALL
            COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
            WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
            COMMENT "Running Doxygen"
            VERBATIM)
else (DOXYGEN_FOUND)
    message("Doxygen was not found on this system, skipping doc build")
endif (DOXYGEN_FOUND)