#ifndef FENVIK_INCLUDE
#define FENVIK_INCLUDE

#include <vector>
#include "RacunanjeSumeIAzuriranje.h"

class FenvikovoStablo:public RacunanjeSumeIAzuriranje
{
private:
	//pomocna metoda
	int najnizi_znacajni_bit(int broj);
public:
	//konstruktori
	FenvikovoStablo(int velicina) :RacunanjeSumeIAzuriranje(velicina) {}
	FenvikovoStablo(std::vector<int> pocetni);
	//metode
	void azuriraj(int indeks, int dodatak);
	int kumulativna_suma(int indeks);

};

#endif 



