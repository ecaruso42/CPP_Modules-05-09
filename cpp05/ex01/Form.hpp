#pragma once
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _sign;
	const int _sigGrade;
	const int _excGrade;
public:
	Form(const std::string& set_name, int set_sigGrade, int set_excGrade);
	Form(const Form& other);
	Form& operator=(const Form& other);
	~Form();

	void beSigned(Bureaucrat& b);

	std::string getName() const;
	bool getSign() const;
	int getSigGrade() const;
	int getExcGrade() const;

	class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade is too high! Must be lower or equal to 1";
			}
	};
	class GradeTooLowException : public std::exception{
		private:
    		std::string _message;

		public:
    		GradeTooLowException(const std::string& message) : _message(message) {}

    		const char* what() const throw() {
        	return _message.c_str();
    		}
			~GradeTooLowException() throw() {}
};
	friend std::ostream& operator<<(std::ostream& os, const Form& f);
};

