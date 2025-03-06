#include "RobotomyRequestForm.hpp"

void RobotomyRequestForm::executeAction() const{
	std::cout << "Bzzzzzzz...rrrrrrr...prrrrrrrr" << std::endl;
	srand(time(NULL));

	if (rand() % 2 == 0) {
		std::cout << target << " has been robotomized successfully" << std::endl;
	}
	else {
		std::cout << "The robotomy of " << target << " has failed." << std::endl;
	}
}

static AForm* create(std::string target) { 
	return new RobotomyRequestForm(target); 
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyForm", 72, 45), target(target){
	std::cout << "Robotomy Form has been created" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), target(other.getTarget()){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other){
	(void) other;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

std::string RobotomyRequestForm::getTarget(void) const {
	return this->target;
}