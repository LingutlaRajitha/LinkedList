#include<stdio.h>
#include<stdlib.h>
insertion(int pos);
int count();
deletion(int pos);
struct node{
    struct node *lptr;
    int info;
    struct node *rptr;
};
typedef struct node node;
node *head=NULL,*tail=NULL,*temp,*t,*th;
//int c=0;
node *createNode(){
    temp=(node*)malloc(sizeof(node));
    if(temp==NULL){
        printf("node is not created");
        return 0;
    }
    printf("enter data:");
    scanf("%d",&temp->info);
    temp->lptr=NULL;
    temp->rptr=NULL;
    //count++;
    return temp;
}

void main(){
    int ch,pos;
    while(10){
        printf("\nEnter\n 1 for insertion\n 2 for deletion \n 3 for display1 \n 4 for display2 \n 5 for count\n 6 for exit");
        scanf("%d",&ch);
        switch(ch){
            case 1:insertion(pos);break;
            case 2:deletion(pos);break;
            case 3:display1();break;
           // case 4:display2();break;
            case 5:count();
            case 6:exit(10);
        }
    }
}

insertion(int pos){
    t=createNode();
    int c=count();
    printf("\nenter position where you want to insert:");
    scanf("%d",&pos);
    if(head==NULL && tail==NULL){
        head=t;
        tail=t;
    }
    else if(pos<=0){
        t->rptr=head;
        head->lptr=t;
        head=t;
    }
    else if(pos>=c){
        t->lptr=tail;
        tail->rptr=t;
        tail=t;
    }
    else{//InsertAtAnuPossition
        th=head;
        while(pos>1){
            th=th->rptr;
            pos--;
        }
        t->lptr=th;
        t->rptr=th->rptr;
        t->lptr->rptr=t;
        t->rptr->lptr=t;
    }
}
display1(){
    temp=head;
    printf("%u",temp);
    while(temp!=NULL){
        printf("->||%u-%d-%u",temp->lptr,temp->info,temp->rptr);
        temp=temp->rptr;
    }
}
int count(){
    int c=0;
    node *th;
    th=head;
    while(th!=NULL){
        c++;
        th=th->rptr;
    }
   // printf("\ncount:%d",c);
   return c;
}
deletion(int pos)
{
    node *th,*th2;
    int pos2;
    int c=count();
    printf("Enter deleteNode:");
    scanf("%d",&pos);
    if(head==NULL &&tail==NULL){
        printf("List is empty");
        return;
    }
    //DeleteNode at first Position
    if(pos<=0){      
        head=head->rptr;
        t=head;
        t->lptr=NULL;
        return;
    }
    //DeleteNode at last position
    if(pos>=c){
        tail=tail->lptr;
        tail->rptr=NULL;
        return;
    }
    //DeleteNode at any position
    th=head;
    pos2=pos;
    while(pos>1){
        th=th->rptr;
        pos--;
    }
    th2=head;
    while(pos2>=0){
        th2=th2->rptr;
        pos2--;
    }
    th->rptr=th2;
    th2->lptr=th;
    /*DeleteNode at any position(approach2)
     else{
        node *th=head;
        while(pos>1){
            th=th->rptr;
            pos;
        }
        th->rptr->rptr->lptr=th;
        th->rptr=th->rptr->rptr;
     }
    
    */
}

