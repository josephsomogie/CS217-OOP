#pragma once
#include <string>
using namespace std;

void ClearStream();
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
private:
	float side;
public:
	Square();
	Square(float s);
	void setSide(float s);
	float getSide();
	 float Area() const;
	 string GetName2D() const;
	  void Scale(float scaleFactor);
	 void Display() const;

};

class RectangleX : public Shape2D {
private:
	float length, width;
public:
	RectangleX();
	RectangleX(float L, float W);
	void setL(float L);
	void setW(float W);
	float getL();
	float getW();
	 float Area() const;
	 string GetName2D() const;
	 void Scale(float scaleFactor);
	 void Display() const;

	
};
class Triangle : public Shape2D {
private:
	float base, height;
public:
	Triangle();
	Triangle(float b, float h);
	void setB(float b);
	void setH(float h);
	float getB();
	float getH();
	 float Area() const;
	 string GetName2D() const;
	 void Scale(float scaleFactor);
	 void Display() const;

};
class Circle : public Shape2D {
private:
	float radius;
public:
	Circle();
	Circle(float r);
	void setR(float r);
	float getR() const;
	 float Area() const;
	 string GetName2D() const;
	 void Scale(float scaleFactor);
	 void Display() const;
};
class EllipseX : public Shape2D {
private:
	float semiMinorAxis, semiMajorAxis;
public:
	EllipseX();
	EllipseX(float min, float maj);
	void setMin(float min);
	void setMaj(float maj);
	float getMin();
	float getMaj();
	 float Area() const;
	 string GetName2D() const;
	 void Scale(float scaleFactor);
	 void Display() const;

};
class Trapezoid : public Shape2D {
private:
	float sideA, sideB, height;
public:
	Trapezoid();
	Trapezoid(float a, float b, float h);
	void setA(float a);
	void setB(float b);
	void setH(float h);
	float getA();
	float getB();
	float getH();
	 float Area() const;
	 string GetName2D() const;
	 void Scale(float scaleFactor);
	 void Display() const;


};
class Sector : public Shape2D {
private:
	float radius, angleRadians;	
public:
	Sector();
	Sector(float r, float a);
	void setR(float r);
	void setA(float a);
	float getR();
	float getA();
	 float Area() const;
	 string GetName2D() const;
	 void Scale(float scaleFactor);
	 void Display() const;
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

class TriangularPyramid : public Shape3D, private Triangle {
private:
	float heightP;
public:
	TriangularPyramid();
	TriangularPyramid(float hP, float h, float b);
	void setHp(float hP);
	float getHp();
	  float Volume() const;
	  string GetName3D() const;
	  void Scale(float scaleFactor);
	  void Display() const;
	

};
class RectangularPyramid : public Shape3D, private RectangleX {
private:
	float height;
public:
	RectangularPyramid();
	RectangularPyramid(float h, float l, float w);
	void setHeight(float h);
	float getHeight();
	 float Volume() const;
	 string GetName3D() const;
	 void Scale(float scaleFactor);
	 void Display() const;

};
class Cylinder : public Shape3D, private Circle {
private:
	float height;
public:
	Cylinder();
	Cylinder(float r, float h);
	void setHeight(float h);
	float getHeight();
	 float Volume() const;
	 string GetName3D() const;
	 void Scale(float scaleFactor);
	 void Display() const;

};
class Sphere : public Shape3D, private Circle {
public:
	Sphere();
	Sphere(float r);
	 float Volume() const;
	 string GetName3D() const;
	 void Scale(float scaleFactor);
	 void Display() const;

};



