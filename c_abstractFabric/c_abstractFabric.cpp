#include <iostream>
#include <string>
#include <conio.h>

class IChair;
class ISofa;

class IFurnitureFactory {
public:
	virtual IChair* CreateChair() = 0;
	virtual ISofa* CreateSofa() = 0;
	virtual ~IFurnitureFactory() {}
};

class IChair {
public:
	virtual std::string About() = 0;
	virtual ~IChair() {}
};

class ISofa {
public:
	virtual std::string About() = 0;
	virtual ~ISofa() {}
};

class VictorianChair :public IChair {
public:
	std::string About() override {
		return "I'm victorian chair";
	}
};

class VictorianSofa :public ISofa {
public:
	std::string About() override {
		return "I'm victorian sofa";
	}
};

class ModernChair : public IChair {
public:
	std::string About() override {
		return "I'm modern chair";
	}
};

class ModernSofa :public ISofa {
public:
	std::string About() override {
		return "I'm modern sofa";
	}
};

class ModernFurnitureFactory : public IFurnitureFactory {
public:
	IChair* CreateChair() override {
		return new ModernChair();
	}

	ISofa* CreateSofa() override {
		return new ModernSofa();
	}
};

class VictorianFurnitureFactory : public IFurnitureFactory {
public:
	IChair* CreateChair() override {
		return new VictorianChair();
	}

	ISofa* CreateSofa() override {
		return new VictorianSofa();
	}
};

class ComplectOfFurniture {
private:
	IChair* chair;
	ISofa* sofa;
public:
	ComplectOfFurniture(IFurnitureFactory* factory) {
		chair = factory->CreateChair();
		sofa = factory->CreateSofa();
	}

	std::string ShowInfoAboutComplect() {
		return chair->About() + " " + sofa->About();
	}

	~ComplectOfFurniture() {
		if (chair)
			delete chair;
		if (sofa)
			delete sofa;
	}
};


int main()
{
	IFurnitureFactory* factory = new ModernFurnitureFactory();
	ComplectOfFurniture* cof = new ComplectOfFurniture(factory);
	std::cout << cof->ShowInfoAboutComplect() << std::endl;

	delete factory;
	delete cof;
	factory = nullptr;
	cof = nullptr;


	_getch();


	factory = new VictorianFurnitureFactory();
	cof = new ComplectOfFurniture(factory);

	std::cout << cof->ShowInfoAboutComplect() << std::endl;

	delete factory;
	delete cof;
	factory = nullptr;
	cof = nullptr;


	return 0;
}