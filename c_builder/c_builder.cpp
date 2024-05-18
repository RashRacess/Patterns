#include <iostream>
#include <string>
#include <vector>
#include <crtdbg.h>
#define _CRTDBG_MAP_ALLOC

class IComponent {
public:
	std::string data;
	IComponent(const std::string& value) : data(value) {}
};

class Bun : public IComponent {
public:
	Bun() : IComponent("Bun") {}
};

class Cutlet : public IComponent {
public:
	Cutlet() : IComponent("Cutlet") {}
};

class Cheese : public IComponent {
public:
	Cheese() : IComponent("Cheese") {}
};

class Tomato : public IComponent {
public:
	Tomato() : IComponent("Tomato") {}
};

class Sauce : public IComponent {
public:
	Sauce() : IComponent("Sauce") {}
};

class Salad : public IComponent {
public:
	Salad() : IComponent("Salad") {}
};

class Burger {
private:
	std::vector<IComponent*> compound;
public:
	void SetIngredient(IComponent* component) {
		compound.push_back(component);
	}
	std::vector<IComponent*> getBurger() {
		return compound;
	}
	~Burger() {
		for (auto it = compound.begin(); it != compound.end(); ++it) {
			if (*it) {
				delete* it;
				*it = nullptr;
			}
		}
		compound.clear();
	}
};

class IDeveloper {
public:
	virtual void addBun() = 0;
	virtual void addCutlet() = 0;
	virtual void addTomato() = 0;
	virtual void addCheese() = 0;
	virtual void addSauce() = 0;
	virtual void addSalad() = 0;

	virtual Burger* getBurger() = 0;
	virtual ~IDeveloper() {}
};

class VigaterianDeveloper : public IDeveloper {
private:
	Burger* burger;
public:
	VigaterianDeveloper() :burger{ new Burger } {}
	void addBun() override {
		burger->SetIngredient(new Bun);
	}
	void addCutlet() override {
		burger->SetIngredient(new Cutlet);
	}
	void addCheese() override {}
	void addTomato() override {
		burger->SetIngredient(new Tomato);
	}
	void addSauce() override {
		burger->SetIngredient(new Sauce);
	}
	void addSalad() override {
		burger->SetIngredient(new Salad);
	}
	Burger* getBurger() override {
		return burger;
	}
	~VigaterianDeveloper() {
		if (burger) {
			delete burger;
			burger = nullptr;
		}
	}
};


class OrdinaryDeveloper : public IDeveloper {
private:
	Burger* burger;
public:
	OrdinaryDeveloper() : burger{ new Burger } {}
	void addBun() override {
		burger->SetIngredient(new Bun);
	}
	void addCutlet() override {
		burger->SetIngredient(new Cutlet);
	}
	void addCheese() override {
		burger->SetIngredient(new Cheese);
	}
	void addTomato() override {
		burger->SetIngredient(new Tomato);
	}
	void addSauce() override {
		burger->SetIngredient(new Sauce);
	}
	void addSalad() override {
		burger->SetIngredient(new Salad);
	}
	Burger* getBurger() override {
		return burger;
	}
	~OrdinaryDeveloper() {
		if (burger)
			if (burger) {
				delete burger;
				burger = nullptr;
			}
	}
};

class Director {
	IDeveloper* developer;
public:
	Director(IDeveloper* dev) : developer{ dev } {}

	Burger* createViraterianBurger() {
		developer->addBun();
		developer->addCutlet();
		developer->addTomato();
		developer->addSauce();
		developer->addSalad();
		return developer->getBurger();
	}

	Burger* createOrdinaryBurger() {
		developer->addBun();
		developer->addCutlet();
		developer->addTomato();
		developer->addCheese();
		developer->addSauce();
		developer->addSalad();
		return developer->getBurger();
	}

	~Director() {
		if (developer) {
			delete developer;
			developer = nullptr;
		}
	}
};

int main() {
	VigaterianDeveloper* vigDev = new VigaterianDeveloper();
	Director* director = new Director(vigDev);

	Burger* burger = director->createViraterianBurger();
	std::vector<IComponent* >compound = burger->getBurger();
	for (auto& component : compound) {
		std::cout << component->data << "\t";
	}

	delete director;

	_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_DEBUG);
	_CrtDumpMemoryLeaks();
}