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


void index_c(vector<string> Nombre, vector<int> Eleccion)
{
	AVLTree<int> elec;
	for (int i = 0; i < Eleccion.size(); i++)
	{
		cout << Nombre[i] << "\t" << Eleccion[i] << endl;
		elec.Add(Eleccion[i]);
	}
}

vector<int> empiezacon(vector<string> Nombre, char a)
{
	vector<int> pos;
	for (int i = 0; i < Nombre.size(); i++)
	{
		string compare = Nombre[i];
		if (compare[0] == a)
		{
			pos.push_back(i);
		}
	}
	return pos;
}

vector<int> contiene(vector<string> Nombre, char a)
{
	vector<int> pos;
	for (int i = 0; i < Nombre.size(); i++)
	{
		string compare = Nombre[i];
		for (int j = 1; j < Nombre[i].size()-1; j++)
		{
			
			if (compare[j] == a)
			{
				pos.push_back(i);
			}
		}
		
	}
	return pos;
}

vector<int> terminacon(vector<string> Nombre, char a)
{
	vector<int> pos;
	for (int i = 0; i < Nombre.size(); i++)
	{
		string compare = Nombre[i];
		if (compare[Nombre[i].size()-1] == a)
		{
			pos.push_back(i);
		}
	}
	return pos;
}

void mostrar(vector<int> pos, vector<string> filename, vector<string> extension, vector<int> size)
{
	for (int i = 0; i < pos.size(); ++i)
	{
		cout << filename[pos[i]] << "\t" << extension[pos[i]] << "\t" << size[pos[i]] << endl;
	}

}


void main() {

	Console::SetWindowSize(115, 28);
	if (1)
	{
		system("cls");
		menu();
		system("pause>0");
		system("cls");
		vector<fs::directory_entry> vec;
		vector<string> filename;
		vector<string> extension;
		vector<int> size;
		vector<string> _nombre;
		vector<int> _codigo;
		vector<int> _stock;
		vector<int> _produccion;
		vector<int> _vencimiento;
		string _archivo;
		cout << "	Ingrese el nombre del archivo que quiere explorar: "; cin >> _archivo; cout << endl;
		fs::path RUTA{ _archivo };
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

			filename.push_back(Name);
			extension.push_back(aPath.extension().string());
			size.push_back(fs::file_size(vec[i]));
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
		//cout << filename[empiezacon(filename, t)] << "\t" << extension[empiezacon(filename, t)] << "\t" << size[empiezacon(filename, t)] << endl;
		//cout << filename[terminacon(filename, t)] << "\t" << extension[terminacon(filename, t)] << "\t" << size[terminacon(filename, t)] << endl;
		//cout << filename[contiene(filename, t)] << "\t" << extension[contiene(filename, t)] << "\t" << size[contiene(filename, t)] << endl;
		mostrar(empiezacon(filename, t), filename, extension, size);
	}
	cin.ignore();
	system("pause>0");
}