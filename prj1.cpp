#include <iostream>
#include <cstdlib>
#include <pthread.h>

using namespace std;


void *LCR(void *threadid) {
    long tid;
    tid = (long)threadid;
    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    int rc;
    long i;

    int num_threads = atoi(argv[1]);
    pthread_t threads[num_threads];
   
    for( i = 0; i < num_threads; i++ ) {
        rc = pthread_create(&threads[i], NULL, LCR, (void *)i);
      
        if (rc) {
            cout << "Error:unable to create thread," << rc << endl;
            exit(-1);
        }
    }
   pthread_exit(NULL);
}