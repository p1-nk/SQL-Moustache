//Copyright of "Dziewiczy Wąsik Studio" 2021-2021
#include<iostream>

using namespace std;

string command;
//command used at the moment

string databasename;
string table[1000][1000];
// table[tablenumber][columnnumber];

void Create_Database()
{
    cin>>databasename;
    cout<<"CREATE DATABASE"<<databasename<<";"<<endl;
}

void Drop_Database()
{
    cin>>databasename;
    cout<<"DROP DATABASE"<<databasename<<";"<<endl;
}

void Create_Table()
{
    //Create Table.
}

void Drop_Table()
{
    //Drop Table.
}

void Insert_Into()
{
    //Insert Into.
}

void Conect()
{
    //Conect tabels.
}

void Get_File()
{
    int nr_lini=1;

    fstream plik;
    plik.open("code.txt", ios::in);
    if(plik.good()==false)
    {
    cout<<"Nie mozna otworzyc pliku!";
    exit(0);
    }
    while (getline(plik, linia))
    {
        //todo.
    }
    plik.close(); 
}



void Question()
{
    cin>>command;

    if(command=="database")
    {
        Create_Database();
    }
    else if(command=="drop database")
    {
        Drop_Database();
    }
    else if(command=="table")
    {
        Create_Table();
    }
    else if(command=="drop table")
    {
        Drop_Table();
    }
    else if(command=="insert")
    {
        Insert_Into();
    }
    else if(command=="conect")
    {
        Conect();
    }
    else if(command=="get file")
    {
        Get_File();
    }
    else
    {
        cout<<"Invalid command!";
        exit(0);
    }
}

int main()
{
    Question();

    return 0;
}
