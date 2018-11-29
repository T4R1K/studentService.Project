#ifndef PREDMET_H
#define PREDMET_H

#include<string>
#include<vector>

using namespace std;

class Predmet
{
        private: 
            
            string key, naziv, smjer, odsjek;
            int semestar, auditV, labV, ects, predavanja, ciklus;
                        
        public:
            
            Predmet(){key = " "; naziv = " "; smjer = " "; odsjek = " "; semestar = 0; predavanja = 0; auditV = 0; labV = 0; ects = 0; ciklus = 0;}
            virtual ~Predmet();
            
            void inputInfo(vector<Predmet>& box);
            void outputInfo(vector<Predmet>& box);
            void showInfo();
            void showAll(vector<Predmet>& box, vector<Predmet>::iterator& it);
            void editPredmet(vector<Predmet>& boxSt);
            void saveFile(vector<Predmet>& boxSt);
            void deletePredmet(vector<Predmet>& box);
            void sortPredmets(vector<Predmet>& box);
            void showSingle(vector<Predmet>& box, int& i);
            void loader();
            
            string getKey(){return key;}
            string getPredmet(){return naziv;}
            string getSmjer(){return smjer;}
            string getOdsjek(){return odsjek;}
            
            int getSemestar(){return semestar;}            
            int getPredavanja(){return predavanja;}
            int getAuditV(){return auditV;}
            int getLabV(){return labV;}
            int getEcts(){return ects;} 
            int getCiklus(){return ciklus;}
            
            
            void setKey(string K){key = K;}
            void setPredmet(string P){naziv = P;}
            void setSmjer(string S){smjer = S;}
            void setOdsjek(string O){odsjek = O;}
            
            int setSemestar(int S){semestar = S;}      
            int setPredavanja(int P){predavanja = P;}
            int setAuditV(int A){auditV = A;}
            int setLabV(int L){labV = L;}
            int setEcts(int E){ects = E;}
            int setCiklus(int C){ciklus = C;}
            
};

#endif /* PREDMET_H */

