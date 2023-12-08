add_library(Tests)

target_sources(Tests
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}/main_test.cpp
)

target_include_directories(Tests
  PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
  )

target_link_libraries(
    Tests
    GTest::gtest_main
  )