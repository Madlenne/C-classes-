#pragma once
#include <iostream>
#include <exception>
#include <string>

namespace myerrors
{
	class calc_error: public std::runtime_error
	{
	public:
		calc_error(const std::runtime_error* previous = NULL, const char* name = "", std::string file = "", int line = 0): std::runtime_error(name), m_previous(previous), m_name(name), m_file(file), m_line(line) {}
		void print() const;
	private:
		const std::runtime_error* m_previous;
		const char* m_name;
		std::string m_file;
		int m_line;

	};

	void handler();
}

