#include<iostream>
using namespace std;

class Department
{
	private:
	const static string name;
	const static string email;
	const static string owner;
	const static long int phoneno;
	const static long int postalcode;
    public:
	Department();
};

const string Department::name="BlueJay Online Clothing Store";
const string Department::email="contact_us@bluejay.com";
const string Department::owner="Mr. Simon Maxwell";
const long int Department::phoneno=60122600;
const long int Department::postalcode=58000;

Department:: Department() 
{
    cout<<"\n\t\t---------------------------------------------------------------------------------------\n";
	cout<<"\n\t\t\t\t\tWelcome to "<<name;
    cout<<"\n\t\t---------------------------------------------------------------------------------------\n";
	cout<<"\n\t\tContact Us:";
	cout<<"\n\t\tPhone no: " <<phoneno;
	cout<<"\n\t\tEmail address: " <<email;
	cout<<"\n\t\tPostal code: " <<postalcode;
	cout<<"\n\t\tOwner: " <<owner;
    cout<<"\n\t\t---------------------------------------------------------------------------------------\n";
}
