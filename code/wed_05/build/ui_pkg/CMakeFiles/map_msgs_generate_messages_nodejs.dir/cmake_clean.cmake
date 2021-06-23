file(REMOVE_RECURSE
  "sqlite_node_automoc.cpp"
  "ui_pkg_automoc.cpp"
)

# Per-language clean rules from dependency scanning.
foreach(lang )
  include(CMakeFiles/map_msgs_generate_messages_nodejs.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
