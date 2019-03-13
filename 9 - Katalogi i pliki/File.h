#pragma once
#include <iostream>

class File {
public:
	File();

	File(std::string fname);

	virtual std::ostream &print(std::ostream &os, int spaces) const;

	virtual std::string get_name() const { return m_fname; }

	friend std::ostream &operator<<(std::ostream &os, const File &directory);

	virtual ~File();

private:
	
	std::string m_fname;
};