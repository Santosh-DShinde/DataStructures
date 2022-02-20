#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *right;
	struct node  *left;
}NODE, *PNODE;


class BST
{
private:
	PNODE first;
	int size ;

public:
	BST();

		void Insertion(int);

			bool Search(int);

				void PreOrder();

		 		int CountParent();

			 int CountLeaf();

		 int CountAtLeast();

	int Count();
	
};

	//	  FUNCTION DEFINATIONS	//

	BST :: BST()      // CONSTRUCTOR 	
	{
		first = NULL;
		size = 0;
	}


void BST :: Insertion(int value)
{
	PNODE newn = new NODE;

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


bool BST :: Search(int value)
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


int BST :: CountParent()
{
	PNODE temp = first;

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

int BST:: CountLeaf()
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


int BST :: CountAtLeast()
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


int BST :: Count()
{
	return size;
}


int main()
{
	BST obj;

	int iRet = 0, no=0, bRet = 0, CPret = 0;

	obj.Insertion(25);
	obj.Insertion(46);
	obj.Insertion(41);
	obj.Insertion(81);
	obj.Insertion(31);
	obj.Insertion(11);

	cout<<"Enter Number to Search :  ";
	cin>>no;

	bRet = obj.Search(no);

	if (bRet == true)
	{
		cout<<"The Number iS There :\n";
	}
	else
	{
		cout<<"Nuber Is Not There :\n";
	}

	iRet = obj.Count();
	cout<<"Number Of Nodes Are :"<<iRet<<"\n";

	CPret = obj.CountParent();
	cout<<"Numer Of Parent Nodes Are :"<<CPret<<"\n";

	int CLret = obj.CountLeaf();
	cout<<"Numer Of Leaf Nodes Are :"<<CLret<<"\n";

	int ALret = obj.CountAtLeast();
	cout<<"Nodes whose only one Node Is NULL :"<<ALret<<"\n";
	return 0;
}