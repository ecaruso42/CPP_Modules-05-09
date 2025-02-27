#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialForm", 25, 5), target(target){
	std::cout << "Presidential Form has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.getTarget()){
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

std::string PresidentialPardonForm::getTarget(void) const {
	return this->target;
}