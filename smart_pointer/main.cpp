#include <iostream>
#include <memory> // для std::shared_ptr
#include <string>
//cyclical references
//std::make_shared/unique избегать исключений/ошибок в конструкторах
//class Human
//{
//    std::string m_name;
//    std::shared_ptr<Human> m_partner; // изначально пустой
//
//public:
//
//    Human(const std::string &name): m_name(name)
//    {
//        std::cout << m_name << " created\n";
//    }
//    ~Human()
//    {
//        std::cout << m_name << " destroyed\n";
//    }
//
//    friend bool partnerUp(std::shared_ptr<Human> &anton, std::shared_ptr<Human> &ivan)
//    {
//        if (!anton || !ivan)
//            return false;
//
//        anton->m_partner = ivan;
//        ivan->m_partner = anton;
//
//        std::cout << anton->m_name << " is now partnered with " << ivan->m_name << "\n";
//
//        return true;
//    }
//};
//
//int main()
//{
//    auto anton = std::make_shared<Human>("Anton"); // создание умного указателя с объектом Anton класса Human
//    auto ivan = std::make_shared<Human>("Ivan"); // создание умного указателя с объектом Ivan класса Human
//
//    partnerUp(anton, ivan); // Anton указывает на Ivan-а, а Ivan указывает на Anton-а
//
//    return 0;
//}
//****************************************************************************
//****************************************************************************
//****************************************************************************
class Human
{
    std::string m_name;
    std::weak_ptr<Human> m_partner; // обратите внимание, здесь std::weak_ptr

public:

    Human(const std::string &name): m_name(name)
    {
        std::cout << m_name << " created\n";
    }
    ~Human()
    {
        std::cout << m_name << " destroyed\n";
    }

    friend bool partnerUp(std::shared_ptr<Human> &h1, std::shared_ptr<Human> &h2)
    {
        if (!h1 || !h2)
            return false;

        h1->m_partner = h2;
        h2->m_partner = h1;

        std::cout << h1->m_name << " is now partnered with " << h2->m_name << "\n";

        return true;
    }
};

int main()
{
    auto anton = std::make_shared<Human>("Anton");
    auto ivan = std::make_shared<Human>("Ivan");

    partnerUp(anton, ivan);

    return 0;
}