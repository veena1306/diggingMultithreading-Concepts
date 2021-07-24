/****** Write a program to create 5 threads,and all 5 threads writes a string into a file. thread_x.txt where x is the thread id.
string to write : I am thread <thread id> ************/

#define N_SLAVES 5
pthread_t slaves[N_SLAVES];

void* write_into_file(void* arg)
{
  char file_name[64]; 
  char strinf_to_write[64];
  int len ;
  int count = 0;
  
  pthread_setcancelstate(PTHREAD_CANCEL_ENABLE,0);  //PTHREAD_CANCEL_DISABLE
  pthread_setcanceltype(PTHREAD_CANCEL_ASYNCHRONUOS,0);
  
  int *thread_id = (void*)arg;
  sprintf(file_name, "thread_%d.txt",*thread_id);
  File *fptr = fopen(file_name, "w");
  
  if(!fptr)
  {
    printf("could not open log file, errno : %d\n", file_name.errno); 
    return 0;
  }
  
  while(1)
  {
   len = sprintf(string_to_write,"%d : I am thread %d\n", count++, *thread_id); 
   fwrite(string_to_write,sizeof(char),len,fptr);
   fflush(ptr);
    sleep(1);
  }
  
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
           pthread_cancel(slave[thread_num]);
           break;
       default :
          continue;
    }
        
    }
     return 0;
  }
  
}
