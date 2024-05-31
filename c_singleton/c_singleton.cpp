#include <iostream>
#include <string>

class Singleton {
protected:
	Singleton(const std::string& value) : value_{value} {}

	std::string value_;

	static Singleton* singleton_;

public:
	Singleton(Singleton& singleton) = delete;

	void operator=(const Singleton& singleton) = delete;

	static Singleton* GetInstance(const std::string value);

	std::string GetValue() { return value_; }
};

Singleton* Singleton::singleton_ = nullptr;

Singleton* Singleton::GetInstance(const std::string value) {
	if (singleton_ == nullptr) {
		singleton_ = new Singleton(value);
	}
	return singleton_;
}

int main() {
	std::string foostr = "foo";
	std::string barstr = "bar";
	
	Singleton* singleton1 = Singleton::GetInstance(foostr);
	Singleton* singleton2 = Singleton::GetInstance(foostr);

	Singleton* singleton3 = Singleton::GetInstance(barstr);
	Singleton* singleton4 = Singleton::GetInstance(barstr);

	std::cout << singleton1 << std::endl;
	std::cout << singleton2 << std::endl;
	std::cout << singleton3 << std::endl;
	std::cout << singleton4 << std::endl;

	return 0;
}
