#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("Default"){
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), _target(target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copyConstructor)
: AForm(copyConstructor), _target(copyConstructor._target) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copyAssignment) {
    if (this == &copyAssignment)
        return *this;
    AForm::operator=(copyAssignment);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

void PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const {
    if (!this->getSign())
        throw AForm::FormNotSignedException();
    if (bureaucrat.getGrade() > this->getExecute())
        throw AForm::GradeTooLowException();
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}