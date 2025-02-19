#include "Bureaucrat.hpp"

void Bureaucrat::incrementGrade(){
	if ((this->_grade - 1) < 1){
		throw GradeTooHighException();
	}
	this->_grade -= 1;
}

void Bureaucrat::decrementGrade(){
	if ((this->_grade + 1) > 150){
		throw GradeTooLowException();
	}
	this->_grade += 1;
}

std::string Bureaucrat::getName() const{
	return (this->_name);
}

int Bureaucrat::getGrade() const{
	return (this->_grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other) {
	if (this != &other) {
		this->_name = other._name;
		this->_grade = other._grade;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}