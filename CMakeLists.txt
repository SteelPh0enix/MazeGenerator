cmake_minimum_required(VERSION 3.0)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

project(Ph0enixMaze)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wextra -Werror -Wpedantic")

if(CMAKE_BUILD_TYPE MATCHES Debug)
  set(SFML_LIBS sfml-system-d sfml-window-d sfml-graphics-d)
else()
  set(SFML_LIBS sfml-system sfml-window sfml-graphics)
endif()

# Detect and add SFML
if(WIN32)
  set(SFML_INCLUDE_DIRECTORY "C:/SFML-2.4.2/include" CACHE PATH "SFML include directory")
  if(CMAKE_BUILD_TYPE MATCHES Debug)
    set(SFML_LIB_DIRECTORY "C:/SFML-2.4.2/build/gcc_debug/lib" CACHE PATH "SFML libraries directory")
  else()
    set(SFML_LIB_DIRECTORY "C:/SFML-2.4.2/build/gcc_release/lib" CACHE PATH "SFML libraries directory")
  endif()
elseif(UNIX)
  set(SFML_INCLUDE_DIRECTORY "/usr/include" CACHE PATH "SFML include directory")
  set(SFML_LIB_DIRECTORY "/usr/lib" CACHE PATH "SFML libraries directory")
endif()

set(CMAKE_CXX_STANDARD 17)
file(GLOB SOURCES "*.cpp")

include_directories(${SFML_INCLUDE_DIRECTORY} ${PROJECT_SOURCE_DIR})
link_directories(${SFML_LIB_DIRECTORY})

if(WIN32 AND CMAKE_BUILD_TYPE MATCHES Release)
  add_executable(${PROJECT_NAME} WIN32 ${SOURCES})
else()
  add_executable(${PROJECT_NAME}  ${PROJECT_SOURCE_DIR}/main.cpp ${SOURCES})
endif()
target_link_libraries(${PROJECT_NAME} ${SFML_LIBS})
