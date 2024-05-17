#include <iostream>
#include <string>
#include <memory>


class Transport {
public:
	virtual ~Transport() {}
	virtual std::string deliver() = 0;
};

class Car :public Transport {
private:
	std::string name;

public:
	Car() : name{ "car" } {}
	std::string deliver() override {
		return "By car";
	}
};

class Ship : public Transport {
private:
	std::string name;
public:
	Ship() : name{ "ship" } {}
	std::string deliver() override {
		return "By ship";
	}

};

std::unique_ptr<Transport> createTransport(std::string name) {
	if (name == "car")
		return std::make_unique<Car>();
	else if (name == "ship")
		return std::make_unique<Ship>();
}

void showDeliver(Transport& tr) {
	std::cout << tr.deliver() << std::endl;
}

int main() {

	Transport* tr = new Car();
	showDeliver(*tr);
	delete tr;
	tr = nullptr;

	tr = new Ship();
	showDeliver(*tr);
	delete tr;
	tr = nullptr;

	return 0;
}