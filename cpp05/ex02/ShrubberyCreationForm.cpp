#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default"){
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), _target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copyConstructor)
: AForm(copyConstructor), _target(copyConstructor._target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copyAssignment) {
    if (this == &copyAssignment)
        return *this;
    AForm::operator=(copyAssignment);
    // Note: _target is const, so it cannot be reassigned
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const {
    if (!this->getSign())
        throw AForm::FormNotSignedException();
    if (bureaucrat.getGrade() > this->getExecute())
        throw AForm::GradeTooLowException();
    std::ofstream outFile(this->_target + "_shrubbery");
    outFile << "       /\\       \n";
    outFile << "      /  \\      \n";
    outFile << "     /____\\     \n";
    outFile << "    /      \\    \n";
    outFile << "   /        \\   \n";
    outFile << "  /          \\  \n";
    outFile << " /__________*__\\ \n";
    outFile << "       ||       \n";
    outFile << "       ||       \n";
    outFile << "    ___||___    \n";
    outFile << "               \n";
    outFile.close();
    
    std::cout << "Shrubbery has been created and written to " << this->_target + "_shrubbery" << std::endl;
}
