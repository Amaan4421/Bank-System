/*
		AUTHOR:AMAAN SAJINA
		DOC:17/01/2022
		OBJECT:BANK APP USING STRUCTURE
*/
#include<stdio.h>
#include<conio.h>
#define SIZE 5
struct Bank{
	int cid;
	float balance;
	char name[100];
	int flag;

}b[SIZE]; //variables
void createAccount();
void displayAccounts();
int deposit(int id);
int withDraw(int id);
int checkBalance(int id);
int deactivateAccount(int id);
void displayParticular(int index);
int search(int id);

void main()
{
	int choice,id,ans;
	while(1)
	{
		clrscr();
		printf("\n1---Create Account");
		printf("\n2---Display Accounts");
		printf("\n3---Deposit");
		printf("\n4---Withdraw");
		printf("\n5---Check Balance");
		printf("\n6---Deactivate Account");
		printf("\n7---Display particular");
		printf("\n8---Exit");

		printf("\nEnter your choice:");
		scanf("%d",&choice);

		switch(choice)
		{
			case 1: createAccount();
			break;

			case 2: displayAccounts();

			break;

			case 3: printf("\nEnter id:");
				scanf("%d",&id);
				ans=deposit(id);
				if(ans==-1)
				{
					printf("\nRecord not found!!");
				}//end of if
				else
				{
					printf("\nBalance updated!!");
					displayParticular(ans);
				}//end of else
			break;

			case 4: printf("\nEnter id:");
				scanf("%d",&id);
				ans=withDraw(id);
				if(ans==-1)
				{
					printf("\nRecord not found!!");
				}//end of if
				else
				{
					printf("\nBalance updated!!");
					displayParticular(ans);
				}//end of else

			break;

			case 5: printf("\nEnter the id for balance check:");
				scanf("%d",&id);
				ans=search(id);
				if(ans==-1)
				{
					printf("\nRecord not found!!");
				}//end of if
				else
				{
				       ans=checkBalance(id);
				}//end of else
			break;

			case 6: printf("\nEnter account id which you want to Deactivate:");
				scanf("%d",&id);
				ans=deactivateAccount(id);
				if(ans>=0)
				{
					printf("Acoount details as shown below!!");
					displayParticular(ans);
					printf("\nAccount is deactivated successfully!!");
				}//end of if
				else
				{
					printf("\nRecord not found!!");
				}//end of else
			break;

			case 7: printf("\nEnter id you want to search:");
				scanf("%d",&id);
				ans=search(id);
				if(ans==-1)
				{
					printf("Error!!Not found!!");
				}//end of if
				else{
					displayParticular(ans);
				}//end of else
			 break;


			case 8:exit(0);
			break;

			default:printf("\nInvalid!!");
		}//end of switch

	getch();
	}//end of while
}//end of main

void createAccount()
{
	int i;

	for(i=0;i<SIZE;i++)
	{
		printf("\nEnter id:");
		scanf("%d",&b[i].cid);
		printf("\nEnter name:");
		scanf("%s",&b[i].name);
		b[i].balance=10000;

	}//end of for

}//end of create

void displayAccounts()
{
	int i;
	printf("\nid\t\tName\t\tBalance");
	for(i=0;i<SIZE;i++)
	{
		if(b[i].flag!=-1)
			printf("\n%d\t\t%s\t\t%.2f",b[i].cid,b[i].name,b[i].balance);
	}//end of for


}//end of display

void displayParticular(int index)
{
	printf("\nRecord is found!!\n");
	printf("\nid\t\tName\t\tBalance");
	printf("\n%d\t\t%s\t\t%.2f",b[index].cid,b[index].name,b[index].balance);

}//end of particular

int search(int id)
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		if(id==b[i].cid)
		{
			return i;
		}//end of if
	}//end of for
	return -1;


}//end of search


int deposit(int id)
{
       int ans=-1,i;
       float temp;
       ans=search(id);
       if(ans!=-1 && b[ans].flag!=-1)
       {
		displayParticular(ans);
		printf("\nEnter amount for deposit:");
		scanf("%f",&temp);
		b[ans].balance=temp+b[ans].balance;
		return ans;
       }//end of if
       return -1;

}//end of deposit

int withDraw(int id)
{
       int ans=-1,i;
       float temp;
       ans=search(id);
       if(ans!=-1 && b[ans].flag!=-1)
       {
		displayParticular(ans);
		printf("\nEnter amount for withdraw:");
		scanf("%f",&temp);
		b[ans].balance-=temp;
		return ans;
       }//end of if
       return -1;

}//end of withdraw

int checkBalance(int id)
{
	int ans;
	printf("\nid\t\tBalance");
	printf("\n%d\t\t%.2f",b[ans].cid,b[ans].balance);
	return ans;
}//end of checkBalance

int deactivateAccount(int id)
{
	int index;
	index=search(id);
	if(index>=0)
	{
		b[index].flag=-1;
		return index;
	}
	return index;

}//end of deactivate

































