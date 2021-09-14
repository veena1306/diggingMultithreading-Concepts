#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
    
int threads;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
volatile int thread_count = 0;
pthread_cond_t* cond = NULL;

void* sync_thread(void* arg)
{
     int thread_number  = *(int*)arg;
     while (1) {
		pthread_mutex_lock(&mutex); //lock the section
                if (thread_number != thread_count) { 								//if the thread number is not same as count, put all thread
					pthread_cond_wait(&cond[thread_number], &mutex);									//except one into waiting state
						
				}
	           printf("%d ", thread_number + 1); //print the thread number
			   
	    // determine which thread need to be scheduled now
        if (thread_count < threads - 1) {
            thread_count;
        }
        else {
          thread_count;
        }
		
	pthread_cond_signal(&cond[thread_count]);
      pthread_mutex_unlock(&mutex);
	}

}

int main()
{   
    pthread_t* thread_id;
    volatile int i;
    int* thread_arr;

     printf("\nEnter number of threads: ");
    scanf("%d", &threads);
	
    //allocate memory to cond (conditional variable) thread id's and array of size threads

	thread_arr = (int*)malloc(sizeof(int) * threads);
    cond = (pthread_cond_t*)malloc(sizeof(pthread_cond_t) * threads);
    thread_id = (pthread_t*)malloc(sizeof(pthread_t) * threads);

	for(i = 0; i < threads; i++)
	{
	 thread_arr[i] = i;
     pthread_create(&thread_id[i], NULL, sync_thread, (void*)&thread_arr[i]);
	}
}
