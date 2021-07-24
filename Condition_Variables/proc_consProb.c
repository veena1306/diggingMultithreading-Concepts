T1 = consumer Thread
T2 = producer Thread

  maininting a queue.
scenerio : if consumer tries to access queue and it is empty, in that case cv works. have to check if queue is full

T1

pthread_mutex_lock(&q_mutex)
if(q_empty(n)){
  pthread_cond_wait(&t_cv,&q_mutex);
}
pthread_mutex_unlock(&q_mutex)


T2(producer thread)

pthread_mutex_lock(&q_mutex)
if(!q.full())
{
enque();
pthread_cond_signal(&t_cv);
}
pthread_mutex_unlock(&q_mutex)
