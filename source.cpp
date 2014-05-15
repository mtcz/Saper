//wersja 0.2B
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
	pole *plansza[40][40];

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
	void drukujplansze(int xzaznaczonej, int yzaznaczonej){
		clrscr();
		textcolor(10);
		for (int i = 0; i < x+2; i++)
		{
			cout << '=';
		}
		cout << endl;
		for (int i = 0; i < y; i++)
		{
			cout << '|';
			for (int j = 0; j < x; j++)
			{
				if (xzaznaczonej==i && yzaznaczonej==j)
				{
					textcolor(4);
				}
				if(plansza[i][j]->odkryty==1) cout << plansza[i][j]->znak;
				else cout << '#';
				textcolor(10);
			}

			cout << '|';
			cout << endl;
		}
		for (int i = 0; i < x+2; i++)
		{
			cout << '=';
		}
	}
	void rozlozminy(int miny){
		int xminy = 0;
		int yminy = 0;
		for (int i = 0; i < miny; i++)
		{
			do
			{
				xminy = rand() % (y);
				yminy = rand() % (x);

			} while (plansza[xminy][yminy]->znak == '*');


			plansza[xminy][yminy]->znak = '*';
		}
	}
	void zanumerujplansze(){
		int numer;

		cout << endl;
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
	void steruj(){
		int xzaznaczonej = 0;
		int yzaznaczonej = 0;
		while (true)
		{
			if (GetAsyncKeyState(VK_RIGHT)) {
				yzaznaczonej++;
				drukujplansze(xzaznaczonej, yzaznaczonej);
			}
			if (GetAsyncKeyState(VK_LEFT)) {
				yzaznaczonej--;
				drukujplansze(xzaznaczonej, yzaznaczonej);
			}
			if (GetAsyncKeyState(VK_UP)) {
				xzaznaczonej--;
				drukujplansze(xzaznaczonej, yzaznaczonej);
			}
			if (GetAsyncKeyState(VK_DOWN)) {
				xzaznaczonej++;
				drukujplansze(xzaznaczonej, yzaznaczonej);
			}
			if (GetAsyncKeyState(VK_LSHIFT)) {
				plansza[xzaznaczonej][yzaznaczonej]->odkryty = 1;
				drukujplansze(xzaznaczonej, yzaznaczonej);
			}
			Sleep(200);
		}
	}

};

int main(){
	srand(time(NULL));
	int wybor;
	cout << "Wybierz poziom trudnosci: \n [1]-Latwy(9x9 10 min)\n [2]-Sredni(16x16 40 min)\n [3]-Trudny(30x16 99 min)\n [4]-Wlasny";
	cin >> wybor;
	gra *nowagra = new gra;
	switch (wybor)
	{
	case 1: {
				clrscr();
				nowagra->x = 9;
				nowagra->y = 9;
				nowagra->z = 10;
				nowagra->tworzplansze(9, 9, 10);
				nowagra->rozlozminy(10);
				
				break;
	}
	case 2: {
				clrscr();
				
				nowagra->x = 16;
				nowagra->y = 16;
				nowagra->z = 40;
				nowagra->tworzplansze(16, 16, 40);
				nowagra->rozlozminy(40);
	
				break;
	}
	case 3: {
				clrscr();
				nowagra->x = 30;
				nowagra->y = 16;
				nowagra->z = 99;
				nowagra->tworzplansze(30, 16, 99);
				nowagra->rozlozminy(99);
	
				break;
	}
	case 4: {
				clrscr();
				cout << "Ta opcja bedzie dostepna w nastepnych wersjach gry";
				break;

	}
	}
	nowagra->zanumerujplansze();
	nowagra->drukujplansze(0, 0);
	nowagra->steruj();


	cin.get();
	cin.get();
	return 0;
}