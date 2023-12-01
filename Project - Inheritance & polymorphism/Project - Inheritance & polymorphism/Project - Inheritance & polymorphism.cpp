

#include <iostream>
#include <cmath>
#include <cstdlib>
#include "Shapes.h"
#include <vector>
#include <chrono>
#include <thread>
#include <Windows.h>
#include <conio.h>

const string BLACK = "\033[30m";
const string RED = "\033[31m";
const string GREEN = "\033[32m";
const string YELLOW = "\033[33m";
const string BLUE = "\033[34m";
const string MAGENTA = "\033[35m";
const string CYAN = "\033[36m";
const string WHITE = "\033[37m";
const string COLOR_RESET = "\033[0m";

const string options[] = {
		"0: Exit Program",
		"1: Add Shape",
		"2: Delete Shape",
		"3: Clear List",
		"4: Sort list",
		"5: Search shapes",
		"6: Display Shape",
		"7: Demo"
};
//menu Functions
void ColorCycle(string text, int numCycles, int cycleSpeed);
void ClearLine(int len);
using namespace std;
int main()
{
	/*vector<Shape*> shapes;
	shapes.push_back(new Square);
	shapes.push_back(new Square(1.1));
	shapes.push_back(new Rectangle);
	shapes.push_back(new Rectangle(2.2, 3.3));

	for (unsigned int i = 0; i < shapes.size(); i++)
		shapes[i]->Display();
	for (unsigned int i = 0; i < shapes.size(); i++) delete shapes[i];*/
		
	//list creation
	vector<Shape*> shapes;
	bool menu = true;
	//Welcome Message
	cout << CYAN;
	string title = "Joseph Somogie Project: Inheritance & polymorphism";
	ColorCycle(title, 100, 150);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	ClearLine(51);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	
	
	//Menu
	char command = '0';
	short optionIndex = 0;
	while (menu)
	{

		

			system("cls");

			cout << RED;
			cout << "*********************************************\n";
			cout << YELLOW;
			cout << "******PRESS NUM KEY FOR DESIRED COMMAND*******\n";
			cout << BLUE;
			cout << "1: Add Shape" << endl;
			cout << "2: Delete Shape" << endl;
			cout << "3: Clear List" << endl;
			cout << "4: Sort list" << endl;
			cout << "5: Search shapes" << endl;
			cout << "6: Display Shape" << endl;
			cout << "7: Demo" << endl;
			cout << "0: Exit Program" << endl;
			cout << YELLOW;
			cout << "*********************************************\n";
			cout << RED;
			cout << " --> ";

			cout << COLOR_RESET;
			cout << GREEN;
			while ((command = _getch()) > '9' || (command = _getch()) < '0') {
				cout << CYAN;
				cout << "Invalid Command!\n";
				cout << COLOR_RESET;
				std::this_thread::sleep_for(std::chrono::seconds(1));
				
			}
			 optionIndex = command - '0';
			cout << options[optionIndex] << endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(400));

			switch (command)
			{
			case '0':
				cout << CYAN;
				cout << "THANKS!\n";
				return 0;

				break;
			case '1':
				break;
			case '2':
				break;
			case '3':
				break;
			case '4':
				break;
			case '5':
				break;
			case '6':
				break;
			case '7':
				break;
			case '8':
				break;
			case '9':
				break;


			}

			std::this_thread::sleep_for(std::chrono::milliseconds(900));
			system("cls");
		
	}
	return 0;
}

void ColorCycle(string text, int numCycles = 1, int cycleSpeed = 50) {
	while (numCycles > 0) {
		cout << RED;
		cout << text;
		std::this_thread::sleep_for(std::chrono::milliseconds(cycleSpeed));
		ClearLine(text.length());
		cout << GREEN;
		cout << text;
		std::this_thread::sleep_for(std::chrono::milliseconds(cycleSpeed));
		ClearLine(text.length());
		cout << YELLOW;
		cout << text;
		std::this_thread::sleep_for(std::chrono::milliseconds(cycleSpeed));
		ClearLine(text.length());
		cout << BLUE;
		cout << text;
		std::this_thread::sleep_for(std::chrono::milliseconds(cycleSpeed));
		ClearLine(text.length());
		cout << MAGENTA;
		cout << text;
		std::this_thread::sleep_for(std::chrono::milliseconds(cycleSpeed));
		ClearLine(text.length());
		cout << CYAN;
		cout << text;
		std::this_thread::sleep_for(std::chrono::milliseconds(cycleSpeed));
		ClearLine(text.length());
		cout << WHITE;
		cout << text;
		std::this_thread::sleep_for(std::chrono::milliseconds(cycleSpeed));
		ClearLine(text.length());

		numCycles--;
	}
}
void ClearLine(int len) {
	string str(len, ' ');
	cout.flush();
	for (int i = 0; i < len; ++i) {
		cout << '\b';
	}
	cout << str;
	for (int i = 0; i < len; ++i) {
		cout << '\b';
	}
}


