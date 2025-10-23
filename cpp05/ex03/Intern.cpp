#include "Intern.hpp"

Intern::Intern()
{
    
}

Intern::~Intern()
{
    
}

Intern::Intern(const Intern& copyConstructor)
{
    (void)copyConstructor;
}

Intern& Intern::operator=(const Intern& copyAssignment)
{
    (void)copyAssignment;
    return *this;
}

AForm* Intern::createShrubberyCreationForm(const std::string& target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomyRequestForm(const std::string& target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidentialPardonForm(const std::string& target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formName, const std::string& target)
{
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    AForm* (Intern::*formCreators[3])(const std::string& target) = {
        &Intern::createShrubberyCreationForm,
        &Intern::createRobotomyRequestForm,
        &Intern::createPresidentialPardonForm
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (formName == formNames[i])
        {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return (this->*formCreators[i])(target);
        }
    }
    std::cout << "Intern tried to create an invalid form called: " << formName << "." << std::endl;
    return NULL;
}