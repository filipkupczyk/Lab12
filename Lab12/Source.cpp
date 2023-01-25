#include "Header.h"

using namespace std;

Car::Car(string model1, int rok1, double pojemnosc1) {
	model = model1;
	rok = rok1;
	pojemnosc = pojemnosc1;
}
void Car::setModel(string value) {
	model = value;
}
void Car::setRok(int value) {
	rok = value;
}
void Car::setPojemnosc(double value) {
	pojemnosc = value;
}
string Car::getModel() {
	return model;
}
int Car::getRok() {
	return rok;
}
double Car::getPojemnosc() {
	return pojemnosc;
}
void Car::wysiwietl() {
	cout << "model " << model << endl;
	cout << "rok produkcji " << rok << endl;
	cout << "pojemnosc " << pojemnosc << endl;
}