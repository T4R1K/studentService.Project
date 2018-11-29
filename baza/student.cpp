#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <Windows.h>
#include "osoba.h"
#include "student.h"


using namespace std;

//Metoda za unos podataka od strane korisnika

void Student::inputInfo(vector<Student>& box) {
    Student *st1;
    st1 = new Student;   
    cin.ignore();
    
    cout << "Upisite ime studenta:" << endl;
    getline(cin, ime);
    st1->setIme(ime);
    
    cout << "Upisite prezime studenta:" << endl;
    getline(cin, prezime);
    st1->setPrezime(prezime);
    
    cout << "Upisite JMBG studenta:" << endl;
    getline(cin, jmbg);
    st1->setJmbg(jmbg);
    
    ponovi:
    cout << "Upisite broj indeksa:" << endl;
    getline(cin, indeks);
    if (indeks.size() == 9) {st1->setBrojIndeksa(indeks);} else {cout << "Nevazeci unos, pokusajte ponovo!\n"; loader(); cout << endl << endl; goto ponovi;}
    
    cout << "Upisite smjer:" << endl;
    getline(cin, smjer);
    st1->setSmjer(smjer);
    
    box.push_back(*st1);
}

//Metoda za ucitavanje podataka iz datoteke u vektor

void Student::outputInfo(vector<Student>& box) {
    string temp;
    int br = 0;
    Student *f1;
    f1 = new Student;

    ifstream studentdat("student.dat", ios::out);
    if (studentdat.eof())
        cout << "Prazan fajl";
    else if (studentdat.is_open()) {
        while (!studentdat.eof()) {
            
            getline(studentdat, temp, '#');
            f1->setJmbg(temp);
            
            getline(studentdat, temp, '#');
            f1->setIme(temp);

            getline(studentdat, temp, '#');
            f1->setPrezime(temp);

            getline(studentdat, temp, '#');
            f1->setBrojIndeksa(temp);

            getline(studentdat, temp, '#');
            f1->setSmjer(temp);

            box.push_back(*f1);
        }
        box.pop_back(); 
        studentdat.close();
    }
}
// Metoda za format ispisa podataka

void Student::showInfo() {

    cout << " " << setw(12) << indeks  << setw(20) << ime << setw(20) << prezime << setw(16) << jmbg << setw(4) << smjer << endl;
}

//Metoda za ispis podataka iz vektora na ekran

void Student::showAll(vector<Student>& box, vector<Student>::iterator& it) {
    cout << left << " " << setw(12) << "Indeks:" << setw(20) << "Ime:" << setw(20) << "Prezime:" << setw(16) << "Maticni Broj:" << setw(4) << "SM:" <<  endl << endl;
    
    for (it = box.begin(); it != box.end(); ++it) {
        it->showInfo();
    }
    cout << "\n*SM-Smjer" << endl;
    cout << "\n" << string(80, '*') << endl;
}

// Metoda za ispis jednog podatka u pretrazi
void Student::showSingle(vector<Student>& box, int& i)
{   
    cout << left << " " << setw(12) << "Indeks:" << setw(20) << "Ime:" << setw(20) << "Prezime:" << setw(16) << "Maticni Broj:" << setw(4) << "SM:" <<  endl << endl;
    cout << " " << setw(12) << box.at(i).indeks << setw(20) << box.at(i).ime << setw(20) << box.at(i).prezime << setw(16) << box.at(i).jmbg << setw(4) << box.at(i).smjer << endl << endl;
}

// Metoda za editovanje podataka unutar vektora prema odabiru

void Student::editStudent(vector<Student>& box) {
    string edit, option;
    cout << "Unesite broj indeksa studenta za editovanje podataka: " << endl;
    cin >> edit;
    for (int i = 0; i < box.size(); i++) {
        if (box.at(i).indeks == edit) {

            int m2 = 0;

            cout << "\nOdaberite koju opciju zelite mijenjati za clana:\n\n";
            showSingle(box, i);
            
            cout << " 1 : Ime:\n";
            cout << " 2 : Prezime:\n";
            cout << " 3 : JMBG:\n";
            cout << " 4 : Broj Indeksa:\n";
            cout << " 5 : Smjer\n";
            cout << " 6 : Semestar\n";

            cin>>m2;          

            switch (m2) {
                case (1): 
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin>>option;
                    box.at(i).ime = option;
                    break;
                    
                case (2): 
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin>>option;
                    box.at(i).prezime = option;
                    break;
                    
                case (3): 
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin>>option;
                    box.at(i).jmbg = option; 
                    break;
                    
                case (4): 
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin>>option;
                    if(option.size() == 9) {box.at(i).indeks = option;} else cout << "Nevazeci unos, pokusajte ponovo!\n"; loader(); break;
                    break;
                    
                case (5): 
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin>>option;
                    box.at(i).smjer = option;
                    break;
                    
                case (6): 
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin>>option;
                    box.at(i).semestar = option;
                    break;   
            }
        }
    }
}

// Metoda za ispis podataka iz vektora u datoteku

void Student::saveFile(vector<Student>& box) {
    ofstream output("student.dat", ios::out | ios::trunc);
    for (int i = 0; i < box.size(); i++) {
        output << box[i].ime << '#' << box[i].prezime << '#' << box[i].jmbg << '#' << box[i].indeks << '#' << box[i].smjer << '#';
    }
}

  // Metoda za brisanje elemenata iz vektora

void Student::deleteStudent(vector<Student>& box) {

    string remove;
    cout << "Unesi broj indeksa studenta za brisanje: " << endl;
    cin >> remove;

    for (int i = 0; i < box.size(); i++) {
        {
            if (box.at(i).indeks == remove) {
                box.erase(box.begin() + i);
                return;
            }
        }
    }
}

//Metoda za sortiranje po izboru

void Student::sortStudents(vector<Student>& box){
    
    auto poImenu = [](const Student & a, const Student & b) -> bool{ return a.ime < b.ime;};
    auto poPrezimenu = [](const Student & a, const Student & b) -> bool{ return a.prezime < b.prezime;};
    auto poJmbg = [](const Student & a, const Student & b) -> bool{ return a.jmbg < b.jmbg;};
    auto poIndeksu = [](const Student & a, const Student & b) -> bool{ return a.indeks < b.indeks;};
    auto poSmjeru = [](const Student & a, const Student & b) -> bool{ return a.smjer < b.smjer;};
    
    int s1 = 0;
    cout << "Sortiraj po:" << endl;
    cout << "1 : Imenu\n2 : Prezimenu\n3 : JMBG\n4 : Indeksu\n5 : Smjeru" << endl;
    cin >> s1;
    switch(s1){
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
            sort(box.begin(), box.end(), poIndeksu);
            break;
        case(5):
            sort(box.begin(), box.end(), poImenu);
            break;            
    }

}

//Kratki loader

void Student::loader(){
    cout << "\nUcitavam";
    for(int i = 0; i < 4; i++)
    {
        Sleep(0400);
        cout << " .";
    }
}

//Destruktor

Student::~Student() {

}

