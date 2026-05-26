#include <stdio.h>
 void producer(int n);
 void consumer(int n);
 int n,mutex=1,empty,full=0,x=0;
 int main(){
     printf("Enter the size of buffer:");
     scanf("%d",&n);
     empty=n;
     int choice;
     while(1){
         printf("\nchoose one\n1.producer\n2.consumer\n3.exit\n");
         printf("Enter your choice:");
         scanf("%d",&choice);
         switch(choice){
             case 1:
                 producer(n);
                 break;
             case 2:
                 consumer(n);
                 break;
             case 3:
                 return 0;
             default:
                 printf("Invalid");

        }
    }
    return 0;
}
void producer (int n){
    if(mutex==1 && empty!=0){
        mutex=0;
        empty--;
        full++;
        x++;
        printf("Producer produced item %d\n",x);
        mutex=1;
    }
    else{
        printf("Buffer is full\n");
    }
}

void consumer(int n){
    if(mutex==1 && full!=0){
        mutex=0;
        printf("consumer consumed item %d\n",x);
        x--;
        empty++;
        full--;
        mutex=1;
    }
    else{
        printf("buffer is empty\n");
    }
}
