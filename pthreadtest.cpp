#include <emscripten/bind.h>
#include <iostream>
#include <pthread.h>
#define NUM_THREADS 4

using namespace emscripten;

void *worker(void* threadid) {
    long tid;
    tid = (long)threadid;

    std::cout << "I am worker number:" << tid << std::endl;
    pthread_exit(NULL);
}

void test() {
    pthread_t threads[NUM_THREADS];
    int rc;

    std::cout << "hello, world" << std::endl;
    for( int i = 0; i < NUM_THREADS; i++ ) {
        rc = pthread_create (&threads[i], NULL, worker, (void*)i);
        if (rc) {
            std::cout << "Error:unable to create thread," << rc << std::endl;
            exit(-1);
        }
    }
    pthread_exit(NULL);
}

EMSCRIPTEN_BINDINGS(my_module) {
    function("test", &test);
}
