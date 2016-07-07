#include <stdio.h>
#include <stdlib.h>
struct record { 
       int data;
       struct record *next;
               };//���c�����G���e��(int)�A���Ц걵(self)
//�]�ߦ�C���Y[�����ܼ�] 
struct record *phead;//�إߤ@�ӫ��A�����crecord������ 

struct record *creat(int);//���͸`�I�ƨ禡 -���w�I���ƭȤ��e 
void printLinkedList(struct record*);//�L�X��C�ƨ禡-���w���Y 
void insert(int,int);//���J�`�I �ƨ禡
void link(int);//���͸`�I��b��C�̫᭱ 
void unlink(int);//���X�Y�Ӹ`�I 

int main(){

       char op;
       int a,b;

//�ظm���n���Y 
       phead = creat(0); // �إߤ@���s�Ȫ����Y �ñN��m�ǵ�phead        
       printf("Head: %d %d\n",phead,phead->next);//�L�X�Ӽ��Y
       
       
//�إ߿�� 
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

           
struct record *creat(int i){//�ƨ禡 
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
     temp=creat(i);//�إߤ@��temp���sstruct(data,node)�ǳƴ��J�A
     ptr=phead;//ptr�h�@���j�M��
     while(ptr->data!=j)
     {
       ptr=ptr->next;}//���n���J����m(j�᭱) 
     temp->next=ptr->next;//�s���J����Ƨ��ݳs��j���U�@�Ӽ� 
     ptr->next=temp;//j�n�s��s���(temp) 
}


void unlink(int i){
     struct record *ptr,*temp;//��ӳ��Ψӷj�M 
     ptr=phead->next;
     temp=phead;
     while(ptr->data!=i && ptr->next !=NULL)
     { temp=ptr;      //temp�N���i���e�@�Ӽ� 
       ptr=ptr->next;}//ptr�N���n�R�������(i) 
    if(ptr->data!=i){
    	printf("\n!!No this num in nodes!!\n");
	}else{
		temp->next=ptr->next;//��i���e�@�Ӽƫ��Vi���U�@�ӭ� 
     	free(ptr);//�u���R��i��m����(�쥻���������L 
	}
     
}

void printLinkedList(struct record *i){//�ǨӶ}�Y����(phead) 
     while(i->next!=NULL){
          printf("%8d||%3d||%8d\n",i,i->data,i->next);//i��},��,���V��m 
          i=i->next;}//���ʨ�i���U�@�� 
          printf("%8d||%3d||%8d\n",i,i->data,i->next);//�̫���VNULL�����Ф����� 
}




