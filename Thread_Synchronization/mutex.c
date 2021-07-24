int arr[] = {1,2,3,4,5};


static void* thread_fn_callback_sum(void *arg){
  
   int arr_size = sizeof(arr)/sizeof(arr[0]);
  do {
        int i = 0;
        int sum = 0;
      while(i < arr_size){
       sum = sum + arr[i]; 
        i++;
   }
    printf("sum is : %d\n", sum);    
  }while(1);
}

static void* thread_fn_callback_swap(void *arg){
  
   int arr_size = sizeof(arr)/sizeof(arr[0]);
  do {
      int temp;
      temp = arr[0];
      arr[0] = arr[arr_size-1];
      arr[arr_size-1]=temp;
   }
    printf("sum is : %d\n", sum);    
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
