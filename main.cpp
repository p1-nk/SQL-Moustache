//Copyright of "Dziewiczy Wąsik Studio" 2021-2021
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;

int number;
int number2;
int howManyNames;
string tableName;
string nameValue;
string surnameValue;
string name[1000];
string surname[1000];
string linia;
string writeAge;
int age = 15;

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

void cRandom()
{
    const string filename = "Output.txt";
    ofstream plik1(filename);

    srand(time(NULL));
    for(int i = 0; i < howManyNames; i++)
    {
        number = rand()%626+1;
        number2 = rand()%250+1;
        age = rand()%15+10;
        plik1 << "insert into " << tableName << " ("<< nameValue <<", "<< surnameValue;
        if (writeAge == "y") {
            plik1 << ", age";
        }
        plik1 << ") VALUES ('" << name[number] << "', '" << surname[number2] << "'";
        if (writeAge == "y"){
            plik1 <<  ", " << age;
        }
        plik1 << ");" << endl;
    }
}

int main()
{
    assignment();

    cout << "Ile osob chcesz wylosowac?\n";
    cin >> howManyNames;
    cout << "Jak sie nazywa tabela do ktorej wklejasz te dane?\n";
    cin >> tableName;
    cout << "Jak sie nazywa kolumna w ktorej przechowujesz imie?\n";
    cin >> nameValue;
    cout << "Jak sie nazywa tabela w ktorej przechowujesz nazwisko?\n";
    cin >> surnameValue;
    cout << "Chcesz wylosować wiek? (y/n)\n";
    cin >> writeAge;
    cRandom();
    cout << "Wygenerowano liste z zapytaniami SQL!";
    cin >> number;
    
    return 0;
}
