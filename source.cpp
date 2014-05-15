//wersja 0.1B
//Autorzy: Mateusz Czy¿ - 45746, Mateusz Serwan - 45837, Artur Kubok - 45787
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <athio.h>
#include <windows.h>

using namespace std;
class pole{
public:
	bool odkryty;
	char znak;
};
class gra{
public:
	int	x;		//szerokoœæ planszy
	int	y;		//wysokoœæ planszy
	int z;		//iloœæ min
	pole *plansza[30][30];

	void tworzplansze(int x, int y, int z){

		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				plansza[i][j] = new pole;
				plansza[i][j]->znak = '#';
				plansza[i][j]->odkryty = 0;
			}
		}
	}
	void drukujplansze(int x, int y){
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				cout << plansza[i][j]->znak;
			}
			cout << endl;
		}
	}
	void rozlozminy(int miny){
		int liczbamin = 0;
		int xminy = 0;
		int yminy = 0;
		for (int i = 0; i < miny; i++)
		{
			do
			{
				xminy = rand() % (x);
				yminy = rand() % (y);

			} while (plansza[xminy][yminy]->znak == '*');


			plansza[xminy][yminy]->znak = '*';
		}
	}
	void zanumerujplansze(){
		int numer;
		for (int i = 0; i < y; i++)
		{
			for (int j = 0; j < x; j++)
			{
				if (plansza[i][j]->znak != '*')
				{
					numer = 0;
					if (i>0 && j>0) if (plansza[i - 1][j - 1]->znak == '*') numer++;
					if (i > 0) if (plansza[i - 1][j]->znak == '*') numer++;
					if (i > 0 && j<x - 1) if (plansza[i - 1][j + 1]->znak == '*') numer++;
					if (j>0) if (plansza[i][j - 1]->znak == '*') numer++;
					if (j < x - 1) if (plansza[i][j + 1]->znak == '*') numer++;
					if (i<y - 1 && j>0) if (plansza[i + 1][j - 1]->znak == '*') numer++;
					if (i < y - 1) if (plansza[i + 1][j]->znak == '*') numer++;
					if (i < y - 1 && j < x - 1) if (plansza[i + 1][j + 1]->znak == '*') numer++;
					switch (numer)
					{

					case 0: plansza[i][j]->znak = ' '; break;
					case 1: plansza[i][j]->znak = '1'; break;
					case 2: plansza[i][j]->znak = '2'; break;
					case 3: plansza[i][j]->znak = '3'; break;
					case 4: plansza[i][j]->znak = '4'; break;
					case 5: plansza[i][j]->znak = '5'; break;
					case 6: plansza[i][j]->znak = '6'; break;
					case 7: plansza[i][j]->znak = '7'; break;
					case 8: plansza[i][j]->znak = '8'; break;
					}
				}



			}
		}

	}

};

int main(){
	srand(time(NULL));
	gra *ekspert = new gra;
	ekspert->x = 20;
	ekspert->y = 20;
	ekspert->z = 20;
	ekspert->tworzplansze(20, 20, 20);
	ekspert->rozlozminy(40);
	ekspert->zanumerujplansze();
	ekspert->drukujplansze(20, 20);



	cin.get();
	cin.get();
	return 0;
}