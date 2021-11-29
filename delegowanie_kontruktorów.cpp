//delegowanie konstruktor�w
#include <iostream>

using namespace std;

class Rectangle{
	public:
		double sideA;
		double sideB;
		Rectangle();
		Rectangle(double pSideA, double pSideB);
	//prototyp konstruktor kopiuj�cy
	Rectangle(const Rectangle&);
	
	void catchSides(double&, double&);
	void setSides(double sideA, double sideB);
	double area();
	double circuite();
	void getSides();
	
};

	Rectangle::Rectangle(){
		cout<<"konstruktor domy�lny"<<endl;
	}
	
	Rectangle::Rectangle(double pSideA, double pSideB){
		cout<<"konstruktor parametryczny"<<endl;
		sideA=pSideA;
		sideB=pSideB;
	}
	
	Rectangle::Rectangle(const Rectangle& model ){
		cout<<"konstruktor kopiuj�cy"<<endl;
		sideA= model.sideA;
		sideB= model.sideB;
		
	}
	
	
	void Rectangle::catchSides(double &pSideA, double &pSideB){
		pSideA= sideA;
		pSideB= sideB;
	}
	
	void Rectangle::setSides(double pSideA, double pSideB){
		sideA= pSideA;
		sideB= pSideB;
	}
	
	double Rectangle::area(){
	return sideA * sideB;
	}
	
	double Rectangle::circuite(){
	return 2* sideA + 2 * sideB;
	}
	
	void Rectangle::getSides(){
		cout<<"bok a: "<<sideA<<"Bok b: "<<sideB<<endl;
	}
	
	Rectangle copyRectangle(Rectangle rectangle){
		return rectangle;
	}


int main(int argc, char** argv) {
	setlocale(LC_CTYPE, "polish");
	
	//jawny
	double a, b;
	cout<<"Prostok�t 1: "<<endl;
	Rectangle prostokat1(5, 9);
	prostokat1.getSides();
	cout<<"a: "<<a<<" b: "<<b<<endl<<endl;
	
	//nie jawny
	cout<<"Prostok�t 2: "<<endl;
	Rectangle prostokat2= prostokat1;
	prostokat2.catchSides(a, b);
	prostokat2.getSides();
	cout<<"a: "<<a<<" b: "<<b<<endl<<endl;
	
	cout<<"Prostok�t 3: "<<endl;
	Rectangle prostokat3(prostokat1);
	prostokat3.catchSides(a, b);
	prostokat3.getSides();
	cout<<"a: "<<a<<" b: "<<b<<endl<<endl;
	
	cout<<"Prostok�t 4: "<<endl;
	Rectangle prostokat4;
	prostokat4 = copyRectangle(prostokat1);
	prostokat4.catchSides(a, b);
	cout<<"a: "<<a<<" b: "<<b<<endl<<endl;
	
	cout<<"Obw�d: "<<prostokat4.circuite()<<endl<<"Pole: "<<prostokat4.area();

	return 0;
}
