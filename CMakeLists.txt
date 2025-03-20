cmake_minimum_required(VERSION 3.10)
project(MovieRentalSystem VERSION 1.0)

# C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directory for header files
include_directories(${CMAKE_SOURCE_DIR})

# Explicitly list all source files in your project
set(SOURCES
    main.cpp
    filereader.cpp
    inventorystorage.cpp
    movie.cpp
    customer.cpp
    classicmovie.cpp
    comedymovie.cpp
    dramamovie.cpp
    borrow.cpp
    return.cpp
    classicfactory.cpp
    comedyfactory.cpp
    dramafactory.cpp
    borrowfactory.cpp
    returnfactory.cpp
    movieparams.cpp
)

# Create executable
add_executable(movie_rental ${SOURCES})

# Copy data files to build directory
configure_file(data4customers.txt ${CMAKE_CURRENT_BINARY_DIR}/data4customers.txt COPYONLY)
configure_file(data4movies.txt ${CMAKE_CURRENT_BINARY_DIR}/data4movies.txt COPYONLY)
configure_file(data4commands.txt ${CMAKE_CURRENT_BINARY_DIR}/data4commands.txt COPYONLY)