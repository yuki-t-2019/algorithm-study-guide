cmake_minimum_required(VERSION 3.22.1)
project(dijkstra)

# Guard against in-source builds
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include FetchContent module
include(FetchContent)

# Option to enable or disable testing
option(ENABLE_TESTING "Enable testing" ON)

if (ENABLE_TESTING)
    # Fetch GoogleTest
    FetchContent_Declare(
      googletest
      # Specify the commit you depend on and update it regularly.
      URL https://github.com/google/googletest/archive/5376968f6948923e2411081fd9372e71a59d8e77.zip
      DOWNLOAD_EXTRACT_TIMESTAMP TRUE
    )
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
    FetchContent_MakeAvailable(googletest)

    # Enable testing
    enable_testing()
endif()

# Add the main executable
file(GLOB SOURCES src/*.cpp)
add_executable(program ${SOURCES})

# Set the output directory for the executable
set_target_properties(program PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

# Include the directory for header files
include_directories(${CMAKE_SOURCE_DIR})

if (ENABLE_TESTING)
    # Add the test executable
    file(GLOB TEST_SOURCES test/*.cpp)
    add_executable(tests ${TEST_SOURCES} src/dijkstra.cpp)

    # Link test executable with GoogleTest
    target_link_libraries(tests gtest_main)

    # Add tests
    add_test(NAME tests COMMAND tests)
endif()
