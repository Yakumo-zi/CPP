//
// Created by Yakumo on 2022/11/27.
//
#include "ClassFactory.h"
#include <utility>

using namespace yakumo::reflect;

void ClassFactory::register_class(const std::string &className, create_object method) {
    classMap[className] = std::move(method);
}

Object *ClassFactory::create_class(const std::string &className) {
    auto item = classMap.find(className);
    if (item == classMap.end())
        return nullptr;
    return item->second();
}

yakumo::reflect::ClassFactory::ClassFactory() = default;

yakumo::reflect::ClassFactory::~ClassFactory() = default;

void ClassFactory::register_class_field(const std::string &className, const std::string &fieldName,
                                        const std::string &fieldType, size_t offset) {
    classFields[className].push_back(new ClassField(fieldName,fieldType,offset));
}

int ClassFactory::get_field_count(const std::string &className) {
    return classFields[className].size();
}

ClassField *ClassFactory::get_field(const std::string &className, const std::string &fieldName) {
    for(auto& e:classFields[className]){
        if(e->name()==fieldName){
            return e;
        }
    }
    return nullptr;
}

ClassField *ClassFactory::get_field(const std::string &className, int pos) {
    int size=classFields[className].size();
    if(pos<0||pos>=size){
        return nullptr;
    }
    return classFields[className][pos];
}

void
ClassFactory::register_class_method(const std::string &className, const std::string &methodName, uintptr_t method) {
    classMethods[className].push_back(new ClassMethod(methodName, method));
}

int ClassFactory::get_method_count(const std::string &className) {
    return classMethods[className].size();
}

ClassMethod *ClassFactory::get_method(const std::string &className, const std::string &methodName) {
    for(auto& e:classMethods[className]){
        if(e->name()==methodName){
            return e;
        }
    }
    return nullptr;
}


int Object::get_field_count() {
    return Singleton<ClassFactory>::instance()->get_field_count(get_className());
}

//ClassField *Object::get_field(int pos) {
//    return Singleton<ClassFactory>::instance()->get_field(get_className(),pos);
//}

void Object::set_className(const std::string &c_name) {
    className=c_name;
}

const std::string& Object::get_className() {
    return className;
}

ClassField *Object::get_field(const std::string &fieldName) {
    return Singleton<ClassFactory>::instance()->get_field(className,fieldName);
}

ClassField *Object::get_field(int pos) {
    return Singleton<ClassFactory>::instance()->get_field(className,pos);
}

void Object::call(const std::string &methodName) {
    ClassMethod* method=Singleton<ClassFactory>::instance()->get_method(className,methodName);
    uintptr_t func=method->method();
    using class_method=std::function<void(decltype(this))>;
    (*((class_method*)func))(this);
}


