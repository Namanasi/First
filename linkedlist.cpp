#include <stdio.h>
#include <stdlib.h>
struct record { 
       int data;
       struct record *next;
               };

struct record *phead;

struct record *creat(int);
void printLinkedList(struct record*);
void insert(int,int);
void link(int);
void unlink(int);

int main(){

       char op;
       int a,b;


       phead = creat(0); 
       printf("Head: %d %d\n",phead,phead->next);
       
       

       printf("\n'l':Link a node.\n'i':Insert a node.\n'd':Delete a node.\n'p':Print this linked list.\nwhat do you want to do?");
       scanf("%c",&op);
       
      while(op=='i'||op=='d'||op=='l'||op=='p'){
                                       
           switch(op)
           {
           case'l':
                   printf("you can add a nuber to this link:");
                   scanf("%d",&a);
                   link(a);
                   printf("\n=============result=============\n");
                   printLinkedList(phead);
                   printf("\n================================\n");                
                   break;
           case'i':
                   printf("input x,y you can insert a nuber x after y:");
                   scanf("%d%d",&a,&b);
                   insert(a,b);
                   printf("\n=============result=============\n");
                   printLinkedList(phead);
                   printf("\n================================\n");  
                   break;
           case'd':
                   printf("delete a nuber from this link:");
                   scanf("%d",&a);
                   unlink(a);
                   printf("\n=============result=============\n");
                   printLinkedList(phead);
                   printf("\n================================\n"); 
                   break;
           case'p':
                   printf("\n=============result=============\n");
                   printLinkedList(phead);
                   printf("\n================================\n"); 
                   break;
                   
           }
           
       getchar();
       printf("\n'l':Link a node.\n'i':Insert a node.\n'd':Delete a node.\n'p':Print this linked list.\nwhat do you want to do?");
       scanf("%c",&op);
   
       }
              
       system("PAUSE");
}

           
struct record *creat(int i){
       struct record *New;
       New=(struct record*)malloc(sizeof(struct record));
       New->data=i;
       New->next=NULL;
       return(New);
}


void link(int i){
         struct record *ptr,*temp;
         temp=creat(i);
         ptr=phead;
         while(ptr->next!=NULL)
         {ptr=ptr->next;}
         ptr->next=temp;  
}

void insert(int i,int j){
     struct record *ptr,*temp; 
     temp=creat(i);
     ptr=phead;
     while(ptr->data!=j)
     {
       ptr=ptr->next;}
     temp->next=ptr->next;
     ptr->next=temp;
}


void unlink(int i){
     struct record *ptr,*temp;
     ptr=phead->next;
     temp=phead;
     while(ptr->data!=i && ptr->next !=NULL)
     { temp=ptr;     
       ptr=ptr->next;}
    if(ptr->data!=i){
    	printf("\n!!No this num in nodes!!\n");
	}else{
		temp->next=ptr->next;
     	free(ptr);
	}
     
}

void printLinkedList(struct record *i){
     while(i->next!=NULL){
          printf("%8d||%3d||%8d\n",i,i->data,i->next);
          i=i->next;}
          printf("%8d||%3d||%8d\n",i,i->data,i->next);
}




