#pragma once
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{

	private:
	const std::string target;

	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);	
		~ShrubberyCreationForm();

		std::string getTarget() const;
};
