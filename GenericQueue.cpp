
#include<iostream>
using namespace std;

template <typename T>
struct node
{
	T data;
	struct node *next;

};

template<class T>
class Queue
{
private:

	node<T>* first;
	int size;

public:
	Queue();
	
	void InQueue(T);

	void DeQueue();

	void Display();

	int Count();
	
};

template <class T>
	Queue <T>:: Queue()
	{
		first = NULL;
		size = 0;
	}

template <class T>
	void Queue<T>:: InQueue(T value)
	{
		node<T>* newn = new node<T>;
		newn->data = value;
		newn->next = NULL;

		if (first == NULL)
		{
			first = newn;
		}

		else
		{
			node<T>* temp = first;

			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = newn;

		}
		size++;
	}

template <class T>
	void Queue<T>:: DeQueue()
	{
		node<T>* temp = first;

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

template <class T>
	void Queue<T> :: Display()
	{
		node<T>* temp = first;

		while(temp != NULL)
		{
			cout<<temp->data<<"  ";
			temp = temp->next;
		}
		cout<<"\n";
	}

template <class T>
	int Queue<T> :: Count()
	{
		return size;
	}

/////////////////////////////////////////////////////////////////////

int main()
{
	Queue <float> obj;

	float iValue = 0;
	int iRet = 0, Choice = 1;

	while(Choice != 0)
	{

		cout<<"\n\n______________________________________________________________________________\n\n";
		cout<<"\n\t\t\t ENTER YOUR CHOICE\n\n";
		cout<<" 1: Insert The Node \n";
		cout<<" 2: Delete The Node \n";
		cout<<" 3: Display The Nodes \n";
		cout<<" 4: Count The Nodes \n";
		cout<<" 0: Terminate Application \n";

		cout<<"\n________________________________________________________________________________\n\n";

		cout<<"Enter Choice :  ";
	cin>>Choice;

		switch(Choice)
		{

			case 1:
			cout<<"Enter Data :  ";
				cin>>iValue;
			obj.InQueue(iValue);
		break;

		case 2:
			obj.DeQueue();
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