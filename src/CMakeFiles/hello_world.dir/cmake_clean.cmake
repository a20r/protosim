FILE(REMOVE_RECURSE
  "CMakeFiles/hello_world.dir/hello_world.cpp.o"
  "../bin/hello_world.pdb"
  "../bin/hello_world"
)

# Per-language clean rules from dependency scanning.
FOREACH(lang CXX)
  INCLUDE(CMakeFiles/hello_world.dir/cmake_clean_${lang}.cmake OPTIONAL)
ENDFOREACH(lang)
