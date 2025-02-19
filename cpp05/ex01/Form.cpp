#include "Form.hpp"

int Form::beSigned(Bureaucrat& b) {
	if (b.getGrade() <= getSigGrade()) {
		_sign = true;
		return 1;
	}
	else {
		return -1;
	}
}

std::string Form::getName() const{
	return (this->_name);
}

bool Form::getSign() const{
	return (this->_sign);
}

int Form::getSigGrade() const{
	return (this->_sigGrade);
}

int Form::getExcGrade() const{
	return (this->_excGrade);
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Form name: " << f.getName() << ", sign status: " << f.getSign() << ", required sign grade: " << f.getSigGrade() << "required exec grade" << f.getExcGrade();
	return os;
}

Form::Form(const std::string& set_name, int set_sigGrade, int set_excGrade) : _name(set_name), _sigGrade(set_sigGrade), _excGrade(set_excGrade) {
	if (set_sigGrade < 1 || set_excGrade < 1) {
		throw GradeTooHighException();
	}
	if (set_sigGrade > 150 || set_excGrade > 150) {
		throw GradeTooLowException("Invalid grade for form! Must be between 1 and 150.");
	}
	this->_sign = false;
}

Form::Form(const Form& other) : _name(other._name), _sign(other._sign), _sigGrade(other._sigGrade), _excGrade(other._excGrade) {
}

Form& Form::operator=(const Form& other) {
	if (this != &other) {
		this->_sign = other._sign;
	}
	return *this;
}

Form::~Form(){
}