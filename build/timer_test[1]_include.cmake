if(EXISTS "/root/workspace/MiniServer/build/timer_test[1]_tests.cmake")
  include("/root/workspace/MiniServer/build/timer_test[1]_tests.cmake")
else()
  add_test(timer_test_NOT_BUILT timer_test_NOT_BUILT)
endif()
