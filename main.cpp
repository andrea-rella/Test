#include <iostream>
#include "vector"
#include "string"
#include "memory"
#include "map"
#include "limits"

class Base{
    int i=0;
public:

     virtual void print(){
        std::cout << "Base method" << std::endl;
    }

};

// Boh prova di cambiamento per git

class Derived: public Base{
    void print() override{
        std::cout << "Derived method" << std::endl;
    }
};

void usePrint(Base& b){
    b.print();
};

void usePrint_notref(Base b){
    b.print();
};

int main() {

    Derived d;
    Base* b_ptr = &d;
    std::vector<Base> vB;
    vB.push_back(d);

    usePrint(d); // prints derived method (because the method is overridden,
                    // dynamic binding if it wasn't overriden it would print base)
    usePrint_notref(d); // Base method (slice down happen)
    b_ptr->print(); // prints derived method (because the method is overridden, dynamic binding)
                    // dynamic binding if it wasn't overriden it would print base)
    vB[0].print();  // Base method (slice down happens)

}


