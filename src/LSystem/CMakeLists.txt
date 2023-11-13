add_library(LSystem "")

target_sources(LSystem
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/LSystem.cpp
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/LSystem.hpp
  )

target_include_directories(LSystem
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )