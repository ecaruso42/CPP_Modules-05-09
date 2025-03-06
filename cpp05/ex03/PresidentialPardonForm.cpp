#include "PresidentialPardonForm.hpp"

void PresidentialPardonForm::executeAction() const{
	std::cout << target << " has beeen pardoned by Zaphod Beeblebrox" << std::endl;
}

static AForm* create(std::string target) { 
	return new PresidentialPardonForm(target); 
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialForm", 25, 5), target(target){
	std::cout << "Presidential Form has been created" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm(other), target(other.getTarget()){
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other){
	(void) other;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

std::string PresidentialPardonForm::getTarget(void) const {
	return this->target;
}