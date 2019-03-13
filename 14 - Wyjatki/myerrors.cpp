#include "myerrors.h"

namespace myerrors
{
	void calc_error::print() const
		{	
			std::cout << what() << " [w pliku: " << m_file << " w linii " << m_line << "]" << std::endl;
			std::cout << "z powodu: ";
			const calc_error* is_calc = dynamic_cast<const calc_error*>(m_previous);
			if(is_calc)
				is_calc->print();
			else
				std::cout << m_previous->what() << std::endl;

			delete is_calc;
		}

	void handler()
	{
		std::cout << "Wyjatek w: ";

		try
		{
			throw;
		} 
		catch(const calc_error* err)
		{
			err->print();
			delete err;
		}


	}	
}