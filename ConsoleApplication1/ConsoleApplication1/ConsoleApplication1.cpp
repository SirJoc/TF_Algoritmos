#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <vector>
#include <string>
#include <experimental/filesystem>
#include <sys/stat.h>
#include <time.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <sstream>
using namespace std;
using namespace System;
namespace fs = experimental::filesystem;
using namespace std::chrono_literals;
int main()
{
	string _archivo;
	cout << "\n\n\t\t\t\tIngrese el nombre de la carpeta que quiere explorar: \n\t\t\t\t\t"; cin >> _archivo; cout << endl;
	fs::path RUTA{ _archivo };
	vector<fs::directory_entry> vec;
	stringstream ss;
	string linea = "";
	string aux;
	for (auto& p : fs::recursive_directory_iterator(RUTA))
	{
		vec.push_back(p);
		fs::path xD = fs::current_path();
		ss << xD;
		ss << char(92);
		ss << p;
		ss >> linea;
		cout << "\n";
		
		for (int i = 0; i < linea.size(); ++i)
		{
			
			aux.push_back(linea[i]);
			if(linea[i] == char(92))
			{
				aux.push_back(char(92));
			}
		}
		cout << aux;
		aux.clear();
		ss.clear();
		linea.clear();
		for (int k = 0; k < 5; k++)
		{
			auto ftime = fs::last_write_time(p);
			time_t cftime = decltype(ftime)::clock::to_time_t(ftime);
			cout << endl;
			ss << (std::asctime(std::localtime(&cftime)));
		}
		

		ss >> linea;
		cout << linea << endl;
		ss.clear();
		linea.clear();

		//////////////
		
	}
	
	
	
	//struct stat t_stat;
	////stat("Holaaaaa.txt", &t_stat);
	//struct tm * timeinfo = localtime(&t_stat.st_ctime); // or gmtime() depending on what you want
	////printf("%s", asctime(timeinfo));
	//std::cout << asctime(timeinfo);
	//stat("C:\\Users\\Josue\\source\\repos\\OK\\ConsoleApplication1\\ConsoleApplication1\\archivo\\archivo.txt", &t_stat);
	cin.ignore();
	std::cin.get();
	return 0;
}