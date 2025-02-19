#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

class Bureaucrat {
private:
	std::string _name;
	int _grade;
public:
	Bureaucrat(const std::string& set_name, int set_grade);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);
	~Bureaucrat();

	void incrementGrade();
	void decrementGrade();

	std::string getName() const;
	int getGrade() const;

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw(){
				return "Grade is too high! Must be lower or equal to 1";
		}
	};
	class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw(){
				return "Grade is too low! Must be higher or equal to 150";
		}
	};

	friend std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);
};
