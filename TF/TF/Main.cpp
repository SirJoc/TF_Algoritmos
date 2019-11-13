#include "Producto.h"
#include <vector>
#include <sstream>
#include <fstream>
#include <filesystem>

using namespace System;
namespace fs = experimental::filesystem;

void menu()
{
	cout << "\n\n\t\t\t $$$$$$$$\\ $$$$$$\\ $$\\       $$$$$$$$\\ $$$$$$$$\\ $$\\   $$\\ $$$$$$$\\" << endl;
	cout << "\t\t\t $$  _____|\\_$$  _|$$ |      $$  _____|$$  _____|$$ |  $$ |$$  __$$\\" << endl;
	cout << "\t\t\t $$ |        $$ |  $$ |      $$ |      $$ |      \\$$\\ $$  |$$ |  $$ |" << endl;
	cout << "\t\t\t $$$$$\\      $$ |  $$ |      $$$$$\\    $$$$$\      \\$$$$  / $$$$$$$  |" << endl;
	cout << "\t\t\t $$  __|     $$ |  $$ |      $$  __|   $$  __|    $$  $$<  $$  ____/" << endl;
	cout << "\t\t\t $$ |        $$ |  $$ |      $$ |      $$ |      $$  /\\$$\\ $$ |" << endl;
	cout << "\t\t\t $$ |      $$$$$$\\ $$$$$$$$\\ $$$$$$$$\\ $$$$$$$$\\ $$ /  $$ |$$ |" << endl;
	cout << "\t\t\t \\__|      \\______|\\________|\\________|\\________|\\__|  \\__|\\__|" << endl;

	cout << "\t\t\t\t      " << "\t\t\t\t\t    " << endl;
	cout << "\t\t\t\t      " << "\t\t       OPCIONES\t\t    " << endl;
	cout << "\t\t\t\t      " << "\t\t\t\t\t    " << endl;
	cout << "\t\t\t\t      " << "A. FILTRAR DATOS DE LOS PRODUCTOS POR COLUMNAS " << endl;
	cout << "\t\t\t\t      " << "B. ORDENAR PRODUCTOS\t\t    " << endl;
	cout << "\t\t\t\t      " << "C. GUARDAR ARCHIVO DE PRODUCTOSt\t    " << endl;
	cout << "\t\t\t\t      " << "D. AÑADIR OTRO ARCHIVO DE PRODUCTOS\t\t    " << endl;
	cout << "\t\t\t\t      " << "D. INDEXAR COLUMNA\t\t    " << endl;
	cout << "\t\t\t\t      " << "0. Salir           \t\t    " << endl;
}

bool loggeado()
{
	std::string usuario, contra, user, pass;
	std::cout << "Ingrese el Usuario: "; std::cin >> usuario;
	std::cout << "Ingrese la contraseña: "; std::cin >> contra;
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
	
	loop: std::cout << "1.Registrarse\n2.Iniciar Sesion\n3.Salir\nEleccion : "; std::cin >> opt;
	if (opt == 1)
	{
		system("cls");
		std::cout << "\tRegistrase\n";
		std::string usuario, contra;
		std::cout << "Ingrese su  nombre de usuario: "; std::cin >> usuario;
		std::cout << "Ingrese su  contraseña: "; std::cin >> contra;

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
			std::cout << "\tIniciar Sesion\n";
			bool ingreso = loggeado();
			if (!ingreso)
			{
				std::cout << "Usuario y/o contraseña incorrectos." << std::endl;
				std::cout << "Usted tiene " << 2 - cont << " intentos mas." << std::endl;
				cont++;
				system("pause>0");
			}
			else
			{
				std::cout << "Bienvenido." << std::endl;
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

	Console::SetWindowSize(115, 28);
	if (SOS())
	{
		system("cls");
		menu();
		system("pause>0");
		system("cls");
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