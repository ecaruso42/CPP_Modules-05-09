#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm{

	private:
	const std::string target;

	public:
		PresidentialPardonForm(const std::string target);
		PresidentialPardonForm(const PresidentialPardonForm& other);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& other);	
		~PresidentialPardonForm();

		std::string getTarget() const;
		void executeAction() const;
};