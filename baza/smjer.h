#ifndef SMJER_H
#define SMJER_H
#include<string>
#include<vector>

using namespace std;

class Smjer
{
	protected:
            string naziv;
            string skracenica;
            string opis;
            
        public:
            Smjer() { naziv= " ";}
            string getNaziv(){return naziv;}
            void setNaziv(string A){naziv = A;}

};



#endif /* SMJER_H */

