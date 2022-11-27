//
// Created by Yakumo on 2022/11/27.
//

#ifndef REFLECTION_B_H
#define REFLECTION_B_H
#include <iostream>
#include "../reflect/ClassFactory.h"
#include "../reflect/ClassRegister.h"

using namespace yakumo::reflect;
class B:public Object{
public:
    B(){}
    ~B(){}
    void show(){
        std::cout<<"B"<<name<<std::endl;
    }
public:
    std::string name;
};

REGISTER_CLASS(B);
REGISTER_FIELD(B,name,std::string);
REGISTER_METHOD(B,show);
#endif //REFLECTION_B_H
