#include <iostream>
#include <string>
#include <thread>

class ITransport {
public:
	virtual std::string About() = 0;
	virtual void DeliverBy() = 0;

	virtual ~ITransport() {	}
};

class Car : public ITransport {
private:
	std::string brand_;
	std::string number_;
	std::string color_;
	int mileage_;

public:
	Car() : brand_{ "indef" }, number_{ "indef" }, color_{ "indef" }, mileage_{ 0 } {}
	Car(std::string brand, std::string number, std::string color, int mileage) {
		this->brand_ = brand;
		this->number_ = number;
		this->color_ = color;
		this->mileage_ = mileage;
	}

	std::string About() override {
		return "Brand: " + brand_ + "number: " + number_ + "color: " + color_ + "mileage: " + std::to_string(mileage_);
	}

	void DeliverBy() override {
		std::cout << "I deliver by land" << std::endl;
	}

	// Геттеры
	std::string GetBrand() const { return brand_; }
	std::string GetNumber() const { return number_; }
	std::string GetColor() const { return color_; }
	int GetMileage() const { return mileage_; }

	// Сеттеры
	void SetBrand(const std::string& brand) { brand_ = brand; }
	void SetNumber(const std::string& number) { number_ = number; }
	void SetColor(const std::string& color) { color_ = color; }
	void SetMileage(int mileage) { mileage_ = mileage; }

};

class Ship : public ITransport {
private:
	std::string name_;
	std::string number_;
	double length_;
	double width_;

public:
	Ship() : name_{ "undef" }, number_{ "undef" }, length_{ 0 }, width_{ 0 } {}
	Ship(std::string name, std::string number, double length, double width) {
		this->name_ = name;
		this->number_ = number;
		this->length_ = length;
		this->width_ = width;
	}

	std::string About() override {
		return "Name: " + name_ + "number: " + number_ + "length: " + std::to_string(length_) + "width: " + std::to_string(width_);
	}

	void DeliverBy() override {
		std::cout << "I deliver by sea" << std::endl;
	}

	// Геттеры
	std::string GetName() const { return name_; }
	std::string GetNumber() const { return number_; }
	double GetLength() const { return length_; }
	double GetWidth() const { return width_; }

	// Сеттеры
	void SetName(const std::string& name) { name_ = name; }
	void SetNumber(const std::string& number) { number_ = number; }
	void SetLength(double length) { length_ = length; }
	void SetWidth(double width) { width_ = width; }
};

int main() {
	ITransport* tr = new Car();
	tr->DeliverBy();
	
	delete tr;

	tr = new Ship();
	tr->DeliverBy();
	delete tr;	
}