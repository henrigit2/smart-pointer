#include <iostream>
#include <memory>

using namespace std;

class myType {
    public:
        int prop;
        myType(int a){
            prop = a;
        }
};

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

    MyClass my_obj(250);

    shared_ptr<MyClass> my_ptr_1 = make_shared<MyClass>(my_obj);
    cout << "Referencia atual Count de my_ptr_1 = " << my_ptr_1.use_count() << endl;

    shared_ptr<MyClass> my_ptr_2 = my_ptr_1;

    cout << "Referencia atual Count de my_ptr_1 = " << my_ptr_1.use_count() << endl;
    cout << "Referencia atual Count de my_ptr_2 = " << my_ptr_2.use_count() << endl;

    cout << "Valor de um (de desreferenciamento my_ptr_1): " << my_ptr_1->a << endl;
    cout << "Valor de um (de desreferenciamento my_ptr_2): " << my_ptr_2->a << endl;

    cout << "Liberando os ponteiros..." << endl;
    my_ptr_1.reset();
    cout << "Liberado my_ptr_1" << endl;
    cout << "Referencia atual Count de my_ptr_1 = " << my_ptr_1.use_count() << endl;
    cout << "Referencia atual Count de my_ptr_2 = " << my_ptr_2.use_count() << endl;
    my_ptr_2.reset();
    cout << "Liberado my_ptr_2" << endl;
    cout << "Referencia atual Count de my_ptr_1 = " << my_ptr_1.use_count() << endl;
    cout << "Referencia atual Count de my_ptr_2 = " << my_ptr_2.use_count() << endl;

    
    
    return 0;
}