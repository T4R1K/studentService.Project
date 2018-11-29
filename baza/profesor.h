#ifndef PROFESOR_H
#define PROFESOR_H

#include<string>
#include<vector>
#include"predmet.h"

using namespace std;

class Profesor : public Osoba 
{
private:

    string pozicija, usmjerenje;

public:

    Profesor() {
        pozicija = " ";
        usmjerenje = " ";
    }
    virtual ~Profesor();

    void inputInfo(vector<Profesor>& box); //input sa tastature
    void outputInfo(vector<Profesor>& box); // ispis iz fajla i inputa sa tast
    void showInfo(); // ispis informacija za pojedinacnu osobu u kontejneru
    void showAll(vector<Profesor>& box, vector<Profesor>::iterator& it);
    void editProfesor(vector<Profesor>& boxSt);
    void saveFile(vector<Profesor>& boxSt);
    void deleteProfesor(vector<Profesor>& box);
    void sortProfesors(vector<Profesor>& box);
    void showSingle(vector<Profesor>& box, int& i);
    void loader();

    string getPozicija() {
        return pozicija;
    }

    string getPredmet() {
        return usmjerenje;
    }

    void setPozicija(string A) {
        pozicija = A;
    }

    void setPredmet(string A) {
        usmjerenje = A;
    }

};

#endif /* PROFESOR_H */

