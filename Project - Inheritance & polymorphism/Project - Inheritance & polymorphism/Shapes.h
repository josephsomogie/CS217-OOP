#pragma once

#include <string>
using namespace std;
class Shape {
public:
	virtual void Scale(float scaleFactor) = 0;
	virtual void Display() const = 0;
	//virtual ~Shape() = 0;
};
//2D shapes classes
class Shape2D : virtual public Shape {
public:
	virtual float Area() const = 0;
	void ShowArea() const; //done
	virtual string GetName2D() const = 0;
	bool operator>(const Shape2D& rhs) const;
	bool operator<(const Shape2D& rhs) const;
	bool operator==(const Shape2D& rhs) const;
};

class Square : public Shape2D {
private:
	float side;
public:
	void setSide(float s);
	float getSide();
	float Area() const override;
	string GetName2D() const override;
	 void Scale(float scaleFactor) override;
	 void Display() const override;

};
class Rectangle : public Shape2D {

};
class Triangle : public Shape2D {

};
class Circle : public Shape2D {

};
class Ellipse : public Shape2D {

};
class Trapezoid : public Shape2D {

};
class Sector : public Shape2D {

};



class Shape3D : virtual public Shape {
public:
	virtual float Volume() const = 0;
	void ShowVolume() const;
	virtual string GetName3D() const = 0;
	bool operator>(const Shape3D& rhs) const;
	bool operator<(const Shape3D& rhs) const;
	bool operator==(const Shape3D& rhs) const;
};

class TriangularPyramid : public Shape3D, public Triangle {

};
class RectangularPyramid : public Shape3D, public Rectangle {

};
class Cylinder : public Shape3D, public Circle {

};
class Sphere : public Shape3D, public Circle {

};



