#include "FenvikovoStablo.h"
#include <algorithm>
#include <iostream>
//pomocne metode



//konstruktor
FenvikovoStablo::FenvikovoStablo(std::vector<int> pocetni):FenvikovoStablo(pocetni.size())
{
	int indeks = 1;
	for (int vred : pocetni)
	{
		azuriraj(indeks,vred);
		indeks++;
	}
}

//pomocna metode
int FenvikovoStablo::najnizi_znacajni_bit(int broj)
{
	return broj & (-broj);
}

//glavne metode
void FenvikovoStablo::azuriraj(int indeks,int dodatak)
{
	while (indeks <=n)
	{
		v[indeks] += dodatak;
		indeks += najnizi_znacajni_bit(indeks);
	}
}
int FenvikovoStablo::kumulativna_suma(int indeks)
{
	int z = 0;
	while (indeks>0)
	{
		z += v[indeks];
		indeks -= najnizi_znacajni_bit(indeks);
	}
	return z;
} 

