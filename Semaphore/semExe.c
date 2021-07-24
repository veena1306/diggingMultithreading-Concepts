/* create 5 threads
  allow only 2 threads to execute under cs */
sem_t sem;
pthread_t thread[5];
#define permit_count = 2;

static void* thread_fn_callback(void *arg)
{
  int i; 
  char *thread_name = (char*)arg;
  
    printf("%s is enetering  in c.s\n", thread_name);
  
  
  sem_wait(&sem);
  
  printf("%s is entered  into c.s\n", thread_name);
  for(i = 0 ; i < 5; i++)
  {
    printf("%s is execuring in c.s\n", thread_name);
    sleep(1);
  }
  
  printf("%s is exeting  in c.s\n", thread_name);
  sem_post(&sem);

}

void thread_create(pthread_t *thread_handle, void *arg)
{
  
  int rc = pthread_create(&thread_handle, NULL,thread_fn_callback,arg);
  
  if(rc != 0)
  {
    printf("thread not created with errno : %d\n",errno);
    exit(0);
  }
  
  
}


int main()
{
  sem_int(&sem,0,permit_count);
  thread_create(&thread[0],"thread0"); 
  thread_create(&thread[1],"thread1"); 
  thread_create(&thread[2],"thread2"); 
  thread_create(&thread[3],"thread3"); 
  thread_create(&thread[4],"thread4");
  
  for(int i = 0; i < 5; i++)
  {
    pthread_join(&thread[i],NULL);
  }
  sem_destroy(&sem);
  return 0;
}
