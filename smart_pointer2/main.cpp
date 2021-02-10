#include <iostream>
#include <memory> // для std::shared_ptr и std::weak_ptr
#include <string>

class Human
{
	std::string m_name;
	std::weak_ptr<Human> m_partner; // обратите внимание, здесь std::weak_ptr

public:

	Human(const std::string &name) : m_name(name)
	{
		std::cout << m_name << " created\n";
	}
	~Human()
	{
		std::cout << m_name << " destroyed\n";
	}

	friend bool partnerUp(std::shared_ptr<Human> &anton, std::shared_ptr<Human> &h2)
	{
		if (!anton || !h2)
			return false;

        anton->m_partner = h2;
		h2->m_partner = anton;

		std::cout << anton->m_name << " is now partnered with " << h2->m_name << "\n";

		return true;
	}

	const std::shared_ptr<Human> getPartner() const { return m_partner.lock(); } // используем метод lock() для конвертации std::weak_ptr в std::shared_ptr
	const std::string& getName() const { return m_name; }
};

int main()
{
	auto anton = std::make_shared<Human>("Anton");
	auto ivan = std::make_shared<Human>("Ivan");

	partnerUp(anton, ivan);

	auto partner = ivan->getPartner(); // передаем partner-у содержимое умного указателя, которым владеет ivan
	std::cout << ivan->getName() << "'s partner is: " << partner->getName() << '\n';

	return 0;
}
