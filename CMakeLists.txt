cmake_minimum_required(VERSION 3.16)
project(PlantsEvolution LANGUAGES CXX)

enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)
    
FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
    )
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)


add_subdirectory(src)
add_subdirectory(test)

set(CMAKE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/test")

add_executable(${CMAKE_PROJECT_NAME} src/main.cpp test/main_test.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE sfml-graphics GTest::gtest_main GTest::gtest)
target_compile_features(${CMAKE_PROJECT_NAME} PRIVATE cxx_std_17)

if(WIN32)
    add_custom_command(
        TARGET CMakeSFMLProject
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:CMakeSFMLProject>
        VERBATIM)
endif()

install(TARGETS ${CMAKE_PROJECT_NAME})


gtest_discover_tests(${CMAKE_PROJECT_NAME}
                    EXTRA_ARGS --test 1
                    WORKING_DIRECTORY test)