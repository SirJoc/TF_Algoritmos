#include "AVL.h"
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
}
void menu()
{
	cout << "\t\t\t\t      " << "\n\n\n\t\t\t\t\t\tOPCIONES\t\t    " << endl;
	cout << "\t\t\t\t      " << "1. ORDENAR ARCHIVOS\t\t" << endl;
	cout << "\t\t\t\t      " << "2. FILTRAR ARCHIVOS POR NOMBRE\t" << endl;
	cout << "\t\t\t\t      " << "3. FILTRAR ARCHIVOS POR TAMA�O\t\t" << endl;
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
	std::cout << "\t\t\t\t\tIngrese la contrase�a: \n\t\t\t\t\t"; std::cin >> contra;
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
		std::cout << "\t\t\t\t\tIngrese su  contrase�a: \n\t\t\t\t\t"; std::cin >> contra;

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
				std::cout << "\t\t\t\t\t\tUsuario y/o contrase�a incorrectos." << std::endl;
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


void index_c(vector<string> Nombre, vector<int> Eleccion)
{
	AVLTree<int> elec;
	for (int i = 0; i < Eleccion.size(); i++)
	{
		cout << Nombre[i] << "\t" << Eleccion[i] << endl;
		elec.Add(Eleccion[i]);
	}
}

int empiezacon(vector<string> Nombre, char a)
{
	for (int i = 0; i < Nombre.size(); i++)
	{
		string compare = Nombre[i];
		if (compare[0] == a)
		{
			return i;
		}
	}
}

int terminacon(vector<string> Nombre, char a)
{
	for (int i = 0; i < Nombre.size(); i++)
	{
		string compare = Nombre[i];
		if (compare[compare.size()-1] == a)
		{
			return i;
		}
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

		cout << "Nombre\tExtension\tTama�o" << endl;
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
			f.close();
		}
		cout << "Nombre\t\tCodigo\tStock\tProduccion\tVencimiento" << endl;
		for (int i = 0; i < vec.size(); i++)
		{
			cout << _nombre[i] << "\t\t" << _codigo[i] << "\t" << _stock[i] << "\t" << _produccion[i] << "\t" << _vencimiento[i] << endl;
		}
		system("pause>0");
		system("cls");

		string _eleccion;
		cout << "Ingrese el nombre de la caracteristica para indexar : "; cin >> _eleccion;
		if (_eleccion == "Codigo")
		{
			index_c(_nombre, _codigo);		
		}
		if (_eleccion == "Stock")
		{
			index_c(_nombre, _stock);
		}
		if (_eleccion == "Produccion")
		{
			index_c(_nombre, _produccion);
		}
		if (_eleccion == "Vencimiento")
		{
			index_c(_nombre, _vencimiento);
		}
		cout << "ingrese tecla :";
		char t;
		cin >> t;
		cout << filename[empiezacon(filename, t)] << "\t" << extension[empiezacon(filename, t)] << "\t" << size[empiezacon(filename, t)] << endl;
	
	}	
	cin.ignore();
	system("pause>0");
}