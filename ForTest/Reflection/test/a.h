//
// Created by Yakumo on 2022/11/27.
//

#ifndef REFLECTION_A_H
#define REFLECTION_A_H
#include <iostream>
#include "../reflect/ClassRegister.h"
using namespace yakumo::reflect;
class A:public Object{
public:
    A(){}
    ~A(){}
    void show(){
        std::cout<<"A"<<name<<std::endl;
    }
    void f1(){
        std::cout<<"f1"<<std::endl;
    }
    void f2(){
        std::cout<<"f2"<<std::endl;
    }
public:
    std::string name;
    int age;
};

REGISTER_CLASS(A);
REGISTER_FIELD(A,name,std::string);
REGISTER_FIELD(A,age,int);
REGISTER_METHOD(A,show);
REGISTER_METHOD(A,f1);
REGISTER_METHOD(A,f2);
#endif //REFLECTION_A_H
