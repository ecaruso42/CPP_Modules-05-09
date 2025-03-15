#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void){
	try{
		std::cout << "INIZIALIZZAZIONE CLASSI E TEST DI COPY CONSTRUCTOR E OPERATOR\n" << std::endl;
		Bureaucrat b1("Franco", 2);
		Bureaucrat b2("Carlo", 149);
		Bureaucrat b3("Paolo", 50);
		
		AForm* f0;
		AForm* f1;
		AForm* f2;
		AForm* f3;
		Intern I;
		f0 = I.makeForm("shrek form", "Shrek");
		//il void l'ho messo solo per testare il caso di errore di makeform
		(void) f0;
		f1 = I.makeForm("shrubbery request", "tree");
		b1.signForm(*f1);
		b1.executeForm(*f1);
		f2 = I.makeForm("robotomy request", "Bender");
		b1.signForm(*f2);
		b1.executeForm(*f2);
		f3 = I.makeForm("presidential request", "Luigi Mangione");
		b1.signForm(*f3);
		b1.executeForm(*f3);
		delete f1;
		delete f2;
		delete f3;
	}
	catch (const AForm::GradeTooLowException& e){
		std::cerr << "Exception caught: " << e.what() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}