// ConsoleApplication1.cpp : main project file.
#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <vector>
#include <string>
#include <experimental/filesystem>
using namespace std;
namespace fs = std::experimental::filesystem;
using namespace std::chrono_literals;

int main()
{
	string _archivo;
	cout << "\n\n\t\t\t\tIngrese el nombre de la carpeta que quiere explorar: \n\t\t\t\t\t"; cin >> _archivo; cout << endl;
	fs::path RUTA{ _archivo };

	for (auto& p : fs::recursive_directory_iterator(RUTA))
	{
		auto ftime = fs::last_write_time(p);

		std::time_t cftime = decltype(ftime)::clock::to_time_t(ftime); // assuming system_clock
		std::cout << "File write time is " << std::asctime(std::localtime(&cftime)) << '\n';
	}

	std::cin.ignore();
	std::cin.get();
	return 0;
}
