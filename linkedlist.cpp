#include <stdio.h>
#include <stdlib.h>
struct record { 
       int data;
       struct record *next;
               };//結構成員：內容值(int)，指標串接(self)
//設立串列標頭[全域變數] 
struct record *phead;//建立一個型態為結構record的指標 

struct record *creat(int);//產生節點副函式 -給定點之數值內容 
void printLinkedList(struct record*);//印出串列副函式-給定標頭 
void insert(int,int);//插入節點 副函式
void link(int);//產生節點街在串列最後面 
void unlink(int);//取出某個節點 

int main(){

       char op;
       int a,b;

//建置首要標頭 
       phead = creat(0); // 建立一為零值的標頭 並將位置傳給phead        
       printf("Head: %d %d\n",phead,phead->next);//印出該標頭
       
       
//建立選單 
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

           
struct record *creat(int i){//副函式 
       struct record *New;
       New=(struct record*)malloc(sizeof(struct record));
       New->data=i;
       New->next=NULL;
       return(New);
}


void link(int i){//....i,j
         struct record *ptr,*temp;
         temp=creat(i);
         ptr=phead;
         while(ptr->next!=NULL)
         {ptr=ptr->next;}
         ptr->next=temp;  
}

void insert(int i,int j){
     struct record *ptr,*temp; 
     temp=creat(i);//建立一個temp的新struct(data,node)準備插入，
     ptr=phead;//ptr則作為搜尋用
     while(ptr->data!=j)
     {
       ptr=ptr->next;}//找到要插入的位置(j後面) 
     temp->next=ptr->next;//新插入的資料尾端連到j的下一個數 
     ptr->next=temp;//j要連到新資料(temp) 
}


void unlink(int i){
     struct record *ptr,*temp;//兩個都用來搜尋 
     ptr=phead->next;
     temp=phead;
     while(ptr->data!=i && ptr->next !=NULL)
     { temp=ptr;      //temp將位於i的前一個數 
       ptr=ptr->next;}//ptr將位於要刪掉的資料(i) 
    if(ptr->data!=i){
    	printf("\n!!No this num in nodes!!\n");
	}else{
		temp->next=ptr->next;//讓i的前一個數指向i的下一個值 
     	free(ptr);//真的刪掉i位置的值(原本為忽略跳過 
	}
     
}

void printLinkedList(struct record *i){//傳來開頭指標(phead) 
     while(i->next!=NULL){
          printf("%8d||%3d||%8d\n",i,i->data,i->next);//i位址,值,指向位置 
          i=i->next;}//移動到i的下一項 
          printf("%8d||%3d||%8d\n",i,i->data,i->next);//最後指向NULL的指標仍有值 
}




