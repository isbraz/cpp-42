#include "RobotomyRequestForm.hpp"
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default"){
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), _target(target){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copyConstructor)
: AForm(copyConstructor), _target(copyConstructor._target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copyAssignment) {
    if (this == &copyAssignment)
        return *this;
    AForm::operator=(copyAssignment);
    // Note: _target is const, so it cannot be reassigned
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const {
    if (!this->getSign())
        throw AForm::FormNotSignedException();
    if (bureaucrat.getGrade() > this->getExecute())
        throw AForm::GradeTooLowException();
    std::cout << "Brrrr... Brrrr... Drilling noises..." << std::endl;
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator
    if (rand() % 2) { // 50% chance
        std::cout << this->_target << " has been robotomized successfully!" << std::endl;
    } else {
        std::cout << "The robotomy on " << this->_target << " failed." << std::endl;
    }
}