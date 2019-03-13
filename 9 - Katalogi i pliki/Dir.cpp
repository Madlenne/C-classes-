#include "Dir.h"


Dir::Dir()
{
	m_amount = 0;
	m_array[m_amount] = 0;
}

Dir::Dir(std::string dname)
{
	m_dname = dname;
	m_amount = 0;
	m_array[m_amount] = 0;
}

Dir& Dir::operator+=(File* added)
{
	m_array[m_amount] = added;
	m_amount++;
	return *this;
}


File* Dir::get(std::string text) const
{
	for (int i = 0; i <m_amount; i++)
    {
        if ((m_array[i]->get_name()) == text)
			return m_array[i];
	}
    std::cout << std::endl;

}

std::ostream& Dir::print(std::ostream& os, int spaces) const
{
	for(int i=0; i<spaces; i++)
		os << " ";

	os << m_dname << std::endl;
	for(int i=0; i<m_amount; i++)
		m_array[i]->print(os, spaces+1);

	return os;
}



Dir::~Dir()
{
    for (int i = 0; i < m_amount ; i++) {
        std::cout << "Deleting Dir: " << m_array[i]->get_name() << std::endl;
            delete m_array[i];
    }

}