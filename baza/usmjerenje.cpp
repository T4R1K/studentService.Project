#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include "usmjerenje.h"
#include "windows.h"

using namespace std;

//Metoda za unos podataka od strane korisnika

void Usmjerenje::inputInfo(vector<Usmjerenje>& box) {
    Usmjerenje *us;
    us = new Usmjerenje;
    cin.ignore();

    cout << "Upisite skracenicu usmjerenja:" << endl;
    getline(cin, usmjerenje);
    us->setNaziv(usmjerenje);
    
    cout << "Upisite puni naziv usmjerenja:" << endl;
    getline(cin, naziv);
    us->setNaziv(naziv);
    
    cout << "Upisite studijski program:" << endl;
    getline(cin, st_program);
    getline(cin, st_program);
    us->setNaziv(st_program);
    box.push_back(*us);
}


//Metoda za ucitavanje podataka iz datoteke u vektor

void Usmjerenje::outputInfo(vector<Usmjerenje>& box) {
    string temp;
    int br = 0;
    Usmjerenje *us1;
    us1 = new Usmjerenje;

    ifstream usmjerenjedat("usmjerenje.dat", ios::out);
    if (usmjerenjedat.eof())
        cout << "Prazan fajl";
    else if (usmjerenjedat.is_open()) {
        while (!usmjerenjedat.eof()) {
            
            //Ukoliko klasa Usmjerenje bude ispisana sa pogresnim redoslijedom ubaciti jmbg dio u komentar dole
            getline(usmjerenjedat, temp, '#');
            us1->setUsmjerenje(temp);
            
            getline(usmjerenjedat, temp, '#');
            us1->setNaziv(temp);

            getline(usmjerenjedat, temp, '#');
            us1->setStProgram(temp);
            box.push_back(*us1);
            }
        box.pop_back();
        usmjerenjedat.close();
    }
}

// Metoda za format ispisa podataka

void Usmjerenje::showInfo() {
    cout << " " << setw(4) << usmjerenje << setw(40) << naziv << setw(4) << st_program  << endl;
}

//Metoda za ispis podataka iz vektora na ekran

void Usmjerenje::showAll(vector<Usmjerenje>& box, vector<Usmjerenje>::iterator& it) {
    cout << left << " " << setw(4) << "US:" << setw(40) << "Puni Naziv:" << setw(4) << "SP:" << endl << endl;
    for (it = box.begin(); it != box.end(); ++it) {
        it->showInfo();
    }
    cout << "\n*US-Usmjerenje SP-Studijski Program\n";
    cout << "\n" << string(80, '*') << endl;
}

// Metoda za ispis jednog podatka u pretrazi

void Usmjerenje::showSingle(vector<Usmjerenje>& box, int& i)
{   
    cout << left << " " << setw(4) << "US:" << setw(40) << "Puni Naziv:" << setw(15) << "SP:" << endl << endl;
    cout << " " << setw(4) << box.at(i).usmjerenje << setw(40) << box.at(i).naziv << setw(4) << box.at(i).st_program  << endl << endl;
}

// Metoda za editovanje podataka unutar vektora prema odabiru

void Usmjerenje::editUsmjerenje(vector<Usmjerenje>& box) {
    string edit, option;
    cout << "Unesite skracenicu usmjerenja za editovanje: " << endl;
    cin >> edit;
    for (int i = 0; i < box.size(); i++) {
        if (box.at(i).usmjerenje == edit) {

            int m2 = 0;
            
            cout << "\nOdaberite koju opciju zelite mijenjati za clana:\n\n";
            showSingle(box, i);
            
            cout << "1 : Skracenica:\n";
            cout << "2 : Naziv:\n";
            cout << "3 : Studijski program:\n";

            cin>>m2;
            cout << "Unesite novu izmjenu:\n" << endl;
            cin>>option;

            switch (m2) {
                case (1): box.at(i).usmjerenje = option;
                    break;
                case (2): box.at(i).naziv = option;
                    break;
                case (3): box.at(i).st_program = option;
                    break;                
            }
        }
    }
}

// Metoda za ispis podataka iz vektora u datoteku

void Usmjerenje::saveFile(vector<Usmjerenje>& box) {
    ofstream output("usmjerenje.dat", ios::out | ios::trunc);
    for (int i = 0; i < box.size(); i++) {
        output << box[i].usmjerenje << '#' << box[i].naziv << '#' << box[i].st_program << "#";
    }
}

  // Metoda za brisanje usmjerenja

void Usmjerenje::deleteUsmjerenje(vector<Usmjerenje>& box) {

    string remove;
    cout << "Unesi skracenicu usmjerenja za brisanje: " << endl;
    cin >> remove;

    for (int i = 0; i < box.size(); i++) {
        {
            if (box.at(i).usmjerenje == remove) {
                box.erase(box.begin() + i);
                return;
            }
        }
    }
}

void Usmjerenje::sortUsmjerenja(vector<Usmjerenje>& box) {

    auto poUsmjerenju = [](const Usmjerenje & a, const Usmjerenje & b) -> bool {
        return a.usmjerenje < b.usmjerenje;
    };
    auto poNazivu = [](const Usmjerenje & a, const Usmjerenje & b) -> bool {
        return a.naziv < b.naziv;
    };
    auto poStProgramu = [](const Usmjerenje & a, const Usmjerenje & b) -> bool {
        return a.st_program < b.st_program;
    };

    int s1 = 0;
    cout << "Sortiraj po:" << endl;
    cout << "1 : Usmjerenju\n2 : Nazivu\n3 : Studijskom programu\n" << endl;
    cin >> s1;
    switch (s1) {
        case(1):
            sort(box.begin(), box.end(), poUsmjerenju);
            break;
        case(2):
            sort(box.begin(), box.end(), poNazivu);
            break;
        case(3):
            sort(box.begin(), box.end(), poStProgramu);
            break;
    }
}

//Kratki loader

void Usmjerenje::loader(){
    cout << "\nUcitavam";
    for(int i = 0; i < 4; i++)
    {
        Sleep(0400);
        cout << " .";
    }
}

//Destruktor
Usmjerenje::~Usmjerenje(){
    
}
