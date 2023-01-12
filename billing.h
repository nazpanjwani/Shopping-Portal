#include<iostream>
#include<string.h>
#include <stdlib.h>
using namespace std;
void printtime();

class Customer
{
	private:
	char name[30];
	char address[200];
	char phoneno[12];
	char email[30];
	public:
	void enterdetails();
	void displaydetails();
	virtual void feedback()=0;
};

void Customer:: enterdetails()
{
	int i=0,temp=0, check=0;
	cout<<"\nPlease enter your details below: \n";

	while (1)
	{
	cout<<"\nFull name: ";
	cin.ignore();
	cin.getline(name,30);
	   for(i=0; i<strlen(name);i++)
	   {
		   if(toupper(name[i])>=65 && toupper(name[i])<=90 || name[i]==32){
               check=1;
               continue;
           }
           else
           {
               check=0;
               break;
           }           
	   }
        if (check==1 && (i=strlen(name)))
        break;
        if (check==0)
        cout<<"\nInvalid name. Please enter again.";
	}
	
	while(1)        //Data validation on phone number
	{
	cout<<"\nPhone number: ";
	cin>>phoneno;
		for(i=0; i<strlen(phoneno); i++)
		{
			if(phoneno[i]-48>=0 && phoneno[i]-48<=9 && strlen(phoneno)<=11)
			{
				temp=1;
				continue;
			}
			else
			{
				temp=0;
				break;
			}
		}
	if(temp==1&&(i==strlen(phoneno)))
		break;
	if(temp==0)
		cout<<"\nInvalid phone number. Please enter again.";
	}
	cout<<"\nHouse address: ";
	cin.ignore();
	cin.getline(address,200);
	cout<<"\nEmail: ";
	cin.ignore();
	cin.getline(email,30);
}

void Customer:: displaydetails()
{
	cout<<"\n\t\tName:              "<<name;
	cout<<"\n\t\tContact Number:    "<<phoneno;
	cout<<"\n\t\tEmail address:     "<<email;
	cout<<"\n\t\tAddress:           "<<address;
}

class Payment:public Customer
{
	private:
	double amountdue=0;
	char promocode[6];
	int quantity;
	double price;
	public:	
    void setamount(int qty,double price);
    void check_promo();
    void generate_invoice();
	void feedback();
	friend Payment operator*(Payment &temp);

};

Payment operator*(Payment &temp)
{
    temp.amountdue = temp.quantity*temp.price;
    return temp;
}

void Payment:: setamount(int qty,double price)
{
	Payment c;
	c.quantity=qty;
	c.price=price;
	c=*c;
	amountdue=amountdue+c.amountdue;
}

void Payment:: feedback()
{
	int rate[5], j;
    char s='*';
    
    cout<<"\n\t\t---------------------------------------------------------------------------------------\n";
	cout<<"\t\t\t\t\t\tFeedback Form";
	cout<<"\n\t\t---------------------------------------------------------------------------------------\n";
	cout<<"\n\t\t\t\t\tPlease rate from 1(Lowest) to 5(Highest)\n\n";
	fflush(stdin);

	cout<<"\t\tHow was your shopping experience?\t\t1\t2\t3\t4\t5\n\n\t\t";
	cin>>rate[0];
	while (1)
	{
	    if(rate[0]>=1&&rate[0]<=5)
		    break;
		else
		{
			cout<<"\t\tInvalid Rate number! Please enter again: ";
			cin>>rate[0];
		}
	}
	cout<<"\n\n";
	
	cout<<"\t\tDid you find your required items?\t\t1\t2\t3\t4\t5\n\n\t\t";
	cin>>rate[1];
	while (1)
	{
	    if(rate[1]>=1&&rate[1]<=5)
		    break;
		else
		{
			cout<<"\t\tInvalid Rate number! Please enter again: ";
			cin>>rate[1];
		}
	}
	cout<<"\n\n";
	
	cout<<"\t\tAre the prices of items economical?\t\t1\t2\t3\t4\t5\n\n\t\t";
	cin>>rate[2];
	while (1)
	{
	    if(rate[2]>=1&&rate[2]<=5)
		    break;
		else
		{
			cout<<"\t\tInvalid Rate number! Please enter again: ";
			cin>>rate[2];
		}
	}
	cout<<"\n\n";	
	
	cout<<"\t\tIs our shopping portal user-friendly?\t\t1\t2\t3\t4\t5\n\n\t\t";
	cin>>rate[3];
	while (1)
	{
	    if(rate[3]>=1&&rate[3]<=5)
		    break;
		else
		{
			cout<<"\t\tInvalid Rate number! Please enter again: ";
			cin>>rate[3];
		}
	}
	cout<<"\n\n";
	
	cout<<"\t\tWhat are the chances of your come back?\t\t1\t2\t3\t4\t5\n\n\t\t";
	cin>>rate[4];
	while (1)
	{
	    if(rate[4]>=1&&rate[4]<=5)
		    break;
		else
		{
			cout<<"\t\tInvalid Rate number! Please enter again: ";
			cin>>rate[4];
		}
	}
	cout<<"\n\n";
    system("cls");
    cout<<"\n\n\t\t\t\t\t\tBlueJay Online Shopping.\n";
	cout<<"\n\t\t---------------------------------------------------------------------------------------\n";
	cout<<"\t\t\t\t\t\tYour Feedback!";
	cout<<"\n\t\t---------------------------------------------------------------------------------------\n";

    fstream rate_file;
    rate_file.open("Rate.txt",ios::out|ios::app);
    rate_file<<"\n\nCustomer Rating of ";

	cout<<"\n\n\t\tShopping Experience\t\t\t\t";
	for(j=0;j<rate[0];j++)
    cout<<s<<" ";
	rate_file<<"\n\n\t\tShopping Experience\t\t\t\t";
	for(j=0;j<rate[0];j++)
    rate_file<<s<<" ";
		
	cout<<"\n\n\t\tRequirement\t\t\t\t\t";
	for(j=0;j<rate[1];j++)
    cout<<s<<" ";
	rate_file<<"\n\n\t\tRequirement\t\t\t\t\t";
	for(j=0;j<rate[1];j++)
    rate_file<<s<<" ";
	
	cout<<"\n\n\t\tPrices\t\t\t\t\t\t";
	for(j=0;j<rate[2];j++)
    cout<<s<<" ";
	rate_file<<"\n\n\t\tPrices\t\t\t\t\t\t";
	for(j=0;j<rate[2];j++)
    rate_file<<s<<" ";
			
	cout<<"\n\n\t\tUser Friendly\t\t\t\t\t";
	for(j=0;j<rate[3];j++)
    cout<<s<<" ";
	rate_file<<"\n\n\t\tUser Friendly\t\t\t\t\t";
	for(j=0;j<rate[3];j++)
    rate_file<<s<<" ";
		
	cout<<"\n\n\t\tCome Back\t\t\t\t\t";
	for(j=0;j<rate[4];j++)
    cout<<s<<" ";
	rate_file<<"\n\n\t\tCome Back\t\t\t\t\t";
	for(j=0;j<rate[4];j++)
    rate_file<<s<<" ";
	
	cout<<"\n\t\t---------------------------------------------------------------------------------------\n";
	cout<<"\t\t\t\t     Thankyou for visiting BlueJay Online Shopping.";
	cout<<"\n\t\t---------------------------------------------------------------------------------------\n";
	rate_file.close();
	exit (0);
}

void Payment:: check_promo()
{
	char ans;
	int tries=0;
	cout<<"\n\nPayment: ";
	cout<<"\n\nDo you have a promo code? (y/n)";
	cin>>ans;
    if(ans=='y')
    {
		set:
		cout<<"\nEnter promo code: ";
		cin>>promocode;
	if(strcmp(promocode,"GET50")==0 || strcmp(promocode,"25OFF")==0 || strcmp(promocode,"DISCOUNT75")==0 )
	{
		if(strcmp(promocode,"GET50")==0)
			amountdue=amountdue-(0.5*amountdue);
		else if(strcmp(promocode,"25OFF")==0)
			amountdue=amountdue-(0.25*amountdue);
		else if(strcmp(promocode,"DISCOUNT75")==0)
			amountdue=amountdue-(0.75*amountdue);
			cout<<"\nPromo code applied!"<<endl;
	}
	else
	{
		char c;
		cout<<"\nPromo code invalid. Try again? (y/n)";
		cin>>c;
		if(c=='y'){
			if(tries<2){
				tries++;
				goto set;
			}
			else
			cout<<"\nToo many tries! Promo code can't be applied."<<endl;
		}
    }
}
}

void Payment:: generate_invoice()
{
	char code[6];
	string name;
	double price;
	int qty;
	Payment cus;
	cus.enterdetails();
	cout<<"\n\t\t---------------------------------------------------------------------------------------\n";
	cout<<"\t\t\t\t\t\tINVOICE";
	cout<<"\n\t\t---------------------------------------------------------------------------------------\n";
	cus.displaydetails();
    cout<<"\n\t\t---------------------------------------------------------------------------------------\n";
    
	cout<<"\t\tItem name\t\tPrice\t\tQuantity"<<endl;
	ifstream cart;
	cart.open("Cart.txt");
    	while(cart>>code>>name>>price>>qty)
        {
         	cout<<"\t\t"<<name<<"\t\t"<<price<<"\t\t"<<qty<<endl;
        }
	cout<<"\n\t\tTotal balance due: "<<amountdue;
	cout<<"\n\t\t---------------------------------------------------------------------------------------\n";
	printtime();
	cart.close();
	remove("Cart.txt");   /////so that for every customer there will be a new cart
    
	char feed;
    cout<<"\n\nWe have a feedback form for you. We request you to kindly fill it so we can improve our services.";
    cout<<"\n\nTo fill feedback form please enter F.";
    cout<<"\n\nEnter any other alphabet to exit.  ";
    cin>>feed;
    
    if(feed=='f'||feed=='F')
    cus.feedback();
	else
	exit (1);

}

void printtime(void)
{
    time_t t;
    time(&t);
    printf("\t\t%s", ctime(&t));
}
