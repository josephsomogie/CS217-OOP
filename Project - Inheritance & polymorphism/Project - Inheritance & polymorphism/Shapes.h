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
	Square();
	Square(float s);
	void setSide(float s);
	float getSide();
	float Area() const override;
	string GetName2D() const override;
	 void Scale(float scaleFactor) override;
	 void Display() const override;

};
class Rectangle : public Shape2D {
private:
	float length, width;
public:
	Rectangle();
	Rectangle(float L, float W);
	void setL(float L);
	void setW(float W);
	float getL();
	float getW();
	float Area() const override;
	string GetName2D() const override;
	void Scale(float scaleFactor) override;
	void Display() const override;

	
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
	float Area() const override;
	string GetName2D() const override;
	void Scale(float scaleFactor) override;
	void Display() const override;

};
class Circle : public Shape2D {
private:
	float radius;
public:
	Circle();
	Circle(float r);
	void setR(float r);
	float getR();
	float Area() const override;
	string GetName2D() const override;
	void Scale(float scaleFactor) override;
	void Display() const override;
};
class Ellipse : public Shape2D {
private:
	float semiMinorAxis, semiMajorAxis;
public:
	Ellipse();
	Ellipse(float min, float maj);
	void setMin(float min);
	void setMaj(float maj);
	float getMin();
	float getMaj();
	float Area() const override;
	string GetName2D() const override;
	void Scale(float scaleFactor) override;
	void Display() const override;

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
	float Area() const override;
	string GetName2D() const override;
	void Scale(float scaleFactor) override;
	void Display() const override;


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
	float Area() const override;
	string GetName2D() const override;
	void Scale(float scaleFactor) override;
	void Display() const override;
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
	void setHp(float hP);
	float getHp();
	 float Volume() const override;
	 string GetName3D() const override;
	 void Scale(float scaleFactor) override;
	 void Display() const override;
	

};
class RectangularPyramid : public Shape3D, private Rectangle {

};
class Cylinder : public Shape3D, private Circle {

};
class Sphere : public Shape3D, private Circle {

};



