#include <string.h>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <time.h>
#include "billing.h"
using namespace std;

class shop
{
    protected:
    char code[6];
    string name;
    int small;
    int med;
    int lar;
    double price;
    public:
    char show_more();
    void order();
};

class men_category : public virtual shop
{
    public:
    char show_more();
    void show_eastern();
    void show_western();
};

class women_category : public virtual shop
{
    public:
    char show_more();
    void show_eastern();
    void show_western();
};

class cart : public men_category, public women_category
{
	public:
	void show_cart();
    void del_item();
    void select(char[]);
};

char women_category::show_more()
{
    char t;
    cout<<"\n E >>>> Eastern\n";
    cout<<" W >>>> Western\n";
    cout<<"\n\nEnter type: ";
    cin>>t;
    return t;
}

void women_category::show_eastern()
{
ifstream infile("WomenEastern.txt");
cout<<"\n---------------------------------------------------------------------------------------\n";
cout<<"\n                                  Quantity (Sizes)";
cout<<"\nCode   Names\t\t\tSmall   Medium   Large\n";
cout<<"\n---------------------------------------------------------------------------------------\n";
while (infile>>code>>name>>small>>med>>lar>>price)
{
    cout<<code<<"   "<<name<<"\t\t"<<small<<"    "<<med<<"    "<<lar<<"   "<<price<<endl;
}
cout<<"\n---------------------------------------------------------------------------------------\n";
infile.close();
}

void women_category::show_western()
{
ifstream infile("WomenWestern.txt");
cout<<"\n---------------------------------------------------------------------------------------\n";
cout<<"\n                                  Quantity (Sizes)";
cout<<"\nCode   Names\t\t\tSmall   Medium   Large\n";
cout<<"\n---------------------------------------------------------------------------------------\n";
while (infile>>code>>name>>small>>med>>lar>>price)
{
    cout<<code<<"   "<<name<<"\t\t"<<small<<"   "<<med<<"   "<<lar<<"   "<<price<<endl;   
}
cout<<"\n---------------------------------------------------------------------------------------\n";
infile.close();
}

char men_category::show_more()
{
    char t;
    cout<<"\n E >>>> Eastern\n";
    cout<<" W >>>> Western\n";
    cout<<"\n\nEnter type: ";
    cin>>t;
    return t;
}

void men_category::show_eastern()
{
ifstream infile("MenEastern.txt");
cout<<"\n---------------------------------------------------------------------------------------\n";
cout<<"\n                                  Quantity (Sizes)";
cout<<"\nCode   Names\t\t\tSmall   Medium   Large\n";
cout<<"\n---------------------------------------------------------------------------------------\n";
while (infile>>code>>name>>small>>med>>lar>>price)
{
    cout<<code<<"   "<<name<<"\t\t"<<small<<"   "<<med<<"   "<<lar<<"   "<<price<<endl;
}
cout<<"\n---------------------------------------------------------------------------------------\n";
infile.close();
}

void men_category::show_western()
{
ifstream infile("MenWestern.txt");
cout<<"\n---------------------------------------------------------------------------------------\n";
cout<<"\n                                  Quantity (Sizes)";
cout<<"\nCode   Names\t\t\tSmall   Medium   Large\n";
cout<<"\n---------------------------------------------------------------------------------------\n";
while (infile>>code>>name>>small>>med>>lar>>price)
{
    cout<<code<<"   "<<name<<"\t\t"<<small<<"   "<<med<<"   "<<lar<<"   "<<price<<endl;
}
cout<<"\n---------------------------------------------------------------------------------------\n";
infile.close();
}

char shop::show_more()
{
    char t;
    cout<<"\nW >>> Women";
    cout<<"\nM >>> Men";
    cout<<"\n\nEnter type: ";
    cin>>t;
    return t;
}

void cart::select(char filename[])
{
    char opt[6],sizes,ans;
    int temp=0,quan=0;
    ifstream infile;
    ofstream updated_file, cart_file;
    updated_file.open("temp.txt");
    cart_file.open("Cart.txt",ios::out | ios::app);  //create cart

    up:
    cout<<"\nEnter code to select: ";
    cin>>opt;
    infile.open(filename);
     while (!infile.eof())                               //for checking if the item is available
    {
    infile>>code>>name>>small>>med>>lar>>price;
    if(strcmp(opt,code)==0)
       {
       temp=0;
       break;

       }
    else
        temp=1;    
    }
    if(temp==1)
    {
        cout<<"\nInvalid code entered! Please enter correct code";
        infile.close();
        goto up;
    }
    infile.close();

    infile.open(filename);                   /////opening this file again to take order

    cout<<"\nS >>> Small\n";
	cout<<"\nM >>> Medium\n";
	cout<<"\nL >>> Large\n";
			
     cout << "\nEnter Size: ";
     cin >> sizes;
    while(1) 
    {
      if(sizes=='S'||sizes=='s'||sizes=='M'||sizes=='m'||sizes=='L'||sizes=='l')
      break;
      else
      {
        cout<<"Invalid choice .... Please enter again: ";
        cin>>sizes;
      }
    }
	cout<<"\n\nEnter Quantity: ";
	cin>>quan;

    while (infile>>code>>name>>small>>med>>lar>>price){
    if(strcmp(opt,code)==0)
       {
        if(((sizes=='S'||sizes=='s')&&small<quan)||((sizes=='M'||sizes=='m')&&med<quan)||((sizes=='L'||sizes=='l')&&lar<quan))
		{
			cout<<"\n\nSorry for inconvenience. This item is out of stock for your required size and quantity.";
			updated_file.close();
            remove("temp.txt");
            cart_file.close();
            infile.close();
            select(filename);
		}
        else
       {            
           if(sizes=='S'||sizes=='s')
		   {
            small=small-quan;
            }					
		    else if(sizes=='M'||sizes=='m')
			{
            med=med-quan;
            }
			else if(sizes=='L'||sizes=='l')
			{
            lar=lar-quan;
            }
        }
       cart_file<<code<<"   "<<name<<"   "<<price<<"   "<<quan<<endl;  //cart file for customer
       cout<<endl<<code<<"\t\t"<<name<<"\t\t"<<price<<"\t\t"<<quan<<endl;//display on screen
       }
        updated_file<<code<<"   "<<name<<"   "<<small<<"   "<<med<<"   "<<lar<<"   "<<price<<endl;//updated file 
       }
    infile.close();
    cart_file.close();
    updated_file.close();
    remove(filename);
    rename("temp.txt",filename);
    cout<<"\nDo you want to buy anything else?(y/n)";
    cin>>ans;
    if(ans=='y')
    {
        
        order();
    }
    else
    {  
        show_cart();
    }
}

void shop::order()
{
	cart c;
    up:
    char t;
            t=show_more();     //returns category; women or Men
            if(t=='M'||t=='m')
            {
                men_category mc;
                again:
                t=mc.show_more();   //returns type; eastern or western
                if(t=='E'||t=='e')
                {
                    mc.show_eastern();
                    c.select("MenEastern.txt");
                }
                else if(t=='W'||t=='w')
                {
                    mc.show_western();
                    c.select("MenWestern.txt");
                }
                else
                {
                    cout<<"\nInvalid Choice! Please enter correct choice";
                    goto again;
                }
                
            }
            else if(t=='W'||t=='w')
            {
                women_category wc;
                again1:
                t=wc.show_more();    //returns type; eastern or western
                if(t=='E'||t=='e')
                {
                    wc.show_eastern();
                    c.select("WomenEastern.txt");
                }
                else if(t=='W'||t=='w')
                {
                    wc.show_western();
                    c.select("WomenWestern.txt");
                }
                else
                {
                    cout<<"\nInvalid Choice! Please enter correct choice";
                    goto again1;
                }
            }
            else
            {
                cout<<"\nInvalid Choice! Please enter correct choice";
                goto up;
            }
}

void cart::show_cart()
{
    int quan=0;
    char ans='\0';
    ifstream cart_file("Cart.txt");
    cout<<"\n\t\t\t\t\t\tYour Cart";
    cout<<"\n\t\t---------------------------------------------------------------------------------------\n";
    cout<<"\n\t\t\tCode   Names\t\t\tPrice\t\tQuantity\n";
    cout<<"\n\t\t---------------------------------------------------------------------------------------\n";
    while(cart_file>>code>>name>>price>>quan)
    {
    	cout<<"\t\t\t"<<code<<"   "<<name<<"\t\t"<<price<<"\t\t"<<quan<<endl;
    }
    cout<<"\n\t\t---------------------------------------------------------------------------------------\n";
    cart_file.close();

    cout<<"Do you want to Add or Delete something?(y/n) ";
    cin>>ans;
    while(1)
    {
    if(ans=='y')
    {
        cout<<"Add >>> A";
        cout<<"\nDelete >>> D";
        cout<<"\nAny other >>> To make Payment";
        cout<<"\nEnter your choice: ";
        cin>>ans;
        if(ans=='A'||ans=='a')
        {
            order();
        }
        else if(ans=='D'||ans=='d')
        {
            del_item();
        }
        else
        {
            continue;
        }
          
    }
    else
    {
        Payment p;
    	ifstream cartfile("Cart.txt");
    	while(cartfile>>code>>name>>price>>quan)
        {
        p.setamount(quan,price);
        }
        cartfile.close();
        p.check_promo();
        p.generate_invoice();
        exit (0);
    }
   }
    
}

void cart:: del_item(){
    char del[6],option;     //code of item to delete
    int rem=0,quan=0,temp=0,flag=0;
	ifstream cart_file;  
	
	repeat:
		cart_file.open("Cart.txt",ios::app); 
	cout<<"\n\nEnter code of item to remove: ";
    cin>>del;
    cart_file.seekg(0);
    
	while(cart_file>>code>>name>>price>>quan)
    {
    	if(strcmp(code,del)==0){
    		flag=0;
    		break;
		}
        
        else
        flag=1;
    }    
    if(flag==1){
    	cout<<"\nItem not found in cart. Try again!";
    	cart_file.close();
    	goto repeat;
    	
	}
    
    cout<<"\nEnter quantity of "<<del<<" item you want to remove: ";
    cin>>rem;
    
    ofstream temp_cart;
    cart_file.seekg(0);
    temp_cart.open("temp_cart.txt");
    while(cart_file>>code>>name>>price>>quan)
    {
    	if(strcmp(code,del)==0)
        {
            temp=quan-rem;
            if(temp>0)
            temp_cart<<endl<<code<<"   "<<name<<"   "<<price<<"   "<<temp;
        }
        if(strcmp(code,del)!=0)
        {
            temp_cart<<endl<<code<<"   "<<name<<"   "<<price<<"   "<<quan;
        }
    }
    temp_cart.close();
    cart_file.close();
    remove("Cart.txt");
    rename("temp_cart.txt","Cart.txt");
    
    cout<<"\n\nY >>> Yes";
	cout<<"\nN  >>> No";
	cout<<"\nDo you want to remove anything else? ";
	cin>>option;
	        
	    if(option=='Y'||option=='y')	
		{
            del_item();
        }

        else
        {
            show_cart();
        }	    
}
