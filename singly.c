#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist{
    int info;
    struct linkedlist *next;
}node;

void traverse(node *head);
void insert_at_beg(node **head,int value);

void insert_at_end(node **head, int value);

void main()
{
    int value;
    node *head = NULL;                      //creating head of linkedlist
    for(int i=0;i<10;i++){
        printf("enter value:");
        scanf("%d",&value);
        // insert_at_beg(&head,value);
        insert_at_end(&head,value);
    }
    traverse(head);
}

void insert_at_beg(node **head, int value){
    node *temp;
    temp=(node *)malloc(sizeof(node));      //creating new node to insert at beg
    temp->info= value;                      // inserting value
    if(*head==NULL){
        temp->next=NULL;                   // if it is 1st node next will be null
    }
    else{
        temp->next=(*head);                 // address of previous node will be inserted at temp->next
    }
    *head=temp;                             //changing head to new insert_at_beg node 
}

void traverse(node *head){
    while(head!=NULL){
        printf("%d-> ",head->info);
        head=head->next;
    }
}

void insert_at_end(node **head,int value){
    node *temp,*loc;
    temp=(node*)malloc(sizeof(node));       //creating new node 
    if(temp==NULL)
    {
        printf("not able to insert ...");
    }
    temp->info=value;
    temp->next=NULL;                       // temp is inserted at end to next will be null always
    if(*head==NULL){
        *head=temp;                        // if it is 1st node then change head to temp
    }
    else{
        loc=*head;
        while(loc->next!=NULL){
            loc=loc->next;                  // locating the last node of linkedlist to add new node
        }
        loc->next=temp;                     // making previous last node to 2nd last node.
    }
}