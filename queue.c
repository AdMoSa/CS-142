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
      while(start!=NULL)
        {
            printf("%d\t",start->data); printf("\t");
            start=start->next;
        }
}


node * addnodeend(node *start)
{
    node *temp=NULL;
    temp=createblock();
    if(start==NULL)/* create first node*/
        return temp;
    else
      start->next=temp; // /* create block and add it to the last*/

    return temp;
}




node * deletefrombeg(node * head)       //delete node from the beginning
{
    if(head==NULL)
        printf("empty list\n");
    else
        {
            node * temp=NULL;
            temp=head;
            head=head->next;
            free(temp);
            printf("Popped top node\n");
        }
    return head;
}




int main (){

  /*creating linked list has three steps, create first node, create new block, add them at the last of the list*/
  int option=1,n=0;
  node *qtop=NULL;
  node *qend=NULL;
  node *temp=NULL;

  printf("Please enter\n 1 to push queue\n 2 to pop queue\n 3 to print list\n and 0 to exit :");
  scanf("%d",&option);
  getchar();
  while (option!=0)
    {
        switch(option)
        {
            case 1:
                if(qtop==NULL)
                {
                    qtop=addnodeend(qtop);
                    qend=qtop;
                }
                else
                    qend=addnodeend(qend);
                break;

            case 2:
                qtop=deletefrombeg(qtop);
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
   printf("\nPlease enter\n 1 to push queue\n 2 to pop queue\n 3 to print list\n and 0 to exit :");
   scanf("%d",&option);
    getchar();
 }

 free(qtop);
 free(qend);
 free(temp);

 return 0;
}


