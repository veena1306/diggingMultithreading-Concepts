
/****** Write a program to create 5 threads,and all 5 threads writes a string into a file. thread_x.txt where x is the thread id.
string to write : I am thread <thread id> ************/

#define N_SLAVES 5
pthread_t slaves[N_SLAVES];

void memory_cleanup_handler(void *arg)
{
  printf("%s invoked ...\n",__FUNC__);
  free(arg);
}

void file_cleanup_handler(void *fptr)
{
   printf("%s invoked ...\n",__FUNC__);
   Fclose((FILE*)arg);
}

void* write_into_file(void* arg)
{
  char file_name[64]; 
  char strinf_to_write[64];
  int len ;
  int count = 0;
  
  int *thread_id = (void*)arg;
  
  pthread_cleaup_push(memory_cleaup_handler,arg);
  
  sprintf(file_name, "thread_%d.txt",*thread_id);
  File *fptr = fopen(file_name, "w");
  
  if(!fptr)
  {
    printf("could not open log file, errno : %d\n", file_name.errno); 
    return 0;
  }
  
  pthread_cleaup_push(file_cleaup_handler,fptr);

  
  while(1)
  {
   len = sprintf(string_to_write,"%d : I am thread %d\n", count++, *thread_id); 
   fwrite(string_to_write,sizeof(char),len,fptr);
   fflush(ptr);
    sleep(1);
  }
  
  pthread_cleanup_pop(0);
  pthread_cleanup_pop(0);
}

int main(int argc, char **argv)
{
  int i;  
  int *thread_id = 0;
  
  for(i = 0; i < N_SLAVES; i++)
  {
    thread_id = calloc(1, sizeof(*thread_id));
    *thread_id = 1;
     pthread_create(&slaves[i],NULL,write_into_file,thread_id);
  }
  
  int choice;
  int thread_num;
  
  while(1){
    printf("1. cancel the thread\n");
    scanf("%d",&choice);
    printf("Enter slave thread id : [0-%d]",N_SLAVES-1);
    scanf("%d\n",thread_num);
    
    if(thread_num < 0 || thread_num > N_SLAVES)
    {
     printf("invalid thread number");
      exit(0);
    }
    printf("\n");
    switch(choice)
    {
      case 1: 
           break;
       default :
          continue;
    }
        
    }
     return 0;
  }
  
}
