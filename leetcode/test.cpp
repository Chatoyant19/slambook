#include <iostream>

class A{
  public:
   void foo() { std::cout << "a_foo" << std::endl; }

   virtual void bar() { std::cout << "a_bar" << std::endl; }
};

class B : public A{
  public : 
  virtual void foo(){std::cout << "b_foo" << std::endl;}

  void bar() { std::cout << "b_bar" << std::endl; }
};

int main() {
  A *p = new B;
  p->foo();
  p->bar();
}
