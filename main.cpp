//Section C
//Naz 19k-1256
//Sara jamal 19k-0207


#include <iostream>
#include <string.h>
#include <fstream>
#include <cstdio>
#include <time.h>
#include "department.h"
#include "store.h"
using namespace std;

int main()
{
    const Department d;
    cout<<" \t\t\t\t\t\t\t\t\t~Quality Never goes out of style.\n";
	cout<<"\t\t---NOTE---\n";
	cout<<"\t\t -Enter code carefully. If the entered code is not in the list, required item will not \n\t\t  be added in the cart\n";
	cout<<"\t\t -Free Delivery All Over Pakistan\n";
	cout<<"\t\t -Exclusive Discount Offers\n";
	cout<<"\t\t -No exchange offer\n";
	cout<<"\t\t -Payment by cash only\n\n";
    shop sh;
    
    char user;
		cout<<"\n\t\t\t\tCustomer   >>> C";
		cout<<"\n\n\t\t\t\tExit       >>> Any character\n";
		cout<<"\n\t\t\t\tEnter your choice: ";
        cin>>user;
		
		if(user=='C'||user=='c')
	    {
            sh.order();
        }
		else
		exit (0);
}

