#include <iostream>
#include <cstdlib>
#include <ctime>
#include <stdio.h>
using namespace std;

//TEST GIT-A TEST GIT-A

int main() {
	setlocale(LC_ALL,"");
	srand(time(NULL));
	int wygrane=0, przegrane=0, remisy=0, krupier_suma, gracz_suma, wyjscie=0, pomocnicza, wyjdz, wylosowana_karta, wybor, gracz_wynik, krupier_wynik;
	int karty[52];
	
	do {
		//"POTASOWANIE" TALII, WYCIĄGNIĘCIE PIERWSZYCH KART
		cout << "Rozpoczynamy nową rozgrywkę Blackjacka!" << endl;
		krupier_suma=0;
		gracz_suma=0;
		wyjscie=0;
		int karty[] = {2,2,2,2,3,3,3,3,4,4,4,4,5,5,5,5,6,6,6,6,7,7,7,7,8,8,8,8,9,9,9,9,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,10,11,11,11,11};
		cout << "Karty potasowane!" << endl;
		cout << "=======================================" << endl << endl;
		
		pomocnicza=rand()%51+1;
		wylosowana_karta=karty[pomocnicza];
		krupier_suma=krupier_suma+wylosowana_karta;
		karty[pomocnicza]=0;
		
		pomocnicza=rand()%51+1;
		wylosowana_karta=karty[pomocnicza];
		if(wylosowana_karta==0) {
			do {
				pomocnicza=rand()%51+1;
				wylosowana_karta=karty[pomocnicza];
			} while(wylosowana_karta==0);
		}
		gracz_suma=gracz_suma+wylosowana_karta;
		karty[pomocnicza]=0;
		
		//PĘTLA DOBIERANIA PRZEZ GRACZA
		do {
			cout << "Suma krupiera wynosi " << krupier_suma << "." << endl;
			cout << "Suma gracza wynosi " << gracz_suma << "." << endl << endl;
			cout << "Dobrać kartę? 1 na tak, 2 na nie." << endl;
			cout << "Twój wybór: ";
			cin >> wybor;
			while(wybor<1||wybor>2) {
				cout << endl << "Niepoprawna opcja! Wybierz 1, aby dobrać kartę lub 2, aby przestać dobierać." << endl;
				cout << "Twój wybór: ";
				cin >> wybor;
			}
			cout << endl;
			
			//GRACZ DOBIERA KARTĘ
			if(wybor==1) {
				pomocnicza=rand()%51+1;
				wylosowana_karta=karty[pomocnicza];
				if(wylosowana_karta==0) {
					do {
						pomocnicza=rand()%51+1;
						wylosowana_karta=karty[pomocnicza];
					} while(wylosowana_karta==0);
				}
				gracz_suma=gracz_suma+wylosowana_karta;
				karty[pomocnicza]=0;
			}
			
			if(gracz_suma>21) {
				cout << "Suma gracza: " << gracz_suma << "." << endl;
				cout << "Przekroczenie progu 21 punktów." << endl;
				cout << "PRZEGRAŁEŚ!" << endl;
				przegrane++;
				goto zakonczenie;
			}
		} while (wybor!=2);
		
		//PODLICZENIE WYNIKU GRACZA
		gracz_wynik=21-gracz_suma;
		
		//PĘTLA DOBIERANIA KRUPIERA
		do {
			powtorka:
			pomocnicza=rand()%51+1;
			wylosowana_karta=karty[pomocnicza];
			if(wylosowana_karta==0) {
				do {
					pomocnicza=rand()%51+1;
					wylosowana_karta=karty[pomocnicza];
				} while(wylosowana_karta==0);
			}
			krupier_suma=krupier_suma+wylosowana_karta;
			karty[pomocnicza]=0;
			cout << "Krupier dobiera kartę!" << endl;
			cout << "Suma krupiera: " << krupier_suma << endl << endl;
			
			if(krupier_suma>21) {
				cout << "Krupier przekroczył 21." << endl;
				cout << "WYGRAŁEŚ!" << endl;
				wygrane++;
				goto zakonczenie;
			} else if(krupier_suma==gracz_suma&&krupier_suma==21) {
				cout << "Remis! Gracz i krupier mają po 21 punktów!" << endl;
				remisy++;
				goto zakonczenie;
			} else {
				krupier_wynik=21-krupier_suma;
				if(krupier_wynik<gracz_wynik) {
					cout << "Suma gracza: " << gracz_suma << endl;
					cout << "Suma krupiera: " << krupier_suma << endl;
					cout << endl << "Krupier nie dobiera więcej kart, będąc bliżej wyniku 21 niż gracz." << endl;
					cout << "PRZEGRAŁEŚ!" << endl;
					przegrane++;
					goto zakonczenie;
				} else goto powtorka;
			}
		} while(wyjdz==0);
		
		//MENU KOŃCOWE
		zakonczenie:
		cout << endl << "Rozpocząć nową rozgrywkę? 1 na tak, 2 na nie." << endl;
		cout << "Twój wybór: ";
		cin >> wybor;
		cout << endl;
		while(wybor<1||wybor>2) {
			cout << "Nieprawidłowy wybór!" << endl;
			cout << "Rozpocząć nową rozgrywkę? 1 na tak, 2 na nie." << endl;
			cout << "Twój wybór: ";
			cin >> wybor;
		}
		if(wybor==2) {
			cout << endl << "WYNIKI KOŃCOWE:" << endl;
			cout << "===============" << endl;
			cout << "Wygrane: " << wygrane << endl;
			cout << "Przegrane: " << przegrane << endl;
			cout << "Remisy: " << remisy << endl << endl;
			wyjscie=1;
		}
		
	} while(wyjscie==0);
	
	return 0;
}
