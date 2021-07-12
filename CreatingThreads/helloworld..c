+++++++++ writing a hello world program ++++++++++

#include<pthread.h>
  
Static void* thread_fn_callback(void *arg){
 char *input = (char*)arg;
  while(1) 
  {
   printf(“input string is %s\n”, input);
   sleep(1);
  }
} 
  
void thread_create()
{

  pthread_t pthread1;                                   // creating the threads, thread handle(pthread1)
  
  static char *thread_input = "i am into thread1";      // (input to the thread, thats goint to create) 
  
  int rc = pthread_create(&pthread1, NULL, thread_fn_callback,(void*)thread_input);    // 1st arg -  address of thread handle //3rd - pointer to the functionn
   if(rc != 0)                                                                        // address of the memory going to pass input to the child thread
   {
    printf("error occured, while thread creation %d", rc) 
     exit();
   }
  
                                                                                       
}                                                                                       

int main(int argc, char **argv)
{ 
  thread_create();
  printf("main is paused");
  pause();
  
  return 0;
}
