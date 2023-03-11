// POP_2021_01_19_projekt_2_Koitalla_Agnieszka_EiT_3_184933.cpp // Code::Blocks 17.12 // GNU GCC Compiler

#include <iostream>

#include <fstream>

using namespace std;
int wielkosc = 16;

void szyfrowanie() {
  string plikW;
  char tab[wielkosc];

  cout << " Podaj nazwe pliku, ktory chcesz zaszyfrowac: ";
  cin >> plikW;

  int klucz, wyjscie, wejscie, i;
  char krzak;
  int wektor_i = 170;

  ifstream WczytywanyPlik;
  WczytywanyPlik.open(plikW);

  ofstream plikZapisywany("szyfr.txt");

  int licznik = 0;
  cout << "Poczatkowy stan licznika: ";
  cin >> licznik;

  if (licznik < 0 || licznik > 255) {
    cout << "Licznik musi byc z przedzialu od 0 do 255!" << endl;
  } else {
    if (WczytywanyPlik.good() == false) {
      cout << "Nie udalo sie otworzyc pliku";
    } else {
      while (!WczytywanyPlik.eof()) {
        for (i = 0; i < wielkosc; i++) {
          tab[i] = WczytywanyPlik.get();

          if (i < wielkosc && !WczytywanyPlik.eof()) {


            klucz = wektor_i ^ licznik;
            licznik++;
            licznik = licznik%256;
            wyjscie = tab[i] ^ klucz;
            wektor_i = wyjscie;

            krzak = static_cast < char > (wyjscie);

         cout << tab[i] << "  " << wyjscie << "  " << krzak  << endl;



            plikZapisywany << krzak;
          }
        }

      }

      plikZapisywany.close();
    }
  }

  cout << endl;
}

void deszyfrowanie() {
  int klucz, wyjscie, i;
  char krzak;
  int wektor_i = 170;
  char tab[wielkosc];
  int licznik = 0;

  ifstream WczytywanyPlik;
  ofstream plikZapisywany("deszyfr.txt");
  WczytywanyPlik.open("szyfr.txt");
  cout << "Poczatkowy stan licznika: ";
  cin >> licznik;

  if (licznik < 0 || licznik > 255) {
    cout << "Licznik musi byc z przedzialu od 0 do 255!" << endl;
  } else {
    if (WczytywanyPlik.good() == false) {
      cout << "Nie udalo sie otworzyc pliku";
    } else {
      while (!WczytywanyPlik.eof()) {
        for (i = 0; i < wielkosc; i++) {
          tab[i] = WczytywanyPlik.get();

          if (i < wielkosc && !WczytywanyPlik.eof()) {


            klucz = wektor_i ^ licznik;
            licznik++;
            licznik = licznik%256;
            wektor_i = tab[i];
            wyjscie = tab[i] ^ klucz;

            krzak = static_cast < char > (wyjscie);

            cout << tab[i] << "  " << krzak << endl;

            plikZapisywany << krzak;
          }
        }
      }

      plikZapisywany.close();
    }
  }

  cout << endl;
}

int main() {
  setlocale(LC_CTYPE, "Polish");
  int wybor = 0;

  while (wybor != 5) {
    cout << "wybierz opcje" << endl;
    cout << "1 - szyfrowanie" << endl;
    cout << "2 - deszyfrowanie" << endl;
    cout << "5 - koniec" << endl;
    cin >> wybor;

    switch (wybor) {
    case 1:
      szyfrowanie();
      break;
    case 2:
      deszyfrowanie();
      break;

    case 5:
      break;
    }
  }

  return 0;
}
