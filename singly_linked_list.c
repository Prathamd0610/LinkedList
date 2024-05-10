#include<stdio.h>
#include<stdlib.h>

typedef struct linkedlist{
    int info;
    struct linkedlist *next;
}node;

void delete_entire_list(node **head);
void reverse_list(node **head);
node * search(node *head,int value);
void delete_after_element(node *head, int s);
void insert_after_element(node *head,int s,int value);
void delete_at_beg(node** head);
void delete_at_end(node **head);
void traverse(node *head);
void insert_at_beg(node **head,int value);
void insert_at_end(node **head, int value);

void main()
{
    int value,choice,s;
    node *head = NULL;                      //creating head of linkedlist
    while(1){
        printf("\n1. insert at beginning :\n");
        printf("2. insert at end :\n");
        printf("3. insert after element :\n");
        printf("4. delete at beginning :\n");
        printf("5. delete at end :\n");
        printf("6. delete after element :\n");
        printf("7. delete entire list :\n");
        printf("8. search :\n");
        printf("9. traverse:\n");
        printf("10. traverse in reverse:\n");
        printf("11. reverse list:\n");
        printf("12. exit:\n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("enter element to insert: ");
                scanf("%d",&value);
                insert_at_beg(&head,value);
                break;
            case 2:
                printf("enter element to insert: ");
                scanf("%d",&value);
                insert_at_end(&head,value);
                break;
            case 3:
                printf("enter after which element to insert: ");
                scanf("%d",&s);
                printf("enter element to insert: ");
                scanf("%d",&value);
                insert_after_element(head,s,value);
                break;
            case 4:
                printf("enter element to insert: ");
                delete_at_beg(&head);
                break;
            case 5:
                printf("enter element to insert: ");
                delete_at_end(&head);
                break;
            case 6:
                printf("enter after which element to delete: ");
                scanf("%d",&s);
                delete_after_element(head,s);
                break;
            case 7:
                delete_entire_list(&head);
                break;
            case 8:
                printf("enter item to search: ");
                scanf("%d",&s);
                node *address=search(head,s);
                printf("%x",address);
                break;
            case 9:
                traverse(head);
                break;
            case 10:
                printf("not defined...");
                break;
            case 11:
                reverse_list(&head);
                break;
            case 12:
                exit(0);        
        }
    }
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

void delete_at_end(node **head){
    node *temp,*loc;
    if((*head)->next==NULL){
        temp= *head;
    }
    else{
        temp= *head;
        while(temp->next!= NULL){
            loc = temp;
            temp= temp->next;
        }
        loc->next=NULL;
    }
    free(temp);
}

void delete_at_beg(node **head){
    node *temp,*loc;
    if((*head)->next==NULL){
        temp=(*head);
        (*head)=NULL;
    }
    else{
        temp=(*head);
        (*head) = temp->next;
    }
    free(temp);
}

node* search(node *head,int value){
    while(head!=NULL){
        if(head->info==value){
            return head;
        }
        head=head->next;
    }
    return NULL;
}
void insert_after_element(node *head,int s,int value){
    node *temp,*loc;
    loc=search(head,s);
    temp=(node*)malloc(sizeof(node));
    temp->info=value;
    if(loc->next==NULL){
        temp->next=NULL;
    }
    else{
        temp->next=loc->next;
    }
    loc->next=temp;
}

void delete_after_element(node *head,int s){
    node *temp,*loc;
    loc=search(head,s);
    if(loc->next==NULL){
        printf("not able to delete...");
    }
    else{
        temp=loc->next;
        loc->next=temp->next;
        free(temp);
    }
}

void reverse_list(node **head){
    node *temp,*loc;
    temp=*head;
    *head=NULL;
    while(temp!=NULL){
        loc=temp;
        temp=temp->next;
        loc->next=*head;
        *head=loc;
    }
}

void delete_entire_list(node **head){
    node *temp;
    while((*head)!=NULL){
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
    printf("list deleted\n");
}