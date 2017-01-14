cmake_minimum_required(VERSION 3.6)
project(NewGame)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp settings/settings.h game_objects/Map.cpp game_objects/Map.h input/InputManager.cpp input/InputManager.h game_objects/GameObject.cpp game_objects/GameObject.h game_objects/Character.cpp game_objects/Character.h game_objects/PlayableCharacter.cpp game_objects/PlayableCharacter.h)
add_executable(NewGame ${SOURCE_FILES})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(NewGame ${SFML_LIBRARIES})
endif()