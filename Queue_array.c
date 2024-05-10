#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define NIL -1

typedef struct queue{
    int front,rear;
    int a[MAX];
}queue;


int is_full(queue);
int is_empty(queue);

int main(){
    queue q;
    int c,value;
    while(1){
        // clrscr();
        printf("1. insert in QUEUE\n");
        printf("2. delete from QUEUE\n");
        printf("3. exit\n");
        printf("Enter Your Choice :");
        scanf("%d",&c);
        switch(c){
            case 1:
                if(is_full(s)){
                    printf("QUEUE overflow");
                }
                else{
                    printf("enter value :");
                    scanf("%d",&value);
                    push(&s,value);
                }
                break;
            
            case 2:
                if(is_empty(s)){
                    printf("stack underflow");
                }
                else{
                    value=pop(&s);
                    printf("item popped from stack = %d",value);
                }
                break;

            case 3:
                exit(0);
        }
    }
    return 0;
}

void insert_queue(queue *q,int value){

}

int pop(stack *s){
    int value;
    value=s->a[s->top];
    (s->top)--;
}

int is_full(stack s){
    if(s.top== MAX-1)
        return 1;
    else
        return 0;
}

int is_empty(stack s){
    if(s.top==NIL){
        return 1;
    }
    else{
        return 0;
    }
}