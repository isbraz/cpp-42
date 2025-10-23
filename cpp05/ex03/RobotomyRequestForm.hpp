#pragma once

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
    private:
        const std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm& copyConstructor);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& copyAssignment);
        ~RobotomyRequestForm();
        
        void execute(const Bureaucrat& bureaucrat) const;
};
