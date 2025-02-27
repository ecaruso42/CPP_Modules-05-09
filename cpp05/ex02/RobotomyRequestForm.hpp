#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm{

	private:
	const std::string target;

	public:
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);	
		~RobotomyRequestForm();

		std::string getTarget() const;
};