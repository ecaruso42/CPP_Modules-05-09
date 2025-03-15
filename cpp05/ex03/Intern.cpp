#include "Intern.hpp"

AForm* Intern::makeForm(std::string formName, std::string formTarget){
	struct FormType {
		std::string name;
		AForm* (*create)(std::string target);
	};

	static const FormType formTypes[] = {
		{"shrubbery request", &ShrubberyCreationForm::create},
		{"robotomy request", &RobotomyRequestForm::create},
		{"presidential request", &PresidentialPardonForm::create}
	};

	for (size_t i = 0; i < 3; i++) {
		if (formTypes[i].name == formName) {
			std::cout << "Intern creates " << formName << std::endl;
			return formTypes[i].create(formTarget);
		}
	}
	std::cout << "Error: " << formName << " does not exist" << std::endl;
	return NULL;
}

Intern::Intern(){
}

Intern::Intern(const Intern& other){
	(void) other;
}

Intern& Intern::operator=(const Intern& other){
	(void) other;
	return *this;
}

Intern::~Intern(){	
}