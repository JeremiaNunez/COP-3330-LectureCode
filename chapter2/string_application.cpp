/*

                Jeremia Nunez
                COP 3330 - OOP
     This program reads a txt file uing fstream class


*/

#include <iostream>
#include <stdio.h>
#include <fstream>  // This library allows to read txt files
#include <string> // allow us to use cerr
#include <cstdlib>
#include <iomanip>


using namespace std;

//void print_by_name(string name [], string id[], string phone[], int num_clients);
//void print_by_id(string name [], string id[], string phone[], int num_clients);
void print_by_phone(string name [], string id[], string phone[], int num_clients);

int main () 
{

fstream InputFile;
string name [6]={};
string id[6]={};
string phone[6]={};
int count =0;
string client_info;
int expression =0;

InputFile.open("agenda_phone.txt");

if(!InputFile)
{
    cerr<<"Error: file could not be opened"<<endl;
    exit(1);

}

while(InputFile.eof())
{
    InputFile >> id[count];
    InputFile >> name [count];
    InputFile >> phone [count];

    printf(" Client: %s %s %s\n", id[count].c_str(), name[count].c_str(), phone[count].c_str());
    count = count + 1;
}

int num_clients = count-1;

cout <<"\n\n*******************"<<endl;
cout<<"*****"<<setw(19)<<" MENU "<<setw(19)<<"*****"<<endl;
cout<<left<<"1."<<setw(5)<<"Search by id"<<endl;

cin >>expression;

switch (expression)
{
    case 1:
    //print_by_name(name,id,phone,num_clients);
    break;
    case 2:
    //print_by_id(name,id,phone,num_clients);
    break;
    case 3:
    print_by_phone(name,id,phone,num_clients);
    break;
    default:
    cout<<"Selected option is not valid"<<endl;
    break;
}

InputFile.close();
cout<<"All clients were uploaded"<<endl;


}

void print_by_phone(string name [], string id[], string phone[], int num_clients)
{

    string given_phone;
    cout <<"please write the name of the client: ";
    cin >> given_phone;
    bool found = false;

    for(int i=0; i<num_clients;i++)
    {
        if(given_phone==phone[i])
        {
            found=true;
            printf("\nThe client information: %s %s %s", id[i].c_str(), name[i].c_str(), phone[i].c_str());
            break;
        }
    }

    if(!found)
    {
        cout <<"\nClient was not found" <<endl;
    }

}







