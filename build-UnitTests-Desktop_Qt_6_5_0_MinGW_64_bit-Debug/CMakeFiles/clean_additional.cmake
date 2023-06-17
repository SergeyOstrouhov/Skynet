# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\UnitTests_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\UnitTests_autogen.dir\\ParseCache.txt"
  "UnitTests_autogen"
  )
endif()
