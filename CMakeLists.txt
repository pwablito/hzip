cmake_minimum_required(VERSION 3.16)

project(hzip C)

set(CMAKE_C_STANDARD 11)

add_executable(
        hzip
        main.c
        file_util.c
        hzip.c
        frequency.c
        pqueue.c
        huffman_tree.c
        key_table.c
        io.c
)

add_executable(
        pqueue_test
        pqueue.c
        pqueue_test.c
)

add_executable(
        htree_test
        huffman_tree.c
        htree_test.c
        pqueue.c
        key_table.c
)


enable_testing()

add_test(
        usage_test
        hzip
)
set_tests_properties(usage_test PROPERTIES WILL_FAIL TRUE)

add_test(
        pqueue_test
        pqueue_test
)
set_tests_properties(pqueue_test PROPERTIES WILL_FAIL FALSE)

add_test(
        htree_test
        htree_test

)
set_tests_properties(htree_test PROPERTIES WILL_FAIL FALSE)

install(TARGETS hzip DESTINATION bin)
