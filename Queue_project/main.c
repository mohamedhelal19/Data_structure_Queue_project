#include <stdio.h>
#include <stdlib.h>

#define MAXQUEUE 100

typedef int queueEntry;

typedef struct queuee{
unsigned long Front;
unsigned long Rear;
unsigned long Size;
queueEntry entry [MAXQUEUE];
}Queue;

void creatqueue(Queue *pq);
void append(queueEntry e, Queue *pq);
void serve(Queue *pq);
unsigned char queueEmpty(Queue *pq);
unsigned char queueFull(Queue *pq);
unsigned long queueSize(Queue *pq);
void clearQueue(Queue *pq);
void print_ele(Queue *pq);

int main()
{
    int choice;
    int ele;
    Queue q;
    creatqueue(&q);
    printf("\t\t\t  Remember that Queue is a FIFO technique.");
    printf("\t\t\tenter choice:\n");
    printf("\t\t\tpress '1' to add element.\n");
    printf("\t\t\tpress '2' to delete first element you had entered.\n");
    printf("\t\t\tpress '3' to print the first element you had entered.\n");
while(1){

    printf("\nyour choice>>");
    scanf("%d",&choice);
    printf("\n");
switch(choice){
case 1:
    printf("\nplease enter element: \n");
    scanf("%d",&ele);
    append(ele,&q);
    break;
case 2:

    serve(&q);
    break;
case 3:
    print_ele(&q);

default:

    break;
    }

}
    return 0;
}
void creatqueue(Queue *pq){
    pq->Front=0;
    pq->Rear=-1;
    pq->Size=0;
}
void append(queueEntry e, Queue *pq){
    if(pq->Rear==MAXQUEUE+1){
        pq->Rear=0;
    }
    else{
        pq->Rear++;
    }

    pq->entry[pq->Rear]=e;
    pq->Size++;
}
void serve(Queue *pq){
    queueEntry *pe;
    *pe=pq->entry[pq->Front];

    if(pq->Front==MAXQUEUE+1){
        pq->Front=0;
    }
    else{
        pq->Front++;
    }
    pq->Size--;

}
unsigned char queueEmpty(Queue *pq){
    if(pq->Size==0){
        return 1;
    }
    else{
        return 0;
    }
}
unsigned char queueFull(Queue *pq){
    if(pq->Size==MAXQUEUE){
        return 1;
    }
    else{
        return 0;
    }
}
unsigned long queueSize(Queue *pq){
    return pq->Size;
}
void clearQueue(Queue *pq){
    pq->Front=0;
    pq->Rear=-1;
    pq->Size=0;
}

void print_ele(Queue *pq){
    if(pq->Size==0)
        printf("\nQueue empty \n");
    else
        printf("%d \n",pq->entry[pq->Front]);
}
