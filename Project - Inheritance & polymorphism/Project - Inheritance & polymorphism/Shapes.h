#pragma once
#include <string>
class Shape {
public:
	virtual void Scale(float scaleFactor) = 0;
	virtual void Display() const = 0;
	virtual ~Shape() = 0;
};
//2D shapes classes
class Shape2D : virtual public Shape {
public:
	virtual float Area() const = 0;
	void ShowArea() const;
	virtual string GetName2D() const = 0;
	bool operator>(const Shape2D& rhs) const;
	bool operator<(const Shape2D& rhs) const;
	bool operator==(const Shape2D& rhs) const;
};

class Square : public Shape2D {

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



