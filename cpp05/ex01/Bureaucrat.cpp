#include "Bureaucrat.hpp"

void Bureaucrat::signForm(Form f){
	try {
		f.beSigned(*this);
		std::cout << getName() << " signed " << f.getName();
	}
	catch (const std::exception& e) {
		std::cout << getName() << " couldn't sign " << f.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::incrementGrade(){
	if (this->_grade == 1){
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
		this->_grade = other._grade;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}

Bureaucrat::Bureaucrat(const std::string& set_name, int set_grade) : _name(set_name) {
	if (set_grade < 1) {
		throw GradeTooHighException();
	}
	if (set_grade > 150) {
		throw GradeTooLowException();
	}
	this->_grade = set_grade;
}

Bureaucrat::~Bureaucrat(){}