#include <iostream>
#include <string>

class IShape {
public:
	virtual double GetPerimetr() = 0;
	virtual double GetSquare() = 0;
	virtual IShape* Clone() = 0;

	virtual ~IShape() { std::cout << "IShape destructor" << std::endl; }
};

class Rectangle : public IShape {
private:
	double x;
	double y;

	Rectangle(const Rectangle& rect) {
		this->x = rect.x;
		this->y = rect.y;
	}
public:
	Rectangle() : x{ 0 }, y{ 0 } {}

	double GetPerimetr() override { return 2 * (x + y); }
	double GetSquare() override { return x * y; }
	Rectangle* Clone() override {
		return new Rectangle(*this);
	}

	double GetX() { return x; }
	void SetX(double x) { this->x = x; }

	double GetY() { return y; }
	void SetY(double y) { this->y = y; }

	~Rectangle() {
		std::cout << "Recangle destructor" << std::endl;
	}
};

class Circle : public IShape {
private:
	double radius;

	Circle(const Circle& circle) {
		this->radius = circle.radius;
	}

public:
	Circle() : radius{ 0 } {}

	double GetPerimetr() override { return 2 * 3.14 * radius; }
	double GetSquare() override { return 3.14 * radius * radius; }
	Circle* Clone() override { return new Circle(*this); }

	double GetRadius() { return radius; }
	void SetRadius(double r) { this->radius = r; }

	~Circle() {
		std::cout << "Circle destructor" << std::endl;
	}
};

int main() {
	Circle* circle = new Circle();

	Circle* clone = circle->Clone();

	std::cout << circle << std::endl;
	std::cout << clone << std::endl;

	delete circle;
	delete clone;
}