#include "KlasicanVektor.h"

//konstruktor

KlasicanVektor::KlasicanVektor(std::vector<int> pocetni) :KlasicanVektor(pocetni.size())
{
	int indeks = 1;
	for (int vred : pocetni)
	{
		azuriraj(indeks, vred);
		indeks++;
	}
}


//metode
void KlasicanVektor::azuriraj(int indeks,int dodatak)
{
	v[indeks] += dodatak;
}
int KlasicanVektor::kumulativna_suma(int indeks)
{
	int z = 0;
	for (int i = 1; i <= indeks; i++)
	{
		z += v[i];
	}
	return z;
}

