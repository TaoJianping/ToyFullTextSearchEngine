cmake_minimum_required(VERSION 3.21)
project(ToyFullTextSearchEngine)

set(CMAKE_CXX_STANDARD 20)

find_package(tinyxml2 CONFIG REQUIRED)

include_directories(
        ${CMAKE_SOURCE_DIR}/lib/porter2_stemmer/include
)

add_executable(ToyFullTextSearchEngine main.cpp Document.cpp Document.h SearchEngine.cpp SearchEngine.h TextAnalyzer.cpp TextAnalyzer.h)
target_link_libraries(ToyFullTextSearchEngine PRIVATE tinyxml2::tinyxml2 ${CMAKE_SOURCE_DIR}/lib/porter2_stemmer/lib/libporter2-stemmer.a)
