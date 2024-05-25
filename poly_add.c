#include<stdio.h>
#include<stdlib.h>
typedef struct linkedlist{
    int coeff;
    int pow;
    struct linkedlist *next;
}node;

void create_node(node **head,int c,int p){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL){
        printf("memory not allocated");
    }
    temp->coeff=c;
    temp->pow=p;
    // temp->next=NULL;
    if(*head==NULL){
        temp->next=NULL;
    }
    else{
        temp->next=*head;
    }
    *head=temp;
}

void polyadd(node *poly1, node *poly2, node **poly){
    while(poly1 &&poly2){
        if(poly1->pow>poly2->pow){
            create_node(poly,poly1->coeff,poly1->pow);
            poly1=poly1->next;
        }
        else if(poly1->pow<poly2->pow){
            create_node(poly,poly2->coeff,poly2->pow);
            poly2=poly2->next;
        }
        else{
            create_node(poly,poly1->coeff+poly2->coeff,poly1->pow);
            poly1=poly1->next;
            poly2=poly2->next;
        }
    }
    while(poly1||poly2){
        if(poly1)
        {
            create_node(poly,poly1->coeff,poly1->pow);
            poly1=poly1->next;
        } 
        else{
            create_node(poly,poly2->coeff,poly2->pow);
            poly2=poly2->next;
        }
        }
}

void show_poly(node *poly){
    while(poly!=NULL){
        if(poly->next==NULL){
            // printf("%dx^%d\n",poly->coeff,poly->pow);
            printf("%dx^%d \b ",poly->coeff,poly->pow);
        }
        else if((poly->next)->coeff>0)
            printf("%dx^%d + ",poly->coeff,poly->pow);
        else if((poly->next)->coeff<0)
            printf("%dx^%d ",poly->coeff,poly->pow);
        poly=poly->next;   
    }
    printf("\n");

}

void main()
{
    node *poly = NULL, *poly1 = NULL, *poly2 = NULL;
    //creating nodes of poly1
    create_node(&poly1,5,2);
    create_node(&poly1,4,1);
    create_node(&poly1,3,0);

    printf("polynomial 1 :");
    show_poly(poly1);

    //creating nodes of poly2
    create_node(&poly2,-2,1);
    create_node(&poly2,-1,0);  

    printf("polynomial 2 :");
    show_poly(poly2);

    // Perform polynomial addition
    polyadd(poly1, poly2, &poly);
    printf("Resultant polynomial after addition :\n");
    show_poly(poly);
}