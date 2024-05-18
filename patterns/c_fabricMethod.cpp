#include <iostream>
#include <string>
#include <memory>


class ITransport {
public:
	virtual ~ITransport() {}
	virtual std::string deliver() = 0;
};

class Car :public ITransport {
private:
	std::string name;

public:
	Car() : name{ "car" } {}
	std::string deliver() override {
		return "By car";
	}
};

class Ship : public ITransport {
private:
	std::string name;
public:
	Ship() : name{ "ship" } {}
	std::string deliver() override {
		return "By ship";
	}

};

void showDeliver(ITransport& tr) {
	std::cout << tr.deliver() << std::endl;
}

int main() {

	ITransport* tr = new Car();
	showDeliver(*tr);
	delete tr;
	tr = nullptr;

	tr = new Ship();
	showDeliver(*tr);
	delete tr;
	tr = nullptr;

	return 0;
}