#include<stdio.h>
#include<stdlib.h>

typedef struct doubly{
    int info;
    struct doubly *next;
    struct doubly *prev;
}node;

void insert_at_beg(node **head,node **tail,int value);

void insert_at_end(node **head,node **tail,int value);

void traverse(node *head);

void reverse_traverse(node *tail);

void insert_after_element(node *head,node **tail,int value,int s);

int main()
{
    int value,choice,s;
    node *head = NULL;                      //creating head of linkedlist
    node *tail = NULL;                     //creating tail of linkedlist
    while(1){
        printf("\n1. insert at beginning :\n");
        printf("2. insert at end :\n");
        printf("3. insert after element :\n");
        // printf("4. delete at beginning :\n");
        // printf("5. delete at end :\n");
        // printf("6. delete after element :\n");
        // printf("7. delete entire list :\n");
        // printf("8. search :\n");
        printf("9. traverse:\n");
        printf("10. traverse in reverse:\n");
        // printf("11. reverse list:\n");
        printf("12. exit:\n");
        printf("enter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                printf("enter element to insert: ");
                scanf("%d",&value);
                insert_at_beg(&head,&tail,value);
                break;
            case 2:
                printf("enter element to insert: ");
                scanf("%d",&value);
                insert_at_end(&head,&tail,value);
                break;
            // case 3:
            //     printf("enter after which element to insert: ");
            //     scanf("%d",&s);
            //     printf("enter element to insert: ");
            //     scanf("%d",&value);
            //     insert_after_element(head,s,value);
            //     break;
            // case 4:
            //     printf("enter element to insert: ");
            //     delete_at_beg(&head);
            //     break;
            // case 5:
            //     printf("enter element to insert: ");
            //     delete_at_end(&head);
            //     break;
            // case 6:
            //     printf("enter after which element to delete: ");
            //     scanf("%d",&s);
            //     delete_after_element(head,s);
            //     break;
            // case 7:
            //     delete_entire_list(&head);
            //     break;
            // case 8:
            //     printf("enter item to search: ");
            //     scanf("%d",&s);
            //     node *address=search(head,s);
            //     printf("%x",address);
            //     break;
            case 9:
                traverse(head);
                break;
            case 10:
                reverse_traverse(tail);
                break;
            // case 11:
            //     reverse_list(&head);
            //     break;
            case 12:
                exit(0);        
        }
    }
}

void insert_at_beg(node **head,node **tail,int value){
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->info = value;
    temp->prev=NULL;
    if((*head)==NULL){
        temp->next=NULL;
        *head=temp;
        *tail=temp;
    }
    else{
        temp->next=*head;
        (*head)->prev=temp;
        *head=temp;
    }  
}

void insert_at_end(node **head, node **tail, int value){
    node *temp;
    temp = (node*)malloc(sizeof(node));
    temp->info = value;
    temp->next=NULL;
    if((*tail)==NULL){
        temp->prev=NULL;
        *head=temp;
        *tail=temp;
    }
    else{
        temp->prev=*tail;
        (*tail)->next=temp;
        *tail=temp;
    }
}

void traverse(node *head){
    node *temp=head;
    while(temp!=NULL){
        printf("%d-> ",temp->info);
        temp=temp->next;
    }
    printf("\n");
}

void reverse_traverse(node *tail){
    node *temp=tail;
    while(temp!=NULL){
        printf("%d-> ",temp->info);
        temp=temp->prev;
    }
    printf("\n");
}

node* search(node *head,int s){
    while(head!=NULL){
        if(head->info==s){
            return head;
        }
        head=head->next;
    }
    return NULL;
}

void insert_after_element(node *head, node **tail, int value, int s){
    node *temp,*loc;
    loc=search(head,value);
    if(loc!=NULL){
        printf("cannot insert after element");
    }
    temp= (node *)malloc(sizeof(node));
    temp->info=value;
    if(loc->next!=NULL){
        temp->next=loc->next;
        temp->prev=loc;
        (loc->next)->prev=temp;
        loc->next=temp;
    }
    else{
        temp->next=loc->next;
        temp->prev=loc;
        loc->next=temp;
        tail=temp;
    }

}