#include <iostream>
#include <memory>

struct A {
 public:
	int a_ = 10;
	virtual ~A(){}; // base class destructor must be virtual (I forgot this while tech interview)
    virtual void print(){
        std::cout << "A print\n"; 
    }
};

struct B : public A {
 public:
	int b_ = 20;
	~B(){}

    void print() override {
        std::cout << "B print\n"; 
    }
};

void fn(A& a) { // replaced A a with A& a to let it working correctly
    a.print(); 
}

int main (){
    std::unique_ptr<A> a = std::make_unique<B>();
    fn(*a);
	return 0; 
}
