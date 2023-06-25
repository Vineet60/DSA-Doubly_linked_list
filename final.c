#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
char name[30];
char roll_number[10];
char course[5];
int marks;
struct node *llink;
struct node *rlink;
};
typedef struct node *NODE;
NODE first=NULL;
NODE insert_begin(NODE first)
{
NODE temp;
temp=(NODE)malloc(sizeof(struct node));
if(temp==NULL)
{
printf("Out of memory\n");
exit(0);
}
printf("Enter the details\n");
printf("Name: ");
scanf("%s",temp->name);
printf("Roll number: ");
scanf("%s",temp->roll_number);
printf("Course: ");
scanf("%s",temp->course);
printf("Marks: ");
scanf("%d",&temp->marks);
temp->llink=NULL;
temp->rlink=NULL;
if(first==NULL)
{
first=temp;
printf("Student record is inserted\n");
return first;
}
first->llink=temp;
temp->rlink=first;
printf("Student record is inserted\n");


first=temp;
return first;
}
NODE display(NODE first)
{
NODE cur;
if(first==NULL)
{
printf("List is empty\n");
return first;
}
cur=first;
printf("Contents of the list are:\n");
printf("\n");
printf("Name\t");
printf("Roll\t");
printf("Course\t");
printf("Marks\t");
printf("\n----------------------------\n");
while(cur!=NULL)
{
printf("%s\t",cur->name);
printf("%s\t",cur->roll_number);
printf("%s\t",cur->course);
printf("%d\t",cur->marks);
printf("\n----------------------------\n");
cur=cur->rlink;
}
return first;
}
void search(NODE first)
{
NODE cur;
char key[20];
int count=0;
int result;
printf("Enter the roll number to be searched\n");
scanf("%s",key);
cur=first;
while(cur!=NULL)
{
count=count+1;
result=strcmp(key,cur->roll_number);
if(result==0)
{
printf("Key element found at %d position\n",count);
break;
}
else
{
cur=cur->rlink;
}
if(result==1)
{
printf("Key element not found\n");
break;
}
}
}
NODE delete_specified(NODE first)
{
char key[20];
NODE prev,cur,ptr;
if(first==NULL)
{
printf("List is empty\n");
return first;
}
printf("Enter the roll no of the student whose record is to be deleted: ");
scanf("%s",key);
if(first->rlink==NULL&&strcmp(first->roll_number,key)==0)
{
printf("Student record is deleted\n");
free(first);
first=NULL;
return first;
}
cur=first;
prev=NULL;
while(cur!=NULL&&strcmp(cur->roll_number,key)==1)
{
prev=cur;
cur=cur->rlink;
}
ptr=cur->rlink;
if(cur==NULL)
{
printf("Student not found\n");
return first;
}
prev->rlink=ptr;
ptr->llink=prev;
printf("Student record is deleted\n");
free(cur);
return first;
}

NODE edit(NODE first)
{
NODE cur;
int opt;
char roll[30];
if(first==NULL)
{
printf("No changes have been done\n");
return first;
}
printf("Enter the roll number you want to edit\n");
scanf("%s",roll);
cur=first;
while((cur!=NULL)&&(strcmp(roll,cur->roll_number)!=0))
{
cur=cur->rlink;
}
if(cur==NULL)
{
printf("Record not found\n");
return first;
}
printf("What field would you like to change??\n");
printf("1.Name\t2.Roll_number\t3.Course\t4.Marks\n");
scanf("%d",&opt);
switch(opt)
{
case 1:printf("Enter the new value of name\n");
scanf("%s",cur->name);
break;
case 2:printf("Enter the new value of roll number\n");
scanf("%s",cur->roll_number);
break;
case 3:printf("Enter the new value of course\n");
scanf("%s",cur->course);
break;
case 4: printf("Enter the new value of marks\n");
scanf("%d",&cur->marks);
break;
default:printf("Option not found\n");
break;
}
printf("Updated value of the record\n");
printf("Name:%s\n",cur->name);
printf("Roll number:%s\n",cur->roll_number);
printf("Course:%s\n",cur->course);
printf("Marks:%d\n",cur->marks);



return first;
}
void main()
{
int option;
do
{
printf("\nDoubly linked list operations\n");
printf("1.Insert\t2.Delete\t3.Display\t4.Search\t5.Edit\t6.Exit\n");
printf("Enter the option\n");
scanf("%d",&option);
switch(option)
{
case 1:first=insert_begin(first);
break;
case 2:first=delete_specified(first);
break;
case 3:first=display(first);
break;
case 4:search(first);
break;
case 5:first=edit(first);
break;
case 6:break;
}
} while(option!=6);
}