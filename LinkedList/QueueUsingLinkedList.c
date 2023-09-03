#include<stdio.h>
#include<stdlib.h>
addLast();
deleteFirst();
display();
struct node{
    int info;
    struct node *ptr;
};
typedef struct node node;
node *head=NULL,*tail=NULL,*temp,*prev;
//node creation
node *createNode()
{
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL){
        printf("node is not created");
        return;
    }
    printf("enter data");
    scanf("%d",&temp->info);
    temp->ptr=NULL;
    return temp;
}
void main(){
    int ch;
    while(10){
        printf("\nenter \n 1 for addLast \n 2 for deleteFirst \n  3 for display \n 4 for exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:addLast();break;
            case 2:deleteFirst();break;
            case 3:display();break;
            case 4:exit(10);
        }
    }
}
addLast(){
    node *t;
    if(head==NULL){
        head=createNode();
        tail=head;
    }
    t=createNode();
    tail->ptr=t;
    tail=t;
 }
deleteFirst(){
    if(head==NULL || tail==NULL){
        printf("List is empty");
        return;
    }
    if(head==tail){
        head=tail=NULL;
    }
    else{
        head=head->ptr;
    }
 }
 display(){
    temp=head;
    printf("%u",temp);
    while(temp!=NULL){
        printf("->||%d-%u\n",temp->info,temp->ptr);
        temp=temp->ptr;
    }
}
            