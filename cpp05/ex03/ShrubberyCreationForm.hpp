#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm{

	private:
	const std::string target;

	public:
		ShrubberyCreationForm(const std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);	
		~ShrubberyCreationForm();

		static AForm* create(std::string target);
		std::string getTarget() const;
		void executeAction() const;
};
