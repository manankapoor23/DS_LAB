#include <iostream>
using namespace std ;

class Animal{
    public:
        virtual void speak(){ // run time pe decide hoga ab , not compile time jo ki without virtual hora tha
            cout<<"hu hu";
        }

};

class Dog:public Animal{
    public:
        void speak(){
            cout<<"bark";
        }
};


int main(){
    Animal *p;
    p = new Dog(); // p stores the address of class Dog
    p->speak();
}