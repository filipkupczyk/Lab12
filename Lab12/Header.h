#ifndef  HEADER_H_INCLUDED
#define HEADER_H_INCLUDED
#include <iostream>

using namespace std;

class Car {
	private:
		string model;
		int rok;
		double pojemnosc;
	public: 
		Car(string model, int rok, double pojemnosc);
		void setModel(string value);
		void setRok(int value);
		void setPojemnosc(double value);
		string getModel();
		int getRok();
		double getPojemnosc();
		void wysiwietl();
};


#endif