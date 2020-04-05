#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include <stdbool.h>

bool primenum(int n)
{
        for(int i=2;i<=n/2;i++)
        {
                if(n%i==0)
                {
                        return false;
                }
        }
        return true;
}

void *prime(void *arg){
        for(int i=1;i<=(*(int *)arg);i++)
        {
                if(primenum(i)){
                        printf("%d ",i);
                }
        }
}
                                                                                                                                                                                                                   int main()                                                                                                                                                                                                         {                                                                                                                                                                                                                          int n;
        pthread_t thread1;
        printf("Enter a Number : ");
        scanf("%d",&n);
        pthread_create(&thread1,NULL,prime,(void *)&n);
        pthread_join(thread1,NULL);
}


