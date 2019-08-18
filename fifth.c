#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
  char st[10];
  float val;
  int data;
  struct node *next;
  struct node *prev;
};
struct node *create()
{
    struct node *temp,*start=NULL,*q,*p,*r,*t;
char str1[10];
while(1)
{
  printf("\n Enter yes or no\n");
  scanf("%s",str1);
  if(strcmp(str1,"no")==0)
  break;
  else
  {
  temp=(struct node *)malloc(sizeof(struct node));
  printf("Enter a value ");
  scanf("%d",&temp->data);
  temp->next=start;
    if(start==NULL)
    {
      start=temp;
      temp->prev=start;
      p=temp;
      q=temp;
    }
    else
    {
      temp->prev=p;
      p->next=temp;
      temp->next=start;
      p=temp;
    }
  }
}
return q;
}
int length(struct node *p)
{
  struct node *start=p;
  int c=0;
do
  {
    c++;
    p=p->next;
  }while(p!=start);
  return c;
}
struct node *reverse(struct node *a)
{
    struct node *q,*p,*r,*t;
    int i=1,j=1,temp,c;
    p=a;
    q=a;
    c=length(a);
    while(i<c)
    {
      q=q->next;
      i++;
    }
    while(j<c)
{
temp=p->data;
p->data=q->data;
q->data=temp;
p=p->next;
q=q->prev;
j++;
c--;
}
return a;
}
void display(struct node *a)
{
  struct node *start=a;
  do
  {
  printf("%d\n",a->data);
  a=a->next;
  }
  while(a!=start);
}
int main()
{
struct node *a,*b;
a=create();
b=reverse(a);
display(b);
}
