#include <iostream>

//napisz klase o nazwie samoch�d zadeklaruj w klasie 2 zmienne klasowe o nazwie ilo�� k� oraz kraj pochodzenia dodaj r�wnie� nast�puj�ce zmienne instancyjne marka model kolor rok produkcji
//dodaj prototypy o nazwie wy�wietl wszystkie dane ustaw wszystkie dane zdefiniuj te prototypy poza klas� dodaj strukture o nazwie dane techniczne z polami pojemno�� oraz d�ugo�� 
//utw�rz obiekt o nazwie auto 
//do zmiennej klasowej kraj pochodzenia przypisz polska, a do ilo�ci k� 4
//dodaj wska�nik o nazwie zsk ktory bedzie wskazywal nasz obiekt wykorzystaj wskaznik aby wskazac marke auta

using namespace std;

struct dane_techniczne{
	float pojemnosc, dlugosc;
};

class Samochod{
	public:
		static unsigned short int ilosc_kol;
		static string kraj_pochodzenia;
		string marka, model, kolor;
		unsigned short int rok_produkcji;
		void setData(string marka, string model, string kolor, unsigned short int rok_produkcji);
		void showData();
};

unsigned short int Samochod::ilosc_kol=4;
string Samochod::kraj_pochodzenia="Polska";

void Samochod::setData(string pMarka, string pModel, string pKolor, unsigned short int pRok_produkcji){
	marka=pMarka;
	model=pModel;
	kolor=pKolor;
	rok_produkcji=pRok_produkcji;
}

void Samochod::showData(){
	cout<<"Marka: "<<marka<<endl<<"Model: "<<model<<endl<<"Kolor: "<<kolor<<endl<<"Rocznik: "<<rok_produkcji<<endl<<"Ilo�� k�: "<<ilosc_kol<<endl<<"Kraj: "<<kraj_pochodzenia<<endl<<endl;
}

int main(int argc, char** argv) {
	setlocale(LC_CTYPE, "polish");
	Samochod auto1{"Mercedes", "SLS AMG", "Czarny", 2020};
	auto1.showData();
	
	Samochod *p_auto;
	p_auto = &auto1;
	cout<<"Marka: "<<p_auto->marka;
	return 0;
}
