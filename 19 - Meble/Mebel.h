#pragma once
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

class Mebel
{
public:
	Mebel(std::string name = "", int height = 0, int width = 0, int length = 0, std::string description = ""): m_name(name), m_height(height), m_width(width), m_length(length), m_description(description){}
	friend std::ostream& operator<<(std::ostream& os, const Mebel& to_print);
	friend std::istream& operator>>(std::istream& is, std::vector<Mebel>& print_in);

private:
	std::string m_name;
	int m_height; 
	int m_width; 
	int m_length;
	std::string m_description;

};

