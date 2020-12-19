cmake_minimum_required(VERSION 3.5)
project(cpp_parser)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic -Werror)
endif()

set(utils_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/modules/utils/include)
set(Variable_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/modules/Variable/include)
set(VariablesMap_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/modules/VariablesMap/include)
set(ConfigParser_INCLUDE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}/modules/ConfigParser/include)
set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED) 

if(${TEST_MODE})
  add_executable(
    ${PROJECT_NAME} 
    ${CMAKE_SOURCE_DIR}/test/main.cpp
  )
else()
  add_executable(
    ${PROJECT_NAME} 
    ${CMAKE_SOURCE_DIR}/src/main.cpp
  )
endif()


target_include_directories(
   ${PROJECT_NAME}
   PUBLIC
   ${CMAKE_SOURCE_DIR}/modules/ConfigParser/include
  ${GTEST_INCLUDE_DIRS}
  ${Threads_INCLUDE_DIR}
)
  
add_subdirectory(modules/utils)
add_subdirectory(modules/Variable)
add_subdirectory(modules/VariablesMap)
add_subdirectory(modules/ConfigParser)

target_link_libraries(${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} Threads::Threads utils ConfigParser)