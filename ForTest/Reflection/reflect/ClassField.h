//
// Created by Yakumo on 2022/11/27.
//

#ifndef REFLECTION_CLASSFIELD_H
#define REFLECTION_CLASSFIELD_H

#include <string>

namespace yakumo {
    namespace reflect {
        class ClassField {
        public:
            ClassField(const std::string &name, const std::string &type, size_t offset)
                    : m_name(name),
                      m_type(type),
                      m_offset(offset) {}

            ClassField() : m_name(""), m_type(""), m_offset(0) {}

            ~ClassField() {}

            const std::string &name() {
                return m_name;
            }

            const std::string &type() {
                return m_type;
            };

            size_t offset() {
                return m_offset;
            }

        private:
            std::string m_name;
            std::string m_type;
            size_t m_offset;
        };
    }
}

#endif //REFLECTION_CLASSFIELD_H
