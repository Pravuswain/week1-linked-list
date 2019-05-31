#include<iostream>
using namespace std;

// define node 
class node
{
	public:
//define structure of node
	int val;
	node*next;
//constructor to define default node 
	node(int newval)
	{
		val = newval;
		next = NULL;
	}	

};

//define default linked list
class linkedlist
{
	public:
//where head points to a node
	node* head;
//constructor to define the val
	linkedlist()
	{
		head= NULL;
	}

//insert function
	void insert(int newval)
	{
//create a node with new value and give a pointer
		node*temp= new node(newval);
//point the next of temp to head instead of NULL
		temp->next = head; 
//transfer the head to temp
		head = temp;
	}
//display function
	void display()
	{
//begin with head
		node*curr=head;
//use while loop till its value is null
		while(curr != NULL)
		{
//print the value
			cout<< curr -> val << "->";
//go to next node
			curr = curr-> next;	
		}		
	}

//insert at function
//define count function
	int countItems()
	{
//begin with head with count as 0
		node*curr=head;
		int count = 0;
//use loop to keep counting till its null
		while(curr != NULL)
		{
			count ++;
//go to next
			curr = curr ->next;	
		}
		return count;
	}					
	
//get a position
		node*getpos(int pos) 
		{
//start with head positioning starting with 1
			int count = 1;
			node*curr= head;
			while (count< (pos-1))
			{
				curr=curr-> next;
				count++;
			}
						 
			return curr;	
		}	
	void insertAt(int val , int pos)
	{
//case 1 out off pos
		
		if ((pos<1) || (pos > (countItems()+1)) )
		{
			cout << "nothing"<<endl;
	
		}
//to check that it is within the function
		node*curr= getpos(pos-1);
		if(pos==1)
		{
//insert insert function
			insert(val);					
		} 	
		else
		{
//AFTER GETTING POSITION to insert IN BETWWEEn two nodes
//create a new node and give apointer
			node*temp=new node (val);
//transfer the value of next of curr to the temp next
			temp->next=curr->next;
//transfer the value of temp to curr next
			curr->next=temp; 					
		
		}
	
	}
//delete function
//deleting node at the end of the list will be done in deletAt function
	void delet()
	{
//usually it deletes the head
//begin with head
				
//case 1 if head is empty
		node*temp =head;
		if (head == NULL)
		{
			cout <<"empty node"<<endl;
		} 
//case 2 for non empty head
		else {
//give a pointer to head
			
//shift the head to the next 
			head = head->next;

			
			delete temp;	
		}

	}
//deletAt function
	void deletAt(int pos)
	{
//use count function to count and get a position
		node*curr= getpos(pos-1);
		if(pos==1){
//call delete function to delete head
			delet();
		}
//use loop to reach the pos
		
		else
		{
//then use curr as reference join to 2nd element from the reference
			curr->next=(curr->next)->next;
//name the pos with a pointer and delete it out
			node*temp=curr->next;
			delete temp;
	


		}


	}

};

 
int main()
{
	return 0;


}
