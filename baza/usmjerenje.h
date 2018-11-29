#ifndef ST_PROGRAM_H
#define ST_PROGRAM_H

#include <string>
#include <vector>

using namespace std;

class Usmjerenje 
{
private:

    string usmjerenje;
    string naziv;
    string st_program;

public:

    Usmjerenje() {
        usmjerenje = " ";
        naziv = " ";
        st_program = " ";
    }

    virtual ~Usmjerenje();

    void inputInfo(vector<Usmjerenje>& box);
    void outputInfo(vector<Usmjerenje>& box);
    void showInfo();
    void showAll(vector<Usmjerenje>& box, vector<Usmjerenje>::iterator& it);
    void showSingle(vector<Usmjerenje>& box, int& i);
    void editUsmjerenje(vector<Usmjerenje>& boxSt);
    void saveFile(vector<Usmjerenje>& boxSt);
    void deleteUsmjerenje(vector<Usmjerenje>& box);
    void sortUsmjerenja(vector<Usmjerenje>& box);
    void loader();

    string getNaziv() {
        return naziv;
    }

    string getUsmjerenje() {
        return usmjerenje;
    }

    string getStProgram() {
        return st_program;
    }

    void setNaziv(string A) {
        naziv = A;
    }

    void setUsmjerenje(string A) {
        usmjerenje = A;
    }

    void setStProgram(string A) {
        st_program = A;
    }

};

#endif /* ST_PROGRAM_H */

