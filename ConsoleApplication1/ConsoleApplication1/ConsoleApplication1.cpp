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
int main()
{

	
	struct stat t_stat;
	//stat("Holaaaaa.txt", &t_stat);
	struct tm * timeinfo = localtime(&t_stat.st_ctime); // or gmtime() depending on what you want
	//printf("%s", asctime(timeinfo));
	std::cout << asctime(timeinfo);
	stat("C:\\Users\\Josue\\source\\repos\\OK\\ConsoleApplication1\\ConsoleApplication1\\archivo\\archivo.txt", &t_stat);
	std::cin.get();
	return 0;
}