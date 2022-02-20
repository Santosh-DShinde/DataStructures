#include<iostream>
using namespace std ;

template <typename T>
struct  node
{
	T data;
	struct node *next;
};

template<class T>
class Stack
{
private:

	node<T>* first;
	int size;

public:
	
Stack();

void Push(T);

void Pop();

void Display();

int Count();

};

template<class T>
	Stack<T> :: Stack()
	{
		first = NULL;
		size = 0;
	}

template<class T>
	void Stack<T> :: Push(T value)
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
				newn->next = first;
				first = newn;
			}
	size++;
}

template<class T>
	void Stack<T> ::  Pop()
	{
		node<T>* temp = first;

		if (first == NULL)
		{
			cout<<"Stack Is Empty :";
			return ;
		}
	
		else
		{
			first = first->next;
			delete temp;
		}
		size--;
	}

template<class T>
	void Stack<T> :: Display()
	{
		 node<T>* temp = first;

		 if (first == NULL)
		 {
		 	cout<<"Stack Is Empty :";
		 }

        while(temp != NULL)
        {
           cout<<temp->data<<"  ";
            temp = temp->next;
        }
        cout<<"\n";
	}

template<class T>
	int Stack<T> ::  Count()
	{
		return size;
	}


////////////////////////////////////////////////////////////////////////

int main()
{
	Stack <float> obj;

	float iValue = 0.0 ; 
	int iRet = 0, Choice = 1;


	while(Choice != 0)
	{

		cout<<"\n\n________________________________________________________________________________\n\n";
		cout<<"\n\t\t\t SELECT YOUR CHOICE\n\n";
		cout<<" 1: Push The Node \n";
		cout<<" 2: Pop The Node \n";
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