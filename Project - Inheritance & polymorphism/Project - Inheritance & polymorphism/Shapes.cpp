#include "Shapes.h"
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

void ClearStream()
{
	cin.clear();
	cin.ignore(INT_MAX, '\n');
}

//Shape
Shape::~Shape() {

}



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
	/*Square****************************************************************************************/
Square::Square() {
	setSide(0);
}
Square::Square(float s) {
	setSide(s);
}
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
	cout << "Shape is a " << GetName2D() << endl;
	ShowArea();
}
/*Rectangle*******************************************************************************************/
RectangleX::RectangleX() {
	setL(0);
	setW(0);
}
RectangleX::RectangleX(float L, float W) {
	setL(L);
	setW(W);
}
void RectangleX::setL(float L) {
	length = L;
}
void RectangleX::setW(float W) {
	width = W;
}
float RectangleX::getL() {
	return length;
}
float RectangleX::getW() {
	return width;
}
float RectangleX::Area() const {
	return length * width;
}
string RectangleX::GetName2D() const {
	return "Rectangle";
}
void RectangleX::Scale(float scaleFactor) {
	length *= scaleFactor;
	width *= scaleFactor;
}
void RectangleX::Display() const{
	cout << "Shape is a " << GetName2D() << endl;
	ShowArea();
}
/*Triangle*******************************************************************************************/
Triangle::Triangle() {
	setB(0);
	setH(0);
}
Triangle::Triangle(float b, float h) {
	setB(b);
	setH(h);
}
void Triangle::setB(float b) {
	base = b;
}
void Triangle::setH(float h) {
	height = h;
}
float Triangle::getB() {
	return base;
}
float Triangle::getH() {
	return height;
}
float Triangle::Area() const {
	return (0.5 * (base * height));
}
string Triangle::GetName2D() const {
	return "Triangle";
}
void Triangle::Scale(float scaleFactor) {
	base *= scaleFactor;
	height *= scaleFactor;
}
void Triangle::Display() const {
	cout << "Shape is a " << GetName2D() << endl;
	ShowArea();
}
/*Circle********************************************************************************************/
Circle::Circle() {
	setR(0);
}
Circle::Circle(float r) {
	setR(r);
}
void Circle::setR(float r) {
	radius = r;
}
float Circle::getR() const {
	return radius;
}
float Circle::Area() const {
	return (3.14159265359 * (pow(radius, 2)));
}
string Circle::GetName2D() const {
	return "Circle";
}
void Circle::Scale(float scaleFactor) {
	radius *= scaleFactor;
}
void Circle::Display() const {
	cout << "Shape is a " << GetName2D() << endl;
	ShowArea();
}
/*Ellipse*******************************************************************************************/
EllipseX::EllipseX() {
	setMin(0);
	setMaj(0);
}
EllipseX::EllipseX(float min, float maj) {
	setMin(min);
	setMaj(maj);
}
void EllipseX::setMin(float min) {
	semiMinorAxis = min;
}
void EllipseX::setMaj(float maj) {
	semiMajorAxis = maj;
}
float EllipseX::getMin() {
	return semiMinorAxis;
}
float EllipseX::getMaj() {
	return semiMajorAxis;
}
float EllipseX::Area() const {
	return (3.14159265359 * (semiMinorAxis * semiMajorAxis));
}
string EllipseX::GetName2D() const {
	return "Ellipse";
}
void EllipseX::Scale(float scaleFactor)  {
	semiMinorAxis *= scaleFactor;
	semiMajorAxis *= scaleFactor;
}
void EllipseX::Display() const {
	cout << "Shape is a " << GetName2D() << endl;
	ShowArea();
}
/*Trapezoid****************************************************************************************/
Trapezoid::Trapezoid() {
	setA(0);
	setB(0);
	setH(0);
}
Trapezoid::Trapezoid(float a, float b, float h) {
	setA(a);
	setB(b);
	setH(h);
}
void Trapezoid::setA(float a) {
	sideA = a;
}
void Trapezoid::setB(float b) {
	sideB = b;
}
void Trapezoid::setH(float h) {
	height = h;
}
float Trapezoid::getA() {
	return sideA;
}
float Trapezoid::getB() {
	return sideB;
}
float Trapezoid::getH() {
	return height;
}
float Trapezoid::Area() const {
	return (0.5 * (sideA + sideB) * height);
}
string Trapezoid::GetName2D() const {
	return "Trapezoid";
}
void Trapezoid::Scale(float scaleFactor) {
	sideA *= scaleFactor;
	sideB *= scaleFactor;
	height *= scaleFactor;
}
void Trapezoid::Display() const {
	cout << "Shape is a " << GetName2D() << endl;
	ShowArea();
}
/*Sector*******************************************************************************************/
Sector::Sector() {
	setR(0);
	setA(0);
}
Sector::Sector(float r, float a) {
	setR(r);
	setA(a);
}
void Sector::setR(float r) {
	radius = r;
}
void Sector::setA(float a) {
	angleRadians = a;
}
float Sector::getR() {
	return radius;
}
float Sector::getA() {
	return angleRadians;
}
float Sector::Area() const {
	return (0.5 * pow(radius, 2) * angleRadians);
}
string Sector::GetName2D() const {
	return "Sector";
}
void Sector::Scale(float scaleFactor) {
	radius *= scaleFactor;
	angleRadians *= scaleFactor;
}
void Sector::Display() const {
	cout << "Shape is a " << GetName2D() << endl;
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

/*Triangular Pyramid****************************************************************************/
TriangularPyramid::TriangularPyramid() {
	
	setHp(0);
	setH(0);
	setB(0);
}
TriangularPyramid::TriangularPyramid(float hP, float h, float b) {
	setHp(hP);
	setH(h);
	setB(b);

}

void TriangularPyramid::setHp(float hP) {
	heightP = hP;
}
float TriangularPyramid::getHp() {
	return heightP;
}
float TriangularPyramid::Volume() const {
	return (Area() * heightP) / 3;
}
string TriangularPyramid::GetName3D() const {
	return "Triangular Pyramid";
}
void TriangularPyramid::Scale(float scaleFactor) {
	heightP *= scaleFactor;
	setH(getH() * scaleFactor);
	setB(getB() * scaleFactor);

}
void TriangularPyramid::Display() const {
	cout << "Shape is a " << GetName3D() << endl;
	ShowVolume();
}

/*Rectangular Pyramid******************************************************************************/
RectangularPyramid::RectangularPyramid() {
	setHeight(0);
	setL(0);
	setW(0);
}
RectangularPyramid::RectangularPyramid(float h, float l, float w) {
	setHeight(h);
	setL(l);
	setW(w);
}
void RectangularPyramid::setHeight(float h) {
	height = h;
}
float RectangularPyramid::getHeight() {
	return height;
}
float RectangularPyramid::Volume() const {
	return (Area() * height) / 3;
}
string RectangularPyramid::GetName3D() const {
	return "Rectangular Pyramid";
}
void RectangularPyramid::Scale(float scaleFactor) {
	setL(getL() * scaleFactor);
	setW(getW() * scaleFactor);
	height *= scaleFactor;
}
void RectangularPyramid::Display() const {
	cout << "Shape is a " << GetName3D() << endl;
	ShowVolume();
}
/*Cylinder********************************************************************************************/
 Cylinder::Cylinder() {
	 setR(0);
	 setHeight(0);
}
 Cylinder::Cylinder(float r, float h) {
	 setR(r);
	 setHeight(h);
 }
 void Cylinder::setHeight(float h) {
	 height = h;
 }
 float Cylinder::getHeight() {
	 return height;
 }
 float Cylinder::Volume() const {
	 return (Area() * height);
 }
 string Cylinder::GetName3D() const {
	 return "Cylinder";
 }
 void Cylinder::Scale(float scaleFactor) {
	 setR(getR() * scaleFactor);
	 height *= scaleFactor;
 }
 void Cylinder::Display() const {
	 cout << "Shape is a " << GetName3D() << endl;
	 ShowVolume();
 }
 /*Sphere****************************************************************************************/
 Sphere::Sphere() {
	 setR(0);
 }
 Sphere::Sphere(float r) {
	 setR(r);
 }
 float Sphere::Volume() const {
	 return (4 * Area() * getR()) / 3;
 }
 string Sphere::GetName3D() const {
	 return "Sphere";
 }
 void Sphere::Scale(float scaleFactor) {
	 setR(getR() * scaleFactor);
 }
 void Sphere::Display() const {
	 cout << "Shape is a " << GetName3D() << endl;
	 ShowVolume();
 }