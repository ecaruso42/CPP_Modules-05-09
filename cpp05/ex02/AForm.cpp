#include "AForm.hpp"

void AForm::execute(const Bureaucrat& executor) const {
	if (!this->_sign)
		std::cout << "The Form have to be signed, come back when you meet the requirements" << std::endl;
	else if (executor.getGrade() > this->getExcGrade())
		std::cout << "I'm sorry but it seems the Bureaucrat doesn't have the grade required to execute this form, search for a higher level Bureaucrat" << std::endl;
	else
		executeAction();
}

void AForm::beSigned(Bureaucrat& b) {
	if (b.getGrade() >= getSigGrade()) {
		throw GradeTooLowException(b.getName() + " couldn't sign " + getName() + " because grade is too low");
	}
	this->_sign = true;
	std::cout << getName() << " signed succesfully" << std::endl;
}

std::string AForm::getName() const{
	return (this->_name);
}

bool AForm::getSign() const{
	return (this->_sign);
}

int AForm::getSigGrade() const{
	return (this->_sigGrade);
}

int AForm::getExcGrade() const{
	return (this->_excGrade);
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << "Form name: " << f.getName() << ", sign status: " << f.getSign() << ", required sign grade: " << f.getSigGrade() << ", required exec grade: " << f.getExcGrade();
	return os;
}

AForm::AForm(const std::string& set_name, int set_sigGrade, int set_excGrade) : _name(set_name), _sigGrade(set_sigGrade), _excGrade(set_excGrade) {
	if (set_sigGrade < 1 || set_excGrade < 1) {
		throw GradeTooHighException();
	}
	if (set_sigGrade > 150 || set_excGrade > 150) {
		throw GradeTooLowException("Invalid grade for form! Must be between 1 and 150.");
	}
	this->_sign = false;
}

AForm::AForm(const AForm& other) : _name(other._name), _sign(other._sign), _sigGrade(other._sigGrade), _excGrade(other._excGrade) {
}

AForm& AForm::operator=(const AForm& other) {
	if (this != &other) {
		this->_sign = other._sign;
	}
	return *this;
}

AForm::~AForm() {
}