#include<stdio.h>
#include<stdlib.h>
/*define a block. Note that you could put more data field in the block like what is commented */
typedef struct block{
   int data;
  //float percentage;
   struct block *next;
}node;

node *head=NULL;
node * findlastblock(node * start){
   if (start==NULL) return start;
  else{
    while(start->next!=NULL){ /* in the last block the next field will be null*/
      start=start->next; /* move to the next node by reading the next block address*/
    }
    return start;
   }

}

void printlist(node *start){


      while(start!=NULL){

      printf("%d\t",start->data);
      start=start->next;
}

}




node* createblock(){
  int val;
  node *temp;
  temp=(node *) malloc(sizeof(node));// ask a place for new block, notice our own data type, in this case node, can be used as any other data type like int, float, char
  if (temp==NULL){
    printf("failed to assign memory\n");
    exit(0);
  }
  else{
    printf("enter value of marks for this node");
    scanf("%d",&val);
    temp->data=val;  /* put the value in the data field*/
    temp->next=NULL; /* this is going to be the last block and hence the next value is NULL*/
  }
  return temp;
}




int main (){

  /*creating linked list has three steps, create first node, create new block, add them at the last of the list*/
  int option=1;
  node *head=NULL;
  node *temp=NULL;

  printf("Please enter 1 to add node at the end, 2 to add node at the beginning, 3 to print list, and 0 to exit");
   scanf("%d",&option);
  getchar();
 while (option!=0){
   switch(option){
   case 1:
     if(head==NULL)/* create first node*/
   head=createblock();
 else{
   temp=findlastblock(head); //find the last block
   if(temp!=NULL)
   temp->next=createblock(); // /* create block and add it to the last*/
 }
 break;
   case 2:
      if(head==NULL)/* create first node*/
   head=createblock();
      else{
    temp=head;
    head=createblock();
    head->next=temp;
      }
      break;
   case 2:
      if(head==NULL)/* create first node*/
   head=createblock();
      else{
    temp=head;
    head=createblock();
    head->next=temp;
      }

   case 3:
      if (head==NULL) printf("empty list\n");
      else
	printlist(head);
     break;
   default:
     printf("not a valid option\n");
     break;
   }
   printf("Please enter 1 to add node at the end, 2 to add node at the beginning, 3 to print list, and 0 to exit");
   scanf("%d",&option);
    getchar();
 }

 free(head);
 free(temp);
}
