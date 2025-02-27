#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyForm", 145, 137), target(target){
	std::cout << "Shrubbery Form has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.getTarget()){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

std::string ShrubberyCreationForm::getTarget(void) const {
	return this->target;
}