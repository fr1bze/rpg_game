cmake_minimum_required(VERSION 3.26)
project(BoxCatcherGame)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL3 REQUIRED)

file(GLOB SOURCES "*.cpp" "*.h")
file(GLOB CPP_SOURCES "*.cpp")

add_executable(${PROJECT_NAME} ${CPP_SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}
        ${SDL3_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
        ${SDL3_LIBRARIES}
)