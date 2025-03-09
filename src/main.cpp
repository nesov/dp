#include <iostream>


class Singleton {
	public:
	
	static Singleton& getInstance(){
		static Singleton m_instance;
		return m_instance;
	}

	private:
	Singleton() = default;
	~Singleton() = default;

	Singleton(const Singleton& ) = delete;
	Singleton(Singleton&& ) = delete;
	Singleton& operator=(const Singleton& ) = delete;  
};


int main(){

	std::cout << "Hello Singleton.\n";
	Singleton& s = Singleton::getInstance();	


	return 0;
}
