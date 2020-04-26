#include <stdio.h>
#include <conio.h>

#define abs(x) ((x >= 0) ?x:-x)

int Turunan(int N)
{
	int Hasil;
	N = N % 4;

	switch (N)
	{
	case 0:
		Hasil = 1; 
		break;
	case 1:
		Hasil = 0;
		break;
	case 2:
		Hasil = -1;
		break;
	case 3:
		Hasil = 0;
		break;
	default:
		break;
	}

	return Hasil;
}

double Cos(double X)
{
	double Pembilang, Penyebut, Hasil, Suku;
	double Galat;
	double N;

	Pembilang = Penyebut = 1;
	Galat = 0.00001;
	Hasil = 0.0;

	N = 0;

	do
	{
		if (Turunan(N) != 0) /* Untuk Mengurangi Perkalian Dengan 0 */
		{
			Suku = Turunan(N) * Pembilang / Penyebut;
			Hasil = Hasil + Suku;
		}

		N++;
		Pembilang = Pembilang * X;	/* Pangkat */
		Penyebut = Penyebut * N;	/* Faktorial */

	} while (abs(Suku) >= Galat);

	return Hasil;
}

void main(void) 
{
	const double PI = 3.14159265;

	printf("%8.4f\n", Cos(0));
	printf("%8.4f\n", Cos(PI / 6));
	printf("%8.4f\n", Cos(PI / 4));
	printf("%8.4f\n", Cos(PI / 2));
	printf("%8.4f\n", Cos(PI));

	_getch();
}