#include <iostream>
#include <memory>

using namespace std;

class B;

class A {
    public:
        int a;
        shared_ptr<B> ptr;
        A(int value = 200){
            a = value;
        }
        ~A(){
            cout << "Destruidor para A" << endl;
        }
};

class B {
    public:
     int a;
     weak_ptr<A> ptr;
     B(int value = 200){
         a = value;
     }
     ~B(){
         cout << "Destruidor para B" << endl;
     }
};

int main(){

    shared_ptr<A> ptr_a = make_shared<A>(750);
    shared_ptr<B> ptr_b = make_shared<B>(750);

    ptr_a->ptr = ptr_b;
    ptr_b->ptr = ptr_a;

    return 0;
}