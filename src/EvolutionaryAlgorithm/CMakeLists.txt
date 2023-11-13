add_library(EvolutionaryAlgorithm "")

target_sources(EvolutionaryAlgorithm
  PRIVATE
  ${CMAKE_CURRENT_LIST_DIR}/EvolutionaryAlgorithm.cpp
  PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/EvolutionaryAlgorithm.hpp
  )

target_include_directories(EvolutionaryAlgorithm
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )