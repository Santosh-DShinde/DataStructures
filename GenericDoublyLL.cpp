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
class DoublyLL
{
private:

   node<T>* first;
   int size;

public:

   DoublyLL();

   void InsertFirst(T);

     void InsertLast(T);

        void InsertAtPos(T, int);

           void DeleteFirst();

               void DeleteLast();

            void DeleteAtPos(int);

         void Display();

      int Count();
};

/////////////////////////////////////////////////////////////////

template <class T>
  DoublyLL<T> :: DoublyLL()
   {
      first =NULL;
      size = 0;
   }

template <class T>
void DoublyLL<T> :: InsertFirst(T value)
{
   node<T>* newn = new node<T>;

   newn->data = value;
       newn->next = NULL;
          newn->prev = NULL;

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

template <class T>
void DoublyLL<T> :: InsertLast (T value)
{
   node<T>* newn = new node<T>;
   node<T>* temp = first;

   newn->data = value;
   newn->next = NULL;
   newn->prev = NULL;

    if (first == NULL)
   {
      first = newn;
   }
      else 
          {
             while(temp->next != NULL)
              {
                 temp = temp->next;
             }
        temp->next = newn;
      newn->prev = temp;
   }

   size++;
}

template <class T>
void DoublyLL<T> :: InsertAtPos(T value, int iPos)
{
   node<T>* newn = new node<T>;

   newn->data = value;
   newn->next = NULL;
   newn->prev = NULL;

   node<T>* temp = new node<T>;
      temp = first;

   if (first == NULL)
   {
      first = newn;
   }
          else if (iPos == 1)
          {
            InsertLast(value);
          }
              else if (iPos == size+1)
                 {
                    InsertLast(value);
                 }
       else
       {
          for (int i = 1; i < iPos-1; i++)
           {
              temp = temp->next;
           }

          newn->next = temp->next;
       temp->next = newn;
      newn->prev = temp;

   size++;

   }
}


template <class T>
void DoublyLL<T> :: DeleteFirst()
{
   node<T>* temp = first;

   if (first == NULL)
   {
      return;
   }
        else 
        {
          first = first->next;
           delete temp ;
       }
   
   size--;
}

template <class T>
void DoublyLL<T> :: DeleteLast()
{
   node<T>* temp = first;

   if (first == NULL)
   {
      return ;
   }
           else if (first->next == NULL)
            {
              delete first;
                first = NULL;
            }
                else
                {
                  while(temp->next->next != NULL)
                  {
                      temp = temp->next;
                  }
          delete temp->next;
      temp->next = NULL;
   }
   size--;
}

template <class T>
void DoublyLL<T> :: DeleteAtPos(int iPos)
{
   node<T>* targeted = new node<T>;

   node<T>* temp  = new node<T>;
   temp = first;


   if (first == NULL)
   {
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
         for (int i = 1; i < iPos - 1; i++)
         {
            temp = temp->next;
         }

            temp->next = temp->next->next;
                temp->next->next->prev = temp;

         size --;
       }
}

template <class T>
void DoublyLL<T> :: Display()
{
   node<T>* temp = first;

   while(temp != NULL)
   {
      cout<<"|"<<temp->data<<"|"<<"  ";
      temp = temp->next;
   }cout<<"\n";
}

template <class T>
int DoublyLL<T> :: Count()
{
   return size;
} 

////////////////////////////////////////////////////////////////////////

int main()
{
   DoublyLL <int> obj;

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