#include "FenvikovoStablo.h"
#include "KlasicanVektor.h"
#include "PrefiksnaSuma.h"
#include "FenvikovoStabloParalelno.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <chrono>
#include <mutex>
#include <thread>
#include "GeneratorTestPrimera.h"
#include "Random.h"
#include "operacija.h"
#include "TestParalelno.h"


using namespace std;

void bezveze(int i,int j)
{

}
string append(string s, int i)
{
	return s +to_string(i);
}
string filename_ulaz(int velicina_strukture, int verovatnoca)
{
	return append(append("ulaz_", velicina_strukture) + "_", verovatnoca)+".txt";
}
string filename_izlaz(int velicina_strukture, int verovatnoca)
{
	return append(append("izlaz_", velicina_strukture) + "_", verovatnoca) + ".txt";
}
void izmeri_performanse(string ulaz,string izlaz,RacunanjeSumeIAzuriranje &struktura,bool novi_red=false)
{
	using namespace std::chrono;
	

	ifstream fin(ulaz, ifstream::in);
	double ukupno_vreme=0;
	int brop;
	fin >> brop;
	for (int i = 0; i < brop; i++)
	{
		int operacija;
		fin >> operacija;
		if (operacija == AZURIRANJE)
		{
			int indeks, dodatak;
			fin >> indeks >> dodatak;
			steady_clock::time_point pocetak = steady_clock::now();
				struktura.azuriraj(indeks, dodatak);
			steady_clock::time_point kraj = steady_clock::now();
			duration<double> vreme_operacije = duration_cast<duration<double>>(kraj - pocetak);
			ukupno_vreme += vreme_operacije.count();
		}
		else
		{
			
			int indeks;
			fin >> indeks;
			steady_clock::time_point pocetak = steady_clock::now();
				int suma=struktura.kumulativna_suma(indeks);
			steady_clock::time_point kraj = steady_clock::now();
			duration<double> vreme_operacije = duration_cast<duration<double>>(kraj - pocetak);
			ukupno_vreme += vreme_operacije.count();
		}
	}
	
	
	fin.close();
	ofstream fout(izlaz,ios::out|ios::app);
	fout <<ukupno_vreme;
	if (novi_red)
	{
		fout << endl;
	}
	else
	{
		fout << " ";
	}
	fout.close();
	//cout << "Proslo je: " << ukupno_vreme << endl;
}
double tabela[5][7][3];
void upisi_matricu()
{
	auto indeks_tabele = [](int p) {
		//p=10+i*20 , treba da vratimo i
		return (p-10)/20; 
	};
	auto red_tabele = [](int N)//nije najefikasnija implementacija, ali 7 operacija nije preterano skupo
	{
		int pr = 10;
		for (int i = 0; i < 7; i++, pr *= 10)
		{
			if (pr == N)
				return i;
		}
	};
	auto kolona_tabele = [](string naziv_strukture)
	{
		if (naziv_strukture == "fenvik")
			return 0;
		if (naziv_strukture == "klasicni")
			return 1;
		if (naziv_strukture == "prefiksna")
			return 2;
	};

	for (int i = 10; i <= (int)1e7; i *= 10)
	{
		for (int p = 10; p < 100; p += 20)
		{
			string fajl = filename_izlaz(i, p);
			ifstream fin(fajl);
			
			fin >> tabela[indeks_tabele(p)][red_tabele(i)][kolona_tabele("fenvik")] >> tabela[indeks_tabele(p)][red_tabele(i)][kolona_tabele("klasicni")] >>
				tabela[indeks_tabele(p)][red_tabele(i)][kolona_tabele("prefiksna")];
			fin.close();
		}
	}
	
}
void upisi_tabelu_u_fajl(string fajl)
{
	ofstream fout(fajl);
	fout << "    " << "Fenvik Klasicni pristup  Pristup po kumulativnim sumama" << endl;
	for (int i = 0; i < 5; i++)
	{
		fout << "Verovatnoca azuriranja: " << 10 + 20 * i << endl;

		for (int j = 0,velicina=10; j < 7; j++,velicina*=10)
		{
			fout << "N=" << velicina << ": ";
			for (int k = 0; k < 3; k++)
			{
				fout << tabela[i][j][k] << " ";
			}
			fout << endl;
		}
	}
	fout.close();
}
int main()
{
	
	vector<int> v1({ 1,2,3,4,5 });
	vector<int> v2({ 2,1,1,3,2,3,4,5,6,7,8,9 });
	FenvikovoStablo fenwick1(v1),fenwick2(v2);
	KlasicanVektor klasicni1(v1), klasicni2(v2);
	PrefiksnaSuma prefiksni1(v1), prefiksni2(v2);



	/*for (int i = 1; i <= fenwick1.size(); i++)
	{
		cout << fenwick1.kumulativna_suma(i) <<" "<<prefiksni1.kumulativna_suma(i)<<" "<<klasicni1.kumulativna_suma(i)<< "\n";
	}
	cout << "\n\n\n";
	for (int i = 1; i <= fenwick2.size(); i++)
	{
		cout << fenwick2.kumulativna_suma(i) << " " << prefiksni2.kumulativna_suma(i) << " " << klasicni2.kumulativna_suma(i) << "\n";
	}*/
	//FenvikovoStabloParalelno fenvik_par(5);
	
	const int BROJ_OPERACIJA = 1000000;
	const int BROJ_OPERACIJA2 = 10000000;
	
	/*for (int i = 10; i <= (int)1e7; i *= 10)
	{
		GeneratorTestPrimera generator_50(filename_ulaz(i,50), 0.5, i);
		GeneratorTestPrimera generator_70(filename_ulaz(i, 70), 0.7, i);
		GeneratorTestPrimera generator_30(filename_ulaz(i, 30), 0.3, i);
		GeneratorTestPrimera generator_90(filename_ulaz(i, 90), 0.9, i);
		GeneratorTestPrimera generator_10(filename_ulaz(i, 10), 0.1, i);
		generator_50.generisi_ulaz(BROJ_OPERACIJA);
		generator_70.generisi_ulaz(BROJ_OPERACIJA);
		generator_30.generisi_ulaz(BROJ_OPERACIJA);
		generator_90.generisi_ulaz(BROJ_OPERACIJA);
		generator_10.generisi_ulaz(BROJ_OPERACIJA);
	}*/

	/*for (int i = 10; i <= (int)1e7; i *= 10)
	{
		if (i < (int)1e7)
			continue;
		KlasicanVektor klasicni(i);
		PrefiksnaSuma prefiksna(i);
		FenvikovoStablo fenvik(i);
		for (int p =10;p<100;p+=20)
		{
			if (p < 70)
				continue;
			string ulaz = filename_ulaz(i, p);
			string izlaz = filename_izlaz(i, p);
			izmeri_performanse(ulaz, izlaz, fenvik);
			izmeri_performanse(ulaz, izlaz, klasicni);
			izmeri_performanse(ulaz, izlaz, prefiksna,true);
		}
	}*/
	
	
	/*izmeri_performanse(filename_ulaz(100000, 10), "ggk0", fenvik);
	izmeri_performanse(filename_ulaz(100000, 10), "ggk0", klasicni);
	izmeri_performanse(filename_ulaz(100000, 10), "ggk0", prefiksna,true);*/
	
	/*upisi_matricu();
	upisi_tabelu_u_fajl("tabela_performansi.txt");*/

	int velicina_stabla = 1000000;
	TestParalelno test_paralelno(1000000,100000,0.7);
	test_paralelno.main();
	

	return 0;
}
 