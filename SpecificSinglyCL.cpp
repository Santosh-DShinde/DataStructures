//working

#include<iostream>
using namespace std;

typedef struct node
{
   int data;
   struct node*next ;
}NODE,*PNODE;


class SinglyCL
{
private:
                     //characteristics
   PNODE first;
   PNODE last;
   int size;

public:

   SinglyCL()
   {
      first = NULL;
      last = NULL;
      size = 0;
   }

void InsertFirst(int no)
{
   PNODE newn = new NODE;
   newn->data = no;
   newn->next = NULL;

   if ((first == NULL)&&(last == NULL))
   {
      first = newn;
      last = newn;
   }
   else
   {
      newn->next = first;
      first = newn;
   }
   size++;
   last->next = first;
}

void InsertLast(int no)
{
   PNODE newn = new NODE;
   newn->next = NULL;
   newn->data = no;

  if ((first == NULL)&&(last == NULL))
   {
      first = newn;
      last = newn;
   }
        else
       {

         last->next = newn;
          last = newn;
       }
   size++;
   last->next = first;
}


void InsertAtPos(int no, int iPos)
{

        PNODE newn= new NODE;

        newn->data = no;
        newn->next = NULL;

        PNODE temp = first;

    if((iPos < 1) || (iPos > size+1))
    {
        return;
    }
    
    if(iPos == 1)
    {
        InsertFirst(no);
    }
    else if(iPos == size +1)
    {
        InsertLast(no);
    }
    else
    {
        for(int i = 1; i < iPos -1; i++)
        {
            temp = temp -> next;
        }
        
        newn->next = temp->next;
        temp->next = newn;
        size ++;
    }

   last->next = first;
}



void DeleteFirst()
{
   if ((first == NULL)&&(last == NULL))
   {
      return ;
   }
   else if (first == last)
   {
      delete first;
      first = NULL;
      last =  NULL;
   }
   else
   {
      first = first->next;
      delete last->next;
   }
   size--;
   last->next = first;
}


void DeleteLast()
{
   PNODE temp = new NODE;
   temp = first;

    if ((first == NULL)&&(last == NULL))
   {
      return;
   }
   else if (size == 1)
   {
      delete last;
      first = NULL;
      last = NULL;
   }

   else
   {
     while(temp->next != last)
     {
         temp = temp->next;
     }

     delete temp->next;
     last = temp;
   }

   last->next=first;
   
   size--;
   
}


void DeleteAtPos(int iPos)
{ 
   PNODE temp = first;

   PNODE targeted = new NODE;

   
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
      for (int i = 1;  i < iPos-1;  i++)
      {
         temp = temp-> next;
      }

      targeted = temp->next;
      temp->next = targeted->next;
      delete targeted;

   size --;

   }
   last->next = first;
}

void Display()
{
   do
   {
      cout<<"|"<<first->data<<"|"<<"  ";
      first = first->next;

   } while(first != last->next);

   cout<<"\n";

}


int Count()
{
   return size;
}

};

////////////////////////////////////////////////////////////////////////

int main()
{
   SinglyCL obj;

   int iValue = 0, Position=0,iChoise=1,iRet=0;

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