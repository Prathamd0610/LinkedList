#include<stdio.h>
#include<stdlib.h>

#define N 10

void bubblesort(int a[N],int n){
    for(int Pass=0;Pass<n;Pass++){
        for(int i=0;i<n-Pass;i++){
            if(a[i]>a[i+1]){
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
            }
        }
    }
    printf("array after bubble sort :\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void insertionsort(int a[N],int n){
    int i,j;
    for(i=1;i<n;i++){
        int temp=a[i];
        for(j=i-1;j>=0 && a[j]>temp;j--){
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
    printf("array after insertion sort :\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void selectionsort(int a[N],int n){
    int min,mini,temp,i,j;
    for(i=0;i<n;i++){
        min=a[i];
        mini=i;
        for(j=i+1;j<n;j++){
            if(a[j]<min){
                min=a[j];
                mini=j;
            }
        }
        if(i!=mini){
            temp=a[i];
            a[i]=a[mini];
            a[mini]=temp;
        }
    }
    printf("array after selection sort :\n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}

void main(){
    int ch;
    // bubblesort(a,N);
    // insertionsort(a,N);
    int a[N]={1,8,9,5,7,3,5,7,2,5};
    printf("\n");
    printf(" 1. Bubble Sort\n 2. Insertion Sort\n 3. Selection Sort\n");
    printf("enter your choice:");
    scanf("%d",&ch);
    switch(ch){
        case 1:
            bubblesort(a,N);
            break;
        case 2:
            insertionsort(a,N);
            break;
        case 3:
            selectionsort(a,N);
            break;
        default:
            printf("invalid choice");
            break;
    }
}