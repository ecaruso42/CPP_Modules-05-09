#pragma once
#include "AForm.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm{

	private:
	const std::string target;

	public:
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);	
		~RobotomyRequestForm();

		static AForm* create(std::string target);
		std::string getTarget() const;
		void executeAction() const;
};