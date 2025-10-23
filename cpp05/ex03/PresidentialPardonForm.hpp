#pragma once

#include "AForm.hpp"

class Bureaucrat;


class PresidentialPardonForm : public AForm {
    private:
        const std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm& copyConstructor);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& copyAssignment);
        ~PresidentialPardonForm();
        
        void execute(const Bureaucrat& bureaucrat) const;
};