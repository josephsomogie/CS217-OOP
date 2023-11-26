

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Shapes.h"
#include <vector>
#include <chrono>
#include <thread>
using namespace std;
int main()
{
	//list creation
	vector<Shape*> shapes;
	bool menu = true;
	while (menu)
	{
		
		int userC = NULL;
		cin >> userC; //implement error handling
		switch (userC)
		{
		case 0:

			
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;


		}
		
		std::this_thread::sleep_for(std::chrono::milliseconds(900));
		system("cls");
	}

}


