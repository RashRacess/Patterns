#include <iostream>
#include <string>

class IAnimal {
public:
	virtual void setName(std::string name) = 0;
	virtual std::string getName() = 0;
	virtual IAnimal* clone() const = 0;

	virtual ~IAnimal() { std::cout << "IAnimal destructor" << std::endl; }
};

class Sheep : public IAnimal {
private:
	std::string name;
	Sheep(const Sheep& sheep) {
		this->name = sheep.name;
	}

public:
	Sheep() {}

	void setName(std::string name) override {
		this->name = name;
	}

	std::string getName() override {
		return name;
	}
	
	Sheep* clone() const {
		return new Sheep(*this);
	}
	
	~Sheep() {
		std::cout << "Sheep destructor" << std::endl;
	}
};

int main()
{
	Sheep* dolly = new Sheep();
	std::cout << dolly << std::endl;

	Sheep* clone = dolly->clone();
	std::cout << clone << std::endl;


	delete clone;
	delete dolly;

	return 0;
}