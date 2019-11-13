#pragma once
#include <iostream>
#include <string>

using namespace std;

class Producto
{
	string Nombre;
	int Codigo;
	int Stock;
	int Produccion;
	int Vencimiento;
public:
	Producto(){}
	Producto(string Nombre, int Codigo, int stock, int Produccion, int Vencimiento)
	{
		this->Nombre = Nombre;
		this->Codigo = Codigo;
		this->Stock = Stock;
		this->Produccion = Produccion;
		this->Vencimiento = Vencimiento;
	}
	~Producto(){}	
	void set_Nombre(string nuevo) { this->Nombre = nuevo; }
	void set_Codigo(int nuevo) { this->Codigo = nuevo; }
	void set_Stock(int nuevo) { this->Stock = nuevo; }
	void set_Produccion(int nuevo) { this->Produccion = nuevo; }
	void set_Vencimiento(int nuevo) { this->Vencimiento = nuevo; }
	string get_Nombre() { return this->Nombre; }
	int get_Codigo() { return this->Codigo; }
	int get_Stock() { return this->Stock; }
	int get_Produccion() { return this->Produccion; }
	int get_Vencimiento() { return this->Vencimiento; }
};		   
