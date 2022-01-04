
function(add_sort_algorithm name)
   add_library(${name} INTERFACE)
   target_include_directories(${name} INTERFACE
     $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>)
endfunction()
