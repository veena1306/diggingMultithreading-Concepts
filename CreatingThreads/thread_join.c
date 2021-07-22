#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>

pthread_t thread2;
pthread_t thread3;

void* thread_fn_callback(void *arg)
{
  int th_id = *(int*)arg;
  free(arg);
  int rc = 0; 
  
   while(rc != th_id)
   {
    printf("Thread %d is doing some work\n",th_id); 
     sleep(1);
     rc++;
   }
  
  int *result = calloc(1, sizeof(int));
  *result = th_id * th_id;
   return (void*)result;
}

void thread_create(pthread_t *thread_handle, int th_id)
{
  pthread_attr_t attr;
  pthread_attr_init(&attr);
  pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_JOINABLE);   //PTHREAD_CREATE_DETACHED (for detached threads)
  
  pthread_create(&thread_handle, &attr, thread_fn_callback, (void*)_th_id);
  
}
  
int main()
{
  thread_create(&thread2,2);
  thread_create(&thread3,10);
  printf("main fn blocked on pthread join for thread_width"th_id = 2\n");
   
  pthread_join(pthread2,&thread_result2);
  
   if(thread_result2){
     printf("Return result from thread 2 = %d\n",*(int*)thread_result2);
     free(thread_result2);
     thread_result2 = NULL;
   }
         
     printf("main fn blocked on pthread join for thread_width"th_id = 3\n");
   
  pthread_join(pthread2,&thread_result3);
  
   if(thread_result3){
     printf("Return result from thread 3 = %d\n",*(int*)thread_result3);
     free(thread_result3);
     thread_result3 = NULL;
   }

}





