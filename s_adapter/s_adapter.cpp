#include <iostream>
#include <string>

class Square {
private:
	int x_;
public:
	Square() : x_{ 0 } { std::cout << "Square constuctor" << std::endl; }
	Square(int x) {
		x_ = x;
	}
	void SetX(int x) {
		this->x_ = x;
	}
	int GetX() const {
		return this->x_;
	}
};

class Circle {
private:
	double radius_;
public:
	Circle() : radius_{0} { std::cout << "Circle constuctor" << std::endl; }
	Circle(double radius) {
		radius_ = radius;
		std::cout << "Circle constuctor" << std::endl;
	}
	void SetRadius(double radius) {
		this->radius_ = radius;
	}
	double GetRadius() {
		return radius_;
	}
};

class AdapterForCircle : public Circle {
private:
	Circle* circle_;
public:
	AdapterForCircle(Circle* circle) : circle_{ new Circle(*circle) } {
		std::cout << "AdapterForCircle constructor" << std::endl;
	}

	AdapterForCircle(const Square& square) : circle_{ new Circle(square.GetX()) } {
		std::cout << "AdapterForCircle constructor" << std::endl;
	}

	AdapterForCircle& operator=(const Square& square) {
		this->SetRadius(square.GetX());
		return *this;
	}
	Circle* GetCircle() {
		return circle_;
	}
	~AdapterForCircle() {
		delete circle_;
		std::cout << "AdapterForCircle destructor" << std::endl;
	}
};

int main() {
	Square* square = new Square(6);
	Circle* circle = new Circle();


	AdapterForCircle* adapter = new AdapterForCircle(circle);
	*adapter = *square;

	Circle* two = adapter->GetCircle();
	std::cout << two->GetRadius() << std::endl;

	delete two;
	delete circle;
	delete square;
	return 0;
}