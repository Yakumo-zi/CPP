#include "reflect/ClassFactory.h"
#include <cstdio>
#include <cstddef>

using namespace yakumo::reflect;

#include "test/a.h"
#include "test/b.h"

class Test {
public:
    Test(const std::string &name, int age)
            : m_name(name),
              m_age(age) {}

    ~Test() {};
    void show(){}
public:
    std::string m_name;
    int m_age;
};

//黑科技1 获取字段在类型中的偏移量
#define OFFSET(className, fieldName)                                      \
          ((size_t)(&((className*)0)->fieldName))


int main() {


    ClassFactory* factory=Singleton<ClassFactory>::instance();
    Object* a=factory->create_class("A");
    a->set("name","Yakumo");
    a->call("show");



//    ClassField* name=factory->get_field("A","name");
//    std::cout<<name->name()<<std::endl;
//    std::cout<<name->type()<<std::endl;
//    std::cout<<name->offset()<<std::endl;
//    ClassField* age=factory->get_field("A","age");
//    std::cout<<age->name()<<std::endl;
//    std::cout<<age->type()<<std::endl;
//    std::cout<<age->offset()<<std::endl;
//    int count=factory->get_field_count("A");
//    std::cout<<"Count:"<<count<<std::endl;


//     Object* a=factory->create_class("A");
//     a->set("name","Yakumo");
//     a->set("age",18);
//     std::string name;
//     int age;
//     a->get("age",age);
//     a->get("name",name);
//     std::cout<<name<<":"<<age<<std::endl;

//     int* field_age=(int*)(((size_t)&a)+age->offset());
//     *field_age=20;
//     std::cout<<*(int*)(((size_t)&a)+age->offset())<<std::endl;

//    A a;
//    a.name="Yakumo";
//    a.age=10;
//    std::cout<<*(int*)(((size_t)&a)+age->offset())<<std::endl;
//    std::cout<<*(std::string*)(((size_t)&a)+name->offset())<<std::endl;

    //黑科技1
//    auto offset= offsetof(Test,m_name);
//    Test t("yakumo",10);
//    std::string name=*(std::string*)((size_t)&t+offset);
//    std::cout<<name<<std::endl;

    //黑科技2
//    Test t("yakumo",18);
//    auto offset=(size_t)&(t.m_age)-(size_t)&t;
//    int age=*(int*)((size_t)&t+offset);
//    std::cout<<age<<std::endl;

//    ClassFactory* factory=Singleton<ClassFactory>::instance();
//    Object* a=factory->create_class("A");
//    a->show();
//    Object* b=factory->create_class("B");
//    b->show();
    return 0;
}
