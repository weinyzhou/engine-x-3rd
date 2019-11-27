cmake_minimum_required(VERSION 3.6)

set(lib_name pugixml)
set(target_name ext_${lib_name})

project(${lib_name})

include(../cmake/CocosExternalConfig.cmake)

if(WINDOWS)
  add_library(${target_name} SHARED IMPORTED GLOBAL)
  set_target_properties(${target_name} PROPERTIES
    IMPORTED_LOCATION "${platform_spec_path}/${lib_name}.dll"
    IMPORTED_IMPLIB "${platform_spec_path}/${lib_name}.lib"
  )
else()
  set(${target_name}_src
   pugixml.cpp
  )
  add_library(${target_name} STATIC
    ${${target_name}_src}
  )
  target_include_directories(${target_name} PRIVATE .)
  set_target_properties(${target_name}
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    FOLDER "External"
  )
endif()

set_target_properties(${target_name} PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}"
)
