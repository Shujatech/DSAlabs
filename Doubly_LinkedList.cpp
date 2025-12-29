#include <iostream>
using namespace std;
struct Node{
	int data;
	Node *next;
	Node *prev;
};
class Doubly{
	Node *head;
	Node *tail;
public:
	Doubly()
	{
		head=NULL;
		tail=NULL;
	}
	void getvalueAtStart(int value)
	{
		Node *node=new Node();
		node->data=value;
		node->next=head;
		node->prev=NULL;
		if(head==NULL)
		{
			head=tail=node;
		}
		else
		{
			head->prev=node;
			head=node;
		}
	}
	void display()
	{
		if(head==NULL)
		{
			cout<<"List is empty";
			return;
		}
		else
		{
			Node *temp=head;
			do
			{
				cout<<temp->data<<endl;
				temp=temp->next;
			}
			while(temp!=NULL);
		}
	}
	void InsertAtEnd(int value)
	{
		Node *node=new Node();
		node->data=value;
		node->next=NULL;
		node->prev=NULL;
		if(head==NULL)
		{
			head=tail=node;
			return;
		}
		else
		{
		node->prev = tail;    
        tail->next = node;    
        tail = node;  
		}
}
   void insertAfterLoc(int loc,int value)
   {
   	Node *node=new Node();
   	node->data=value;
   	node->next=NULL;
   	node->prev=NULL;
   	if(head==NULL)
   	{
   		cout<<"No location exists";
   		return;
	}
	else
	{
		Node *temp=head;
		for (int i=1;i<loc;i++)
		{
			temp=temp->next;
	
		}
		if(temp->next!=NULL)
		{
			node->prev=temp;
			node->next=temp->next;
			temp->next->prev = node;
			temp->next=node;
		}
		else
		{
			node->prev=temp;
			node->next=temp->next;
			temp->next=node;
			tail=node;
		}
	}
   }
   void insertAfterValue(int v,int value)
   {
   	Node *node=new Node();
   	node->data=value;
   	node->next=NULL;
   	node->prev=NULL;
   	if(head==NULL)
   	{
   		cout<<"No value exists in list";
   		return;
	}
	Node *temp=head;
	while(temp->data!=v)
	{
		temp=temp->next;
		if(temp==NULL)
		{
			cout<<"no such value exists in list";
			return;
		}
	}
	if(temp->next!=NULL)
	{
		node->prev=temp;
		node->next=temp->next;
		temp->next->prev = node;
		temp->next=node;
	}
	else
	{
		node->prev=temp;
		node->next=temp->next;
		
		temp->next=node;
		tail=node;
	}
   }
   void delAtStart()
   {
   	if(head==NULL)
   	{
   		cout<<"No node to delete";
   		return;
	   }
	   if(head->next==NULL)
	   {
	   	delete head;
	   	head=tail=NULL;
	   }
	   else
	   {
	   	Node *delnode=head;
	   	head=head->next;
	   	head->prev=NULL;
	   	delnode->next=NULL;
	   	delete delnode;
	   }
   }
   void delAtEnd()
   {
   	if(head==NULL)
   	{
   		cout<<"No node to delete";
   		return;
	}
	if(head->next==NULL)
	{
		delete head;
		head=tail=NULL;
		return;
	}
	else
	{
		Node *delnode=tail;
		tail=tail->prev;
		delnode->prev=NULL;
		tail->next=NULL;
		delete delnode;
	}
   }
   void delAfterLoc(int loc)
   {
   	if(head==NULL)
   	{
   		cout<<"No location exists in list";
   		return;
	   }
	 Node *temp=head;
	 for (int i=1;i<loc;i++)
	 {
	 	temp=temp->next;
	 	if(temp==NULL)
	 	{
	 		cout<<"No such loc exists";
	 		return;
		 }
	   }
	   if(temp->next==NULL)
	   {
	   	cout<<"No node to dleete after that lcoation";
	   	return;
		 }  
		 if(temp->next->next!=NULL)
		 {
		 	Node *delnode=temp->next;
		 	delnode->next->prev=delnode->prev;
		 	temp->next=delnode->next;
		 	delnode->next=NULL;
		 	delnode->prev=NULL;
		 	delete delnode;
		 }
		 else
		 {
		 	Node *delnode=temp->next;
		 	tail=delnode->prev;
		 	tail->next=NULL;
		    delnode->prev=NULL;
		    delete delnode;
		 }
   }
   void delAfterValue(int value)
   {
   	if(head==NULL)
   	{
   		cout<<"No value exists in list";
   		return;
	   }
	   Node *temp=head;
	   while(temp!=NULL &&temp->data!=value)
	   {
	   	temp=temp->next;
	   	if(temp==NULL)
	   	{
	   		cout<<"No such value exists in list";
	   		return;
		   }
	   }
	  
	   if(temp->next==NULL)
	   {
	   	cout<<"No node to delete after that value";
	   	return;
	   }
	   if(temp->next->next!=NULL)
	   {
	   	 Node *delnode=temp->next;
	   	 temp->next=delnode->next;
	   	 delnode->next->prev=temp;
	   	 delete delnode;
	   }
	   else
	   {
	   	Node *delnode=temp->next;
	   	tail=delnode->prev;
	   	tail->next=NULL;
	   	delete delnode;
	   }
   }
};
int main()
{
	Doubly obj;
	obj.getvalueAtStart(5);
	obj.getvalueAtStart(6);
	obj.InsertAtEnd(10);
	obj.insertAfterLoc(1,3);
	obj.insertAfterValue(10,9);
	obj.delAtStart();
	obj.delAtEnd();
	obj.delAfterLoc(1);
	obj.delAfterValue(3);
	obj.display();
}
