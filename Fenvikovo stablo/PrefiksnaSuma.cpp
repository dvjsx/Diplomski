#include "PrefiksnaSuma.h"

PrefiksnaSuma::PrefiksnaSuma(std::vector<int> pocetni) :PrefiksnaSuma(pocetni.size())
{
	int indeks = 1;
	for (int vred : pocetni)
	{
		azuriraj(indeks, vred);
		indeks++;
	}
}

void PrefiksnaSuma::azuriraj(int indeks, int dodatak)
{
	for (int i = indeks; i <= n; i++)
		v[i] += dodatak;
}
int PrefiksnaSuma::kumulativna_suma(int indeks)
{
	return v[indeks];
}