#ifndef GENERATOR_TEST_PRIMERA
#define GENERATOR_TEST_PRIMERA
#include <string>
class GeneratorTestPrimera
{
private:
	std::string fajl;
	int N;
	double verovatnoca_operacije_azuriranja;
public:
	GeneratorTestPrimera(std::string f,double p,int n):fajl(f),verovatnoca_operacije_azuriranja(p),N(n){}
	void generisi_ulaz(int velicina);
};

#endif // !GENERATOR_TEST_PRIMERA



