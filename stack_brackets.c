#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 10
#define NIL -1

typedef struct stack{
    int top;
    char arr[MAX];
}stack;

void main(){
    stack a;
    char bracket[20];
    printf("enter characters:");
    scanf("%s",&bracket);
    a.top=-1;
    for(int i=0;i<strlen(bracket);i++){
        if(bracket[i]=='{'){
            a.top++;
            a.arr[a.top]=bracket[i];
        }
        else if(bracket[i]=='}'){
            a.top--;
        }
    }
    if(a.top==-1){
        printf("balanced");
    }
    else{
        printf("not balanced");
    }
}