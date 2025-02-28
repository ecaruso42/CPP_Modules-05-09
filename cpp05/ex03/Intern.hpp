#pragma once
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
public:
	AForm* makeForm(std::string formName, std::string formTarget);

	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();
};
