#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<vector>
#include"osoba.h"

using namespace std;

class Student : public Osoba 
{
private:

    string indeks, smjer, semestar;
    /*int ocjena1, ocjena2, ocjena3, ocjena4, ocjena5;*/
    
public:

    Student() {
        indeks = " ";
        smjer = " ";
        semestar = " ";
        /*ocjena1 = 0;
        ocjena2 = 0;
        ocjena3 = 0;
        ocjena4 = 0;
        ocjena5 = 0;*/
    }
    virtual ~Student();

    void inputInfo(vector<Student>& box);
    void outputInfo(vector<Student>& box);
    void showInfo();
    void showAll(vector<Student>& box, vector<Student>::iterator& it);
    void editStudent(vector<Student>& boxSt);
    void saveFile(vector<Student>& boxSt);
    void deleteStudent(vector<Student>& box);
    void sortStudents(vector<Student>& box);
    void showSingle(vector<Student>& box, int& i);
    void loader();

    string getBrojIndeksa() {
        return indeks;
    }

    string getSmjer() {
        return smjer;
    }

    string getSemestar() {
        return semestar;
    }

    /*int getOcjena1() {
        return ocjena1;
    }

    int getOcjena2() {
        return ocjena2;
    }

    int getOcjena3() {
        return ocjena3;
    }

    int getOcjena4() {
        return ocjena4;
    }

    int getOcjena5() {
        return ocjena5;
    }*/

    void setBrojIndeksa(string A) {
        indeks = A;
    }

    void setSmjer(string s) {
        smjer = s;
    }

    void setSemestar(string s) {
        semestar = s;
    }

    /*void setOcjena1(int st_ocjena1) {
        ocjena1 = st_ocjena1;
    }

    void setOcjena2(int st_ocjena2) {
        ocjena2 = st_ocjena2;
    }

    void setOcjena3(int st_ocjena3) {
        ocjena3 = st_ocjena3;
    }

    void setOcjena4(int st_ocjena4) {
        ocjena4 = st_ocjena4;
    }

    void setOcjena5(int st_ocjena5) {
        ocjena5 = st_ocjena5;
    }*/

};

#endif /* STUDENT_H */
