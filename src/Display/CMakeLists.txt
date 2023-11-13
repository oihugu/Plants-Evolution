add_library(Display "")

target_sources(Display
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/Display.cpp
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/Display.hpp
  )

target_include_directories(Display
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )