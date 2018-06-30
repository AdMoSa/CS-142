#include<stdio.h>
#include<stdlib.h>

int count=0;

/*define a block. Note that you could put more data field in the block like what is commented */

typedef struct block
{
   int data;
   //float percentage;
   struct block *next;
}
node;

node *head=NULL;

node* createblock()
{
  int val;
  node *temp;
  temp=(node *) malloc(sizeof(node));// ask a place for new block, notice our own data type, in this case node, can be used as any other data type like int, float, char
  if (temp==NULL)
    {
        printf("failed to assign memory\n");
        exit(0);
    }
  else
  {
    printf("Enter value of marks for this node :\t");
    scanf("%d",&val);
    temp->data=val;  /* put the value in the data field*/
    temp->next=NULL; /* this is going to be the last block and hence the next value is NULL*/
    count++;
  }
  return temp;
}

void printlist(node *start)
{
            if(start->next!=NULL)
	printlist(start->next);
      printf("%d\t",start->data); printf("\n");


}


node * pop(node * head)       //delete node from the beginning
{
    if(head==NULL)
        printf("empty list\n");
    else
        {
            node * temp=NULL;
            temp=head;
            head=head->next;
            //printf("Popped top node\n");
        }
    return head;
}

node * push(node *qend)     //add node in the end of the queue
{
	node *temp;
	temp=createblock();
	if(qend==NULL)
        return temp;
    else
        qend->next=temp;
	//printf("Pushed new node\n");
	return temp  ;

}




int main (){

  /*creating linked list has three steps, create first node, create new block, add them at the last of the list*/
  int option=1;
  node *qtop=NULL;
  node *qend=NULL;
  node *temp=NULL;
  printf("Please enter\n 1 to push stack\n 2 to pop stack\n 3 to print list\n and 0 to exit :");
  scanf("%d",&option);
  getchar();
  while (option!=0)
    {
        switch(option)
        {
            case 1:
                if(qtop==NULL)
                        {qtop=qend=push(qend);}
                else
                qend=push(qend);
                printf("Pushed top stack\n");
                break;

            case 2:
                temp=qend;
                node * tmp;
                while(temp!=qtop)
                {
                    tmp=qtop;
                    qtop=pop(qtop);
                    qend->next=tmp;
                    tmp->next=NULL;
                    qend=tmp;
                }
                qtop=pop(qtop);
                printf("Popped top stack\n");
                break;

            case 3:
                if (qtop==NULL)
                    printf("empty list\n");
                else
                    printlist(qtop);
                break;

            default:
                printf("not a valid option\n");
                break;
   }
   printf("\nPlease enter\n 1 to push stack\n 2 to pop stack\n 3 to print list\n and 0 to exit :");
   scanf("%d",&option);
    getchar();
 }

 free(qtop);
 free(qend);


 return 0;
}
