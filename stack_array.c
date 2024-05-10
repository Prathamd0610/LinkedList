#include<stdio.h>
#include<stdlib.h>
#define MAX 10
#define NIL -1

typedef struct stack{
    int top;
    int a[MAX];
}stack;

void push(stack*, int);
int pop(stack*);
int is_full(stack);
int is_empty(stack);

int main(){
    stack s;
    int c,value;
    while(1){
        // clrscr();
        printf("1. push\n");
        printf("2. pop\n");
        printf("3. exit\n");
        printf("Enter Your Choice :");
        scanf("%d",&c);
        switch(c){
            case 1:
                if(is_full(s)){
                    printf("stack overflow");
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

void push(stack *s,int value){
    (s->top)++;
    s->a[s->top]=value;
    printf("%d pushed into stack",s->a[s->top]);
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