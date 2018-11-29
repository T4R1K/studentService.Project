#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <Windows.h>
#include "predmet.h"

using namespace std;

//Metoda za unos podataka od strane korisnika

void Predmet::inputInfo(vector<Predmet>& box) {
    Predmet *pr1;
    pr1 = new Predmet;
    cin.ignore();
    
    ponovi:
    cout << "Upisite kljuc predmeta:" << endl;
    getline(cin, key);
    if (key.size() == 2) {pr1->setKey(key);} else {cout << "Nevazeci unos, pokusajte ponovo!\n"; loader(); cout << endl << endl; goto ponovi;}
    
    cout << "Upisite naziv predmeta:" << endl;
    getline(cin, naziv);
    pr1->setPredmet(naziv);
    
    cout << "Upisite smjer za predmet:" << endl;
    getline(cin, smjer);
    pr1->setSmjer(smjer);
    
    cout << "Upisite odsjek za predmet:" << endl;
    getline(cin, odsjek);
    pr1->setOdsjek(odsjek);
    
    cout << "Unesite semestar za predmet:" << endl;
    cin>>semestar;
    pr1->setSemestar(semestar);
    
    cout << "Unesite broj predavanja:" << endl;
    cin>>predavanja;
    pr1->setSemestar(predavanja);
    
    cout << "Unesite broj auditornih vjezbi:" << endl;
    cin>>auditV;
    pr1->setSemestar(auditV);
    
    cout << "Unesite broj labaratorijskih vjezbi:" << endl;
    cin>>labV;
    pr1->setSemestar(labV);
    
    cout << "Unesite broj ECTS kredita:" << endl;
    cin>>ects;
    pr1->setSemestar(ects);
    
    cout << "Unesite broj ciklusa:" << endl;
    cin>>ciklus;
    pr1->setSemestar(ciklus);

    box.push_back(*pr1);
}

//Metoda za ucitavanje podataka iz datoteke u vektor

void Predmet::outputInfo(vector<Predmet>& box) {
    string temp;
    int br = 0;
    Predmet *pre1;
    pre1 = new Predmet;

    ifstream predmetdat("predmet.dat", ios::out);
    if (predmetdat.eof())
        cout << "Prazan fajl";
    else if (predmetdat.is_open()) {
        while (!predmetdat.eof()) {

            getline(predmetdat, temp, '#');
            pre1->setKey(temp);

            getline(predmetdat, temp, '#');
            pre1->setPredmet(temp);

            getline(predmetdat, temp, '#');
            pre1->setSmjer(temp);

            getline(predmetdat, temp, '#');
            pre1->setOdsjek(temp);

            getline(predmetdat, temp, '#');
            stringstream semestar(temp);
            semestar >> br;
            pre1->setSemestar(br);

            getline(predmetdat, temp, '#');
            stringstream predavanja(temp);
            predavanja >> br;
            pre1->setPredavanja(br);

            getline(predmetdat, temp, '#');
            stringstream auditV(temp);
            auditV >> br;
            pre1->setAuditV(br);

            getline(predmetdat, temp, '#');
            stringstream labV(temp);
            labV >> br;
            pre1->setLabV(br);

            getline(predmetdat, temp, '#');
            stringstream ects(temp);
            ects >> br;
            pre1->setEcts(br);

            getline(predmetdat, temp, '#');
            stringstream ciklus(temp);
            ciklus >> br;
            pre1->setCiklus(br);
            box.push_back(*pre1);
        }
        box.pop_back(); 
        predmetdat.close();
    }

    //cout << "Inicijalno ucitavanje predmeta uspjelo!\n" << endl;
    //cout << string(80, '*') << endl;
}
// Metoda za format ispisa podataka

void Predmet::showInfo() {
    
    cout << " " << setw(3) << key << setw(48) << naziv << setw(3) << smjer << setw(3) << odsjek << setw(3) << semestar << setw(3) << 
            predavanja << setw(3) << auditV << setw(3) << labV << setw(3) << ects << setw(3) << ciklus << endl;
}

//Metoda za ispis svih podataka iz vektora

void Predmet::showAll(vector<Predmet>& box, vector<Predmet>::iterator& it) {

    cout << left << " " << setw(3) << "#K" << setw(48) << "Predmet:" << setw(3) << "SM" << setw(3) << "OD" << setw(3) << "#S" 
            << setw(3) << "#P" << setw(3) << "AV" << setw(3) << "LV" << setw(3) << "EC" << setw(3) << "#C" << endl << endl;
    for (it = box.begin(); it != box.end(); ++it) {
        it->showInfo();
    }
    cout << "\n#K-Kljuc SM-Smjer OD-Odsjek #S-Semestar #P-Predavanja AV/LV-Tip vjezbe #C-Ciklus" << endl;
    cout << string(80, '*') << endl;
}

// Metoda za ispis jednog podatka u pretrazi

void Predmet::showSingle(vector<Predmet>& box, int& i)
{   
    cout << left << " " << setw(3) << "#K" << setw(48) << "Predmet:" << setw(3) << "SM" << setw(3) << "OD" << setw(3) << "#S" 
            << setw(3) << "#P" << setw(3) << "AV" << setw(3) << "LV" << setw(3) << "EC" << setw(3) << "#C" << endl << endl;
    
    cout << " " << setw(3) << box.at(i).key << setw(48) << box.at(i).naziv << setw(3) << box.at(i).smjer << setw(3) << box.at(i).odsjek << setw(3) << box.at(i).semestar << setw(3) << 
            box.at(i).predavanja << setw(3) << box.at(i).auditV << setw(3) << box.at(i).labV << setw(3) << box.at(i).ects << setw(3) << box.at(i).ciklus << endl << endl;
}

// Metoda za editovanje podataka unutar vektora prema odabiru

void Predmet::editPredmet(vector<Predmet>& box) {
    
    string k, edit, option;
    //int option;
    //cin.ignore();
    cout << "Unesite kljuc za editovanje podataka: " << endl;
    cin >> k;
    for (int i = 0; i < box.size(); i++) {
        /*if(box.at(i).key != k){            
            cout << "Nema ga!" << endl; 
            loader();
            break;
        }*/
        if (box.at(i).key == k) {
            
            int m2 = 0;
            system("CLS");
            cout << "\nOdaberite opciju koju zelite mijenjati za clana:\n\n";
            showSingle(box, i);
            
            cout << " 1 : Kljuc:\n";
            cout << " 2 : Naziv:\n";
            cout << " 3 : Smjer:\n";
            cout << " 4 : Odsjek:\n";
            cout << " 5 : Semestar\n";
            cout << " 6 : Broj predavanja:\n";
            cout << " 7 : Broj auditornih vjezbi:\n";
            cout << " 8 : Broj labaratorijskih vjezbi:\n";
            cout << " 9 : Broj ECTS kredita:\n";
            cout << "10 : Ciklus:\n";
            cout << "11 : IZLAZ\n";

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
                    if (option.size() <= 35) {box.at(i).naziv = option;} else cout << "Predug naziv, skratite i pokusajte ponovo!\n"; loader(); break;
                    break;
                    
                case (3): 
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> option;
                    box.at(i).smjer = option;
                    break;
                    
                case (4): 
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> option;
                    box.at(i).odsjek = option;
                    break;
                    
                case (5): 
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> semestar;
                    box.at(i).setSemestar(semestar);
                    break;
                    
                case (6): 
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> predavanja;
                    box.at(i).setPredavanja(predavanja);
                    break;
                    
                case (7): 
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> auditV;
                    box.at(i).setAuditV(auditV);
                    break;
                    
                case (8):
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> labV;
                    box.at(i).setLabV(labV);
                    break;
                    
                case (9): 
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> ects;
                    box.at(i).setEcts(ects);
                    break;
                    
                case (10): 
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> ciklus;
                    box.at(i).setCiklus(ciklus);
                    break;
                case(11): 
                    break;
            }           
        }
    }   
}

// Metoda za ispis podataka iz vektora u datoteku

void Predmet::saveFile(vector<Predmet>& box) {
    
    ofstream output("predmet.dat", ios::out | ios::trunc);
    for (int i = 0; i < box.size(); i++) {
        output << box[i].key << '#' << box[i].naziv << '#' << box[i].smjer << '#' << box[i].odsjek << '#' << box[i].semestar << '#'
                << box[i].predavanja << '#' << box[i].auditV << '#' << box[i].labV << '#' << box[i].ects << '#' << box[i].ciklus << '#' << "\n";
    }
}

// Metoda za brisanje profesora iz vektora

void Predmet::deletePredmet(vector<Predmet>& box) {

    string remove;
    cout << "Unesi kljuc predmeta za brisanje: " << endl;
    cin >> remove;

    for (int i = 0; i < box.size(); i++) {
        {
            if (box.at(i).key == remove) {
                box.erase(box.begin() + i);
                return;
            }
        }
    }
}

// Metoda za sortiranje po izboru

void Predmet::sortPredmets(vector<Predmet>& box) {

    auto poKljucu = [](const Predmet & a, const Predmet & b) -> bool {
        return a.key < b.key;
    };
    auto poNazivu = [](const Predmet & a, const Predmet & b) -> bool {
        return a.naziv < b.naziv;
    };
    auto poSmjeru = [](const Predmet & a, const Predmet & b) -> bool {
        return a.smjer < b.smjer;
    };
    auto poOdsjeku = [](const Predmet & a, const Predmet & b) -> bool {
        return a.odsjek < b.odsjek;
    };
    auto poSemestru = [](const Predmet & a, const Predmet & b) -> bool {
        return a.semestar < b.semestar;
    };
    auto poPredavanju = [](const Predmet & a, const Predmet & b) -> bool {
        return a.predavanja < b.predavanja;
    };
    auto poAv = [](const Predmet & a, const Predmet & b) -> bool {
        return a.auditV < b.labV;
    };
    auto poLv = [](const Predmet & a, const Predmet & b) -> bool {
        return a.labV < b.labV;
    };
    auto poEcts = [](const Predmet & a, const Predmet & b) -> bool {
        return a.ects < b.ects;
    };
    auto poCiklusu = [](const Predmet & a, const Predmet & b) -> bool {
        return a.ciklus < b.ciklus;
    };

    int s1 = 0;
    cout << "Sortiraj po:" << endl;
    cout << " 1 : Kljucu\n 2 : Nazivu\n 3 : Smjeru\n 4 : Odsjeku\n 5 : Semestru\n 6 : Broju predavanja\n"
            " 7 : Broju Auditornih vjezbi\n 8 : Broju Labaratorijskih vjezbi\n 9 : ECTS Kreditu\n10 : Ciklusu\n" << endl;
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
            
        case(6):
        sort(box.begin(), box.end(), poPredavanju);
        break;
        
        case(7):
        sort(box.begin(), box.end(), poAv);
        break;
        
        case(8):
        sort(box.begin(), box.end(), poLv);
        break;
        
        case(9):
        sort(box.begin(), box.end(), poEcts);
        break;
        
        case(10):
        sort(box.begin(), box.end(), poCiklusu);
        break;
    }
}

//Kratki loader

void Predmet::loader(){
    cout << "\nUcitavam";
    for(int i = 0; i < 4; i++)
    {
        Sleep(0600);
        cout << " .";
    }
}

//Destruktor

Predmet::~Predmet() {

}