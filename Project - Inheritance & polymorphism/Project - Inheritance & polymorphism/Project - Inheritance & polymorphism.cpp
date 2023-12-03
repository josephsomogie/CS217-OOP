

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
		"1: Test 2D",
		"2: Test 3D",
		"3: Add Shape",
		"4: Delete Shape",
		"5: Sort list",
		"6: Clear list",
		"7: Display Shape",
		"8: Test 2D&3D",
		
};

//menu Functions
void ColorCycle(string text, int numCycles, int cycleSpeed);
void ClearLine(int len);
template<class T>
void ErrorCheckLoop(T& userInput);
//search & sort Functions
template<class T>
int binarySearch2D(float targetArea, const vector<T*>& vec);
template<class T>
int binarySearch3D(float targetArea, const vector<T*>& vec);
void insertionSort(vector<Shape2D*>& vec);
void insertionSort(vector<Shape3D*>& vec);
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
	vector<Shape2D*> shapes2D;
	vector<Shape3D*> shapes3D;
	vector<Shape2D*> test2d;
	vector<Shape3D*> test3d;
	vector<Shape*> testMixed;
	bool menu = true;
	//Welcome Message
	cout << RED;
	cout << "						 (Press Enter to Skip)\n";
	string title = "                                 Joseph Somogie Project: Inheritance & polymorphism";
	while(!_kbhit())
	ColorCycle(title, 1, 100);
	ClearStream();


	
	//Menu
	string msg = "";
	char command = '0';
	short optionIndex = 0;
	float select = 0;
	while (menu)
	{
		select = -1;
		command = '0';
		optionIndex = 0;

		
		
			system("cls");

			cout << RED;
			cout << "*********************************************\n";
			cout << YELLOW;
			cout << "******PRESS NUM KEY FOR DESIRED COMMAND*******\n";
			cout << BLUE;
			//cout << "1: Add Shape" << endl;
			cout << "1: Test 2D" << endl;
			cout << "2: Test 3D" << endl;
			cout << "3: Add Shape" << endl;
			cout << "4: Delete Shape" << endl;
			cout << "5: Sort List" << endl;
			cout << "6: Clear List" << endl;
			cout << "7: Display Shape" << endl;
			cout << "8: Test 2D&3D" << endl;
			cout << "0: Exit Program" << endl;
			cout << YELLOW;
			cout << "*********************************************\n";
			cout << RED;
			cout << " --> ";
			cout << COLOR_RESET;
			cout << GREEN;
			command = _getch();
			optionIndex = command - '0';
			while (optionIndex  > 9 || optionIndex < 0) {
				cout << CYAN;
				cout << "Invalid Command!";
				_getch();
				ClearLine(16);
				
				cout << GREEN;
				
				
				command = _getch();
				optionIndex = command - '0';
				
			}
			 
			cout << options[optionIndex] << endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(400));

			switch (command)
			{
			case '0': //Exit Program
				cout << CYAN;
				cout << "THANKS!\n";
				return 0;

				break;
			case '1': //Test 2D
				ColorCycle("TEST 2D", 1, 100);
				if (test2d.size() == 0) {
					test2d.push_back(new Square);
					test2d.push_back(new Square(1.1));
					test2d.push_back(new RectangleX);
					test2d.push_back(new RectangleX(2.2, 3.3));
					test2d.push_back(new Triangle());
					test2d.push_back(new Triangle(4.4, 5.5));
					test2d.push_back(new Circle());
					test2d.push_back(new Circle(6.6));
					test2d.push_back(new EllipseX());
					test2d.push_back(new EllipseX(7.7, 8.8));
					test2d.push_back(new Trapezoid());
					test2d.push_back(new Trapezoid(1, 2, 3));
					test2d.push_back(new Sector());
					test2d.push_back(new Sector(5, 6));
				}
				for (auto Shape2D : test2d) {
					std::this_thread::sleep_for(std::chrono::milliseconds(200));
					Shape2D->Display();
					cout << '\n';
				}
				cout << RED;
				cout << "(Press enter to sort)";
				_getch();
				ClearLine(26);
				ColorCycle("Sorting...", 1, 100);
				cout << "-------------------\n";
				insertionSort(test2d);
				for (auto Shape2D : test2d) {
					std::this_thread::sleep_for(std::chrono::milliseconds(200));
					Shape2D->Display();
					cout << '\n';
				}
				cout << "(Press enter to find min/max)";
				_getch();
				std::this_thread::sleep_for(std::chrono::milliseconds(200));
				cout << "\nMIN\n";
				test2d[0]->Display();
				cout << '\n';
				std::this_thread::sleep_for(std::chrono::milliseconds(200));
				cout << "MAX\n";
				test2d[test2d.size() - 1]->Display();
				cout << '\n';
				cout << "(Press enter to search by area)";
				_getch();
				ClearStream();
				cout << "Enter area: ";
				ErrorCheckLoop(select);
				optionIndex = binarySearch2D(select, test2d);
				cout << "\n Closest area shape was index #" << optionIndex << endl;
				test2d[optionIndex]->Display();

				cout << "(Press enter to scale this shape)";
				_getch();
				cout << "Enter Scalar: ";
				ErrorCheckLoop(select);
				test2d[optionIndex]->Scale(select);
				cout << "\n Scaled Shape\n";
				test2d[optionIndex]->Display();

				cout << RED << "\nEND OF DEMO" << endl;
				_getch();
				
				
				break;
			case '2': //Test 3D
				ColorCycle("TEST 3D", 1, 100);
				if (test3d.size() == 0) {
					test3d.push_back(new TriangularPyramid());
					test3d.push_back(new TriangularPyramid(3, 4, 5));
					test3d.push_back(new RectangularPyramid());
					test3d.push_back(new RectangularPyramid(5, 6, 7));
					test3d.push_back(new Cylinder());
					test3d.push_back(new Cylinder(3, 6));
					test3d.push_back(new Sphere());
					test3d.push_back(new Sphere(9));
				}
				for (auto Shape3D : test3d) {
					std::this_thread::sleep_for(std::chrono::milliseconds(200));
					Shape3D->Display();
					cout << '\n';
				}
				cout << RED;
				cout << "(Press enter to sort)";
				_getch();
				ClearLine(26);
				ColorCycle("Sorting...", 1, 100);
				cout << "-------------------\n";
				insertionSort(test3d);
				for (auto Shape3D : test3d) {
					std::this_thread::sleep_for(std::chrono::milliseconds(200));
					Shape3D->Display();
					cout << '\n';
				}
				cout << "(Press enter to find min/max)";
				_getch();
				std::this_thread::sleep_for(std::chrono::milliseconds(200));
				cout << "\nMIN\n";
				test3d[0]->Display();
				cout << '\n';
				std::this_thread::sleep_for(std::chrono::milliseconds(200));
				cout << "MAX\n";
				test3d[test3d.size() - 1]->Display();
				cout << '\n';
				cout << "(Press enter to search by Volume)";
				_getch();
				ClearStream();
				cout << "Enter volume: ";
				ErrorCheckLoop(select);
				optionIndex = binarySearch3D(select, test3d);
				cout << "\n Closest volume shape was index #" << optionIndex << endl;
				test3d[optionIndex]->Display();

				cout << "(Press enter to scale this shape)";
				_getch();
				cout << "Enter Scalar: ";
				ErrorCheckLoop(select);
				test3d[optionIndex]->Scale(select);
				cout << "\n Scaled Shape\n";
				test3d[optionIndex]->Display();

				cout << RED << "\nEND OF DEMO" << endl;
				_getch();
				
				break;
			case '3': //Add Shape
				cout << CYAN;
				cout << "PRESS: (1) 2D Shape (2) 3D Shape";
				 select = _getch() - '0';
				if (select == 1) {
					cout << MAGENTA;
					cout << "\n2D SHAPES:\n";
					cout << YELLOW;
					cout << "Square: 1\n";
					cout << "Rectangle: 2\n";
					cout << "Triangle: 3\n";
					cout << "Circle: 4\n";
					cout << "Ellipse: 5\n";
					cout << "Trapezoid: 6\n";
					cout << "Sector: 7\n";
					select = _getch() - '0';

					if (select == 1) {
						float s;
						cout << BLUE;
						cout << "Enter Square Side: ";
						ErrorCheckLoop(s);
						shapes.push_back(new Square(s));
						shapes2D.push_back(new Square(s));
					}
					if (select == 2) {
						float l, w;
						cout << BLUE;
						cout << "Enter Rectangle Length: ";
						ErrorCheckLoop(l);
						cout << "Enter Rectangle Width: ";
						ErrorCheckLoop(w);
						shapes.push_back(new RectangleX(l, w));
						shapes2D.push_back(new RectangleX(l, w));
					}
					if (select == 3) {
						float b, h;
						cout << BLUE;
						cout << "Enter Triangle Base: ";
						ErrorCheckLoop(b);
						cout << "Enter Triangle Height: ";
						ErrorCheckLoop(h);
						shapes.push_back(new Triangle(b, h));
						shapes2D.push_back(new Triangle(b, h));
					}
					if (select == 4) {
						float r;
						cout << "Enter Circle Radius: ";
						ErrorCheckLoop(r);
						shapes.push_back(new Circle(r));
						shapes2D.push_back(new Circle(r));

					}
					if (select == 5) {
						float min, maj;
						cout << "Enter Semi Minor Axis: ";
						ErrorCheckLoop(min);
						cout << "Enter Semi Major Axis: ";
						ErrorCheckLoop(maj);
						shapes.push_back(new EllipseX(min, maj));
						shapes2D.push_back(new EllipseX(min, maj));

					}
					if (select == 6) {
						float a, b, h;
						cout << "Enter Side A: ";
						ErrorCheckLoop(a);
						cout << "Enter Side B: ";
						ErrorCheckLoop(b);
						cout << "Enter Height: ";
						ErrorCheckLoop(h);
						shapes.push_back(new Trapezoid(a, b, h));
						shapes2D.push_back(new Trapezoid(a, b, h));
					}
					if (select == 7) {
						float r, a;
						cout << "Enter Radius: ";
						ErrorCheckLoop(r);
						cout << "Enter Angle (Radians) : ";
						ErrorCheckLoop(a);
						shapes.push_back(new Sector(r, a));
						shapes2D.push_back(new Sector(r, a));
					}
				}
				else if (select == 2) {
					cout << GREEN;
					cout << "\n3D SHAPES:\n";
					cout << RED;
					cout << "Triangular Pyramid: 1\n";
					cout << "Rectangular Pyramid: 2\n";
					cout << "Cylinder: 3\n";
					cout << "Sphere: 4\n";
					select = _getch() - '0';
					if (select == 1) {
						float b, h, hP;
						cout << GREEN;
						cout << "Enter Triangle Base: ";

						ErrorCheckLoop(b);
						cout << "\nEnter Triangle Height: ";
						ErrorCheckLoop(h);
						cout << "Enter Pyramid Height: ";
						ErrorCheckLoop(hP);
						shapes.push_back(new TriangularPyramid(hP, h, b));
						shapes3D.push_back(new TriangularPyramid(hP, h, b));
					}
					if (select == 2) {
						float l, w, h;
						cout << GREEN;
						cout << "Enter Rectangualr Pyramid Height: ";
						ErrorCheckLoop(h);
						if (h != -1) {
							cout << "Enter Rectangular Pyramid Length";
							ErrorCheckLoop(l);
							if (l != -1) {
								cout << "Enter Rectangular Pyramid Width";
								ErrorCheckLoop(w);
								if (w != -1);
								shapes.push_back(new RectangularPyramid(h, l, w));
								shapes3D.push_back(new RectangularPyramid(h, l, w));
							}
						}
					}
					if (select == 3) {
						float r, h;
						cout << GREEN;
						cout << "Enter Cylinder Raidus: ";
						ErrorCheckLoop(r);
						if (r != -1) {

							cout << "Enter Cylinder Height: ";

							ErrorCheckLoop(h);
							if (h != -1)
								shapes.push_back(new Cylinder(r, h));
							shapes3D.push_back(new Cylinder(r, h));
						}
					}
					if (select == 4) {
						float r;
						cout << GREEN;
						cout << "Enter Sphere Radius: ";

						ErrorCheckLoop(r);
						if(r!=-1)
						shapes.push_back(new Sphere(r));
						shapes3D.push_back(new Sphere(r));
					}
				}

				break;
			case '4': //delete Shape
				cout << "PRESS: (1) 2D Shape (2) 3D Shape";
				select = _getch() - '0';
				cout << '\n';
				if (select == 1 && !shapes2D.empty()) {
					cout << "Enter index of shape: ";
					ErrorCheckLoop(select);
					while (select < 0 || select >= shapes2D.size()) {
						cout << RED;
						cout << " ERROR! INVALID INDEX";
						ErrorCheckLoop(select);

					}
					delete shapes2D[select];
					shapes2D.erase(shapes2D.begin() + select);
					cout << "Shape Deleted" << endl;

				}
				if (select == 2 && !shapes3D.empty()) {
					cout << "Enter index of shape: ";
					ErrorCheckLoop(select);
					while (select < 0 || select >= shapes3D.size()) {
						cout << RED;
						cout << " ERROR! INVALID INDEX";
						ErrorCheckLoop(select);

					}
					delete shapes3D[select];
					shapes3D.erase(shapes3D.begin() + select);
					cout << "Shape Deleted" << endl;

				}
				else ColorCycle("Cancelling...", 1, 100);

			
				break;
			case '5': //Sort Shapes
				cout << RED;
				msg = "Sorting...";
				ColorCycle(msg, 2, 100);
				insertionSort(shapes2D);
				insertionSort(shapes3D);
				cout << CYAN;
				
				break;
			case '6': //Clear List
				cout << "PRESS: (1) 2D Shape (2) 3D Shape";
				select = _getch() - '0';
				cout << '\n';

				cout << RED;
				msg = "Clearing List...";
				ColorCycle(msg, 2, 100);
				if (select == 1) {
					for (auto& Shape2D : shapes2D) {
						delete Shape2D;
					}
					shapes2D.clear();
				}
				if (select == 2) {
					for (auto& Shape3D : shapes3D) {
						delete Shape3D;
					}
					shapes3D.clear();
				}
					ClearLine(msg.length()); 
					cout << CYAN;
					cout << "Cleared!";
	
					ClearStream();
				
				break;
			case '7': //Display Shape
				

				cout << CYAN;
				cout << "PRESS: (1) 2D Shape (2) 3D Shape";
				select = _getch() - '0';
				cout << '\n';
				if (select == 1) {


					for (auto Shape2D : shapes2D) {

						Shape2D->Display();

						cout << '\n';
					}
				}
				else if (select == 2) {

					for (auto Shape3D : shapes3D) {
						Shape3D->Display();
						cout << '\n';
					}
				}
				cout << "(Press enter to continue)";
				_getch();
				ClearStream();
				

				break;
			case '8': //Test Mixed
				ColorCycle("TEST MIXED SHAPES", 1, 100);
				if (testMixed.size() == 0) {
					testMixed.push_back(new TriangularPyramid());
					testMixed.push_back(new Square(5));
					testMixed.push_back(new TriangularPyramid(3, 4, 5));
					testMixed.push_back(new RectangleX(3, 5.5));
					testMixed.push_back(new RectangularPyramid());
					testMixed.push_back(new RectangularPyramid(5, 6, 7));
					testMixed.push_back(new Cylinder());
					testMixed.push_back(new Cylinder(3, 6));
					testMixed.push_back(new Sphere());
					testMixed.push_back(new Sphere(9));
				}
				for (auto Shape : testMixed) {
					std::this_thread::sleep_for(std::chrono::milliseconds(200));
					Shape->Display();
					cout << '\n';
				}
				cout << RED;
				cout << "(Press enter to scale)";
				_getch();
				cout << "Enter shape index to scale: ";
				ErrorCheckLoop(optionIndex);
				while (optionIndex >= testMixed.size() || optionIndex < 0) {
					cout << "Enter valid index 0-" << testMixed.size() - 1 << " :";
					ErrorCheckLoop(optionIndex);
				}
				testMixed[optionIndex]->Display();
				cout << "\nEnter Scalar: ";
				ErrorCheckLoop(select);
				testMixed[optionIndex]->Scale(select);
				cout << "\n Scaled Shape\n";
				testMixed[optionIndex]->Display();

				cout << RED << "\nEND OF DEMO" << endl;
				_getch();
				break;
			case '9': //Search Shapes (broken)
				cout << "PRESS: (1) 2D Shape (2) 3D Shape";
				select = _getch() - '0';

				if (select == 1)
				{
					cout << "Enter Area: ";
					ErrorCheckLoop(select);
					optionIndex = binarySearch2D(select, shapes2D);
					cout << "\nShape is index #" << optionIndex << endl;
					shapes2D[optionIndex]->Display();
				}
				if (select == 2)
				{
					cout << "Enter Volume: ";
					ErrorCheckLoop(select);
					optionIndex = binarySearch3D(select, shapes3D);
					cout << "\nShape is index #" << optionIndex << endl;
					shapes3D[optionIndex]->Display();
				}
				break;


			}

			std::this_thread::sleep_for(std::chrono::milliseconds(900));
			ClearStream();
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
	
template<class T>
void ErrorCheckLoop(T& userInput) {
	cin >> userInput;
	string errMsg = "ERROR: INVALID INPUT!";
	
	while (cin.fail()) {
		cout << RED;
		cout << errMsg;
		std::this_thread::sleep_for(std::chrono::seconds(1));
		cout << WHITE;
		ClearLine(22);
		cout << "Enter " << typeid(T).name() << ": ";
		ClearStream();

		cin >> userInput;
		 
		
	}
}

template<class T>
int binarySearch2D(float targetArea, const std::vector<T*>& vec) {
	int low = 0;
	int high = vec.size() - 1;
	int closestIndex = -1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		double midArea = vec[mid]->Area();

		if (midArea >= targetArea) {
			closestIndex = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return closestIndex;
}

// Binary search algorithm for vector<Shape3D*>
template<class T>
int binarySearch3D(float targetVolume, const std::vector<T*>& vec) {
	int low = 0;
	int high = vec.size() - 1;
	int closestIndex = -1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		double midVolume = vec[mid]->Volume();

		if (midVolume >= targetVolume) {
			closestIndex = mid;
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}

	return closestIndex;
}
void insertionSort(vector<Shape2D*>& vec) {
	int n = vec.size();

	for (int i = 1; i < n; i++) {
		Shape2D* key = vec[i];
		int j = i - 1;

		while (j >= 0 && *vec[j] > *key) {
			vec[j + 1] = vec[j];
			j = j - 1;
		}

		vec[j + 1] = key;
	}
}
void insertionSort(vector<Shape3D*>& vec) {
	int n = vec.size();

	for (int i = 1; i < n; i++) {
		Shape3D* key = vec[i];
		int j = i - 1;

		while (j >= 0 && *vec[j] > *key) {
			vec[j + 1] = vec[j];
			j = j - 1;
		}

		vec[j + 1] = key;
	}
}


