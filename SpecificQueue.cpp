// LIFO

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;

}NODE, *PNODE;

class Queue
{
private:

	PNODE first;
	int size;

public:
	Queue();
	
	void InQueue(int);

	void DeQueue();

	void Display();

	int Count();
	
};

	Queue :: Queue()
	{
		first = NULL;
		size = 0;
	}


	void Queue:: InQueue(int value)
	{
		PNODE newn = new NODE;
		newn->data = value;
		newn->next = NULL;

		if (first == NULL)
		{
			first = newn;
		}

		else
		{
			PNODE temp = first;

			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newn;

		}
		size++;
	}


	void Queue:: DeQueue()
	{
		PNODE temp = first;

		if (first == NULL)
		{
			return;
		}
		else
		{
			first = first->next;
			delete temp;
		}
		size--;
	}

	void Queue:: Display()
	{
		PNODE temp = first;

		while(temp != NULL)
		{
			cout<<"|"<<temp->data<<"|"<<"  ";
			temp = temp->next;
		}
		cout<<"\n";
	}

	int Queue:: Count()
	{
		return size;
	}

/////////////////////////////////////////////////////////////////////

int main()
{
	int iValue = 0, iRet = 0, Choice = 1;

	Stack obj;


	while(Choice != 0)
	{

		cout<<"\n\n________________________________________________________________________________\n\n";
		cout<<"\n\t\t\t ENTER YOUR CHOICE\n\n";
		cout<<"  Push The Node \n";
		cout<<"  Pop The Node \n";
		cout<<"  Display The Nodes \n";
		cout<<"  Count The Nodes \n";
		cout<<"  Terminate Application \n";

		cout<<"\n________________________________________________________________________________\n\n";

		cout<<"Enter Choice :  ";
	cin>>Choice;

		switch(Choice)
		{

			case 1:
			cout<<"Enter Data :  ";
				cin>>iValue;
			obj.Push(iValue);
		break;

		case 2:
			obj.Pop();
			break;

	case 3:
		cout<<"After Updation Your Data Is :\n";
		obj.Display();
		break;

			case 4:
				iRet = obj.Count();
					cout<<"Number of Nodes Are : "<<iRet <<"\n";
				break;

		case 0:
			cout<<"\nThank You For Using This Application ..................\n";
		cout<<"\nApplication Gets Terminated Successessfully \n";
		break;

	default:
	cout<<"please Enter Valid Choice \n";

		}
	}

	return 0;
}