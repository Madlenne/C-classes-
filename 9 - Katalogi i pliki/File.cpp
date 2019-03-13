#include "File.h"

File::File()
{
	m_fname = "";
}
	
File::File(std::string fname)
{
	m_fname = fname;
}

std::ostream& operator<<(std::ostream& os, const File& directory)
{
    int space=0;
    return directory.print(os, space);
}

std::ostream& File::print(std::ostream& os, int spaces) const
{
	for(int i=0; i<spaces; i++)
		os << " ";

	os << m_fname << std::endl;

	return os;

}
 
File::~File()
{

}