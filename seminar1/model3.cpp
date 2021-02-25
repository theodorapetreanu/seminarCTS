#include <iostream>
#include <string>
#include <conio.h>
using namespace std;


//sugestia 1: Adaugarea unui TODO
//sugestia 2: Eliminarea bucatilor de cod comentate si incomplete
//sugestia 3: Existenta codului redundant (mai multi constructori cu parametrii)
class Departament{
private:
	char* denDepartament;
	int nrAngajati;
	//sugestia 4: Alegerea unei denumiri mai explicite a variabilei
	int* efortOmOre;

public:
	Departament() {
		this->denDepartament = new char[strlen("Comunicare") + 1];
		strcpy(this->denDepartament, "Comunicare");
		this ->nrAngajati = 5;
		this->efortOmOre = new int[this->nrAngajati];
		for (int i = 0; i < this->nrAngajati; i++)
			this->efortOmOre[i] = i + 1;
       }

	Departament(char* denP, int nrAngP, int* efortP) {
		this->denDepartament = new char[strlen(denP) + 1];
		strcpy(denDepartament, denP);
		this->nrAngajati = nrAngP;
		this->efortOmOre = new int[nrAngP];
		for (int i = 0; i < nrAngP; i++)
			this->efortOmOre[i] = efortP[i];
	}

	Departament(char* denP, int nrAngP) {
		this->denDepartament = new char[strlen(denP) + 1];
		strcpy(denDepartament, denP);
		this->nrAngajati = nrAngP;
	}

	Departament(const Departament& depart) {
		this->denDepartament = new char[strlen(depart.denDepartament) + 1];
		strcpy(denDepartament, depart.denDepartament);
		this->nrAngajati = depart.nrAngajati;
		this->efortOmOre = new int[depart.nrAngajati];
		for (int i = 0; i < depart.nrAngajati; i++)
			this->efortOmOre[i] = depart.efortOmOre[i];
	}

	Departament operator=(const Departament& depart) {
		this->denDepartament = new char[strlen(depart.denDepartament) + 1];
		strcpy(this->denDepartament, depart.denDepartament);
		this->nrAngajati = depart.nrAngajati;
		this->efortOmOre = new int[depart.nrAngajati];
		for (int i = 0; i < depart.nrAngajati; i++)
			this->efortOmOre[i] = depart.efortOmOre[i];
		return *this;
	}

	char* getDenumire() {
		return this->denDepartament;
	}

	void setDenumire(char* den) {
		delete[]this->denDepartament;
		this->denDepartament = new char[strlen(den) + 1];
		strcpy(this->denDepartament, den);
	}

	//void setVectorEfort(int* vectEf, sizeof(int) / sizeof(float)) {

	//}

	friend ostream& operator<<(ostream& out, Departament& d);

};

ostream& operator<<(ostream& out, Departament& d) {
	cout << "Denumirea departamentului: " << d.denDepartament << endl;
	cout << "Numarul de angajati: " << d.nrAngajati << endl;
	for (int i = 0; i < d.nrAngajati; i++)
		cout << "Orele muncite de fiecare angajat: " << d.efortOmOre[i] << endl;
	return out;
}

int main() {
	int* vectEfort = new int[12];
	//sugestia 5:cod repetitiv; popularea vectorului se putea realiza utilizand o singura linie de cod
	vectEfort[0] = 5;
	vectEfort[1] = 6;
	vectEfort[2] = 2;
	vectEfort[3] = 7;
	vectEfort[4] = 3;
	vectEfort[5] = 1;
	vectEfort[6] = 6;
	vectEfort[7] = 5;
	vectEfort[8] = 4;
	vectEfort[9] = 3;
	vectEfort[10] = 2;
	vectEfort[11] = 4;
	Departament d1, d2("Resurse umane", 12, vectEfort);
	cout << d1 << endl << d2 << endl;
	Departament d3 = d2, d4;
	d4 = d1;
	cout << d3 << endl << d4 << endl;
	cout << d2.getDenumire() << endl;
	d1.setDenumire("Contabilitate si achizitii");
	cout << d1.getDenumire() << endl;
	//Departament d6("Tehnologia informatiei", 5);
	//cout << d6 << endl;

	_getch();
}