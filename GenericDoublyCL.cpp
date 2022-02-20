
#include<iostream>
using namespace std;

template <typename T>
struct node
{
   T data;
    struct node *next;
       struct node *prev;
};

template <class T>
class DoublyCL
{
private:

   node<T>* first;
   node<T>* last;
   int size;

public:

   DoublyCL();

   void InsertFirst(T);

     void InsertLast(T);

        void InsertAtPos(T, int);

           void DeleteFirst();

               void DeleteLast();

            void DeleteAtPos(int);

         void Display();

      int Count();
};

template <class T>
   DoublyCL<T> ::  DoublyCL()
   {
      first = NULL;
      last = NULL;
      size = 0;
   }

template <class T>
void  DoublyCL<T> :: InsertFirst(T value)
{
   node<T>* newn = new node<T>;

      newn->data = value;
      newn->next = NULL;
      newn->prev = NULL;

             if((first == NULL)&&(last == NULL))
             {
                first = newn;
                   last = newn; 
                }
     else 
   {
      newn->next = first;
      first->prev = newn;
      first = newn;       
   }

      last->next = first;
      first->prev = last;  

   size++;
}

template <class T>
void  DoublyCL<T> :: InsertLast (T value)
{
   node<T>* newn = new node<T>;

      newn->data = value;
      newn->next = NULL;
      newn->prev = NULL;

   if ((first == NULL)&&(last == NULL))
   {
      first = newn ;
      last = newn ;
   }

   else
   {
      last->next = newn;
      newn->prev = last;
      last = newn;
   }

   last->next = first;
   first->prev = last;

 size++;
} 

template <class T>
void  DoublyCL<T> ::  InsertAtPos( T value, int iPos)
{
   node<T>* temp = new node<T>;
   temp = first;

   node<T>* newn = new node<T>;

      newn->data = value;
      newn->next = NULL;
      newn->prev = NULL;

      if ((iPos < 1 )||(iPos > size+1))
      {
         cout<<"Please Enter Valid Position :\n";
         return;
         }
           
              if (iPos == 1)
               {
                  InsertFirst(value);
                }

           else if (iPos == size+1)
             {
                 InsertLast(value);
             }
      else
      {
         for (int i = 1; i < iPos-1 ; i++)
         {
            temp = temp->next;
         }

    newn->next = temp->next;
       temp->next->prev = newn;
         temp->next = newn;
            newn->prev = temp;
             size++;
    
         last->next = first;
      first->prev = last;
   }

}

template <class T>
void DoublyCL<T> ::  DeleteFirst()
{
   node<T>* temp = first;

      if ((first == NULL)&&(last == NULL))
      {
         return ;
      }
           else  if (first == last)
              {
               delete first;
                first = NULL;
                   last = NULL;
                }
      else
      {
         first = first->next;
         delete last->next;

         first->prev = last;
         last->next = first;
      }

      size--;
}

template <class T>
void  DoublyCL<T> :: DeleteLast()
{
   if ((first == NULL)&&(last == NULL))
   {
      return ;
   }
       else if (first == last)
         {
         delete first;
            first = NULL;
             last = NULL;
         }
            else
            {
               last = last->prev;
               delete last->next;

               last->next = first;
               first->prev = last;
            }

      size--;
}

template <class T>
void DoublyCL<T> :: DeleteAtPos(int iPos)
{
   node<T>* temp = first;

   if ((iPos < 1 ) || (iPos > size+1))
   {
         cout<<"Please Enter Valid Position :\n";

      return;
   }
       if (iPos == 1)
       {
            DeleteFirst();
         }
             else if (iPos == size)
             {
                DeleteLast();
               }
                  else
                  {
                     for (int i = 1; i < iPos-1; i++)
                     {
                        temp = temp->next;  
                       }

                       temp->next = temp->next->next;  //
                       delete temp->next->prev;        //
                       temp->next->prev = temp;        //
                size--;   
                   }
   
             last->next = first;
                first->prev = last;
}

template <class T>
void  DoublyCL<T> ::  Display()
{
   node<T>* temp = first;  

   for (int i = 1; i <= size; i++)
   {
      cout<<"|"<<temp->data<<"|"<<"  ";
      temp = temp->next;
   }
   cout<<"\n";
}

template <class T>
int  DoublyCL<T> ::  Count()
{
   return size;
}
 

////////////////////////////////////////////////////////////////////////

int main()
{
   DoublyCL <int> obj;

   int iValue = 0, Position=0,iChoise=1,iRet=0;

   while(iChoise != 0)
   {
      cout<<"\n_____________________________________________________________\n";

      cout<<"\n\t\t\t SELECT YOUR CHOICE\n\n";

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