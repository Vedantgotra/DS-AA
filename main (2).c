#include<stdio.h>
#include<stdlib.h>
#define MAX 10
typedef struct queuetype{
    int front,rear;
    int a[10];
    
}queue;
int isfull(queue);
int isempty(queue);
void insertion(queue*,int);
int delete(queue*);

void main(){
    
int data,c;
queue q;
q.front=-1;
q.rear=-1;
while(1){
printf("\npress 1 for insert\n");
printf("presa 2 for delete\n");
printf("press 3 for exit\n");
scanf("%d",&c);

switch(c){
    case 1:
    if(isfull(q)){
      printf("queue overflow\n");  
    }
    else{
    printf("enter the element you want to insert\n");
    scanf("%d",&data);
    insertion(&q,data);
    }
    break;
    case 2:
    if(isempty(q)){
        printf("queue underflow\n");
    }
    else{
    data=delete(&q);
    printf("%d",data);
    }
    break;
    case 3:
    exit(0);
    default:
    printf("Invalid Input\n");
    break;
    
}
}
}
int isfull(queue q){
    if(q.front==0&&q.rear==MAX-1){
        return 1;
    }
        else if(q.front-1==q.rear){
        return 1;
    }
    else
    return 0;
    }
    int isempty(queue q){
        if(q.front==-1&&q.rear==-1){
            return 1;
        }
        else{
            return 0;
        }
    }
    
    
    void insertion(queue *q,int d){
        int i;
    if(q->front==-1){
        q->front=0;
        q->rear=0;
    }
    else if(q->front!=0&&q->rear==MAX-1){
        q->rear=0;
        
    }
    else{
        q->rear++;
    }
        q->a[q->rear]=d;
        }
        int delete(queue*q){
            int d;
            d=q->a[q->front];
            if(q->front==q->rear){
                q->front=-1;
                q->rear=-1;
            }
            else if(q->front==MAX-1){
                q->front=0;
            }
            else{
                q->front=q->front+1;
            }
            return d;
            }
            
        


