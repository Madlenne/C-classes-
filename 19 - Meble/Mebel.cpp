#include "Mebel.h"

std::ostream& operator<<(std::ostream& os, const Mebel& to_print)
{
	os << to_print.m_name << " " << to_print.m_height << " " << to_print.m_width << " " << to_print.m_length << " \"" << to_print.m_description << "\"" << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, std::vector<Mebel>& print_in)
{
	std::string line;
	
	std::string temp_name, temp_description;
	int temp_height, temp_width, temp_length;
	while(getline(is, line))
	{
		 std::stringstream sline(line);
		 sline >> temp_name >> temp_height >> temp_width >> temp_length;

		 getline(sline, temp_description);
		 temp_description = temp_description.substr(2, temp_description.size()-3);

		 print_in.push_back(Mebel(temp_name, temp_height, temp_width, temp_length, temp_description));
	}
}