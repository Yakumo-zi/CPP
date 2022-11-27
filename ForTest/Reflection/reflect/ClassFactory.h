//
// Created by Yakumo on 2022/11/27.
//

#ifndef REFLECTION_CLASSFACTORY_H
#define REFLECTION_CLASSFACTORY_H

#include <map>
#include <string>
#include <functional>
#include <vector>
#include "../utilty/Singleton.h"
#include "ClassField.h"
#include "ClassMethod.h"

using namespace yakumo::utility;
namespace yakumo {
    namespace reflect {
        class Object {
        public:
            Object() {};

            virtual ~Object() {};

            void set_className(const std::string &c_name);

            const std::string &get_className();

            int get_field_count();

            void call(const std::string& methodName);

            ClassField *get_field(int pos);

            ClassField *get_field(const std::string &fieldName);

            template<class T>
            void get(const std::string &fieldName, T &value) {
                ClassField *field = get_field(fieldName);
                value = *(T *) (size_t) (((unsigned char *) (this)) + field->offset());
            }

            template<class T>
            void set(const std::string &fieldName, T &value) {
                ClassField *field = get_field(fieldName);
                *(T *) (((unsigned char *) (this)) + field->offset()) = value;
            }

            template<class T>
            void set(const std::string &fieldName, const T &value) {
                ClassField *field = get_field(fieldName);
                *(T *) (((unsigned char *) (this)) + field->offset()) = value;
            }

            void set(const std::string &fieldName, const char *value) {
                ClassField *field = get_field(fieldName);
                *(std::string *) (((unsigned char *) (this)) + field->offset()) = value;
            }

        private:
            std::string className;
        };



        //    typedef void*(*create_object)(void);
        using create_object = std::function<Object *()>;

        class ClassFactory {
            friend class Singleton<ClassFactory>;

        public:
            void register_class(const std::string &className, create_object method);

            Object *create_class(const std::string &className);

            void register_class_field(const std::string &className, const std::string &fieldName,
                                      const std::string &fieldType, size_t offset);
            void register_class_method(const std::string& className,const std::string & methodName,uintptr_t method);
            int get_method_count(const std::string& className);

            ClassMethod* get_method(const std::string& className,const std::string& methodName);
            int get_field_count(const std::string &className);

            ClassField *get_field(const std::string &className, int pos);

            ClassField *get_field(const std::string &className, const std::string &fieldName);

        private:
            ClassFactory();

            ~ClassFactory();

            std::map<std::string, create_object> classMap;
            std::map<std::string, std::vector<ClassField *>> classFields;
            std::map<std::string,std::vector<ClassMethod* >> classMethods;
        };
    }
}

#endif //REFLECTION_CLASSFACTORY_H
