#include<iostream>

using namespace std;

class Worker{
	public:
		unsigned int id;
		string name, surname, classroom, school;
		Worker();
		Worker(unsigned int id, string name, string surname, string classroom, string school);
		void getData();
};

Worker::Worker(){
	cout<<"Konstruktor domyslny"<<endl;
}

Worker::Worker(unsigned int pId, string pName, string pSurname, string pClassroom, string pSchool){
	cout<<"Konstruktor parametryczny"<<endl;
	id=pId;
	name=pName;
	surname=pSurname;
	classroom=pClassroom;
	school=pSchool;
}

void Worker::getData(){
	cout<<"ID: "<<id<<endl<<"Imiê: "<<name<<endl<<"Nazwisko: "<<surname<<endl<<"Klasa: "<<classroom<<endl<<"Szko³a: "<<school<<endl;
}

int main(){
	setlocale(LC_CTYPE, "polish");
	Worker pracownik(10, "Janusz", "Kowalski", "2E", "ZSK");
	pracownik.getData();
	return 0;
}
