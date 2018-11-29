#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <Windows.h>
#include "studijskiprogram.h"

using namespace std;

//Metoda za unos podataka od strane korisnika
void Studijski_program::inputInfo(vector<Studijski_program>& box)
{
    Studijski_program *s;
    s = new Studijski_program;
    cin.ignore();
    
    ponovi:     
    cout<<"Upisite skracenicu studijskog programa:" << endl;
    getline(cin,skracenica);
    if (skracenica.size() == 2) {s->setSkracenica(skracenica);} else {cout << "Nevazeci unos, pokusajte ponovo!\n"; loader(); cout << endl << endl; goto ponovi;}
    
    cout<<"Upisite naziv studijskog programa:" << endl;
    getline(cin,naziv);
    s->setNaziv(naziv);
    
    box.push_back(*s);
} 

//Metoda za ucitavanje podataka iz datoteke u vektor
void Studijski_program::outputInfo(vector<Studijski_program>& box)
{
    string temp;
    int br = 0;
    Studijski_program *s1;
    s1 = new Studijski_program;
    
    ifstream studijskiprogramdat("studijskiProgram.dat", ios::out);
    if(studijskiprogramdat.eof())
        cout<<"Prazan fajl";
    else if(studijskiprogramdat.is_open())
    {
        while(!studijskiprogramdat.eof())
        {        
            getline(studijskiprogramdat, temp, '#');
            s1->setSkracenica(temp);

            getline(studijskiprogramdat, temp, '#');
            s1->setNaziv(temp); 
            box.push_back(*s1);    
        }
        box.pop_back(); 
        studijskiprogramdat.close();
    }  
}
// Metoda za format ispisa podataka
void Studijski_program::showInfo()
{    
    cout << " " << setw(4) << skracenica <<setw(50)<< naziv << endl;
}

//Metoda za ispis podataka iz vektora na ekran
void Studijski_program::showAll(vector<Studijski_program>& box, vector<Studijski_program>::iterator& it)
{
    cout<< left << " " << setw(4) << "SK:" <<setw(50) << "Naziv:" <<endl <<endl;
        for(it = box.begin(); it != box.end(); ++it)
            { 
            it->showInfo();
            }
    cout << "\n*SK-Skracenica\n";
    cout << "\n" << string(80, '*') << endl;
}

// Metoda za ispis jednog podatka u pretrazi

void Studijski_program::showSingle(vector<Studijski_program>& box, int& i)
{   
    cout<< left << " " << setw(4) << "SK:" <<setw(50) << "Naziv:" <<endl <<endl;
    cout << " " << setw(4) << box.at(i).skracenica <<setw(50)<< box.at(i).naziv << endl << endl;
}

// Metoda za editovanje podataka unutar vektora prema odabiru

void Studijski_program::editStudijski_program(vector<Studijski_program>& box) {
    string edit, option;
    cout << "Unesite skracenicu smjera za editovanje: " << endl;
    cin >> edit;
    for (int i = 0; i < box.size(); i++) {
        if (box.at(i).skracenica == edit) {

            int m2 = 0;
            cout << "\nOdaberite koju opciju zelite mijenjati za clana:\n\n";
            showSingle(box, i);
            
            cout << "1 : Skracenica:\n";
            cout << "2 : Naziv:\n";

            cin>>m2;
            cout << "Unesite novu izmjenu:\n" << endl;
            cin>>option;

            switch (m2) {
                case (1): 
                    if (option.size() == 2) {box.at(i).skracenica = option;} else cout << "Nevazeci unos, pokusajte ponovo!\n"; loader(); break;
                    break;
                case (2): 
                    box.at(i).naziv = option;
                    break;
            }
        }
    }
}

// Metoda za ispis podataka iz vektora u datoteku

void Studijski_program::saveFile(vector<Studijski_program>& box) {
    ofstream output("studijskiProgram.dat", ios::out | ios::trunc);
    for (int i = 0; i < box.size(); i++) {
        output << box[i].skracenica << '#' << box[i].naziv << '#';
    }
}

// Metoda za brisanje studenta iz vektora

void Studijski_program::deleteStudijski_program(vector<Studijski_program>& box) {

    string remove;
    cout << "Unesi skracenicu studijskog programa za brisanje: " << endl;
    cin >> remove;

    for (int i = 0; i < box.size(); i++) {
        {
            if (box.at(i).skracenica == remove) {
                box.erase(box.begin() + i);
                return;
            }
        }
    }
}

// Metoda za sortiranje po izboru

void Studijski_program::sortStudijski(vector<Studijski_program>& box) {

    auto poKljucu = [](const Studijski_program & a, const Studijski_program & b) -> bool {
        return a.skracenica < b.skracenica;
    };
    auto poNazivu = [](const Studijski_program & a, const Studijski_program & b) -> bool {
        return a.naziv < b.naziv;
    };

    int s1 = 0;
    cout << "Sortiraj po:" << endl;
    cout << "1 : Skracenici\n2 : Nazivu" << endl;
    cin >> s1;
    switch (s1) {
        case(1):
            sort(box.begin(), box.end(), poKljucu);
            break;
        case(2):
            sort(box.begin(), box.end(), poNazivu);
            break;
    }
}

//Kratki loader

void Studijski_program::loader(){
    cout << "\nUcitavam";
    for(int i = 0; i < 4; i++)
    {
        Sleep(0400);
        cout << " .";
    }
}

//Destruktor
Studijski_program::~Studijski_program(){
    
}