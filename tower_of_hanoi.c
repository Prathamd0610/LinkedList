#include<stdio.h>
#include<stdlib.h>
void TOH(int n, char a, char b , char c){
    if(n==1){
        printf("move from %c to %c\n",a,b);
        return;
    }
    else{
        TOH(n-1,a,c,b);
        printf("move from %c to %c\n",a,b);
        TOH(n-1,c,b,a);
    }
}

void main(){
    int n;
    char a,b,c;
    scanf("%d",&n);
    TOH(n,'A','B','C');
}