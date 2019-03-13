#pragma once
#include <iostream>
#include <exception>
#include <string>

namespace Executor
{
	class Function
	{
	public:
		virtual double operator()( double x) const = 0;
		virtual ~Function() {}

	};

	struct Result
	{
		Result(): value(0.0), valid(true) {}
		Result(bool val): value(val), valid(true) {}
		operator double() const;

		bool valid;
		double value;

	};

	Result secureRun(const Function& fun, double param);	
}

std::ostream & operator<<(std::ostream&os, const Executor::Result& to_print);
