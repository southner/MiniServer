add_test( Buffer.get_readable_bytes /root/workspace/MiniServer/build/buffer_test [==[--gtest_filter=Buffer.get_readable_bytes]==] --gtest_also_run_disabled_tests)
set_tests_properties( Buffer.get_readable_bytes PROPERTIES WORKING_DIRECTORY /root/workspace/MiniServer/build)
add_test( Buffer.read /root/workspace/MiniServer/build/buffer_test [==[--gtest_filter=Buffer.read]==] --gtest_also_run_disabled_tests)
set_tests_properties( Buffer.read PROPERTIES WORKING_DIRECTORY /root/workspace/MiniServer/build)
add_test( Buffer.write_buffer /root/workspace/MiniServer/build/buffer_test [==[--gtest_filter=Buffer.write_buffer]==] --gtest_also_run_disabled_tests)
set_tests_properties( Buffer.write_buffer PROPERTIES WORKING_DIRECTORY /root/workspace/MiniServer/build)
add_test( Buffer.File /root/workspace/MiniServer/build/buffer_test [==[--gtest_filter=Buffer.File]==] --gtest_also_run_disabled_tests)
set_tests_properties( Buffer.File PROPERTIES WORKING_DIRECTORY /root/workspace/MiniServer/build)
set( buffer_test_TESTS Buffer.get_readable_bytes Buffer.read Buffer.write_buffer Buffer.File)