#include "Producto.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <filesystem>
using namespace System;
namespace fs = experimental::filesystem;

void fileexp()
{
	cout << "\n\n\t\t\t $$$$$$$$\\ $$$$$$\\ $$\\       $$$$$$$$\\ $$$$$$$$\\ $$\\   $$\\ $$$$$$$\\" << endl;
	cout << "\t\t\t $$  _____|\\_$$  _|$$ |      $$  _____|$$  _____|$$ |  $$ |$$  __$$\\" << endl;
	cout << "\t\t\t $$ |        $$ |  $$ |      $$ |      $$ |      \\$$\\ $$  |$$ |  $$ |" << endl;
	cout << "\t\t\t $$$$$\\      $$ |  $$ |      $$$$$\\    $$$$$\      \\$$$$  / $$$$$$$  |" << endl;
	cout << "\t\t\t $$  __|     $$ |  $$ |      $$  __|   $$  __|    $$  $$<  $$  ____/" << endl;
	cout << "\t\t\t $$ |        $$ |  $$ |      $$ |      $$ |      $$  /\\$$\\ $$ |" << endl;
	cout << "\t\t\t $$ |      $$$$$$\\ $$$$$$$$\\ $$$$$$$$\\ $$$$$$$$\\ $$ /  $$ |$$ |" << endl;
	cout << "\t\t\t \\__|      \\______|\\________|\\________|\\________|\\__|  \\__|\\__|" << endl;
}
void menu()
{
	cout << "\t\t\t\t      " << "\n\n\n\t\t\t\t\t\tOPCIONES\t\t    " << endl;
	cout << "\t\t\t\t      " << "1. ORDENAR ARCHIVOS\t\t" << endl;
	cout << "\t\t\t\t      " << "2. FILTRAR ARCHIVOS POR NOMBRE\t" << endl;
	cout << "\t\t\t\t      " << "3. FILTRAR ARCHIVOS POR TAMAÑO\t\t" << endl;
	cout << "\t\t\t\t      " << "4. INDEXAR ARCHIVO POR CARACTERISTICA\t\t" << endl;
	cout << "\t\t\t\t      " << "0. Salir" << endl;
}
void lil_menu()
{
	cout << "\t\t\t\t Ingresa el criterio por el cual quieres filtrar: " << endl;
	cout << "\t\t\t\t 1. Mayor " << endl;
	cout << "\t\t\t\t 2. Menor " << endl;
	cout << "\t\t\t\t 3. Inicia con " << endl;
	cout << "\t\t\t\t 4. Termina con " << endl;
	cout << "\t\t\t\t 5. Contenido en " << endl;
	cout << "\t\t\t\t 6. Igual a " << endl;
}
void menu_N()
{
	cout << "\t\t\t\t Ingresa el criterio por el cual quieres filtrar: " << endl;
	cout << "\t\t\t\t 1. Inicia con " << endl;
	cout << "\t\t\t\t 2. Termina con " << endl;
	cout << "\t\t\t\t 3. Contenido en " << endl;
}
void menu_T()
{
	cout << "\t\t\t\t Ingresa el criterio por el cual quieres filtrar: " << endl;
	cout << "\t\t\t\t 1. Mayor " << endl;
	cout << "\t\t\t\t 2. Menor " << endl;
	cout << "\t\t\t\t 3. Igual a " << endl;
}
bool loggeado()
{
	std::string usuario, contra, user, pass;
	std::cout << "\t\t\t\t\tIngrese el Usuario: \n\t\t\t\t\t"; std::cin >> usuario;
	std::cout << "\t\t\t\t\tIngrese la contraseña: \n\t\t\t\t\t"; std::cin >> contra;
	std::ifstream read(usuario + ".txt");
	std::getline(read, user);
	std::getline(read, pass);

	if (user == usuario)
	{
		if (pass == contra)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}
bool SOS()
{
	int cont = 0;
	int opt;
	
	loop: std::cout << "\n\n\n\t\t\t\t\t\t1.Registrarse\n\t\t\t\t\t\t2.Iniciar Sesion\n\t\t\t\t\t\t3.Salir\n\t\t\t\t\t\tEleccion : "; std::cin >> opt;
	if (opt == 1)
	{
		system("cls");
		fileexp();
		std::cout << "\n\n\n\t\t\t\t\t\tRegistrase\n";
		std::string usuario, contra;
		std::cout << "\t\t\t\t\tIngrese su  nombre de usuario: \n\t\t\t\t\t"; std::cin >> usuario;
		std::cout << "\t\t\t\t\tIngrese su  contraseña: \n\t\t\t\t\t"; std::cin >> contra;

		std::ofstream file;
		file.open(usuario + ".txt");
		file << usuario << std::endl << contra;
		file.close();
		system("cls");
		goto loop;
	}
	else if (opt == 2)
	{
		do
		{
			system("cls");
			fileexp();
			std::cout << "\n\n\n\t\t\t\t\t\tIniciar Sesion\n";
			bool ingreso = loggeado();
			if (!ingreso)
			{
				std::cout << "\t\t\t\t\t\tUsuario y/o contraseña incorrectos." << std::endl;
				std::cout << "\t\t\t\t\t\tUsted tiene " << 2 - cont << " intentos mas." << std::endl;
				cont++;
				system("pause>0");
			}
			else
			{
				std::cout << "\t\t\t\t\t\tBienvenido." << std::endl;
				system("pause>0");
				return 1;
			}
		} while (cont < 3);
		if (cont == 3)
		{
			return 0;
		}
	}
	else if (opt == 3)
	{
		exit(1);
	}
}

void main() {
	vector<fs::directory_entry> vec;
	vector<string> _nombre;
	vector<int> _codigo;
	vector<int> _stock;
	vector<int> _produccion;
	vector<int> _vencimiento;
	fs::path RUTA{ "archivos" };
	for (auto& p : fs::recursive_directory_iterator(RUTA))
	{
		vec.push_back(p);
	}

	cout << "Nombre\tExtension\tTamaño" << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		fs::path aPath = vec[i];
		string Name;
		for (int i = 0; i < aPath.filename().string().size(); i++)
		{
			if (aPath.filename().string()[i] == 46)
			{
				break;
			}
			Name += aPath.filename().string()[i];
		}
		cout << Name << "\t" << aPath.extension() << "\t\t" << fs::file_size(vec[i]) << "B" << endl;
	}
	int opt;
	Console::SetWindowSize(115, 28);
	fileexp();
	if (1)
	{
		system("cls");
		fileexp();		
		do {
			menu();
			cin >> opt;
		} while (opt > 4 || opt < 0);
		switch (opt)
		{
		case 1:
		{
			("cls");
			string _name;
			fileexp();
			cout << "Ingre el nombre de la columna por la que quiere ordenar : " << endl;
			cin >> _name;
			int _opt1;
			do
			{
				cout << "1. Ascendente" << endl;
				cout << "2. Descendente" << endl;
				cin >> _opt1;
			} while (_opt1 > 2 || _opt1 < 1);

			if (_opt1 == 1)
			{
				odenar_columna(_name);	//funcion pa ordenar menor a mayor gaaaa
			}
			else if (_opt1 == 2)
			{
				odenar_columna(_name);	//funcion pa ordenar mayor a menor gaaaa
			}
			break;
		}
		case 2:
		{
			char tecla;
			int _opt2;
			("cls");
			fileexp();
			do {
				menu_N();
				cin >> _opt2;
			} while (_opt2 > 3 || _opt2 < 1);
			switch (_opt2)
			{
			case 1:	
			{
				cout << "Ingrese la letra con la que inicia : " << endl; cin >> tecla;
				buscar_letrainicial(tecla); //funcion para buscar por la letra;
				break;
			}
			case 2:
			{
				cout << "Ingrese la letra con la que termina : " << endl; cin >> tecla;
				buscar_letrafinal(tecla); //funcion para buscar por la letra;
				break;
			}
			case 3:
			{
				cout << "Ingrese la letra que contiene : " << endl; cin >> tecla;
				buscar_contiene(tecla); //funcion para buscar por la letra;
				break;
			}
			}
			break;
		}
		case 3:
		{
			int tecla1;
			int _opt3;
			("cls");
			fileexp();
			do {
				menu_N();
				cin >> _opt3;
			} while (_opt3 > 3 || _opt3 < 1);
			switch (_opt3)
			{
			case 1:
			{
				cout << "Ingrese la cantidad a la que sera mayor: " << endl; cin >> tecla1;
				buscar_mayor(tecla1); //funcion para buscar por la letra;
				break;
			}
			case 2:
			{
				cout << "Ingrese la cantidad a la que sera menor : " << endl; cin >> tecla1;
				buscar_menor(tecla1); //funcion para buscar por la letra;
				break;
			}
			case 3:
			{
				cout << "Ingrese la cantidad a la que sera igual : " << endl; cin >> tecla1;
				buscar_igual(tecla1); //funcion para buscar por la letra;
				break;
			}
			}
			break;
		}
		case 4:
		{
			string columna;
			cout << "Ingrese el nombre de la caracteristica por la cual quiere indexar : " << endl; cin >> columna;
			indexar(columna);
			break;
		}
		case 5:
		{
			exit(1);
			break;
		}
		}

		for (int i = 0; i < vec.size(); i++)
		{
			Producto* obj_producto = new Producto();
			fs::path aPath = vec[i];
			std::ifstream f(aPath);
			if (!f.is_open())
			{
				return;
			}
			else
			{
				std::string linea, num;
				while (f >> linea)
				{
					std::stringstream ss(linea);
					int cont = 1;
					while (std::getline(ss, num, ','))
					{
						switch (cont)
						{
						case 1: obj_producto->set_Nombre(num.c_str()); break;
						case 2: obj_producto->set_Codigo(atoi(num.c_str())); break;
						case 3: obj_producto->set_Stock(atoi(num.c_str())); break;
						case 4: obj_producto->set_Produccion(atoi(num.c_str())); break;
						case 5: obj_producto->set_Vencimiento(atoi(num.c_str())); break;
						}
						cont++;
					}
					_nombre.push_back(obj_producto->get_Nombre());
					_codigo.push_back(obj_producto->get_Codigo());
					_stock.push_back(obj_producto->get_Stock());
					_produccion.push_back(obj_producto->get_Produccion());
					_vencimiento.push_back(obj_producto->get_Vencimiento());
				}
			}
		}
		cout << "Nombre\t\tCodigo\tStock\tProduccion\tVencimiento" << endl;
		for (int i = 0; i < vec.size(); i++)
		{
			cout << _nombre[i] << "\t\t" << _codigo[i] << "\t" << _stock[i] << "\t" << _produccion[i] << "\t" << _vencimiento[i] << endl;;
		}
	}	

	system("pause>0");;
}