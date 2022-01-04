function(add_sort_test name source)
  add_executable (${name} ${source})
  target_link_libraries(${name} PUBLIC doctest::doctest)
  target_include_directories(${name} PUBLIC ${PROJECT_SOURCE_DIR}/include)

  add_test(${name}.test ${name})
endfunction()
