#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int vip=301;
int ac=201;
int nonac=101;
struct node *headb;
struct node
{
    char food[50];
    int qty;
    float price;
    int data;
    struct node *prev;
    struct node *next;

    int id,age,days,room,amount;
    char name[10];
    struct node* nextb;
};

struct node *headc = NULL,*newnode,*tailc = NULL;
struct node *heada = NULL, *taila = NULL;
struct node *head_s;

//hotel

struct node* checkin(struct node*headb,char *name,int age,int id,int days,int c){
    struct node*temp,*nn;
    nn=(struct node*)malloc(sizeof(struct node));

    if(headb==NULL)

    {
     nn->nextb=headb;
     nn->age=age;
     strcpy(nn->name,name);
     nn->days=days;
     nn->id=id;
     headb=nn;
     if(c==1){
     printf("\t\t\t\t\t\t\tVIP ROOM NO.%d ALLOCATED TO YOU.\n",vip);
     nn->room=vip;
     vip++;
     nn->amount=nn->days*5000;
     printf("\t\t\t\t\t\t\tBILL:%d\n",nn->amount);
     }
     else if(c==2){
     printf("\t\t\t\t\t\t\tAC ROOM NO.%d ALLOCATED TO YOU.\n",ac);
     nn->room=ac;
     ac++;
     nn->amount=nn->days*3000;
     printf("\t\t\t\t\t\t\tBILL:%d\n",nn->amount);
     }
     else{
     printf("\t\t\t\t\t\t\tNON-AC ROOM NO.%d ALLOCATED TO YOU.\n",nonac);
     nn->room=nonac;
     nonac++;
     nn->amount=nn->days*2000;
     printf("\t\t\t\t\t\t\tBILL:%d\n",nn->amount);
    }
     return headb;
    }

    else

    {
temp=headb;
while(temp->nextb!=NULL)
{
temp=temp->nextb;
}
nn->nextb=temp->nextb;
temp->nextb=nn;
  nn->age=age;
  strcpy(nn->name,name);
  nn->id=id;
  nn->days=days;
    if(c==1){
     printf("\t\t\t\t\t\t\tVIP ROOM NO.%d ALLOCATED TO YOU.\n",vip);
     nn->room=vip;
     vip++;
     nn->amount=days*5000;
     printf("\t\t\t\t\t\t\tBILL:%d\n",nn->amount);
     }
     else if(c==2){
     printf("\t\t\t\t\t\t\tAC ROOM NO.%d ALLOCATED TO YOU.\n",ac);
     nn->room=ac;
     ac++;
     nn->amount=days*3000;
     printf("\t\t\t\t\t\t\tBILL:%d\n",nn->amount);
     }
     else{
     printf("\t\t\t\t\t\t\tNON-AC ROOM NO.%d ALLOCATED TO YOU.\n",nonac);
     nn->room=nonac;
     nonac++;
     nn->amount=days*2000;
     printf("\t\t\t\t\t\t\tBILL:%d\n",nn->amount);
    }
    return headb;

    }

}

struct node*show(struct node*headb,int id)
{struct node*temp;
temp=headb;
if(temp==NULL)
{
    printf("\t\t\t\t\t\t\tNo user found.\n");
    return NULL;
}
while(temp!=NULL)
{
    if(temp->id==id)
    {
        break;
    }
    temp=temp->nextb;
}
if(temp==NULL)
{
    printf("\t\t\t\t\t\t\tENTER VALID ID.");
    return headb;
}
else{
printf("\n\t\t\t\t\t\t\t*****DETAILS*****\n");
printf("\t\t\t\t\t\t\tNAME:%s\n",temp->name);
printf("\t\t\t\t\t\t\tAGE:%d\n",temp->age);
printf("\t\t\t\t\t\t\tID:%d\n",temp->id);
printf("\t\t\t\t\t\t\tDAYS OF STAY:%d\n",temp->days);
printf("\t\t\t\t\t\t\tROOM NO:%d\n",temp->room);
printf("\t\t\t\t\t\t\tBILL AMOUNT:%d\n",temp->amount);
return headb;
}
};

void hotelroom()
{
int cho,ch;
int age,id,days,amount;
char name[10];
struct node* t=headb;
mmenu:
printf("\n\t\t\t\t\t\t\t1]ROOM BOOKING\n\t\t\t\t\t\t\t2]COSTOMER AND BILL DETAILS.\n\t\t\t\t\t\t\t3]EXIT\n");
printf("\t\t\t\t\t\t\tEnter your choice\n");
printf("\t\t\t\t\t\t\t");

scanf("%d",&ch);
switch(ch){
case 1:
{

smenu:
printf("\n\t\t\t\t\t\t\tENTER WHICH TYPE OF ROOM YOU WANT:\n\t\t\t\t\t\t\t1]VIP ROOM\n\t\t\t\t\t\t\t2]AC ROOM\n\t\t\t\t\t\t\t3]NON-AC ROOM\n\t\t\t\t\t\t\t4]EXIT\n");
printf("\t\t\t\t\t\t\tEnter your choice\n");
printf("\t\t\t\t\t\t\t");
scanf("%d",&cho);
if(cho==4)
{
    system("cls");
    goto mmenu;
}
if(cho>4)
{
  printf("\t\t\t\t\t\t\tENTER VALID CHOICE.");
  system("cls");
  goto smenu;
}
printf("\t\t\t\t\t\t\t*******ENTER YOUR DETAILS PLEASE:********\n");
printf("\t\t\t\t\t\t\tENTER THE NAME :");
scanf("%s",name);
printf("\t\t\t\t\t\t\tENTER YOUR AGE:");
scanf("%d",&age);
printf("\t\t\t\t\t\t\tENTER AADHAR ID:");
scanf("%d",&id);
printf("\t\t\t\t\t\t\tENTER NUMBER OF DAYS YOU WANT TO STAY:");
scanf("%d",&days);
switch(cho)
{
case 1:
 if(vip<=310) {
headb=checkin(headb,name,age,id,days,1);
goto mmenu;
 }
else
{
printf("\t\t\t\t\t\t\tSORRY! VIP ROOMS ARE NOT AVAILABLE.\n");
}
goto mmenu;

case 2:
if(ac<=230) {
headb=checkin(headb,name,age,id,days,2);

 }
else
{
printf("\t\t\t\t\t\t\tSORRY! AC ROOMS ARE NOT AVAILABLE.\n");
}
goto mmenu;

case 3:
 if(nonac<=130) {
headb=checkin(headb,name,age,id,days,3);
 }
else
{
printf("\t\t\t\t\t\t\tSORRY! NON-AC ROOMS ARE NOT AVAILABLE.\n");
}
goto mmenu;
default:
    printf("\t\t\t\t\t\t\tENTER VALID CHOICE.");
    goto mmenu;
    system("cls");
}
}

case 2:
{

int i;
printf("\t\t\t\t\t\t\tenter id:");
scanf("%d",&i);
headb=show(headb,i);
goto mmenu;
}
case 3:
printf("\t\t\t\t\t\t\tTHANKYOU FOR VISITING.\n");
break;
system("cls");
default:
printf("\t\t\t\t\t\t\tENTER VALID CHOICE.");
goto mmenu;
}
system("cls");
}
//////////////////////////////restaurant/////////////////////////////////////
void customermenu()
{
    printf("\n\t\t\t\t\t\t\t1. Place your order\n");
    printf("\t\t\t\t\t\t\t2. View your ordered items\n");
    printf("\t\t\t\t\t\t\t3. Delete an item from order\n");
    printf("\t\t\t\t\t\t\t4. Display final bill\n");
    printf("\t\t\t\t\t\t\t5. Back To Main Menu \n\n");
    printf("\t\t\t\t\t\t\t   Enter Your Choice --->");
}

struct node* createadmin(struct node *head,int data, char food[25], float price)
{
    newnode = (struct node*)malloc(sizeof(struct node));

    newnode->data = data;
    newnode->price = price;
    newnode-> qty = 0;
    strcpy(newnode->food,food);
    newnode->next = NULL;
    newnode->prev = NULL;

    struct node *temp = head;

    if(temp==NULL)
        heada = taila = newnode;
    else
    {
        while(temp->next!=NULL)
            temp=temp->next;

        temp->next=newnode;
        newnode->prev = taila;
        taila = newnode;
    }

    return heada;
}

struct node* createmenu(struct node *head,int data,int qty)
{
    newnode = (struct node*)malloc(sizeof(struct node));

    struct node *temp1 = heada;
    int flag = 0;
    while(temp1!=NULL)
    {
        if(temp1->data==data)
        {
            flag = 1;
            break;
        }
        temp1 = temp1->next;
    }

    if(flag==1)
    {
        newnode->data = data;
        newnode->price = qty*(temp1->price);
        newnode-> qty = qty;
        strcpy(newnode->food,temp1->food);
        newnode->next = NULL;
        newnode->prev = NULL;

        struct node *temp = head;

        if(temp==NULL)
            headc = tailc = newnode;
        else
        {
            while(temp->next!=NULL)
                temp=temp->next;

            temp->next=newnode;
            newnode->prev = tailc;
            tailc = newnode;
        }


    }
    else
    {
        printf("\n\t\t\t\t\t\t\tThis item is not present in the menu!\n");
    }
    return headc;
}

void displayList(struct node *head)
{
    struct node *temp1 = head;
    if(temp1==NULL)
    {
        printf("\n\t\t\t\t\t\t\t\tList is empty!!\n\n");
    }
    else
    {
        printf("\n");
        while(temp1!=NULL)
        {
            if(temp1->qty==0)
                printf("\t\t\t\t\t\t\t%d\t%s\t%0.2f\n",temp1->data,temp1->food,temp1->price);
            else
            {
                printf("\t\t\t\t\t\t\t%d\t%s\t%d\t%0.2f\n",temp1->data,temp1->food,temp1->qty,temp1->price);
            }

            temp1 = temp1->next;
        }
        printf("\n");
    }

}

struct node* totalsales(int data,int qty)
{
    newnode = (struct node*)malloc(sizeof(struct node));
    int flag = 0;

    struct node *temp1 = heada;
    while(temp1->data!=data)
    {
        temp1 = temp1->next;
    }

    newnode->data = data;
    newnode->price = qty*(temp1->price);
    newnode-> qty = qty;
    strcpy(newnode->food,temp1->food);
    newnode->next = NULL;
    newnode->prev = NULL;

    struct node *temp = head_s;

    if(temp==NULL)
        head_s = newnode;
    else
    {
        while(temp->next!=NULL)
        {
            if(temp->data==data)
            {
                flag = 1;
                break;
            }
            temp=temp->next;
        }

        if(flag==1)
        {
            temp->qty += newnode-> qty;
            temp->price += newnode->price;
        }
        else
        {
            temp->next=newnode;
        }
    }

    return head_s;
}

void calculatetotsales()
{
    struct node *temp = headc;
    while(temp!=NULL)
    {
        head_s = totalsales(temp->data, temp->qty);
        temp=temp->next;
    }
}

struct node* delete(int data,struct node *head, struct node* tail,int qty)
{
    if(head==NULL)
    {
        printf("\n\t\t\t\t\t\t\tList is empty\n");
    }
    else
    {
        struct node* temp;
        if(data==head->data )
        {

            temp = head;
            if(temp->qty==qty)
            {
            head = head->next;
            if (head != NULL)
                head->prev = NULL;
            free(temp);
            }
            else
            {
                temp->price=(temp->price)/(temp->qty);
                (temp->qty)=(temp->qty)-qty;
                temp->price=(temp->qty)*(temp->price);
            }
        }
        else if(data==tail->data)
        {
            temp = tail;
            if(tail->qty==qty)
            {
            tail = tail->prev;
            tail->next = NULL;
            free(temp);
            }
            else
            {
                tail->price=(tail->price)/(tail->qty);
                tail->qty=(tail->qty)-qty;
                tail->price=(tail->qty)*(tail->price);
        }
        }

        else
        {
            temp = head;
            while(data!=temp->data)
            {
                temp = temp->next;
            }
            if(temp->qty==qty)
            {
            (temp->prev)->next = temp->next;
            (temp->next)->prev = temp->prev;
            free(temp);
            }
            else
            {
                temp->price=(temp->price)/(temp->qty);
                 temp->qty=(temp->qty)-qty;
                temp->price=(temp->qty)*(temp->price);
            }

        }
    }
    return head;
}


int deletemenu()
{
    printf("\n\t\t\t\t\tEnter serial no. of the food item which is to be deleted: ");
    int num,qty;
    scanf("%d",&num);
    printf("\n\t\t\t\t\tEnter the number of item to cancel: ");
    scanf("%d",&qty);
    struct node* temp=headc;
    while(temp!=NULL)
    {
        if (temp->data == num)
        {
            headc = delete(num, headc, tailc,qty);
            return 1;
        }
        temp=temp->next;
    }

    return 0;
}

void displaybill()
{
    displayList(headc);
    struct node *temp = headc;
    float total_price = 0;
    while (temp!=NULL)
    {
        total_price +=temp->price;
        temp = temp->next;
    }

    printf("\t\t\t\t\t\t\tTotal price: %0.02f\n",total_price);

}

struct node* deleteList(struct node* head)
{
    if(head==NULL)
    {
        return NULL;
    }
    else
    {
        struct node* temp = head;
        while(temp->next!=0)
        {
            temp = temp->next;
            free(temp->prev);
        }
        free(temp);
        head = NULL;
    }

    return head;
}

void customer()
{
    int flag=0,j=1;
    char ch;
    printf("\n\t\t\t\t\t   ----------------------------------------------\n");
    printf("\t\t\t\t\t\t\t    Restaurant Section\n");
    printf("\t\t\t\t\t   ----------------------------------------------\n");
    while(1)
    {
        customermenu();

        int opt;
        scanf("%d",&opt);



        switch (opt)
        {
            case 1:
                displayList(heada);
                printf("\n\t\t\t\t\t\tEnter number corresponding to the item you want to order: ");
                int n;
                scanf("%d",&n);
                printf("\t\t\t\t\t\tEnter quantity: ");
                int qty;
                scanf("%d",&qty);
                headc = createmenu(headc, n, qty);
                break;
            case 2:
                printf("\n\t\t\t\t\t\t\t  ### List of ordered items ###\n");
                displayList(headc);
                break;
            case 3:
                if(deletemenu())
                {
                    printf("\n\t\t\t\t\t\t### Updated list of your ordered food items ###\n");
                    displayList(headc);
                }
                else
                    printf("\n\t\t\t\t\t\tFood item with given serial number doesn't exist!!\n");
                break;
            case 4:
                calculatetotsales();
                printf("\n\t\t\t\t\t\t\t  ### Final Bill ###\n");
                displaybill();
                headc = deleteList(headc);
                printf("\n\t\t\t\t\t\tPress any key to return to main menu:\n\t\t\t\t\t\t");

                flag=1;
                break;
            case 5:
             system("cls");
            break;
            default:
                printf("\n\t\t\t\t\t\tWrong Input !! PLease choose valid option\n");
                break;
        }
        if(flag==1)
            break;
    }
}

void mainnenu()
{
    printf("\n                                 **************************************************************************\n");
    printf("                                                     WELCOME TO HOTEL & RESTAURANT MANAGEMENT SYSTEM\n");
    printf("                                 **************************************************************************\n\n\n");
    printf("\t\t\t\t\t\t\t1. Hotelroom--> \n");
    printf("\t\t\t\t\t\t\t2. Restaurant Section--> \n");
    printf("\t\t\t\t\t\t\t3. Exit--> \n\n");
    printf("\t\t\t\t\t\t\tEnter Your Choice --->");
}

int main()
{

    heada = createadmin(heada,1,"Gujarati Thali",100);
    heada = createadmin(heada,2,"Punjabi Thali",200);
    heada = createadmin(heada,3,"Manchurian Noodles",150);
    heada = createadmin(heada,4,"South Indian",180);
    heada = createadmin(heada,5,"Beverages",50);

    while(1)
    {
        MENU:
        mainnenu();
        int choice;
        scanf("%d",&choice);


        switch (choice)
        {
            case 1:
               hotelroom();
               goto MENU;
            case 2:
                customer();
                break;
            case 3:
               system("cls");
               break;
            default:
                printf("\n\t\t\t\t\t\tWrong Input !! PLease choose valid option\n");
                break;
        }


    }

}
