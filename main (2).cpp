#include<iostream>
using namespace std;

class Rectangle{
private:
    double sideA,sideB;
    string color;
public:
    static int objectCount;
    Rectangle();
    Rectangle(double pSideA,double pSideB);
    Rectangle(double pSideA, double pSideB, string pColor);
    Rectangle(string pColor);
    Rectangle(const Rectangle&);

    double circuit();
    double area();

    void getData();
    void setSides(double pSideA, double pSideB);
    void setColor(string pColor);
    void catchSides(double &pSideA, double &pSideB);
    void getAreaCircuit();

    ~Rectangle(){
        cout<<"\ndestruktor";
        objectCount--;
        cout<<"  ilosc obiektow: "<<objectCount;
    }
};

    int Rectangle::objectCount=0;

    Rectangle::Rectangle() {
        sideA=-1;
        sideB=-1;
        cout<<"\nkonstruktor domyslny";
        objectCount++;
        cout<<"  ilosc obiektow: "<<objectCount;
    }

    Rectangle::Rectangle(double pSideA, double pSideB) {
        cout<<"\nkonstruktor parametryczny dwuargumentowy";
        objectCount++;
        cout<<"  ilosc obiektow: "<<objectCount;
        sideA=pSideA;
        sideB=pSideB;
        setColor("default color");
    }

    Rectangle::Rectangle(double pSideA, double pSideB, string pColor):
        sideA{pSideA},
        sideB{pSideB},
        color{pColor}
    {cout<<"\nkonstruktor parametrzyczny - lista inicjalizacjyjna"; objectCount++; cout<<"  ilosc obiektow: "<<objectCount;}


    Rectangle::Rectangle(string pColor) {
        sideA=-2;
        sideB=-2;
        color=pColor;
        setSides(0,0);
        objectCount++;
        cout<<"  ilosc obiektow: "<<objectCount;
    }

    Rectangle::Rectangle(const Rectangle& model) {
        cout<<"\nkonstruktor kopiujacy"<<endl<<endl;
        objectCount++;
        cout<<"  ilosc obiektow: "<<objectCount;
        sideA=model.sideA;
        sideB=model.sideB;
    }

    void Rectangle::getData() {
        cout<<"\nbok a: "<<sideA<<"\nbok b: "<<sideB<<"\nkolor: "<<color;
    }
    void Rectangle::setSides(double pSideA, double pSideB) {
        sideA=pSideA;
        sideB=pSideB;
    }
    void Rectangle::setColor(string pColor) {
        color=pColor;
    }
    void Rectangle::catchSides(double &pSideA, double &pSideB) {
        pSideA=sideA;
        pSideB=sideB;
    }
    double Rectangle::circuit() {
        return 2*sideA+2*sideB;
    }
    double Rectangle::area() {
        return sideA*sideB;
    }

    void Rectangle::getAreaCircuit() {
        cout<<"\nobwod: "<<2*sideA+2*sideB<<"\npole: "<<sideA*sideB;
    }


Rectangle copyRectangle(Rectangle rectangle){
        return rectangle;
    }

    void createObject(){
        cout<<"\nPROSTOKAT 9";
        Rectangle *p_rec9=new Rectangle(4.2,7.1);
        p_rec9->getData();
    }

    int main(){
        double a,b;

        cout<<"\nPROSTAKAT 1";
        Rectangle rectangle1; //stworzenie konstruktorem domyslnym
        rectangle1.getData();

        cout<<"\nPROSTAKAT 2";
        Rectangle rectangle2(5,4.2,"blue"); //stworzenie obiektu za pomocą konstruktora parametrycznego sposob 1
        rectangle2.getData();

        cout<<"\nPROSTAKAT 3";
        Rectangle rectangle3(3,8.9,"red"); //stworzenie obiektu za pomocą konstruktora parametrycznego sposob 2
        rectangle3.getData();

        cout<<"\nPROSTAKAT 4";
        Rectangle rectangle4=Rectangle{2,6.2,"green"}; //stworzenie obiektu za pomocą konstruktora parametrycznego sposob 3
        rectangle4.getData();

        cout<<"\nPROSTAKAT 5";
        Rectangle rectangle5(2.3,3.9); //stworzenie obiektu za pomocą konstruktora parametrycznego dwuargumentowego ktory wykorzystuje funkcje setColor
        rectangle5.getData();
        cout<<"\nobwod: "<<rectangle5.circuit()<<"\npole: "<<rectangle5.area(); //obliczenie pola i obwodu, potrzeba dac obiektu jako argument



        cout<<"\nPROSTAKAT 6";
        Rectangle rectangle6("yellow");  //to co wyzej, tym razem kolor jest ustawiony a boki nie
        rectangle6.getData();

        cout<<"\nPROSTAKAT 7";
        Rectangle rectangle7=copyRectangle(rectangle2); //skopiowanie danych prostakata 1 //podczas wykonywania funckji tworzy sie obiekt i usuwa po jej wykonaniu
        rectangle7.catchSides(a,b);  //przypisanie wartosciom a i b wartosci zmiennych obiektu rectangle2
        cout<<"\na: "<<a<<"  b: "<<b;
        rectangle7.getData();

        cout<<"\nPROSTAKAT 8 WSKAZNIK";
        Rectangle *p_rectangle8=new Rectangle(5,4,"green");   //tworzenie konstruktora jako nowy obiekt
        p_rectangle8->getData();
        p_rectangle8->getAreaCircuit();

        createObject(); //objekt sie niszczy po zakonczeniu funckji

        delete p_rectangle8; //usuniecie wskaznika rectangle8, nie usunie on sie sam


        return 0;
    }
