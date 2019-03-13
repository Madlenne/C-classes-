#include "Executor.h"

namespace Executor
{
	Result::operator double() const
		{ 
			if(valid) 
				return value;
			throw;
		}

	Result secureRun(const Function& fun, double param)
	{
		Result obj;
		try
		{
			obj.value = fun(param);
		}
		catch(bool val)
		{
			obj.valid = false;
			std::cout << "ERROR Boolean of value false thrown ";
		}
		catch(const char* val)
		{
			obj.valid = false;
			std::cout << "ERROR " << val;
		}
		catch(...)
		{
			std::cout << "UNKNOWN ERROR";
		}

		return obj;
	}
}	

std::ostream & operator<<(std::ostream&os, const Executor::Result& to_print)
{
	if(to_print.valid)
		os << to_print.value;

	return os;
}