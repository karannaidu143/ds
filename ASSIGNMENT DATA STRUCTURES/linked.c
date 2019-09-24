#include<stdio.h>
#include<stdlib.h>
struct linklist
{
int data;
struct linklist *next;
};
typedef struct linklist node;
node *start=NULL;
int menu()
{
int ch;
printf("\n\t *****IMPLIMENTATION OF SINGLE LINKED LIST*****");
printf("\n\t ---------------------------------------\n");
printf("\n\t 1.Create list");
printf("\n\t 2.Traverse the list(left to right)");
printf("\n\t 3.Traverse the list(right to left)");
printf("\n\t 4.Number of nodes");
printf("\n\t 5.Insertion at Begining");
printf("\n\t 6.Insertion at End");
printf("\n\t 7.Insertion at position");
printf("\n\t 8.Deletion at Beginning");
printf("\n\t 9.Deletion at End");
printf("\n\t 10.Deletion at position");
printf("\n\t 11.exit the program");



printf("\nEnter your choice:");
scanf("%d",&ch);
return ch;
}
node* getnode()
{
node *newnode;
newnode=(node*)malloc(sizeof(node));
printf("Enter data:\n");
scanf("%d",&newnode->data);
newnode->next=NULL;
return newnode;
}
int countnode(node*start)
{
if(start==NULL)
return 0;
else
return 1+countnode(start->next);

}

void createlist(int n)
{
int i;
node *newnode;
node *temp;
for(i=0;i<n;i++)
{
newnode=getnode();
if(start==NULL)



{
start=newnode;
}
else
{
temp=start;
while(temp->next!=NULL)
temp=temp->next;
temp->next=newnode;
}
}
}
void traverse()
{
node *temp;
temp=start;
printf("The contents of the list(left to right)\n");
if(start==NULL)
{
printf("\n Empty list");
return;
}
else
{
while(temp!=NULL)
{
printf("%d\t",temp->data);
temp=temp->next;
}
}


printf("X");
}
void rev_traverse(node *start)
{
if(start==NULL)
{
return;
}
else
{
rev_traverse(start->next);
printf("%d\t",start->data);
}
}
void insert_at_beg()
{
node *newnode;
newnode=getnode();
if(start==NULL)
{
start=newnode;
}
newnode->next=start;
start=newnode;
}
void insert_at_end()
{
node *newnode,*temp;
newnode=getnode();
if(start==NULL)

{
start=newnode;
}
else
{
temp=start;
while(temp->next!=NULL)
temp=temp->next;
temp->next=newnode;
}

}
void insert_at_mid()
{
node *newnode,*pre,*temp;
int pos,ctr=1,nodectr;
printf("Enter position:");
scanf("%d",&pos);
nodectr=countnode(start);
if(pos>1 && pos<nodectr)
{

newnode=getnode();
temp=pre=start;
while(ctr<pos)
{
pre=temp;
temp=temp->next;
ctr++;
}



pre->next=newnode;
newnode->next=temp;

}
else
{

printf("\nNot a middle position");

}
}
void del_at_beg()
{
node *temp;
if(start==NULL)
{
printf("List is empty");
return;
}
else
{
temp=start;
start=temp->next;
free(temp);
printf("Node is deleted");
}
}
void del_at_end()
{
node *pre,*temp;
if(start==NULL)


{
printf("List is empty");
return;
}
else
{
temp=start;
while(temp->next!=NULL)
{
pre=temp;
temp=temp->next;
}
pre->next=NULL;
free(temp);
printf("Node deleted");
}
}
void del_at_mid()
{
int pos,ctr=1,nodectr;
node *temp,*pre;
nodectr=countnode(start);
if(start==NULL)
{
printf("List is empty");
return;
}
else
{
printf("Enter position:");



scanf("%d",&pos);
if(pos>1 && pos<nodectr)
{
pre=temp=start;
while(ctr<pos)
{
pre=temp;
temp=temp->next;
ctr++;
}
pre->next=temp->next;
free(temp);
}
else
printf("Not a mid position");
}
}
void main(void)
{
int ch,n;
while(1)
{
ch=menu();
switch(ch)
{
case 1:
if(start==NULL)
{
printf("Enter the number of nodes you want to create:");



scanf("%d",&n);
createlist(n);
printf("List is created");
break;
}
else
{
printf("List is already created:");
break;
}
case 2:traverse();
break;

case 3:

printf("The contents of the list(left to right):\n");
rev_traverse(start);
printf("X");
break;

case 4: printf("Number of nodes:%d",countnode(start));

break;
case 5: insert_at_beg();
break;
case 6: insert_at_end();
break;
case 7: insert_at_mid();
break;
case 8: del_at_beg();
break;
case 9: del_at_end();
break;
case 10: del_at_mid();


break;
case 11: exit(0);
}
}
}
