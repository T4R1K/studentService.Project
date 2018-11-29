#ifndef SEMESTAR_H
#define SEMESTAR_H

using namespace std;

class Semestar
{
	protected:
                string semestar;

	public:
        
            Semestar() { semestar = " ";}
		string getSemestar(){return semestar;}

		void setSemestar(string A){semestar = A;}

};


#endif /* SEMESTAR_H */

