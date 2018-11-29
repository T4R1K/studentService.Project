#ifndef ISPIT_H
#define ISPIT_H
#include<string>
#include<vector>

using namespace std;

class Ispit 
{
private:
    string key, jmbg, br_indeksa, datum;
    int rezultat;

public:

    Ispit() {
        key = " ";
        jmbg = " ";
        br_indeksa = " ";
        datum = " ";
        rezultat = 0;
    }
    virtual ~Ispit();

    void inputInfo(vector<Ispit>& box); //input sa tastature
    void outputInfo(vector<Ispit>& box); // ispis iz fajla i inputa sa tast
    void showInfo(); // ispis informacija za pojedinacni ispit u kontejneru
    void showAll(vector<Ispit>& box, vector<Ispit>::iterator& it); //
    void showSingle(vector<Ispit>& box, int& i);
    void editIspit(vector<Ispit>& box);
    void saveFile(vector<Ispit>& box);
    void deleteIspit(vector<Ispit>& box);
    void sortIspit(vector<Ispit>& box);
    void loader();

    string getKey() {
        return key;
    }

    string getJmbg() {
        return jmbg;
    }

    string getBrIndeksa() {
        return br_indeksa;
    }

    string getDatum() {
        return datum;
    }

    int getRezultat() {
        return rezultat;
    }

    void setKey(string n) {
        key = n;
    }

    void setJmbg(string j) {
        jmbg = j;
    }

    void setBrIndeksa(string i) {
        br_indeksa = i;
    }

    void setDatum(string d) {
        datum = d;
    }

    void setRezultat(int r) {
        rezultat = r;
    }

};

#endif /* ISPIT_H */

