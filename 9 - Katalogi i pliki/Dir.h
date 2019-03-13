#pragma once
#include <string>
#include <vector>
#include <iostream>

class File
{
public:

	File(){}
	File(std::string name): m_name(name) {}
	virtual void print(int level) const;

protected:
	std::string m_name;
};


class Dir: public File
{
public:

	Dir() {}
	Dir(std::string name): File(name){}
	void operator+=(File* to_add);
	void print(int level) const;
	File* get(std::string name);
	friend std::ostream& operator<<(std::ostream& os, const File& to_print);
	~Dir();

private:
	std::vector<File*> m_data;
};

void File::print(int level) const
{
	for(int i = 0; i < level; ++i)
		std::cout << " ";

	std::cout << m_name << std::endl;

}

void Dir::operator+=(File* to_add)
{
	m_data.push_back(to_add);
}


void Dir::print(int level) const
{
	for(int i = 0; i < level; ++i)
		std::cout << " ";

	std::cout << m_name << std::endl;

	for(int i = 0; i < m_data.size(); ++i)
		m_data[i]->print(level + 2)
}


std::ostream& operator<<(std::ostream& os, const File& to_print)
{	 
	to_print.print(0);
	return os;
}

Dir::~Dir()
{
	for(std::vector<File*>::iterator it = m_data.begin(); it < m_data.end(); ++it)
		delete (*it);

}