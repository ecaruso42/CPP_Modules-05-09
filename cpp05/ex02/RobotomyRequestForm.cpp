#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyForm", 72, 45), target(target){
	std::cout << "Robotomy Form has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.getTarget()){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

std::string RobotomyRequestForm::getTarget(void) const {
	return this->target;
}