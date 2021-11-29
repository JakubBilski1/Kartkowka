#include<iostream>

using namespace std;

class Rectangle{
	private:
		double sideA;
		double sideB;
		string color;
	public:
		static int objectCount;
		Rectangle();
		Rectangle(double pSideA, double pSideB);
		Rectangle(const Rectangle&);
		void getData();
		void setColor(string pColor);
		double circuit();
		double area();
		void AreaCircuit();
		~Rectangle(){
			cout<<"Destruktor"<<endl;
			objectCount--;
			cout<<"Ilosc obiektow: "<<objectCount<<endl;
		}
};

int Rectangle::objectCount=0;

double Rectangle::area(){
	return sideA*sideB;
}

double Rectangle::circuit(){
	return sideA*2+sideB*2;
}

void Rectangle::setColor(string pColor){
	color=pColor;
}

Rectangle::Rectangle(){
	cout<<"Konstruktor domyslny"<<endl;
	objectCount++;
	cout<<"Ilosc obiektow: "<<objectCount<<endl;
	setColor("default");
}

Rectangle::Rectangle(double pSideA, double pSideB):
	sideA{pSideA},
	sideB{pSideB}
	{
		cout<<"Konstruktor parametryczny - lista inicjalizacyjna"<<endl;
		objectCount++;
		cout<<"Ilosc obiektow: "<<objectCount<<endl;
		setColor("red");
	}


Rectangle::Rectangle(const Rectangle& model){
	cout<<"Konstruktor kopiujacy"<<endl;
	sideA=model.sideA;
	sideB=model.sideB;
	objectCount++;
	cout<<"Ilosc obiektow: "<<objectCount<<endl;
	setColor("blue");
}

Rectangle copyRectangle(Rectangle rectangle){
	return rectangle;
}

void Rectangle::getData(){
	cout<<"a= "<<sideA<<endl<<"b= "<<sideB<<endl<<"Kolor: "<<color<<endl<<endl;
}

void Rectangle::AreaCircuit(){
	cout<<"Obwod: "<<sideA*2+sideB*2<<endl<<"Pole: "<<sideA*sideB<<endl<<endl;
}

int main(){
	//jawny
	Rectangle prostokat;
	prostokat.getData();
	
	//niejawny
	Rectangle prostokat2 = Rectangle(4, 7);
	prostokat2.getData();
	cout<<"Obwod: "<<prostokat2.circuit()<<endl<<"Pole: "<<prostokat2.area()<<endl<<endl;
	
	Rectangle prostokat3 = copyRectangle(prostokat2);
	prostokat3.getData();
	Rectangle *p_prostokat;
	p_prostokat = &prostokat3;
	p_prostokat->AreaCircuit();
	delete p_prostokat;
	return 0;
}
