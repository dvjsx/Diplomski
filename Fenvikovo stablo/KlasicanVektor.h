#ifndef KLASICAN_VEKTOR_INCLUDE
#define KLASICAN_VEKTOR_INCLUDE

#include <vector>
#include "RacunanjeSumeIAzuriranje.h"

class KlasicanVektor:public RacunanjeSumeIAzuriranje
{
private:

public:
	//konstruktori
	KlasicanVektor(int velicina) :RacunanjeSumeIAzuriranje(velicina) {}
	KlasicanVektor(std::vector<int> pocetni);
	//metode
	void azuriraj(int indeks, int dodatak);
	int kumulativna_suma(int indeks);
};

#endif // !1



