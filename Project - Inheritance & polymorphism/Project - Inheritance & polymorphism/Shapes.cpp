#include "Shapes.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//Shape




//Shape2d
void Shape2D::ShowArea() const {
	cout << "Area is " << Area() << endl;
}
bool Shape2D::operator<(const Shape2D& rhs) const {
	return this->Area() < rhs.Area();
}
bool Shape2D::operator>(const Shape2D& rhs) const {
	return this->Area() > rhs.Area();
}
bool Shape2D::operator==(const Shape2D& rhs) const {
	return this->Area() == rhs.Area();
}
	/*Square*/
float Square::Area() const{
	return  pow(side, 2);
}
string Square::GetName2D() const{
	return "Square";
}
void Square::setSide(float s) {
	Square::side = s;
}
float Square::getSide() {
	return Square::side;
}
void Square::Scale(float scaleFactor) {
	side *= scaleFactor;
}
void Square::Display() const {
	ShowArea();
}
//Shape3d
void Shape3D::ShowVolume() const {
	cout << "Volume is " << Volume() << endl;
}
bool Shape3D::operator<(const Shape3D& rhs) const {
	return this->Volume() < rhs.Volume();
}
bool Shape3D::operator>(const Shape3D& rhs) const {
	return this->Volume() > rhs.Volume();
}
bool Shape3D::operator==(const Shape3D& rhs) const {
	return this->Volume() == rhs.Volume();
}

