//Copyright of "Dziewiczy Wąsik Studio" 2021-2021
#include<iostream>
#include<cstdlib>
#include<time.h>
#include<fstream>
using namespace std;

int number[1];
int age[2];
int howManyNames;
int howManyVar;
string data[3]; //0-Nazwa bazy danych, 1-Nazwa tabeli, 2-nameValue, 3-surnameValue
string name[1000];
string surname[1000];
string linia;
string writeAge;
const int tableSize = 50;
bool databaseCreated = false;

const string filename = "Output.txt";
ofstream plik1(filename);

//Konstruktory
void ui();

class Table
{
public:
    string name;
    string dataNames[tableSize];
    string dataTypes[tableSize];
    string data[tableSize];
};

void Create_Database()
{
    cout << "Jak się nazywa baza danych którą chcesz stworzyć?\n";
    cin >> data[0];
    plik1 << "drop database " << data[0] << ";\ncreate database " << data[0] << ";\n";
}

void Drop_Database()
{
    plik1 << "drop database\n";
}

void Create_Table()
{
    cout << "Tak wogóle tego jeszcze nie dokończyłem lmao\n";
    Table table;
    cout << "Nazwa tabeli\n";
    cin >> table.name;
    cout << "Ile kolumn\n";
    cin >> howManyVar;
    cout << "Typy danych\n";
    for(int i = 0; i < howManyVar; i++)
    {
        cin >> table.dataTypes[i];
    }
    cout << "Nazwy kolumn\n";
    for(int i = 0; i < howManyVar; i++)
    {
        cin >> table.dataNames[i];
    }
    ui();
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

void insertNames(){
    cout << "Ile osob chcesz wylosowac?\n";
    cin >> howManyNames;
    cout << "Jak sie nazywa tabela do ktorej wklejasz te dane?\n";
    cin >> data[1];
    cout << "Jak sie nazywa kolumna w ktorej przechowujesz imie?\n";
    cin >> data[2];
    cout << "Jak sie nazywa tabela w ktorej przechowujesz nazwisko?\n";
    cin >> data[3];
    cout << "Chcesz wylosować wiek? (y/n)\n";
    cin >> writeAge;
    cRandom();
    cout << "Wygenerowano liste z zapytaniami SQL!\n";
    ui();
}

void assignment()
{
    int nr_lini=1;

    fstream plik;
    plik.open("names.txt", ios::in);
    if(plik.good()==false)
    {
    cout<<"Nie mozna otworzyc pliku!";
    exit(0);
    }
    while (getline(plik, linia))
    {
        name[nr_lini]=linia;
        nr_lini++;
    }
    plik.close();

    nr_lini=1;

    plik.open("surnames.txt", ios::in);
    if(plik.good()==false)
    {
    cout<<"Nie mozna otworzyc pliku!";
    exit(0);
    }
    while (getline(plik, linia))
    {
        surname[nr_lini]=linia;
        nr_lini++;
    }
    plik.close();
}

void ui()
{
    assignment();
    if(databaseCreated == false)
    {
        createDatabase();
    }
    int choice;
    cout << "Created by Dziewiczy Wąsik Studio 2021\n";
    cout << "Co chcesz zrobić (wprowadzaj liczby)?\n1.Stwórz tabelę\n2.Wylosuj osoby do tabeli\n";
    cin >> choice;
    switch(choice)
    {
        case 1:
            createTable();
            break;
        case 2:
            insertNames();
            break;
        default:
            cout << "Błędne dane!\n";
    }
}

int main()
{
    ui();

    return 0;
}
