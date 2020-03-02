#include<iostream>
#include<cstdlib>
#include<conio.h>
#define size 50
using namespace std;

const int MAX_QUEUE = 50;
static int count = (1);

class Queue
{ 
	private:
		int front; // index at front
		int back; // index at rear queue
		char items[MAX_QUEUE]; //store item in Q
		int cnt;
	public:
		Queue(); // Constructor - create Q
		//~Queue(); // Destructor - destroy Q
		bool isEmpty(); // check Q empty
		bool isFull(); // check Q full
		void enQueue(char); // insert into Q
		void deQueue(); // remove item from Q
		char getFront(); // get item at Front
		char getRear(); // get item at back Q
		void Print();
};

Queue::Queue()
{ front = 0; back = -1; cnt = 0; }

/*Queue::~Queue() 
{ delete [] items; }*/

bool Queue::isEmpty() 
{ return bool(back < front); }

bool Queue::isFull() 
{ return bool(back == MAX_QUEUE - 1); }

void Queue::enQueue (char insertItem)
{
	if(isFull())
	{
		cout <<"\nCannot Insert. Queue is full!";
	}
	else
	{
		back = ( back + 1) % MAX_QUEUE;
		items[back] = insertItem;
		++cnt;
	}
}

char Queue::getFront()
{
	return items[front]; 
}

char Queue::getRear()
{
	return items[back];
}

void Queue::deQueue()
{
	if (isEmpty())
	{
		cout <<"\nCannot remove item. Empty Queue!";
	}
	else
	{
		front = ( front + 1 ) % MAX_QUEUE;
		--cnt;
	}
}

void Queue::Print()
{
	int n = (back + MAX_QUEUE - front) % MAX_QUEUE + 1;
	cout<<"Queue       : ";
	for(int i = 0; i < n; i++)
	{
		int index = (front + i) % MAX_QUEUE; 
		cout<<items[index]<<" ";
	}
	cout<<"\n\n";
}

class Pizza : public Queue
{
	protected:
		int price;
		int sizes;
	public:
		Pizza()
		{ price = 0; sizes = 60; }
		int choose_size();
};

int Pizza::choose_size()
{
	char opt;
	cout<<"\nSelect size of the pizza(S/M/L):\t";
	cin>>opt;
		
	switch (opt)
	{
		case 's':
		case 'S':
		return 1;
		
		case 'm':
		case 'M':
		return 2;
		
		case 'l':
		case 'L':
		return 3;
		
		default:
		return 1;
	}
}


class customize: public Pizza 
{
	protected:
		int serv_size;
	public:
		customize()     
		{ serv_size=1; }
		void calc_price()   
		{
		    int pricet=0;   
		    pricet+=(serv_size)*(size);
		    price=pricet;
		}
		int ret_price()
		{
		    return price;
		}
		void disp_price()   
		{
		    cout<<price;
		}
		void edit_base()    
		{
		    int x;
		    x=choose_size();
		    serv_size=x;
		}
};

class veg_extra: public customize
{
	void veg_extra1()   
	{
	    serv_size=1;
	}
	public:
		void call() 
		{
			veg_extra1();
		}

};

class nveg_extra: public customize
{
	void nveg_extra1()
	{
	    serv_size=1;
	}
	public:
		void call()
		{
		    nveg_extra1();
		}

};

class meat_extra: public customize
{
	void meat_extra1()
	{
	    serv_size=1;
	}
	public:
		void call()
		{
		    meat_extra1();
		}

};

class nmeat_extra: public customize
{
	void nmeat_extra1()
	{
	    serv_size=1;
	}
	public:
		void call()
		{
		    nmeat_extra1();
		}

};

int pin=0;
static long int sales=0;

class admin: public Queue
{

	int user[3];
	int pass[3];

	public:
	admin()    
	{
		user[0]=123;
	    pass[0]=321;
	}
	
	int retuser(int i)
	{
	    return user[i];
	}
	int retpass(int i)
	{
	    return pass[i];
	}
	
	void admin_panel()
	{
	    int r;
	    int opt;
		int key = 1;
	
	    cout<<"\t\t\tADMIN PANEL\n";
	    cout<<"\nPlease choose an option:";
	    cout<<"\n\n\n\t1.Check Total Sales";
	    cout<<"\n\n\n\t2.Check the Pizza";
	    cout<<"\n\n\n\t3.Exit Admin Panel";
	    cout<<"\n\n\n\t4.LOGOUT\n";
	    cout<<"\n-->> ";
	    cin>>r;
	
	    switch(r)
	        {
	        case 1:
	            cout<<"\n\n\n";
	            cout<<"Total sales for the day have been Rm. ";
	            cout<<sales;
	            getch();
	            break;
	
	        case 2:
	            cout<<"Check the item that have been ordered\n";
	            //Print();
	            getch();
	            break;
	            
	        case 3:
	            break;
	
	        case 4:
	            pin=0;
	            break;
	        default:
	            break;
	        }
	}

};

int main()
{
	Queue a;
	int ch,x,y,s,k;
	veg_extra ob1;
	nveg_extra ob2;
	meat_extra ob4;
	nmeat_extra ob5;
	customize ob3;
	admin log;
	
	menu:
	cout<<"\t\t\t\t------------\n";
	cout<<"\t\t\t       *Pizza Store*";
	cout<<"\n\t\t\t\t------------\n";
	
	cout<<"\n\t\t\t  Welcome to Pizza Store!\n";
	cout<<"Order No. : "<<count;
	cout<<"\n*Please choose an option from the list:\n";
	cout<<"\n\n\t1.Order Now!";
	cout<<"\n\n\t2.Admin Login";
	cout<<"\n\n\t3.Cancel order";
	cout<<"\n\n\t4.EXIT";
	cout<<"\n\n--->> ";
		
	cin>>ch;
	switch(ch)
    {
    case 1:

        int ch1;
        cout<<"\nSelect an option to proceed\n";
        cout<<"\n1.Choose from our range of exciting Pizzas!";

        choosech1:
        	cout<<"\n\n--->> ";
        	cin>>ch1;

        switch(ch1)
        {
        case 1:
            int k;

            cout<<"Which pizza would you like \n";
            cout<<"\na.Veg Extraveganza\n";
            cout<<"\nb.Non Veg Extraveganza\n";
            cout<<"\nc.Meat Extravaganza\n";
            cout<<"\nd.Non Meat Extravaganza\n";
		  	cout << "\nEnter you number: ";
		  	cin >> k;
		  	a.enQueue(k);
			  		  	
		  	cout << "\nNumber entered \n";
		  	
            switch(k)
            {
            case 1:
                ob1.call();
                cout<<"\nYou selected Veg Extraveganza\n";
                cout<<endl;
                ob1.edit_base();
                ob1.calc_price();
                cout<<"\nAmount Due: Rm.";
                ob1.disp_price();
                getch();
            
                cout<<"\n\t\t\tThank you for ordering\n";
                cout<<"\t\t\tPlease keep Rm. ";
                ob1.disp_price();
                cout<<" ready.";
                cout<<"\n*Your order will arrive in under 45 mins, or its free!";
                cout<<endl;
                count++;
                sales+=ob1.ret_price();
                getch();
                goto menu;
                break;
                
            case 2:
                ob2.call();
                cout<<"\nYou selected Non Veg Extraveganza\n";
                cout<<endl;
                ob2.edit_base();
                ob2.calc_price();
                cout<<"\nAmount Due: Rm.";
                ob2.disp_price();
                getch();
                
                cout<<"\n\t\t\tThank you for ordering\n";
                cout<<"\t\t\tPlease keep Rm. ";
                ob2.disp_price();
                cout<<" ready.";
                cout<<"\n*Your order will arrive in under 45 mins, or its free!";
                cout<<endl;
                count++;
                sales+=ob2.ret_price();
                getch();
                goto menu;
                break;
                
			case 3:
                ob4.call();
                cout<<"\nYou selected Meat Extraveganza\n";
                cout<<endl;
                ob4.edit_base();
                ob4.calc_price();
                cout<<"\nAmount Due: Rm.";
                ob4.disp_price();
                getch();
                
                cout<<"\n\t\t\tThank you for ordering\n";
                cout<<"\t\t\tPlease keep Rm. ";
                ob4.disp_price();
                cout<<" ready.";
                cout<<"\n*Your order will arrive in under 45 mins, or its free!";
                cout<<endl;
                count++;
                sales+=ob4.ret_price();
                getch();
                goto menu;
                break;
                
            case 4:
                ob5.call();
                cout<<"\nYou selected Non Veg Extraveganza\n";
                cout<<endl;
                ob5.edit_base();
                ob5.calc_price();
                cout<<"\nAmount Due: Rm.";
                ob5.disp_price();
                getch();
                
                cout<<"\n\t\t\tThank you for ordering\n";
                cout<<"\t\t\tPlease keep Rm. ";
                ob5.disp_price();
                cout<<" ready.";
                cout<<"\n*Your order will arrive in under 45 mins, or its free!";
                cout<<endl;
                count++;
                sales+=ob5.ret_price();
                getch();
                goto menu;

            default:
                break;
            }
         
		}
    case 2:
        if(pin!=0)
            {
	            cout<<"\nYou are already logged in\n";
	            getch();
	            log.admin_panel();
            }
        else if(pin==0)
            {
	            int id,cred;
	            cout<<"\t\t\tADMIN LOGIN";
	            cout<<"\n\n\n";
	            cout<<"\t\t\t";
	            cout<<"USER ID: ";
	            cin>>id;
	            for(int i=0;i<3;++i)
	                {
		                if(id==log.retuser(i))
		                    {
		
			                    cout<<"\n\t\t\t";
			                    cout<<"PASSWORD: ";
			                    cin>>cred;
		
		                    if(cred==log.retpass(i))
		                        {
		                        	pin=1;
		                        	log.admin_panel();
		                        }
		                    else
		                        {
		                        	cout<<"\n\t\t\t";
		                        	cout<<"Password doesn't match\n";
		                        	getch();
		                        	goto menu;
		                         // break;
		                        }
		                    }
		                else
		                    {
		                    	continue;
		                    }
	                }
            }
        goto menu;
         // break;
    case 3:
		a.deQueue();
		cout<<"\nYour order has been cancel\n";
		getch();
		goto menu;     
    case 4:
        exit(0);

    default:
        break;
    }
goto menu;
   //   getch();
}
	
