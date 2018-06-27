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

node * findlastblock(node * start)
{
    if (start==NULL)
        return start;
    else
    {
        while(start->next!=NULL)     /* in the last block the next field will be null*/
        {
            start=start->next;       /* move to the next node by reading the next block address*/
        }
        return start;
   }

}

node * findnthblock(node * start,int n)
{
   if (start==NULL)
    return start;
   else
   {
       int i=1;
       for(i;i<n;i++)
        start=start->next;            /* move to the next node by reading the next block address*/

    //printf("printing ",n); printf("th value\t");
    //printf("%d\t",start->data);
       return start;
   }
}



void printlist(node *start)
{
      while(start!=NULL)
        {
            printf("%d\t",start->data);
            start=start->next;
        }
}

node * addnodeend(node *head)
{
    node *temp=NULL;
    if(head==NULL)/* create first node*/
    head=createblock();
    else
        {
            temp=findlastblock(head); //find the last block
            if(temp!=NULL)
            temp->next=createblock(); // /* create block and add it to the last*/
        }
    return head;
}

node * addnodebeg(node *head)
{
    node *temp=NULL;
    if(head==NULL)/* create first node*/
        head=createblock();
    else
    {
        temp=head;
        head=createblock();
        head->next=temp;
    }
    return head;
}

node * addnodemid(node *head,int n)
{
    node *temp=NULL;
    printf("Enter nth node after which to add :\t");
    scanf("%d",&n);
    if(n<count)
    {
        if(head==NULL)/* create first node*/
            head=createblock();
        else
        {
            temp=createblock();
            temp->next=findnthblock(head,n+1);
            findnthblock(head,n)->next=temp;
        }
    }
    else
      printf("not a valid option\n");
    return head;
}

void printnthnode(node * head)
{
    int n;
    node *temp=NULL;
    printf("Enter object no :\t");
    scanf("%d",&n);
    if(n<count)
    {
        temp=findnthblock(head,n);
        printf("printing node "); printf("%d",n); printf(" :\t");
        printf("%d\t",temp->data);

    }
    else
      printf("not a valid option\n");

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
            printf("Deleted first node\n");
        }
    return head;
}

node * deletefromend(node * start)
{
    head=start;
    if (head==NULL)
        printf("empty list");
    if (head->next==NULL)
        head=NULL;
    else
    {
        node * temp=NULL;
        while(start->next!=NULL)
        {
            temp=start;
            start=start->next;
            if(start->next==NULL)
            {
                temp->next=NULL;

                printf("Deleted last node\n");
            }
        }
    }
    free(start);
    return head;
}



int main (){

  /*creating linked list has three steps, create first node, create new block, add them at the last of the list*/
  int option=1,n=0;
  node *head=NULL;
  node *temp=NULL;

  printf("Please enter\n 1 to add node at the end\n 2 to add node at the beginning\n 3 to add in the middle\n 4 to delete node from the beginning\n 5 to delete node from the end\n 6 to find nth block\n 7 to print list\n and 0 to exit :");
  scanf("%d",&option);
  getchar();
  while (option!=0)
    {
        switch(option)
        {
            case 1:
                head=addnodeend(head);
                break;

            case 2:
                head=addnodebeg(head);
                break;

            case 3:
                head=addnodemid(head,n);
                break;

            case 4:
                head=deletefrombeg(head);
                break;

            case 5:
                head=deletefromend(head);
                break;

            case 6:
                printnthnode(head);
                break;

            case 7:
                if (head==NULL)
                    printf("empty list\n");
                else
                    printlist(head);
                break;

            default:
                printf("not a valid option\n");
                break;
   }
   printf("\nPlease enter\n 1 to add node at the end\n 2 to add node at the beginning\n 3 to add in the middle\n 4 to delete node from the beginning\n 5 to delete node from the end\n 6 to find nth block\n 7 to print list\n and 0 to exit :");
   scanf("%d",&option);
    getchar();
 }

 free(head);
 free(temp);

 return 0;
}


