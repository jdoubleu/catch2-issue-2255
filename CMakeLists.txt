cmake_minimum_required(VERSION 3.19)
project(catch2_tttp_feature)

include(FetchContent)

# https://github.com/catchorg/Catch2/blob/devel/docs/cmake-integration.md#cmake-target
FetchContent_Declare(Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.13.6)
FetchContent_MakeAvailable(Catch2)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE Catch2::Catch2)
