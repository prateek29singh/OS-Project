#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>
#pragma GCC diagnostic ignored "-fpermissive"
int food[20],a=0;
sem_t cat_wt_count,mouse_wt_count;
pthread_mutex_t mutex;
	pthread_t t1,t2,t3,t4;

void * cat()
{
	pthread_mutex_lock(&mutex);
	a=a+1;
	sleep(2);
	 pthread_cancel(t3);
	sleep(1);
	pthread_cancel(t4);
	//sleep(2);
	printf("I am the cat %d\n",a);
	food[a]=a;
	
	pthread_mutex_unlock(&mutex);
}

void * mouse()
{
	sleep(7);
	printf("Mouse ate from %d\n",a);
	a=a-1;
	
}

int main()
{
	sem_init(&cat_wt_count,0,5);
	sem_init(&mouse_wt_count,0,5);
	
	int a=5;
	pthread_create(&t1,NULL,cat,NULL);
	pthread_create(&t2,NULL,cat,NULL);
	pthread_create(&t3,NULL,mouse,NULL);
	pthread_create(&t4,NULL,mouse,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	pthread_join(t4,NULL);	
	
}
