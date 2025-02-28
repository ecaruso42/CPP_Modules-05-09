#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void){
	try{
		std::cout << "INIZIALIZZAZIONE CLASSI E TEST DI COPY CONSTRUCTOR E OPERATOR\n" << std::endl;
		Bureaucrat b1("Franco", 2);
		Bureaucrat b2("Carlo", 149);
		Bureaucrat b3("Paolo", 50);
		
		ShrubberyCreationForm Tree("grass");
		Tree.beSigned(b1);
		b1.executeForm(Tree);

		RobotomyRequestForm Robot("Gino");
		Robot.beSigned(b1);
		b1.executeForm(Robot);

		PresidentialPardonForm Galeotto("Pacciani");
		Galeotto.beSigned(b1);
		b2.executeForm(Galeotto);
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