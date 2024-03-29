#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

struct node *CreateNode(int a)
{
	struct node *temp = new struct node();

	temp->data = a;
	temp->next = NULL;
	return temp;
}

struct node *Push(struct node **refHead, int num)
{
	struct node *temp = CreateNode(num);

	if(*refHead!=NULL)
		temp->next = *refHead;

	*refHead = temp;
	return *refHead;
}

void printLL(struct node *head)
{
	if(head==NULL)
	{
		 cout<<"\n The LL is empty!\n";
		 return;
	}

	cout<<endl;
	while(head!=NULL)
	{
		cout<<head->data<<" ";
		head = head->next;
	}
	cout<<endl;
}

void MergeLLsatAlternatePositions(struct node *head1,struct node **refHead2)
{
	if(*refHead2==NULL || head1==NULL)
		return;

	struct node *insert = *refHead2;
	struct node *rest =NULL;

	if(head1!=NULL)
	{
		*refHead2 = (*refHead2)->next;
		insert->next = NULL;

		rest = head1->next;
		head1->next = insert;
		insert->next = rest;
	}

	MergeLLsatAlternatePositions(rest,refHead2);

}


void main()
{
	int num1[] = {1,3};

	struct node *LL1=NULL;
	for(int i=(sizeof(num1)/sizeof(num1[0]))-1 ; i>=0 ; i--)
		Push(&LL1,num1[i]);

	int num2[] = {2,4,6,8,10};

	struct node *LL2=NULL;
	for(int i=(sizeof(num2)/sizeof(num2[0]))-1 ; i>=0 ; i--)
		Push(&LL2,num2[i]);

	printLL(LL1);
	printLL(LL2);

	MergeLLsatAlternatePositions(LL1,&LL2);

	printLL(LL1);
	printLL(LL2);

	cin.get();

}