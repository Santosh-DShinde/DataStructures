#include<iostream>
using namespace std;

template <typename T>
struct node
{
    T data;
    struct node *next;
    
};

template <class T>
class SinglyLL
{
private:
    node <T>* first;
    int size;
    
public:

   SinglyLL();

   void InsertFirst(T);

     void InsertLast(T);

        void InsertAtPos(T, int);

           void DeleteFirst();

               void DeleteLast();

            void DeleteAtPos(int);

         void Display();

      int Count();
};

 /////////////////////////////////////////////////////

template<class T>
    SinglyLL :: SinglyLL()         //constructor
    {
        first = NULL;
        size = 0;
    }

template<class T>
    void  SinglyLL :: InsertFirst(T no)
    {
          node<T>* newn = new   node <T>;  
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
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
    void  SinglyLL :: InsertLast(T no)
    {
          node<T>* newn = new   node <T>;  // newn = (PNODE)malloc(sizeof(NODE))
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
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

template<class T>
    void  SinglyLL :: InsertAtPos(T no, int ipos)
    {
          node<T>* temp = first;

        if ((ipos < 1) || (ipos > size+1))
        {
            return;
        }

        if (ipos == 1)
        {
            InsertFirst(no);
        }
       else if (ipos == size+1)
        {
            InsertLast(no);
        }
        else
        {
              node<T>* newn = new struct node <T>;
            newn->data = no;
            newn->next = NULL;

            for (int i = 1; i < ipos-1; i++)
            {
                temp= temp->next;
            }
            newn->next = temp->next;
            temp->next =newn;
        }
        size++;
    }

    void  SinglyLL :: DeleteFirst()
    {
          node<T>* temp = first;
        
        if(first != NULL)
        {
            first = first->next;
            delete temp;
            
            size--;
        }
    }

template<class T>
    void  SinglyLL :: DeleteLast()
    {
          node<T>* temp = first;
        
        if(first == NULL)
        {
            return;
        }
        else if(first->next == NULL)
        {
            delete first;
            first = NULL;
            size--;
        }
        else
        {
            while(temp->next->next != NULL)
            {
                temp = temp->next;
            }
            
            delete temp->next;
            temp->next = NULL;
            size--;
        }
    }

template<class T>
    void  SinglyLL :: DeleteAtPos(int ipos)
    {
                  node<T>* temp = first;

        if ((ipos < 1)||(ipos > size))        //FIlter
        {
            return;
        }

        if (ipos == 1)         // If Position is first
        {
              DeleteFirst();
        }

        else if (ipos == size)         //If Position Is Last
        {
            DeleteLast(); 
        }

        else
        {
            for (int i = 1; i < ipos-1; i++)
            {
                temp = temp->next;
            }
          
             node<T>* targeted = first;
             targeted = temp->next;
             temp->next = targeted->next;
             delete targeted;
        }
        size--;
    }

template<class T>
    void  SinglyLL :: Display()
    {
          node<T>* temp = first;
        
        while(temp!= NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
        cout<<"\n";
    }

template<class T>

    int  SinglyLL :: Count()
    {
        return size;
    }


////////////////////////////////////////////////////////////////

int main()
{
   SinglyLL <int> obj;

   int iValue = 0;                    
   int Position=0,iChoise=1,iRet=0;

   while(iChoise != 0)
   {
      cout<<"\n_____________________________________________________________\n";

      cout<<"\n                 SELECT YOUR CHOICE\n\n";

      cout<<"1: Insert Element At First Position :\n";
      cout<<"2: Insert Element At Last  Position :\n";
      cout<<"3: Insert Element At Desire Position :\n";
      cout<<"4: Delete First Element :\n";
      cout<<"5: Delete Last  Element :\n";
      cout<<"6: Delete Element At Desire Position :\n";
      cout<<"7: Display All Elements :\n";
      cout<<"8: Count The All Elements :\n";
      cout<<"0: Application Terminate :\n";

      cout<<"_____________________________________________________________\n";
         
         cout<<"\nEnter Choice :  \n";
     cin>>iChoise;

      switch(iChoise)
      {
         case 1:
             cout<<"Enter Data : \n";
             cin>>iValue;
             obj.InsertFirst(iValue);
            break;

                 case 2:
                   cout<<"Enter Data : \n";
                    cin>>iValue;
                     obj.InsertLast(iValue);
                 break;


                 case 3:
                 cout<<"Enter Data : \n";
                    cin>>iValue;
                      cout<<"Enter Position :  ";
                      cin>>Position;
                     obj.InsertAtPos(iValue,Position);
                    break;

         case 4:
             obj.DeleteFirst();
                break;

               case 5:
                      obj.DeleteLast();
                    break;


             case 6:
                 cout<<"Enter Position :  ";
                      cin>>Position;
                     obj.DeleteAtPos(Position);
                  break;


              case 7:
       cout<<"After Updation Your Data Is : \n\n";
                   obj.Display(); 
                   break;

          case 8:

               iRet = obj.Count();   
                      cout<<"\nNumber Of Nodes Are :"<<iRet<<"\n\n";
            break;

           
             case 0:
             cout<<"Thank you For Using Doubly Circular Linked List   *_* \n\n";
             cout<<"Application Gets Successfully Terminated :\n\n";
            break;
      
      default:
       cout<<"Please Enter Valid Choice :\n";
      cout<<"Thank You ...... \n";
    break;

      }
   }

   return 0;
}