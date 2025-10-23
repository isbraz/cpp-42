#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
    
    private: 
        const std::string _name;
        const int _execute;
        const int _required;
        bool _sign;
        
    public:
        class GradeTooLowException : public std::exception{
            public:
                const char *what() const throw();
        };
        class GradeTooHighException : public std::exception{
            public:
                const char *what() const throw();
        };
        
        class FormNotSignedException : public std::exception{
            public:
                const char *what() const throw();
        };
        AForm();
        AForm(const std::string &name, int execute, int required);
        AForm(const AForm& copyConstructor);
        AForm& operator=(const AForm& copyAssignment);
        virtual ~AForm()=0;
        void beSigned(Bureaucrat &b);
        bool getSign() const;
        const std::string getName() const;
        int getRequired() const;
        int getExecute() const;
        virtual void execute(const Bureaucrat& bureaucrat) const = 0;
};

std::ostream& operator<<(std::ostream &os, const AForm &form);
