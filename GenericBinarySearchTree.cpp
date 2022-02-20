#include<iostream>
using namespace std;

template <typename T>
struct node
{
	T data;
	struct node *right;
	struct node  *left;
};

template <class T>
class BST
{
private:
	node<T>*  first;
	int size ;

public:
	BST();

		void Insertion(T);

			bool Search(T);

				void PreOrder();

					void Display();

		 		int CountParent();

			 int CountLeaf();

		 int CountAtLeast();
		
		int Delete(T);                      ////////////////////////////////////new////////////////////////////////////

	int Count();
	
};

	//	  FUNCTION DEFINATIONS	//
template <class T>
	BST <T> :: BST()      // CONSTRUCTOR 	
	{
		first = NULL;
		size = 0;
	}

template <class T>
void BST<T> :: Insertion(T value)
{
	 node<T>* newn = new node<T> ;

	newn->data = value ;
	newn->left = NULL;
	newn->right = NULL;


	if (first == NULL)
	{
		first = newn;
		size++;
	}

	else
	{
		while(1)
		{
			if (first->data == value)
			{
				cout<<"Data Is Aready Exist :";
				delete newn;
				break;
			}
			else if (value < first->data )
			{
				if (first-> left == NULL)
				{
						first->left = newn;
					size++;
				break;
				}

				first = first->left;
			}

			else if (value > first->data)
			{
				if (first->right == NULL)
				{
						first ->right = newn;
					size++;
				break;	 
				}
				
				first = first->right;
			}
		}
	}
} 

template <class T>
bool BST <T> :: Search(T value)
{
	if (first == NULL)
	{
		cout<<"There Is No Data Found :";
		return false;
	}
	else
	{
		while(first != NULL)
		{
			if (first->data == value)
			{
				break;
			}
					else if (first->data < value)
					{
						first = first->right;
					}
						else if (first->data > value)
						{
							first = first->left;
						 }
					}

			if (first == NULL)
			{
				return false;
			}
		else
		{
			return true;
		}
	}	
}

template <class T>
int BST<T> :: CountParent()
{
	node<T>* temp = first;

	static int iCnt = 0;

	if (temp != NULL)
	{
		if ((temp->left != NULL)||(temp->right != NULL))
		{
			iCnt++;
		}
	
	}
	return iCnt;
}

template <class T>
int BST<T>:: CountLeaf()
{
	static int iCnt = 0;

if (first != NULL)
{

			if ((first->left == NULL ) && (first->right == NULL))
			{
				iCnt++;
			}
	
	}
	return iCnt;
}

template <class T>
int BST <T>:: CountAtLeast()
{
	static int iCnt = 0;

	if (first != NULL)
	{
			if (((first->left != NULL)&&(first->right == NULL))||((first->right != NULL)&&(first->left == NULL)))
			{
				iCnt++;
			}
	}
	return iCnt;
}

template <class T>
void BST<T> :: Display( )
{
	if(first != NULL)
	{
		cout<<first->data<<"  \n";
		Display(first->left);
		Display(first->right);
	}
	cout<<"\n";
}


template <class T>
int BST<T> :: Count()
{
	return size;
}


int main()
{
    int Choice = 0, iValue = 0,Element = 0, iRet = 0; 
	BST <int>obj;

	while(Choice != 0)
	{

		cout<<"\n\n________________________________________________________________________________\n\n";
		cout<<"\n\t\t\t ENTER YOUR CHOICE\n\n";
		cout<<"1   Insert Node \n";
		cout<<"2   Search Node \n";
		cout<<"3   Print PreOrder\n";
		cout<<"4   CountParent\n";
		cout<<"5   CountLeaf\n";
		cout<<"6   CountAtLeast\n";
		cout<<"0   Terminate Application \n";

		cout<<"\n________________________________________________________________________________\n\n";

		cout<<"Enter Choice :  ";
	cin>>Choice;

		switch(Choice)
		{

			case 1:
			cout<<"Enter Data :  ";
				cin>>iValue;
			obj.Insertion(iValue);
		break;

		case 2:
			cout<<"Enter Th Element To Search\n";
			cin>>Element ;

			obj.Search(Element);
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