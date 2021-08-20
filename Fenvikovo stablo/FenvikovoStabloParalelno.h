#ifndef FENVIK_PARALELNO_H
#define FENVIK_PARALELNO_H
#include "RacunanjeSumeIAzuriranje.h"
#include <vector>
#include <iostream>
#include <mutex>
#include <atomic>

class FenvikovoStabloParalelno:public RacunanjeSumeIAzuriranje
{
private:
	//pomocna metoda
	std::vector<std::mutex> mutexi_elemenata;
	std::vector<std::atomic<int>> elementi;
	int najnizi_znacajni_bit(int broj);
	
public:
	//konstruktori
	FenvikovoStabloParalelno(int velicina) :RacunanjeSumeIAzuriranje(velicina),mutexi_elemenata(velicina+1),elementi(velicina+1) {  }
	FenvikovoStabloParalelno(std::vector<int> pocetni);
	//metode
	void azuriraj(int indeks, int dodatak);
	void azuriraj_paralelno(int indeks, int dodatak);
	void kumulativna_suma_paralelno(int indeks,int &suma);
	int kumulativna_suma(int indeks);
};

#endif


