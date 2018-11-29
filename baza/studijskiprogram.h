#ifndef STUDIJSKI_PROGRAM_H
#define STUDIJSKI_PROGRAM_H


#include<string>
#include<vector>

using namespace std;

class Studijski_program 
{
private:

    string naziv;
    string skracenica;

public:

    Studijski_program() {
        naziv = " ";
        skracenica = " ";
    }
    virtual ~Studijski_program();

    void inputInfo(vector<Studijski_program>& box);
    void outputInfo(vector<Studijski_program>& box);
    void showInfo();
    void showAll(vector<Studijski_program>& box, vector<Studijski_program>::iterator& it);
    void showSingle(vector<Studijski_program>& box, int& i);
    void editStudijski_program(vector<Studijski_program>& boxSt);
    void saveFile(vector<Studijski_program>& boxSt);
    void deleteStudijski_program(vector<Studijski_program>& box);
    void sortStudijski(vector<Studijski_program>& box);
    void loader();

    string getNaziv() {
        return naziv;
    }

    string getSkracenica() {
        return skracenica;
    }

    void setNaziv(string A) {
        naziv = A;
    }

    void setSkracenica(string A) {
        skracenica = A;
    }

};

#endif /* STUDIJSKI_PROGRAM_H */

