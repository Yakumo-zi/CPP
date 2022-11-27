//
// Created by Yakumo on 2022/11/27.
//

#ifndef REFLECTION_SINGLETON_H
#define REFLECTION_SINGLETON_H
namespace yakumo {
    namespace utility {

        template <typename T>
        class Singleton
        {
        public:
            static T * instance()
            {
                if (m_instance == nullptr)
                    m_instance = new T();
                return m_instance;
            }
            Singleton()=delete;
            Singleton(const Singleton<T> &)=delete;
            Singleton<T> & operator = (const Singleton<T> &) = delete;
            ~Singleton()=delete;
        private:
            static T * m_instance;
        };

        template <typename T>
        T * Singleton<T>::m_instance = nullptr;

    }}
#endif //REFLECTION_SINGLETON_H
