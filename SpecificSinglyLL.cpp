// Working 

#include<iostream>
using namespace std;

typedef struct node
{
    int data;
    struct node*next;
}NODE,*PNODE;


class SinglyLL
{
private:
    PNODE first;
    int size;
    
public:

    SinglyLL()
    {
        first = NULL;
        size = 0;
    }


    void InsertFirst(int no)
    {
        PNODE newn = new NODE;  // newn = (PNODE)malloc(sizeof(NODE))
        
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

    void InsertLast(int no)
    {
        PNODE newn = new NODE;  // newn = (PNODE)malloc(sizeof(NODE))
        
        newn->data = no;
        newn->next = NULL;
        
        if(first == NULL)
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

    void InsertAtPos(int no, int ipos)
    {
        PNODE temp = first;

        if ((ipos < 1) || (ipos > size+1))
        {
            cout<<"Please Enter Valid Position :";
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
            PNODE newn = new NODE;
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


    void DeleteFirst()
    {
        PNODE temp = first;

        if (first == NULL)
        {
            return;
         }
            if(first->next == NULL)
               {
                    delete first;
                    first = NULL;
                    size--;
                 }
          else
          {
            first = first->next;
            delete temp;
            size--;
         }

        
    }
    
    void DeleteLast()
    {
        PNODE temp = first;
        
        if(first == NULL)
        {
            return;
        }
        if(first->next == NULL)
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

    void DeleteAtPos(int ipos)
    {
                PNODE temp = first;

        if ((ipos < 1)||(ipos > size+1))        //FIlter
        {
            cout<<"Please Enter Valid Position :";
            return;
        }

               if (ipos == 1)         //If position is 1
                 {
                      DeleteFirst();
                   }

                    else if (ipos == size)
                    {
                        DeleteLast();
                      }

                else
               {
                     for (int i = 1; i < ipos-1; i++)
                      {
                         temp = temp->next;
                        }

           PNODE targeted = temp->next;
           temp->next = targeted->next;
           delete targeted;
           
            size--;
        }
       
    }

    
    void Display()
    {
        PNODE temp = first;
        
        while(temp!= NULL)
        {
            cout<<temp->data<<"\t";
            temp = temp->next;
        }
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
   SinglyLL obj;

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