//
// Created by Yakumo on 2022/11/27.
//

#ifndef REFLECTION_CLASSREGISTER_H
#define REFLECTION_CLASSREGISTER_H
#include <string>
#include <utility>
#include <functional>
#include "ClassFactory.h"
namespace yakumo{
    namespace reflect{
        class ClassRegister{
        public:
            ClassRegister(const std::string& className,create_object method){
                Singleton<ClassFactory>::instance()->register_class(className,std::move(method));
            }
            ClassRegister(const std::string& className,const std::string& fieldName,const std::string& fieldType,size_t offset){
                Singleton<ClassFactory>::instance()->register_class_field(className,fieldName,fieldType,offset);
            }
            ClassRegister(const std::string& className,const std::string& methodName,uintptr_t method){
                Singleton<ClassFactory>::instance()->register_class_method(className,methodName,method);
            }
        };
    }
#define REGISTER_CLASS(className)                   \
    Object* createObject##className()               \
    {                                               \
        Object* obj=new className();                \
        obj->set_className(#className);             \
        return obj;                                 \
    }                                               \
    ClassRegister classRegister##className(#className,createObject##className)
}
#define REGISTER_FIELD(className,fieldName,fieldType) \
        className className##fieldName;               \
        ClassRegister classRegister##className##fieldName(#className,#fieldName,#fieldType,(size_t)(&(className##fieldName.fieldName))-(size_t)(&(className##fieldName)))
#define REGISTER_METHOD(className,methodName) \
        std::function<void(className*)> className##methodName=&className::methodName;         \
        ClassRegister classRegister##className##methodName(#className,#methodName,(uintptr_t)&(className##methodName))
#endif //REFLECTION_CLASSREGISTER_H
