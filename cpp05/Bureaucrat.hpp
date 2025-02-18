#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat {
private:
	std::string _name;
	int _grade;
public:
	//ricorda di implementare copy constructor e copy operator
	Bureaucrat(const std::string& set_name, int set_grade);
	~Bureaucrat();

	void incrementGrade();
	void decrementGrade();

	std::string getName() const;
	int getGrade() const;

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const noexcept override{
				return "Grade is too high! Must be lower or equal to 1";
		}
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const noexcept override{
				return "Grade is too low! Must be higher or equal to 150";
		}
	};

	friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
};
	

Bureaucrat::Bureaucrat(const std::string& set_name, int set_grade) : _name(set_name) {
		if (set_grade < 1) {
			throw GradeTooHighException();
		}
		if (set_grade > 150) {
			throw GradeTooLowException();
		}
		this->_grade = set_grade;
}

Bureaucrat::~Bureaucrat(){}
