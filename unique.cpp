#include <iostream>
#include <memory>

using namespace std;

class MyClass {

    public:
        int a;
        MyClass(){
            cout << "Construtor padrao" << endl;
            a = 10;
        }
        MyClass(int value = 100){
            cout << "Construtor parametrizado" << endl;
            a = value;
        }
};

int main(){

    MyClass my_obj(120);

    unique_ptr<MyClass> my_ptr_1 = make_unique<MyClass>(my_obj);
    unique_ptr<MyClass> my_ptr_2(new MyClass(500));

    cout << "Valor de (my_ptr_1): " << my_ptr_1->a << endl;
    cout << "Valor de (my_ptr_2): " << my_ptr_2->a << endl;

    cout << "Liberando ponteiros" << endl;

    my_ptr_1.reset();
    my_ptr_2.reset();
   

    return 0;
}