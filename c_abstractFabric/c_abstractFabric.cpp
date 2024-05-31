#include <iostream>
#include<string>

class IChair;
class ISofa;


class IChair {
public:
	virtual std::string About() = 0;
	virtual ~IChair() {}
};

class VictoriunChair : public IChair {
public:
	std::string About() override {
		return "i'm victoriun chair";
	}
};

class ModernChair : public IChair {
public:
	std::string About() override {
		return "i'm modern chair";
	}
};

class VisantiunChair : public IChair {
public:
	std::string About() override {
		return "i'm visantiun chair";
	}
};


class ISofa {
public:
	virtual std::string About() = 0;
	virtual ~ISofa() {}
};

class VictoriunSofa : public ISofa {
public:
	std::string About() override {
		return "i'm victoriun sofa";
	}
};

class ModernSofa : public ISofa {
public:
	std::string About() override {
		return "i'm modern sofa";
	}
};

class VisantiunSofa : public ISofa {
public:
	std::string About() override {
		return "i'm visantiun sofa";
	}
};


class IFurnitureFactory {
public:
	virtual IChair* createChair() = 0;
	virtual ISofa* createSofa() = 0;

	virtual ~IFurnitureFactory() {}
};

class VictoriunFurnitureFactory : public IFurnitureFactory {
public:
	VictoriunChair* createChair() override {
		return new VictoriunChair();
	}

	VictoriunSofa* createSofa() override {
		return new VictoriunSofa();
	}

	~VictoriunFurnitureFactory() {	}
};

class ModernFurnitureFactory : public IFurnitureFactory {
public:
	ModernChair* createChair() override {
		return new ModernChair();
	}

	ModernSofa* createSofa() override {
		return new ModernSofa();
	}

	~ModernFurnitureFactory() {}
};

class VisantiunFurnitureFactory : public IFurnitureFactory {
public:
	VisantiunChair* createChair() override {
		return new VisantiunChair();
	}

	VisantiunSofa* createSofa() override {
		return new VisantiunSofa();
	}

	~VisantiunFurnitureFactory() {}
};

class Complect {
	IChair* chair_;
	ISofa* sofa_;
public:
	Complect(IFurnitureFactory* factory) {
		chair_ = factory->createChair();
		sofa_ = factory->createSofa();
	}

	std::string ShowAll() {
		return chair_->About() + "\t" + sofa_->About();
	}
	~Complect()
	{
		delete chair_;
		delete sofa_;
	}
};

int main() {
	IFurnitureFactory* factory = new VisantiunFurnitureFactory();
	Complect* complect = new Complect(factory);
	std::cout << complect->ShowAll() << std::endl;
	delete complect;
	delete factory;

	factory = new ModernFurnitureFactory();
	complect = new Complect(factory);
	std::cout << complect->ShowAll() << std::endl;
	delete complect;
	delete factory;

	factory = new VictoriunFurnitureFactory();
	complect = new Complect(factory);
	std::cout << complect->ShowAll() << std::endl; 
	delete complect;
	delete factory;

	return 0;
}