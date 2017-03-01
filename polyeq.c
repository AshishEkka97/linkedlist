// Create a polynomial using linked list

#include<stdio.h>
#include<stdlib.h>

struct Poly
{
 int coe;
 int exp;
 struct Poly *next;
};

void show(struct Poly *poly)
{
 struct Poly *ptr;
 ptr=poly;
 printf("%dx^%d",ptr->coe,ptr->exp);
 ptr=ptr->next;
 while(ptr!=NULL)
 {
  printf("+%dx^%d",ptr->coe,ptr->exp);
  ptr=ptr->next;
 }
 printf("\n");
}

struct Poly* createpoly(struct Poly *poly,int c,int e)
{
  struct Poly *newnode;
  struct Poly *ptr,*pptr;
  int flag;
  newnode=(struct Poly*)malloc(sizeof(struct Poly));
  if(newnode==NULL)
  {
   printf("Overflow\n");
  }
  else
  {
   newnode->coe=c;
   newnode->exp=e;
   newnode->next=NULL;
   if(poly==NULL)
   {
    poly=newnode;
   }
   else
   {
    ptr=poly;
    pptr=NULL;
    while(ptr!=NULL&&ptr->exp>=e)
    {
     pptr=ptr;
     ptr=ptr->next;
    }
    if(ptr==NULL)
    {
     pptr->next=newnode;
    }
    else if(pptr==NULL)
    {
     newnode->next=ptr;
     poly=newnode;
    }
    else
    {
      pptr->next=newnode;
      newnode->next=ptr;
    }
   }
  }
  return poly;
}

struct Poly* polyadd(struct Poly *p,struct Poly *q,struct Poly *r)
{
 struct Poly *ptr1,*ptr2;
 int coe,exp;
 ptr1=p;
 ptr2=q;
 while(ptr1!=NULL&&ptr2!=NULL)
 {
  if(ptr1->exp==ptr2->exp)
  {
   coe=ptr1->coe+ptr2->coe;
   exp=ptr1->exp;
   r=createpoly(r,coe,exp);
   ptr1=ptr1->next;
   ptr2=ptr2->next;
  }
  else if(ptr1->exp>ptr2->exp)
  {
   coe=ptr1->coe;
   exp=ptr1->exp;
   r=createpoly(r,coe,exp);
   ptr1=ptr1->next;
  }
  else
  {
   coe=ptr2->coe;
   exp=ptr2->exp;
   r=createpoly(r,coe,exp);
   ptr2=ptr2->next;
  }
 }
 if(ptr1!=NULL)
 {
  while(ptr1!=NULL)
  {
   coe=ptr1->coe;
   exp=ptr1->exp;
   ptr1=ptr1->next;
   r=createpoly(r,coe,exp);
  }
 }
 else if(ptr2!=NULL)
 {
  while(ptr2!=NULL)
  {
   coe=ptr2->coe;
   exp=ptr2->exp;
   ptr2=ptr2->next;
   r=createpoly(r,coe,exp);
  }
 }
 return r;
}

void main()
{
 int ch,coe,exp;
 struct Poly *P,*Q,*R;
 P=(struct Poly*)malloc(sizeof(struct Poly));
 P=NULL;
 Q=NULL;
 R=NULL;
 printf("Enter First Poly\n");
 do
 {
  printf("Enter Coefficient: ");
  scanf("%d",&coe);
  printf("Enter Exponent: ");
  scanf("%d",&exp);
  P=createpoly(P,coe,exp);
  printf("Press 1 To Create Another\n");
  scanf("%d",&ch);
 }while(ch==1);
 show(P);
 
 printf("Enter Second Poly\n");
 do
 {
  printf("Enter Coefficient: ");
  scanf("%d",&coe);
  printf("Enter Exponent: ");
  scanf("%d",&exp);
  Q=createpoly(Q,coe,exp);
  printf("Press 1 To Create Another\n");
  scanf("%d",&ch);
 }while(ch==1);
 show(Q);
 R=polyadd(P,Q,R);
 printf("Adding First and Second Poly we get:\n");
 show(R);
}