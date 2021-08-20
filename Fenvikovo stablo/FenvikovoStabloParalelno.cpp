#include "FenvikovoStabloParalelno.h"
#include <algorithm>
#include <iostream>




//konstruktor
FenvikovoStabloParalelno::FenvikovoStabloParalelno(std::vector<int> pocetni) :FenvikovoStabloParalelno(pocetni.size())
{
	int indeks = 1;
	for (int vred : pocetni)
	{
		azuriraj(indeks, vred);
		indeks++;
	}
}

//pomocna metode
int FenvikovoStabloParalelno::najnizi_znacajni_bit(int broj)
{
	return broj & (-broj);
}

//glavne metode
void FenvikovoStabloParalelno::azuriraj(int indeks, int dodatak)
{
	while (indeks <= n)
	{
		v[indeks] += dodatak;
		indeks += najnizi_znacajni_bit(indeks);
	}
}
void FenvikovoStabloParalelno::azuriraj_paralelno(int indeks, int dodatak)
{
	while (indeks <= n)
	{
		mutexi_elemenata[indeks].lock();
			v[indeks] += dodatak;
		mutexi_elemenata[indeks].unlock();
		indeks += najnizi_znacajni_bit(indeks);
	}
}
int FenvikovoStabloParalelno::kumulativna_suma(int indeks)
{
	int z = 0;
	while (indeks > 0)
	{
		z += v[indeks];
		indeks -= najnizi_znacajni_bit(indeks);
	}
	return z;
}
void FenvikovoStabloParalelno::kumulativna_suma_paralelno(int indeks,int &suma)
{
	suma = 0;
	while (indeks > 0)
	{
		mutexi_elemenata[indeks].lock();
			suma += v[indeks];
		mutexi_elemenata[indeks].unlock();
		indeks -= najnizi_znacajni_bit(indeks);
	}
}

