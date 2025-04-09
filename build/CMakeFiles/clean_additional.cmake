# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/ExplosionGUI_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/ExplosionGUI_autogen.dir/ParseCache.txt"
  "ExplosionGUI_autogen"
  )
endif()
