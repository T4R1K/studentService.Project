#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include "osoba.h"
#include "student.h"
#include "profesor.h"
#include "smjer.h"
#include "ispit.h"
#include "predmet.h"
#include "semestar.h"
#include "studijskiprogram.h"
#include "usmjerenje.h"

using namespace std;


int main() {
    //Kontejner i iterator za studente
    vector<Student> boxSt;
    vector<Student>::iterator itSt;

    //Kontejner i iterator za profesore
    vector<Profesor> boxPr;
    vector<Profesor>::iterator itPr;

    //Kontejner i iterator za predmete
    vector<Predmet> boxPredmet;
    vector<Predmet>::iterator itPredmet;
    
    //Kontejner i iterator za ispite
    vector<Ispit> boxIspit;
    vector<Ispit>::iterator itIs;
    
    //Kontejner i iterator za studijske programe
    vector<Studijski_program> boxStudijski;
    vector<Studijski_program>::iterator itStudijski;
    
    //Kontejner i iterator za usmjerenje
    vector<Usmjerenje> boxUsmjerenje;
    vector<Usmjerenje>::iterator itUsmjerenje;

    Student s;
    s.outputInfo(boxSt);

    Profesor p;
    p.outputInfo(boxPr);

    Predmet c;
    c.outputInfo(boxPredmet); 

    Ispit i;
    i.outputInfo(boxIspit);

    Studijski_program sp;
    sp.outputInfo(boxStudijski);
    
    Usmjerenje us;
    us.outputInfo(boxUsmjerenje);
    

    int Meni = 0;
    int Meni2 = 0;
    int Meni3 = 0;
    int Meni4 = 0;
    int Meni5 = 0;

//Glavni meni i forma
    
Pocetak:
    cout << endl;
    cout << " " << string(50, '/') << endl;
    cout << " //                                              //" << endl;
    cout << " //    Studentska Sluzba | IPI Akademija 6.0     //" << endl;
    cout << " //                                              //" << endl;
    cout << " " << string(50, '/') << endl;
    cout << endl;
    cout << " Odaberite jednu od opcija:\n" << endl;
    cout << " 1 : Studenti\n"
            " 2 : Profesori\n"
            " 3 : Ispiti\n"
            " 4 : Predmeti\n"
            " 5 : Studijski Programi\n"
            " 6 : Usmjerenja\n"
            " 7 : Izlaz" << endl;
    
    cout << " ";
    cin >> Meni;

    switch (Meni) {
        
//Meni sa metodama za studente       
        
        case(1):
            system("CLS");
            cout << "\nUcitavam studente..." << endl << endl;
            s.showAll(boxSt, itSt);            
            
Studenti:

            cout << "1 : Povratak 2 : Promjena Studenta 3 : Dodaj Studenta 4 : Snimi Promjene"
                    "\n\n5 : Obrisi Studenta 6 : Sortiraj Studente" << endl;
            cin >> Meni2;
            switch (Meni2) {
                
                case(1):
                    //boxSt.clear();
                    system("CLS");
                    goto Pocetak;
                    
                case(2):
                    s.editStudent(boxSt);
                    system("CLS");
                    cout << "\nPromjene su azurirane!" << endl << endl;
                    s.showAll(boxSt, itSt);
                    goto Studenti;

                case(3):
                    s.inputInfo(boxSt);
                    system("CLS");
                    cout << "\nStudent je dodan, promjene su azurirane!" << endl << endl;
                    s.showAll(boxSt, itSt);
                    //boxSt.clear();
                    goto Studenti;

                case(4):
                    s.saveFile(boxSt);
                    system("CLS");
                    cout << "\nPromjene su snimljene!" << endl << endl;
                    s.showAll(boxSt, itSt);
                    //boxSt.clear();
                    goto Studenti;
                    
                case(5):
                    s.deleteStudent(boxSt);
                    system("CLS");
                    cout << "\nStudent je izbrisan!" << endl << endl;
                    s.showAll(boxSt, itSt);
                    goto Studenti;
                    
                case(6):
                    s.sortStudents(boxSt);
                    system("CLS");
                    cout << "\nStudenti su sortirani!" << endl << endl;
                    s.showAll(boxSt, itSt);
                    goto Studenti;

            }

//Meni sa metodama za profesore
            
        case(2):
            system("CLS");
            cout << "\nUcitavam profesore..." << endl << endl;
            p.showAll(boxPr, itPr);
            
Profesori:

            cout << "1 : Povratak 2 : Promjena Profesora 3 : Dodaj Profesora 4 : Snimi Promjene"
                    "\n\n5 : Obrisi Profesora 6 : Sortiraj Profesore" << endl;
            cin >> Meni3;
            switch (Meni3) {
                
                case(1):
                    system("CLS");
                    goto Pocetak;

                case(2):
                    p.editProfesor(boxPr);
                    system("CLS");
                    cout << "\nPromjene su azurirane!" << endl << endl;
                    p.showAll(boxPr, itPr);
                    goto Profesori;

                case(3):
                    p.inputInfo(boxPr);
                    system("CLS");
                    cout << "\nProfesor je dodan, promjene su azurirane!" << endl << endl;
                    p.showAll(boxPr, itPr);
                    goto Profesori;

                case(4):
                    p.saveFile(boxPr);
                    system("CLS");
                    cout << "\nPromjene su snimljene!" << endl << endl;
                    p.showAll(boxPr, itPr);
                    goto Profesori;
                    
                case(5):
                    p.deleteProfesor(boxPr);
                    system("CLS");
                    cout << "\n Profesor je izbrisan!" << endl << endl;
                    p.showAll(boxPr, itPr);
                    goto Profesori;

                case(6):
                    p.sortProfesors(boxPr);
                    system("CLS");
                    cout << "\nProfesori su sortirani!" << endl << endl;
                    p.showAll(boxPr, itPr);
                    goto Profesori;
            }

//Meni sa metodama za ispite  
            
        case(3):
            system("CLS");
            cout << "\nUcitavam ispite..." << endl << endl;
            i.showAll(boxIspit, itIs);          
            
Ispiti:     
            
            cout << "1 : Povratak 2 : Promjena Ispita 3 : Dodaj Ispit 4 : Snimi Promjene"
                    "\n\n5 : Obrisi Ispit 6 : Sortiraj Ispite" << endl;

            cin >> Meni3;
            switch (Meni3) {
                
                case(1):
                    system("CLS");
                    goto Pocetak;
                    
                case(2):
                    i.editIspit(boxIspit);
                    system("CLS");
                    cout << "\nPromjene su azurirane!" << endl << endl;
                    i.showAll(boxIspit, itIs);
                    goto Ispiti;

                case(3):
                    i.inputInfo(boxIspit);
                    system("CLS");
                    cout << "\nIspit je dodan, promjene su azurirane!" << endl << endl;
                    i.showAll(boxIspit, itIs);
                    goto Ispiti;
                    
                case(4):
                    i.saveFile(boxIspit);
                    system("CLS");
                    cout << "\nPromjene su snimljene!" << endl << endl;
                    i.showAll(boxIspit, itIs);
                    goto Ispiti;
                    
                case(5):
                    i.deleteIspit(boxIspit);
                    system("CLS");
                    cout << "\nIspit je izbrisan!" << endl << endl;
                    i.showAll(boxIspit, itIs);
                    goto Ispiti;
                    
                case(6):
                    i.sortIspit(boxIspit);
                    system("CLS");
                    cout << "\nIspiti su sortirani!" << endl << endl;
                    i.showAll(boxIspit, itIs);
                    goto Ispiti;

            }

//Meni sa metodama za predmete
            
        case(4):
            system("CLS");
            cout << "\nUcitavam predmete..." << endl << endl;
            c.showAll(boxPredmet, itPredmet);

Predmeti:

            cout << "1 : Povratak 2 : Promjena Predmeta 3 : Dodaj Predmet 4 : Snimi Promjene"
                    "\n\n5 : Obrisi Predmet 6 : Sortiraj Predmete" << endl;

            cin >> Meni4;
            switch (Meni4) {
                
                case(1):
                    system("CLS");
                    goto Pocetak;
                    
                case(2):
                    c.editPredmet(boxPredmet);
                    system("CLS");
                    cout << "\nPromjene su azurirane!" << endl << endl;
                    c.showAll(boxPredmet, itPredmet);
                    goto Predmeti;

                case(3):
                    //boxSt.clear();
                    c.inputInfo(boxPredmet);
                    system("CLS");
                    cout << "\nPredmet je dodan, promjene su azurirane!" << endl << endl;
                    c.showAll(boxPredmet, itPredmet);
                    goto Predmeti;

                    
                case(4):
                    c.saveFile(boxPredmet);
                    system("CLS");
                    cout << "\nPromjene su snimljene!" << endl << endl;
                    c.showAll(boxPredmet, itPredmet);
                    //boxSt.clear();
                    goto Predmeti;
                    
                case(5):
                    c.deletePredmet(boxPredmet);
                    system("CLS");
                    cout << "\nPredmet je izbrisan!" << endl << endl;
                    c.showAll(boxPredmet, itPredmet);
                    goto Studenti;
                    
                case(6):
                    c.sortPredmets(boxPredmet);
                    system("CLS");
                    cout << "\nPredmeti su sortirani!" << endl << endl;
                    c.showAll(boxPredmet, itPredmet);
                    goto Predmeti;

            }  

            
//Meni sa metodama za studijske programe       
        
        case(5):
            system("CLS");
            cout << "\nUcitavam studijske programe..." << endl << endl;
            sp.showAll(boxStudijski, itStudijski);            
            
Programi:

            cout << "1 : Povratak 2 : Promjena Programa 3 : Dodaj Program 4 : Snimi Promjene"
                    "\n\n5 : Obrisi Program 6 : Sortiraj Programe" << endl;
            cin >> Meni2;
            switch (Meni2) {
                
                case(1):
                    //boxSt.clear();
                    system("CLS");
                    goto Pocetak;
                    
                case(2):
                    sp.editStudijski_program(boxStudijski);
                    system("CLS");
                    cout << "\nPromjene su azurirane!" << endl << endl;
                    sp.showAll(boxStudijski, itStudijski);
                    goto Programi;

                case(3):
                    sp.inputInfo(boxStudijski);
                    system("CLS");
                    cout << "\nProgram je dodan, promjene su azurirane!" << endl << endl;
                    sp.showAll(boxStudijski, itStudijski);
                    //boxSt.clear();
                    goto Programi;

                case(4):
                    sp.saveFile(boxStudijski);
                    system("CLS");
                    cout << "\nPromjene su snimljene!" << endl << endl;
                    sp.showAll(boxStudijski, itStudijski);
                    //boxSt.clear();
                    goto Programi;
                    
                case(5):
                    sp.deleteStudijski_program(boxStudijski);
                    system("CLS");
                    cout << "\nProgram je izbrisan!" << endl << endl;
                    sp.showAll(boxStudijski, itStudijski);
                    goto Programi;
                    
                case(6):
                    sp.sortStudijski(boxStudijski);
                    system("CLS");
                    cout << "\nProgrami su sortirani!" << endl << endl;
                    sp.showAll(boxStudijski, itStudijski);
                    goto Programi;

            }        

//Meni sa metodama za usmjerenja  
        
        case(6):
            system("CLS");
            cout << "\nUcitavam usmjerenja..." << endl << endl;
            us.showAll(boxUsmjerenje, itUsmjerenje);            
            
Usmjerenja:

            cout << "1 : Povratak 2 : Promjena Usmjerenja 3 : Dodaj Usmjerenje 4 : Snimi Promjene"
                    "\n\n5 : Obrisi Usmjerenje 6 : Sortiraj Usmjerenja" << endl;
            cin >> Meni2;
            switch (Meni2) {
                
                case(1):
                    //boxSt.clear();
                    system("CLS");
                    goto Pocetak;
                    
                case(2):
                    us.editUsmjerenje(boxUsmjerenje);
                    system("CLS");
                    cout << "\nPromjene su azurirane!" << endl << endl;
                    us.showAll(boxUsmjerenje, itUsmjerenje);
                    goto Usmjerenja;

                case(3):
                    us.inputInfo(boxUsmjerenje);
                    system("CLS");
                    cout << "\nUsmjerenje je dodano, promjene su azurirane!" << endl << endl;
                    us.showAll(boxUsmjerenje, itUsmjerenje);
                    //boxSt.clear();
                    goto Usmjerenja;

                case(4):
                    us.saveFile(boxUsmjerenje);
                    system("CLS");
                    cout << "\nPromjene su snimljene!" << endl << endl;
                    us.showAll(boxUsmjerenje, itUsmjerenje);
                    //boxSt.clear();
                    goto Usmjerenja;
                    
                case(5):
                    us.deleteUsmjerenje(boxUsmjerenje);
                    system("CLS");
                    cout << "\nUsmjerenje je izbrisano!" << endl << endl;
                    us.showAll(boxUsmjerenje, itUsmjerenje);
                    goto Usmjerenja;
                    
                case(6):
                    us.sortUsmjerenja(boxUsmjerenje);
                    system("CLS");
                    cout << "\nUsmjerenja su sortirana!" << endl << endl;
                    us.showAll(boxUsmjerenje, itUsmjerenje);
                    goto Usmjerenja;

            }                    
            
//Zatvaranje programa
            
        case(7):
            goto kraj;
            
        default:
            kraj :
            cout << "\n\n Hvala vam na koristenju programa!\n\n"; 
                    cout << string(80, '*') << endl;
    }

};
