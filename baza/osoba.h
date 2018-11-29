#ifndef OSOBA_H
#define OSOBA_H
#include<string>

using namespace std;

class Osoba
{
    protected:
        string ime;
        string prezime;
        string jmbg;
    public:
        Osoba() { ime = ""; prezime = " "; jmbg = " "; }; //default konstruktor
        Osoba(string i,string p) { ime = i; prezime = p; }; //konstruktor, 2. verzija
        Osoba(string i, string p, string j) {ime = i; prezime = p; jmbg = j;}; //konstruktor, 3. verzija

        string getIme() { return ime; } //inline metod
        string getPrezime() { return prezime; } //inline metod
        string getJmbg() { return jmbg; } //inline metod
        
        void setIme(string novoi) { ime = novoi; };
        void setPrezime(string novop) { prezime = novop; };
        void setJmbg(string novoj) { jmbg = novoj; };
};

#endif /* OSOBA_H */

