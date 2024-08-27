#include "Bureaucrat.hpp"
#include "Form.hpp"


int main(){
	
	try
	{
		Bureaucrat b("Ismael", 4);
		Form f("Formulary", 10, 4);

		std::cout << WHITE << "________________BEFORE________________" <<  RESET << std::endl;
		std::cout << f;
		std::cout << WHITE << "_______________SIGNING________________" << RESET << std::endl;
		b.signForm(f);
		std::cout << WHITE << "________________AFTER_________________" <<  RESET << std::endl;
		std::cout << f;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}