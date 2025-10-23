#pragma once

#include "AForm.hpp"
#include <fstream>
#include <ctime>
#include <cstdlib>

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
    private:
        const std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm& copyConstructor);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& copyAssignment);
        ~ShrubberyCreationForm();
        
        void execute(const Bureaucrat& bureaucrat) const;
};
