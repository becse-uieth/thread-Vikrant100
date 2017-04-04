#include<stdio.h>
#include<pthread.h>
#include<signal.h>
void * thread()
{
int a=1;
int b=2;
int c;
c=a+b;
printf( "i am thread %ld and my sum is %d",pthread_self(),c);
}
int main()
{
int i;
pthread_t tid[4];
for(i=0;i<4;i++)
{
pthread_create(&tid[i],NULL,&thread,NULL);
pthread_join(tid[i],NULL);
}
return 0;
}

