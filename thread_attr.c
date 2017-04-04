#include<stdio.h>
#include<pthread.h>
void*area(void *a)
{
 int *s;
 s=(int*)a;
 int ab;
 ab=s[0]+s[1];
 return (void*)ab;
}

int main()
{
 int c;
 pthread_t tid;
 int a[2]={3,5};
 pthread_join(tid,NULL);
 pthread_attr_t attr;        // attribute
 pthread_attr_init(&attr);
 pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);
 

 pthread_create(&tid,&attr,&area,a);
 pthread_join(tid,(void*)&c);
 pthread_attr_destroy(&attr);
 


 printf("\n%d",c);
 return 0;
}
