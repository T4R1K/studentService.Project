#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <Windows.h>
#include "ispit.h"


using namespace std;

    
//Metoda za unos podataka od strane korisnika
void Ispit::inputInfo(vector<Ispit>& box)
{
    Ispit *isp1;
    isp1 = new Ispit;
    cin.ignore();
    
    ponovi:
    cout<<"Upisite naziv ispita:\n";
    getline(cin,key);
    if (key.size() == 2) {isp1->setKey(key);} else {cout << "Nevazeci unos, pokusajte ponovo!\n"; loader(); cout << endl << endl; goto ponovi;}      
    
    cout<<"Upisite maticni broj:\n ";
    getline(cin,jmbg);
    isp1->setJmbg(jmbg);
    
    cout<<"Upisite broj indeksa:\n ";
    getline(cin,br_indeksa);
    isp1->setBrIndeksa(br_indeksa);
    
    cout<<"Upisite datum:\n ";
    getline(cin,datum);
    isp1->setDatum(datum);
    
    cout<<"Upisite rezultat ispita:\n ";
    cin >>rezultat;
    isp1->setRezultat(rezultat);
    box.push_back(*isp1);
} 

//Metoda za ucitavanje podataka iz datoteke u vektor
void Ispit::outputInfo(vector<Ispit>& box)
{
    string temp;
    int br = 0;
    Ispit *isp1;
    isp1 = new Ispit;
    
    ifstream ispitdat("ispit.dat", ios::out);
    if(ispitdat.eof())
        cout<<"Prazan fajl";
    else if(ispitdat.is_open())
    {
    while(!ispitdat.eof())
    {       
        
        getline(ispitdat, temp, '#');
        isp1->setKey(temp);
        
        getline(ispitdat, temp, '#');
        isp1->setJmbg(temp);
        
        getline(ispitdat, temp, '#');
        isp1->setBrIndeksa(temp); 
        
        getline(ispitdat, temp, '#');
        isp1->setDatum(temp);
        
        getline(ispitdat, temp, '#');
        stringstream rezultat(temp);
        rezultat >> br;
        isp1->setRezultat(br);   
        box.push_back(*isp1); 
    }
    box.pop_back(); 
    ispitdat.close();
    }
    
    //cout<< "Inicijalno ucitavanje ispita uspjelo!\n" << endl;
    //cout << string(80, '*') << endl;
}
// Metoda za format ispisa podataka
void Ispit::showInfo()
{    
    cout<< " " << setw(8) << key <<setw(18)<< jmbg << setw(15) << br_indeksa << setw(15) << datum << setw(5) << rezultat << endl;
}

//Metoda za ispis svih podataka iz vektora
void Ispit::showAll(vector<Ispit>& box, vector<Ispit>::iterator& it)
{
cout << left << " " << setw(8) << "Naziv:" << setw(18) << "JMBG:" <<setw(15) << "Broj Indeksa:" << setw(15) << "Datum:" << setw(5)<< "Rezultat:"<< endl << endl;
for(it = box.begin(); it != box.end(); ++it)
    { 
    it->showInfo();
    }
cout << "\n" << string(80, '*') << endl;
}

// Metoda za ispis jednog podatka u pretrazi
void Ispit::showSingle(vector<Ispit>& box, int& i)
{   
    cout << left << " " << setw(8) << "Naziv:" << setw(18) << "JMBG:" <<setw(15) << "Broj Indeksa:" << setw(15) << "Datum:" << setw(5)<< "Rezultat:" << endl << endl;
    cout<< " " << setw(8) << box.at(i).key <<setw(18)<< box.at(i).jmbg << setw(15) << box.at(i).br_indeksa << setw(15) << box.at(i).datum << setw(5) << box.at(i).rezultat << endl << endl;
}

// Metoda za editovanje podataka unutar vektora prema odabiru

void Ispit::editIspit(vector<Ispit>& box) {
    
    string edit, edit2, edit3, option;
    cout << "Unesite kljuc ispita (naziv) za editovanje podataka: " << endl;
    cin >> edit;
    cout << "Unesite broj indeksa za editovanje podataka: " << endl;
    cin >> edit2;
    cout << "Unesite datum ispita za editovanje podataka: " << endl;
    cin >> edit3;
    
    for (int i = 0; i < box.size(); i++) {
        if (box.at(i).key == edit && box.at(i).br_indeksa == edit2 && box.at(i).datum == edit3) {
            
            int m2 = 0;
            system("CLS");
            cout << "\nOdaberite opciju koju zelite mijenjati za clana:\n\n";
            showSingle(box, i);
            
            cout << "1 : Kljuc:\n";
            cout << "2 : JMBG:\n";
            cout << "3 : Broj Indeksa:\n";
            cout << "4 : Datum:\n";
            cout << "5 : Rezultat:\n";

            cin>>m2;           
            switch (m2) {
                case (1): 
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> option;
                    if (option.size() == 2) {box.at(i).key = option;} else cout << "Nevazeci unos, pokusajte ponovo!\n"; loader(); break;
                    break;
                    
                case (2):
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> option;
                    box.at(i).jmbg = option;
                    break;
                    
                case (3):
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> option;
                    if (option.size() == 9) {box.at(i).br_indeksa = option;} else cout << "Nevazeci unos, pokusajte ponovo!\n"; loader(); break;
                    break;
                    
                case (4):
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> option;
                    if (option.size() == 10) {box.at(i).datum = option;} else cout << "Nevazeci unos, pokusajte ponovo!\n"; loader(); break;
                    break;
                   
                case (5):
                    cin.clear();
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> rezultat;
                    box.at(i).setRezultat(rezultat);
                    break;
            }
        }       
    }
}

// Metoda za ispis podataka iz vektora u datoteku

void Ispit::saveFile(vector<Ispit>& box) {
    
    ofstream output("ispit.dat", ios::out | ios::trunc);
    for (int i = 0; i < box.size(); i++) {
        output << box[i].key << '#' << box[i].jmbg << '#' << box[i].br_indeksa << '#' << box[i].datum << '#' << box[i].rezultat << '#';
    }
}

// Metoda za brisanje podataka iz vektora

void Ispit::deleteIspit(vector<Ispit>& box) {

    string remove, remove1, remove2;
    cout << "Unesite naziv ispita za brisanje: " << endl;
    cin >> remove;
    cout << "Unesite broj indeksa: " << endl;
    cin >> remove1;
    cout << "Unesite datum ispita: " << endl;
    cin >> remove2;

    for (int i = 0; i < box.size(); i++) {
        {
            if (box.at(i).key == remove && box.at(i).br_indeksa == remove1 && box.at(i).datum == remove2) {
                box.erase(box.begin() + i);
                return;
            }
        }
    }
}

// Metoda za sortiranje po izboru

void Ispit::sortIspit(vector<Ispit>& box) {

    auto poKljucu = [](const Ispit & a, const Ispit & b) -> bool {
        return a.key < b.key;
    };
    auto poNazivu = [](const Ispit & a, const Ispit & b) -> bool {
        return a.jmbg < b.jmbg;
    };
    auto poSmjeru = [](const Ispit & a, const Ispit & b) -> bool {
        return a.br_indeksa < b.br_indeksa;
    };
    auto poOdsjeku = [](const Ispit & a, const Ispit & b) -> bool {
        return a.datum < b.datum;
    };
    auto poSemestru = [](const Ispit & a, const Ispit & b) -> bool {
        return a.rezultat > b.rezultat;
    };

    int s1 = 0;
    cout << "Sortiraj po:" << endl;
    cout << "1 : Kljucu\n2 : JMBG\n3 : Broju Indeksa\n4 : Datumu\n5 : Rezultatu" << endl;
    cin >> s1;
    switch (s1) {
        case(1):
            sort(box.begin(), box.end(), poKljucu);
            break;
        case(2):
            sort(box.begin(), box.end(), poNazivu);
            break;
        case(3):
            sort(box.begin(), box.end(), poSmjeru);
            break;
        case(4):
            sort(box.begin(), box.end(), poOdsjeku);
            break;
        case(5):
            sort(box.begin(), box.end(), poSemestru);
            break;
    }
}

//Kratki loader

void Ispit::loader(){
    cout << "\nUcitavam";
    for(int i = 0; i < 4; i++)
    {
        Sleep(0400);
        cout << " .";
    }
}
//Destruktor

Ispit::~Ispit() {

}