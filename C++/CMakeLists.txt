cmake_minimum_required(VERSION 3.5.1)
project(CodingInterview CXX)

include(GoogleTest)
enable_testing()

################################################################
# Macro to make a unit test binary for each chapter of the book
################################################################
macro(package_add_test TESTNAME)
   file(GLOB SOURCES ${ARGN}*.cpp)
   add_executable(${TESTNAME} ${SOURCES})
   target_link_libraries(${TESTNAME} gtest gtest_main pthread)
   gtest_discover_tests(${TESTNAME}
      WORKING_DIRECTORY ${PROJECT_DIR}
      PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_DIR}"
   )
   set_target_properties(${TESTNAME} PROPERTIES COMPILE_FLAGS "-Wall -Wextra -Wpedantic -Werror")
   add_test(NAME ${TESTNAME} COMMAND ${TESTNAME})

endmacro()

########################
# Unit tests by chapter
########################
package_add_test(Chapter_1 Tests/Question_1)
package_add_test(Chapter_2 Tests/Question_2)
package_add_test(Chapter_3 Tests/Question_3)

######################################
# Run the tests after the compilation
######################################
add_custom_target(tests ALL COMMAND ${CMAKE_CTEST_COMMAND} --progress)
