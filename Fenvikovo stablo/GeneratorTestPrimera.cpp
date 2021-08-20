#include "GeneratorTestPrimera.h"
#include "Random.h"
#include "operacija.h"
#include <fstream>
void GeneratorTestPrimera::generisi_ulaz(int velicina)
{
	std::ofstream fout;
	fout.open(fajl);
	fout << velicina << std::endl;

	for (int i = 0; i < velicina; i++)
	{
		int indeks = Random::uniform(1, N);
		Operacija operacija;
		if (Random::do_jedan() <= verovatnoca_operacije_azuriranja)
		{
			operacija = AZURIRANJE;
			int dodatak = Random::uniform(1, 100);
			fout << operacija << " " << indeks << " " << dodatak<<std::endl;
		}
		else
		{
			operacija = KUMULATIVNA_SUMA;
			fout << operacija << " " << indeks << std::endl;
		}
	}
	fout.close();
}