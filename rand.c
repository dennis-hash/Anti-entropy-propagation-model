#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

void* routine(void *arg)
{
   int *newvalue = (int *)arg;
   int oldvalue = (*newvalue);
   printf("Value = %d",*newvalue);
   return NULL;
}

int main()
{
    pthread_t th[10]; //10 threads
    int i,random,value,randomArray[10];
    value = 1;
    for(i=0; i<10; i++)
    {
        random = rand()%10+1; //choosing a thread at random
        randomArray[i]=random;
       
    }

    for(i=0; i<10; i++)
    {  
        random = randomArray[i];
        if(pthread_create(&th[random], NULL, routine, &value) != 0)
        {
            printf("thread create error");
        }
    }

     for(i=0; i<10; i++)
    {
        random = randomArray[i];
        if(pthread_join(th[random], NULL) != 0)
        {
            printf("thread join  error");
        }
    }
    return 0;
}