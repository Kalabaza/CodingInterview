cmake_minimum_required(VERSION 3.22.1)
project(CodingInterview CXX)

############################################################
# Disable a warning related with DOWNLOAD_EXTRACT_TIMESTAMP
############################################################
if(POLICY CMP0135)
  cmake_policy(SET CMP0135 NEW)
endif()

########################################
# Download GoogleTest from the internet
########################################
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
enable_testing()

set(CMAKE_CXX_STANDARD 20)

###################################################################
# Function to make a unit test binary for each chapter of the book
###################################################################
function(defineTest)
cmake_parse_arguments(
  PARSED_ARGS     # prefix of output variables
  ""              # list of names of boolean arguments (only defined ones will be true)
  "TESTNAME"      # list of names of mono-valued arguments
  "SOURCES;LIBS"  # list of names of multi-valued arguments (output variables are lists)
  ${ARGN}         # arguments of the function to parse
  )
  add_executable(${PARSED_ARGS_TESTNAME} ${PARSED_ARGS_SOURCES})
  target_include_directories(${PARSED_ARGS_TESTNAME} PRIVATE Common)
  target_link_libraries(${PARSED_ARGS_TESTNAME} ${PARSED_ARGS_LIBS} gtest gtest_main)
  set_target_properties(${PARSED_ARGS_TESTNAME} PROPERTIES COMPILE_FLAGS "-Wall -Wextra -Wpedantic -Werror")
  add_test(NAME ${PARSED_ARGS_TESTNAME} COMMAND ${PARSED_ARGS_TESTNAME})
endfunction()

file(GLOB CHAPTER_1 "Chapter1/*.cpp")
file(GLOB CHAPTER_2 "Chapter2/*.cpp")
file(GLOB CHAPTER_3 "Chapter3/*.cpp")

########################
# Unit tests by chapter
########################
defineTest(TESTNAME TestChapter_1 SOURCES ${CHAPTER_1})
defineTest(TESTNAME TestChapter_2 SOURCES ${CHAPTER_2})
defineTest(TESTNAME TestChapter_3 SOURCES ${CHAPTER_3})

######################################
# Run the tests after the compilation
######################################
add_custom_target(Test ALL COMMAND ${CMAKE_CTEST_COMMAND} --progress --output-on-failure)
