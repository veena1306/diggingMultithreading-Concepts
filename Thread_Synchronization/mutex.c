int arr[] = {1,2,3,4,5};
pthread_mutex_t arr_mutex;


static void* thread_fn_callback_sum(void *arg){
  
   int arr_size = sizeof(arr)/sizeof(arr[0]);
  do {
        int i = 0;
        int sum = 0;
    pthread_mutex_lock(&arr_mutex);
      while(i < arr_size){
       sum = sum + arr[i]; 
        i++;
   }
    printf("sum is : %d\n", sum);  
    print_array();
   pthread_mutex_unlock(&arr_mutex);
  }while(1);
}

static void* thread_fn_callback_swap(void *arg){
  
   int arr_size = sizeof(arr)/sizeof(arr[0]);
  do {
      int temp;
      pthread_mutex_lock(&arr_mutex);
      temp = arr[0];
      arr[0] = arr[arr_size-1];
      arr[arr_size-1]=temp;
      printf("swap\n");
      print_array();
      pthread_mutex_unlock(&arr_mutex);
   }while(1);
}




void sum_thread_create()
{
  pthread_t pthread1;
  
  int rc = pthread_create(&pthread1, NULL, thread_fn_callback_sum,NULL);
  if(rc != 0)
  {
    printf("errror occurred, thread can't be created, errno = %d\n",errno); 
    exit(0);
  }

}

void swap_thread_create()
{
   pthread_t pthread2;
  
  int rc = pthread_create(&pthread2, NULL, thread_fn_callback_swap,NULL);
  if(rc != 0)
  {
    printf("errror occurred, thread can't be created, errno = %d\n",errno); 
    exit(0);
  }
  
  
}

int main(int argc, char **argv)
{
  sum_thread_create();
  swap_thread_create();
  
  pthread_exit(0);  //allow main thread to exit while other threads keeps running
}
