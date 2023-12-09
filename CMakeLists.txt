cmake_minimum_required(VERSION 3.16)
project(PlantsEvolution LANGUAGES CXX)

enable_testing()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)

##############################################
# Including SFML
##############################################
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

##############################################
# Including GoogleTest
##############################################
FetchContent_Declare(
      googletest
      URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
      DOWNLOAD_EXTRACT_TIMESTAMP 1609450000
    )
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

##############################################
# Including subdirectories
##############################################

link_directories(src)
add_subdirectory(test)

link_directories(LSystem)
link_directories(LSystem/build)
include_directories(LSystem/include)


##############################################
# Create LSystem library
##############################################

add_library(LSystem_library
            SHARED
            src/LSystem/Rule.cpp
            src/LSystem/LSystem.cpp)

target_include_directories(LSystem_library
                           PUBLIC 
                           ${PROJECT_SOURCE_DIR}/src/LSystem/include)

##############################################
# Create LSystem library
##############################################

add_library(EvolutionaryAlgorithm_library
            SHARED
            src/EvolutionaryAlgorithm/EvolutionaryAlgorithm.cpp)

target_include_directories(EvolutionaryAlgorithm_library
                           PUBLIC 
                           ${PROJECT_SOURCE_DIR}/src/EvolutionaryAlgorithm/include)

##############################################
#
##############################################

set(CMAKE_INCLUDE_DIRECTORIES "${CMAKE_SOURCE_DIR}/test")
set(PROJECT_LINK_LIBS LSystem_library)

##############################################
# Create executable
##############################################
add_executable(${CMAKE_PROJECT_NAME} src/main.cpp test/main_test.cpp)
target_link_libraries(${CMAKE_PROJECT_NAME}
                    PUBLIC 
                     sfml-graphics 
                     GTest::gtest_main 
                     GTest::gtest
                     ${PROJECT_LINK_LIBS})



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

