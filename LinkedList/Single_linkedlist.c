#include<stdio.h>
#include<stdlib.h>
addFirst();
addLast();
deleteFirst();
deleteLast();
display();
count();
insert(int pos);
deleteNode(int pos);
//reverseData(node *p);
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
    int ch,c=0,pos;
    while(10){
        printf("\nenter \n 1 for addFirst \n 2 for addLast \n 3 for deleteFirst \n 4 for deleteLast \n 5 for count \n 6 for display \n 7 for insert \n 8 for deleteNode \n 9 for reversedata \n 10 for exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:addFirst();break;
            case 2:addLast();break;
            case 3:deleteFirst();break;
            case 4:deleteLast();break;
            case 5:count();break;
            case 6:display();break;
            case 7:insert(pos);break;
            case 8:deleteNode(pos);break;
            case 9:reverseData(head);break;
            case 10:exit(10);
        }
    }
}

addFirst(){
    node *t;
    t=createNode();
    if(head==NULL){
        head=t;
        tail=t;
    }
    else{
        t->ptr=head;
        head=t;
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
 deleteLast(){
    node *th;
    if(head==NULL || tail==NULL){
        printf("List is empty");
        return;
    }
    if(head==tail){
        head=tail=NULL;
    }
    else{
        th=head;
        if(th->ptr!=NULL){
            prev=th;
            th=th->ptr;
        }
        prev->ptr=NULL;
        tail=prev;
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
count(){
    int c=0;
    temp=head;
    while(temp!=NULL){
        c++;
        temp=temp->ptr;
    }
    printf("\n %d\n",c);
}
insert(int pos){
    printf ("Enter pos: ");
    scanf("%d",&pos);
    node *th,*t;
    int c=count();
    if(pos<=0){
        addFirst();
        return;
    }
    else if(pos>c){
       addLast();
       return;
    }
    else{
        t=createNode();
        th=head;
        while(pos>1){
            th=th->ptr;
            pos--;
        }
        t->ptr=th->ptr;
        th->ptr=t;
    }
}
deleteNode(int pos){
    node *th,*th2;
    int pos2;
    int c=count();
    printf("Enter delete node:");
    scanf("%d",&pos);
    if(head==NULL){
        printf("List is empty");
    }
    if(pos<=0){
        deleteFirst();
        return;
    }
    if(pos>=c){
        deleteLast();
        return;
    }
    th=head;
    pos2=pos;
    while(pos>1){
        th=th->ptr;
        pos--;
    }
    th2=head;
    while(pos2>=0){
        th2=th2->ptr;
        pos2--;
    }
    th->ptr=th2;
}
reverseData(node *p){
    if(p){
        reverseData(p->ptr);
        printf("\n %d",p->info);
    }

}