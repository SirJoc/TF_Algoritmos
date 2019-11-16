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

	for (auto& p : fs::recursive_directory_iterator(RUTA))
	{
		vec.push_back(p);
		cout << p;
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