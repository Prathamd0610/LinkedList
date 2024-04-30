#include <stdio.h>
#include<stdlib.h>
typedef struct linkedlist{
    int info;
    struct linkedlist *next;
}node;

void insert_at_begning(node **head1, int);
void transversing(node *);
void insertend(node **head1, int);
int main()
{
    node *head=NULL;
    int c,val;
    while (1) {
        printf("\n");
        printf("1. insert at beginning\n");
        printf("2. insert at end\n");
        printf("3. insert after element\n");
        printf("4. delete at beginning\n");
        printf("5. delete at end\n");
        printf("6. delete after element\n");
        printf("7. delete entire list\n");
        printf("8. traversing\n");
        printf("9. creation\n");
        printf("10.search\n");
        printf("11. transpose\n");
        printf("12. transpose in reverse\n");
        printf("13.reverse linked list\n");
        printf("14. Exit\n");
        printf("Enter choice for operations: ");
        scanf("%d", &c);
        switch (c) {
            case 1:
                  printf("enter value : ");
                  scanf("%d",&val);
                  insert_at_begning(&head,val);
                break;
            case 2:
                 printf("enter value : ");
                  scanf("%d",&val);
                  insertend(&head, val);
                break;
            case 3:
                printf("not defined yet");
                break;
            case 4:
                printf("not defined yet");
                break;
            case 5:
                printf("not defined yet");
                break;
            case 6:
                printf("not defined yet");
                break;
            case 7:
                printf("not defined yet");
                break;
            case 8:
                transversing(head);
                break;
            case 9:
                printf("not defined yet");
                break;
            case 10:
                printf("not defined yet");
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
    return 0;
}
void insert_at_begning(node **head1, int val){
    node *temp;
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("unable to allocate memory");
    }
    temp -> info=val;
    if(*head1!=NULL)
    {
        temp -> next=(*head1);
    }
    else{
        temp -> next=NULL;
    }
    *head1=temp;
}

void transversing(node *head)
{
    while(head!=NULL)
    {
        printf("%d->",head->info);
        head=head->next;
    }
}
void insertend(node **head1,int v)
{
    node *temp,*loc;
    temp=(node *)malloc(sizeof(node));
    if(temp==NULL)
    {
        printf("unable to allocate memory");
        return;
    }
    temp->info=v;
    temp->next=NULL;
    if(*head1==NULL)
    {
        *head1=temp;
    }
    else{
        loc=*head1;
        while(loc->next!=NULL)
        {
            loc=loc->next;
        }
        loc->next=temp;
    }
}