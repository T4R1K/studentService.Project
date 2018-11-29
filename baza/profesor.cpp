#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include "osoba.h"
#include "profesor.h"
#include "predmet.h"
#include "Windows.h"

using namespace std;

//Metoda za unos podataka od strane korisnika

void Profesor::inputInfo(vector<Profesor>& box) {
    Profesor *pr1;
    pr1 = new Profesor;
    cin.ignore();

    cout << "Upisite ime profesora:" << endl;
    getline(cin, ime);
    pr1->setIme(ime);
    
    cout << "Upisite prezime profesora:" << endl;
    getline(cin, prezime);
    pr1->setPrezime(prezime);
    
    ponovi:
    cout << "Upisite JMBG profesora:" << endl;
    getline(cin, jmbg);
    if (jmbg.size() == 13) {pr1->setJmbg(jmbg);} else {cout << "Nevazeci unos, pokusajte ponovo!\n"; loader(); cout << endl << endl; goto ponovi;}
    
    cout << "Upisite poziciju na predmetu:" << endl;
    getline(cin, pozicija);
    pr1->setPozicija(pozicija);
    
    cout << "Upisite usmjerenje:" << endl;
    getline(cin, usmjerenje);
    pr1->setPredmet(usmjerenje);

    box.push_back(*pr1);
}

//Metoda za ucitavanje podataka iz datoteke u vektor

void Profesor::outputInfo(vector<Profesor>& box) {
    string temp;
    int br = 0;
    Profesor *pr1;
    pr1 = new Profesor;

    ifstream profesordat("nastavnik.dat", ios::out);
    if (profesordat.eof())
        cout << "Prazan fajl";
    else if (profesordat.is_open()) {
        while (!profesordat.eof()) {
            
            //Ukoliko klasa Profesor bude ispisana sa pogresnim redoslijedom ubaciti jmbg dio u komentar dole

            getline(profesordat, temp, '#');
            pr1->setJmbg(temp);
            
            getline(profesordat, temp, '#');
            pr1->setIme(temp);

            getline(profesordat, temp, '#');
            pr1->setPrezime(temp);

            /*U slucaju problema ubaciti JMBG ovdje*/
                     
            getline(profesordat, temp, '#');
            pr1->setPozicija(temp);

            getline(profesordat, temp, '#');
            pr1->setPredmet(temp);
            box.push_back(*pr1);
        }
        box.pop_back();
        profesordat.close();
    }

    //cout << "Inicijalno ucitavanje profesora uspjelo!\n" << endl;
    //cout << string(80, '*') << endl;
}
// Metoda za format ispisa podataka

void Profesor::showInfo() {
    cout << " " << setw(15) << ime << setw(20) << prezime << setw(15) << jmbg << setw(12) << pozicija << setw(15) << usmjerenje << endl;
}

//Metoda za ispis podataka iz vektora na ekran

void Profesor::showAll(vector<Profesor>& box, vector<Profesor>::iterator& it) {
    cout << left << " " << setw(15) << "Ime:" << setw(20) << "Prezime:" << setw(15) << "JMBG:" << setw(12) << "Pozicija:" << setw(15) << "Usmjerenje:" << endl << endl;
    for (it = box.begin(); it != box.end(); ++it) {
        it->showInfo();
    }
    cout << "\n" << string(80, '*') << endl;
}

// Metoda za ispis jednog podatka u pretrazi

void Profesor::showSingle(vector<Profesor>& box, int& i)
{   
    cout << left << " " << setw(15) << "Ime:" << setw(20) << "Prezime:" << setw(15) << "JMBG:" << setw(12) << "Pozicija:" << setw(15) << "Usmjerenje:" << endl << endl;
    cout << " " << setw(15) << box.at(i).ime << setw(20) << box.at(i).prezime << setw(15) << box.at(i).jmbg << setw(12) << box.at(i).pozicija << setw(15) << box.at(i).usmjerenje << endl << endl;
}

// Metoda za editovanje podataka unutar vektora prema odabiru

void Profesor::editProfesor(vector<Profesor>& box) {
    string edit, option;
    cout << "Unesite maticni broj profesora za editovanje podataka: " << endl;
    cin >> edit;
    for (int i = 0; i < box.size(); i++) {
        if (box.at(i).jmbg == edit) {

            int m2 = 0;
            system("CLS");
            cout << "\nOdaberite koju opciju zelite mijenjati za clana:\n\n";
            showSingle(box, i);
            cout << "1 : Ime:\n";
            cout << "2 : Prezime:\n";
            cout << "3 : JMBG:\n";
            cout << "4 : Pozicija:\n";
            cout << "5 : Usmjerenje:\n";

            cin>>m2;
            cout << "Unesite novu izmjenu:\n" << endl;
            cin>>option;

            switch (m2) {
                case (1): box.at(i).ime = option;
                    break;
                case (2): box.at(i).prezime = option;
                    break;
                case (3): 
                    if(option.size() == 13) {box.at(i).jmbg = option;} else cout << "Nevazeci unos, pokusajte ponovo!\n"; loader(); break;
                    break;
                case (4): box.at(i).pozicija = option;
                    break;
                case (5): box.at(i).usmjerenje = option;
                    break;

            }          
        }       
    }
}

// Metoda za ispis podataka iz vektora u datoteku

void Profesor::saveFile(vector<Profesor>& box) {
    ofstream output("nastavnik.dat", ios::out | ios::trunc);
    for (int i = 0; i < box.size(); i++) {
        output << box[i].ime << '#' << box[i].prezime << '#' << box[i].jmbg << '#' << box[i].pozicija << '#' << box[i].usmjerenje << '#';
    }
}

// Metoda za brisanje elemenata iz vektora

void Profesor::deleteProfesor(vector<Profesor>& box) {

    string remove;
    cout << "Unesi jmbg profesora za brisanje: " << endl;
    cin >> remove;

    for (int i = 0; i < box.size(); i++) {
        {
            if (box.at(i).jmbg == remove) {
                box.erase(box.begin() + i);
                return;
            }
        }
    }
}

// Metoda za sortiranje po izboru

void Profesor::sortProfesors(vector<Profesor>& box) {

    auto poImenu = [](const Profesor & a, const Profesor & b) -> bool {
        return a.ime < b.ime;
    };
    auto poPrezimenu = [](const Profesor & a, const Profesor & b) -> bool {
        return a.prezime < b.prezime;
    };
    auto poJmbg = [](const Profesor & a, const Profesor & b) -> bool {
        return a.jmbg < b.jmbg;
    };
    auto poPoziciji = [](const Profesor & a, const Profesor & b) -> bool {
        return a.pozicija < b.pozicija;
    };
    auto poUsmjerenju = [](const Profesor & a, const Profesor & b) -> bool {
        return a.usmjerenje < b.usmjerenje;
    };

    int s1 = 0;
    cout << "Sortiraj po:" << endl;
    cout << "1 : Imenu\n2 : Prezimenu\n3 : JMBG\n4 : Pozicji\n5 : Usmjerenju" << endl;
    cin >> s1;
    switch (s1) {
        case(1):
            sort(box.begin(), box.end(), poImenu);
            break;
        case(2):
            sort(box.begin(), box.end(), poPrezimenu);
            break;
        case(3):
            sort(box.begin(), box.end(), poJmbg);
            break;
        case(4):
            sort(box.begin(), box.end(), poPoziciji);
            break;
        case(5):
            sort(box.begin(), box.end(), poUsmjerenju);
            break;
    }
}

//Kratki loader

void Profesor::loader(){
    cout << "\nUcitavam";
    for(int i = 0; i < 4; i++)
    {
        Sleep(0400);
        cout << " .";
    }
}

//Destruktor

Profesor::~Profesor() {

}