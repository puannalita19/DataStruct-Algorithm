//Mini Project: Pizza Sales And Order Management System
//Group member:
//Beatrice Lim Pei Ying (A17CS0025)
//Puan Alma Nalita (A17CS0267)

#include <iostream>
#include <cstring>
using namespace std;

struct nodeQ
{
	int item;
	nodeQ *next;
};

class Queue
{
	private:
		nodeQ *backPtr;
		nodeQ *frontPtr;
	public:
		createQueue()
		{
			backPtr=NULL;
			frontPtr=NULL;
		}
		
		destroyQueue()
		{
			nodeQ *temp = frontPtr;
			while(temp)
			{
				frontPtr = temp->next;
				delete temp;
				temp = frontPtr;
			}
		}
		
		bool isEmpty()
		{
			return (backPtr == NULL && frontPtr == NULL);
		}
		
		void enQueue(int insertItem)
		{
			frontPtr->item = insertItem;
			if(isEmpty())
			{
				frontPtr->next = NULL;
				backPtr = frontPtr;
			}
			else
			{
				frontPtr->next = NULL;
				backPtr->next = frontPtr;
				backPtr=frontPtr;
			}
		}
		
		void deQueue()
		{
			nodeQ *deletePtr = frontPtr;
			frontPtr = frontPtr->next;
			deletePtr->next=NULL;
			delete deletePtr;
		}
		
		char getFront()
		{
			return frontPtr->item;
		}
		
		char getRear()
		{
			return backPtr->item;
		}		
};

class Pizza
{
	protected:
		char *pName;
		char *pSize;
		char *pType;
		double pPrice;
	public:
		Pizza(char *pn, char *ps, char *pt, double p)
		{
			pName = new char[strlen(pn)+1];
			strcpy(pName, pn);
			
			pSize = new char[strlen(ps)+1];
			strcpy(pSize, ps);
			
			pType = new char[strlen(pt)+1];
			strcpy(pType, pt);
			
			pPrice = p;
		}
		
		void setpPrice(double p)
		{
			pPrice = p;
		}
		
		double getpPrice()
		{
			return pPrice;
		}
		
		void setpName(char *pn)
		{
			pName = pn;
		}
		
		char *getpName()
		{
			return pName;
		}
		
		void setpSize(char *ps)
		{
			pSize = ps;
		}
		
		char *getpSize()
		{
			return pSize;
		}
		
		void setpType(char *pt)
		{
			pType = pt;
		}
		
		char *getpType()
		{
			return pType;
		}
		
		void display()
		{
			cout << "Pizza Name: " << endl;
			cout << "1. Cheese Pizza" << endl;
			cout << "2. Mushroom Pizza" << endl;
			cout << endl;
			cout << "Pizza Size: " << endl;
			cout << "1. Medium" << endl;
			cout << "2. Large" << endl;
			cout << endl;
			cout << "Pizza Type: " << endl;
			cout << "1. Thin" << endl;
			cout << "2. Thick" << endl;
			cout << endl;
			cout << "##### Price List #####";
			cout << endl;
			cout << "Medium and Thin - Price = 5" << endl;
			cout << "Medium and Thick - Price = 7" << endl;
			cout << "Large and Thin - Price = 7" << endl;
			cout << "Large and Thick - Price = 10" << endl;
		}
};

class Staff
{
	private:
		int staffID;
		char *staffName;
	public:
		Staff(int sid, char *sn)
		{
			staffID = sid;
			
			staffName = new char[strlen(sn)+1];
			strcpy(staffName, sn);
		}
		
		int getstaffID()
		{
			return staffID;
		}
		
		char *getstaffName()
		{
			return staffName;
		}		
};

class Customer
{
	private:
		int customerID;
	public:
		Customer(int cid=0)
		{
			customerID = cid;
		}
		
		void setcustomerID(int cid)
		{
			customerID = cid;
		}
		
		int getcustomerID()
		{
			return customerID;
		}
};

class Order:public Pizza
{
	private:
		int orderID;
		double orderPrice;
		Customer *customer;
	public:
		Order();
		Order(int oid, double op, int cid, char *pn, char *ps, char *pt, double p) : Pizza(pn, ps, pt, p)
		{
			orderID = oid;
			orderPrice = op;
			customer->getcustomerID() == cid;
			*getpName() = *pn;
			*getpSize() = *ps;
			*getpType() = *pt;
			getpPrice() == p;
		}
		
		int getorderID()
		{
			return orderID;
		}
		
		double getorderPrice()
		{
			orderPrice = orderPrice + Pizza::getpPrice();
			return orderPrice;
		}
		
		void manageOrder()
		{
			Pizza::getpName();
			Pizza::getpSize();
			Pizza::getpType();
			Pizza::getpPrice();
			getorderPrice();
		}
		
		void makeOrder()
		{
//			Pizza::setpName(pn);
//			Pizza::setpSize(ps);
//			Pizza::setpType(pt);
		}
};

class Sales
{
	private:
		int salesID;
		Customer *customer;
		Order *order;
		double totalSales;
	public:
		Sales()
		{
			salesID=0;
			totalSales=0;
		}
		Sales(int sid, int cid, int oid, double op, double ts)
		{
			salesID = sid;
			customer->getcustomerID() == cid;	
			order->getorderID() == oid;
			order->getorderPrice() == op;
			totalSales = ts;
		}
		
		int getsalesID()
		{
			return salesID;
		}
		
		double gettotalSales()
		{
			totalSales=totalSales+order->getorderPrice();
			return totalSales;
		}
		
		void manageSales()
		{
			gettotalSales();
//****							
		}
		
		void generateReport()
		{
//****
			cout << "SalesID: " << getsalesID() << endl;
			cout << "CustomerID: " << customer->getcustomerID() << endl;
			cout << "OrderID: " << order->getorderID() << endl;
			cout << "Total Sales: " << gettotalSales() << endl;
		}
		
};


main()
{
	Queue q;
//	q.createQueue();
//	Order o;
	Sales sl;
	Customer c;
	Staff s[2] = {Staff(1, "A"),
					Staff(2, "B")};
										
	Pizza p[8] = {Pizza("Cheese Pizza", "medium", "thin", 5), 
					Pizza("Mushroom Pizza", "medium", "thin", 5), 
					Pizza("Cheese Pizza", "large", "thin", 7), 
					Pizza("Mushroom Pizza", "large", "thin", 7), 
					Pizza("Cheese Pizza", "medium", "thick", 7), 
					Pizza("Mushroom Pizza", "medium", "thick", 7), 
					Pizza("Cheese Pizza", "large", "thick", 10), 
					Pizza("Mushroom Pizza", "large", "thick", 10)};
	
	int choice1;
	int choiceN;
	int choiceS;
	int choiceT;
	int count=1;
	cout<<"\n\t***** Welcome To Dominic Pizza *******\n";
	cout << "1. Staff" << endl;
	cout << "2. Customer" << endl;
	cout << "3. Checkout the prices" << endl;
	cout << "Enter your choice: ";
	cin >> choice1;
	cout << endl;
	
	while(choice1!=3)
	{
		while(choice1 < 1 || choice1 > 3)
		{	
		    cout<<"\n\t***** Welcome To Dominic Pizza *******\n";
			cout << "1. Staff" << endl;
			cout << "2. Customer" << endl;
			cout << "3. Checkout the price" << endl;
			cout << "Enter your choice: ";
			cin >> choice1;
			cout << endl;
		}
		
		if(choice1==1)
		{
			int id;
			cout << "Enter staff ID: ";
			cin >> id;
			if(id != s[0].getstaffID() || id != s[1].getstaffID())
			{
				cout << "Access denied." << endl;
				break;
			}
			else
			{
				cout << "Access accepted. " << endl;
				break;
			}
		}
		else
		{
//			q.enQueue(count);
//			count++;
			c.setcustomerID(count);
			p[8].display();
			cout << endl;
			cout << "Enter choice for pizza name: ";
			cin >> choiceN;
			
			if(choiceN==1)
			{
				p[8].setpName("Cheese Pizza");
			}
			else
			{
				p[8].setpName("Mushroom Pizza");
			}
			
			cout << "Enter choice for pizza size: ";
			cin >> choiceS;
			
			if(choiceS==1)
			{
				p[8].setpSize("medium");
			}
			else
			{
				p[8].setpSize("large");
			}
			
			cout << "Enter choice for pizza type: ";
			cin >> choiceT;
			
			if(choiceT==1)
			{
				p[8].setpType("Thin");
			}
			else
			{
				p[8].setpType("Thick");
			}
			
			if(choiceS == 1 && choiceT == 1)
			{
				p[8].setpPrice(5);
			}
			else if(choiceS == 2 && choiceT == 2)
			{
				p[8].setpPrice(10);
			}
			else
			{
				p[8].setpPrice(7);
			}
			
//			cout << "Order Price: " << o.getorderPrice() << endl;
			sl.gettotalSales();
		}
	
		
	}
	
	sl.generateReport();
	return 0;
	
}
