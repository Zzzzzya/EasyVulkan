cmake_minimum_required(VERSION 3.20)

project(EasyVulkan)

add_definitions(-w)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(GLEW REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(Stb REQUIRED)
find_package(assimp CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(Vulkan REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB_RECURSE SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cc)
file(GLOB_RECURSE TEST_FILES ${PROJECT_SOURCE_DIR}/test/main.cc)

add_executable(EasyVulkan ${SRC_FILES} ${TEST_FILES})

target_link_libraries(EasyVulkan PRIVATE glfw)
target_link_libraries(EasyVulkan PRIVATE GLEW::GLEW)
target_link_libraries(EasyVulkan PRIVATE glm::glm)
target_link_libraries(EasyVulkan PRIVATE imgui::imgui)
target_link_directories(EasyVulkan PRIVATE ${Stb_INCLUDE_DIR})
target_link_libraries(EasyVulkan PRIVATE assimp::assimp)
target_link_libraries(EasyVulkan PRIVATE spdlog::spdlog)
target_link_libraries(EasyVulkan PRIVATE Vulkan::Vulkan)
