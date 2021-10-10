cmake_minimum_required(VERSION 3.16)

project(hzip C)

set(CMAKE_C_STANDARD 11)

add_executable(
        hzip
        src/main.c
        src/file_util.c
        src/hzip.c
        src/frequency.c
        src/pqueue.c
        src/huffman_tree.c
        src/key_table.c
)

add_executable(
        pqueue_test
        src/pqueue.c
        src/pqueue_test.c
)

add_executable(
        htree_test
        src/huffman_tree.c
        src/htree_test.c
        src/pqueue.c
        src/key_table.c
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
