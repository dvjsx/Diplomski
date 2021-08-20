#include "Fenvik2D.h"

Fenvik2D::Fenvik2D(int n, int m):N(n),M(m)
{
	v.resize(N + 1);
	for (auto& red : v)
	{
		red.resize(M + 1);
		for (int& el : red)
		{
			el = 0;
		}
	}
}

Fenvik2D::Fenvik2D(std::vector<std::vector<int>> pocetni):Fenvik2D(pocetni.size(),pocetni[0].size())
{
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			azuriraj(i, j, pocetni[i][j]);
		}
	}
}

void Fenvik2D::azuriraj(int i, int j,int dodatak)
{
	while (i <= N)
	{
		int pomj = j;
		while (pomj <= M)
		{
			v[i][pomj] += dodatak;
			pomj += najmanji_znacajni_bit(pomj);
		}
		i += najmanji_znacajni_bit(i);
	}
}
int Fenvik2D::kumulativna_suma(int i, int j)
{
	int z = 0;
	while (i > 0)
	{
		int pomj = j;
		while (pomj > 0)
		{
			z+=v[i][pomj];
			pomj -= najmanji_znacajni_bit(pomj);
		}
		i -= najmanji_znacajni_bit(i);
	}
	return z;
}

