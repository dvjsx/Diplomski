#include "Fenvik2D.h"
#include <iostream>

using namespace std;

int main()
{
	Fenvik2D fenvik(3, 3);
	int br = 0;
	for (int i = 1; i <= fenvik.getN(); i++)
	{
		for (int j = 1; j <= fenvik.getM(); j++)
		{
			fenvik.azuriraj(i,j,++br);
		}
	}
	for (int i = 1; i <= fenvik.getN(); i++)
	{
		for (int j = 1; j <= fenvik.getM(); j++)
		{
			cout << fenvik.kumulativna_suma(i, j) << " ";
		}
		cout << endl;
	}
	return 0;
}