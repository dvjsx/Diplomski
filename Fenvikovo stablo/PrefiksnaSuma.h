#ifndef PREFIKSNA_SUMA_H
#define PREFIKSNA_SUMA_H

#include "RacunanjeSumeIAzuriranje.h"
#include <vector>
class PrefiksnaSuma :
    public RacunanjeSumeIAzuriranje
{
private:
public:
    //konstruktori
    PrefiksnaSuma(int n) :RacunanjeSumeIAzuriranje(n) {}
    PrefiksnaSuma(std::vector<int> pocetni);
    //metode
    void azuriraj(int indeks, int dodatak);
    int kumulativna_suma(int indeks);

};

#endif // !PREFIKSNA_SUMA_H



