cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("ParserSimba")

# Add source to this project's executable.
add_executable (ParserSimba "main.cpp" "PcapParser.h" "PcapParser.cpp" "SimbaDecoder.h" "SimbaDecoder.cpp" "SimbaScheme.h" "PcapScheme.h" "json.h" "base64encoder.h" "base64encoder.cpp" "json.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ParserSimba PROPERTY CXX_STANDARD 20)
endif()

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build
add_subdirectory(${CMAKE_CURRENT_BINARY_DIR}/googletest-src
                 ${CMAKE_CURRENT_BINARY_DIR}/googletest-build)

# Now simply link against gtest or gtest_main as needed
# Test for JSON functionality
add_executable(test_json "test_json.cpp" "base64encoder.h" "base64encoder.cpp" "json.cpp")
target_link_libraries(test_json gtest_main)

# Test for SimbaDecoder functionality
add_executable(test_simba "test_simba.cpp" "SimbaDecoder.h" "SimbaDecoder.cpp" "SimbaScheme.h" "base64encoder.cpp" "json.cpp" )
target_link_libraries(test_simba gtest_main)
