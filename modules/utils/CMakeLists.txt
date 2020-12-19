cmake_minimum_required(VERSION 3.5)
project(utils)

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


# create library
add_library(${PROJECT_NAME} STATIC ${CMAKE_CURRENT_SOURCE_DIR}/src/utils.cpp)

# add include directories
target_include_directories(${PROJECT_NAME}
                           PUBLIC
                           ${CMAKE_CURRENT_SOURCE_DIR}/include
)

# # install the target and create export-set
# install(TARGETS ${PROJECT_NAME}
#         EXPORT ${PROJECT_NAME}Targets
#         LIBRARY DESTINATION lib
#         ARCHIVE DESTINATION lib
#         RUNTIME DESTINATION bin
#         INCLUDES DESTINATION include
# )

# # install header file
# install(FILES ${CMAKE_CURRENT_SOURCE_DIR}/include/utils.hpp DESTINATION include)

# # generate and install export file
# install(EXPORT ${PROJECT_NAME}Targets
#         FILE ${PROJECT_NAME}Targets.cmake
#         DESTINATION lib/cmake
# )