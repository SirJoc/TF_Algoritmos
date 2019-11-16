#include "AVL.h"
#include "QuickSortT.h"
#include "Producto.h"
#include <sstream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <iomanip>
using namespace System;
namespace fs = experimental::filesystem;
using namespace std::chrono_literals;

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
	cout << "\n\n\t\t\t\t" << "\t\t OPCIONES" << endl;
	cout << "\n\n\t\t\t\t" << "1. INDEXAR ARCHIVOS DE LA CARPETA" << endl;
	cout << "\t\t\t\t" << "2. BUSQUEDA DE ARCHIVOS" << endl;
	cout << "\t\t\t\t" << "3. FILTRAR CONTENIDO DE LOS ARCHIVOS POR CARACTERISTICA" << endl;
	cout << "\t\t\t\t" << "4. FILTRAR DATOS POR COLUMNAS" << endl;
	cout << "\t\t\t\t" << "5. ORDENAMIENTO" << endl;
	cout << "\t\t\t\t" << "0. Salir" << endl;
	cout << "\n\t\t\t\t" << "Eleccion : ";
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


vector<int> MayorA(vector<int> size, int a)
{
	vector<int> pos;
	for (int i = 0; i < size.size(); i++)
	{
		
		if (size[i] > a)
		{
			pos.push_back(i);
		}
	}
	return pos;
}

vector<int> MenorA(vector<int> size, int a)
{
	vector<int> pos;
	for (int i = 0; i < size.size(); i++)
	{

		if (size[i] < a)
		{
			pos.push_back(i);
		}
	}
	return pos;
}

vector<int> IgualA(vector<int> size, int a)
{
	vector<int> pos;
	for (int i = 0; i < size.size(); i++)
	{
		if (size[i] == a)
		{
			pos.push_back(i);
		}
	}
	return pos;
}

void mostrar(vector<int> pos, vector<string> filename, vector<string> extension, vector<int> size, vector<char*> fecha)
{
	cout << "Nombre\t\tExtension\tTamaño\tFecha" << endl;
	for (int i = 0; i < pos.size(); ++i)
	{
		cout << filename[pos[i]] << "\t\t" << extension[pos[i]] << "\t\t" << size[pos[i]] << "\t\t" << fecha[pos[i]] << endl;
	}

}

void mostrarDef(vector<string> filename, vector<string> extension, vector<int> size, vector<char*> fecha)
{
	cout << "Nombre\t\tExtension\tTamaño\tFecha" << endl;
	for (int i = 0; i < filename.size(); ++i)
	{
		cout << filename[i] << "\t\t" << extension[i] << "\t\t" << size[i] << "\t\t" << fecha[i] << endl;
	}

}

template <typename T>
vector<int> ordenar_MenToMay(vector<T>& filename)
{
	vector<T> aux = filename;
	vector<int> pos;
	quicksortMenToMay(filename, filename.size());
	for (int i = 0; i < filename.size(); i++)
	{
		for (int j = 0; j < filename.size(); ++j)
		{
			if (filename[i] == aux[j])
			{
				pos.push_back(j);
			}
		}
	}
	return pos;
}

template <typename T>
vector<int> ordenar_MayToMen(vector<T>& filename)
{
	vector<T> aux = filename;
	vector<int> pos;
	quicksortMayToMen(filename, filename.size());
	for (int i = 0; i < filename.size(); i++)
	{
		for (int j = 0; j < filename.size(); ++j)
		{
			if (filename[i] == aux[j])
			{
				pos.push_back(j);
			}
		}
	}
	return pos;
}

void main() {

	Console::SetWindowSize(115, 45);
	if (1)
	{
		fileexp();
		vector<fs::directory_entry> vec;
		vector<string> filename;
		vector<string> extension;
		vector<int> size;
		vector<char*> fecha;

		vector<string> _nombre;
		vector<int> _codigo;
		vector<int> _stock;
		vector<int> _produccion;
		vector<int> _vencimiento;

		string _archivo;
		cout << "\n\n\t\t\t\tIngrese el nombre de la carpeta que quiere explorar: \n\t\t\t\t\t"; cin >> _archivo; cout << endl;
		fs::path RUTA{ _archivo };
		for (auto& p : fs::recursive_directory_iterator(RUTA))
		{
			vec.push_back(p);
			auto ftime = fs::last_write_time(p);
			time_t cftime = decltype(ftime)::clock::to_time_t(ftime);
			char* f = new char();
			f = (asctime(localtime(&cftime)));
			fecha.push_back(f);
		}
		for (int i = 0; i < fecha.size(); i++)
		{
			std::cout << fecha[i] << endl;
		}

		cin.ignore();
		std::cin.get();

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
			auto ftime = fs::last_write_time(vec[i]);
			std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime); // assuming system_clock
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
		int opt_menu;
		while (!!!!!!!!!!!!!!!!!!1)
		{
			do
			{
				system("cls");
				fileexp();
				menu();
				cin >> opt_menu;
			} while (opt_menu > 5 || opt_menu < 0);
			switch (opt_menu)
			{
			case 1:
			{
				system("cls");
				mostrarDef(filename, extension, size, fecha);
				break;
			}
			case 2:
			{
				//falta
				break;
			}
			case 3:
			{
				cout << "Nombre\t\tCodigo\tStock\tProduccion\tVencimiento" << endl;
				for (int i = 0; i < vec.size(); i++)
				{
					cout << _nombre[i] << "\t\t" << _codigo[i] << "\t" << _stock[i] << "\t" << _produccion[i] << "\t" << _vencimiento[i] << endl;
				}
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
				break;
			}
			case 4:
			{
				string opt_3;
				int desc_3;
				char tecla_3;
				int num_3;
				mostrarDef(filename, extension, size, fecha);
				
				cout << "Ingrese el nombre de la columna que desea filtrar(Nombre o Size) : "; cin >> opt_3;
				if (opt_3 == "Nombre")
				{
					do
					{
						cout << "\n1. Empieza con :";
						cout << "\n2. Finaliza con :";
						cout << "\n3. Contiene :";
						cout << "\nEleccion :";
						cin >> desc_3;
					} while (desc_3 > 3 || desc_3 < 0);
					if (desc_3 == 1)
					{
						cout << "Ingrese la letra con la que inicia : "; cin >> tecla_3;
						mostrar(empiezacon(filename, tecla_3), filename, extension, size, fecha);
					}
					else if (desc_3 == 2)
					{
						cout << "Ingrese la letra con la que finaliza : "; cin >> tecla_3;
						mostrar(terminacon(filename, tecla_3), filename, extension, size, fecha);
					}
					else if (desc_3 == 3)
					{
						cout << "Ingrese la letra que contiene : "; cin >> tecla_3;
						mostrar(contiene(filename, tecla_3), filename, extension, size, fecha);
					}	
					break;
				}
				else if (opt_3 == "Size")
				{
					do
					{
						cout << "\n1. Mayor a :";
						cout << "\n2. Menor a :";
						cout << "\n3. Igual a :";
						cout << "\nEleccion :";
						cin >> desc_3;
					} while (desc_3 > 3 || desc_3 < 0);
					if (desc_3 == 1)
					{
						cout << "Ingrese el parametro : "; cin >> num_3;
						mostrar(MayorA(size, num_3), filename, extension, size, fecha);
					}
					else if (desc_3 == 2)
					{
						cout << "Ingrese el parametro : "; cin >> num_3;
						mostrar(MenorA(size, num_3), filename, extension, size, fecha);
					}
					else if (desc_3 == 3)
					{
						cout << "Ingrese el parametro : "; cin >> num_3;
						mostrar(IgualA(size, num_3), filename, extension, size, fecha);
					}

					break;
				}			
			}
			case 5:
			{
				string another;
				int gaa;
				cout << "Bajo que caracteristica desea ordenar(Nombre o Size) : ";  cin >> another;
				if (another == "Nombre")
				{
					do
					{
						cout << "\n1.Ascendente : ";
						cout << "\n2.Descendente : ";
						cout << "\nEleccion :";
						cin >> gaa;
					} while (gaa > 2 || gaa < 1);
					if (gaa = 1)
					{
						mostrar(ordenar_MenToMay<string>(filename), filename, extension, size, fecha);
					}
					else if (gaa = 2)
					{
						mostrar(ordenar_MayToMen<string>(filename), filename, extension, size, fecha);
					}
				}
				else if (another == "Size")
				{
					do
					{
						cout << "\n1.Ascendente : ";
						cout << "\n2.Descendente : ";
						cout << "\nEleccion :";
						cin >> gaa;
					} while (gaa > 2 || gaa < 1);
					if (gaa = 1)
					{
						mostrar(ordenar_MenToMay<int>(size), filename, extension, size, fecha);
					}
					else if (gaa = 2)
					{
						mostrar(ordenar_MayToMen<int>(size), filename, extension, size, fecha);
					}
				}
				break;
			}
			case 0: exit(1); break;

			}
			system("pause>0");
		}		
	}
	cin.ignore();
	system("pause>0");
}