#include "Bureaucrat.hpp"

int main(void){
	try{
		std::cout << "INIZIALIZZAZIONE CLASSI E TEST DI COPY CONSTRUCTOR E OPERATOR\n" << std::endl;
		Bureaucrat b1("Franco", 2);
		Bureaucrat b2("Carlo", 149);
		Bureaucrat b3("Paolo", 50);
		Bureaucrat b4 = b3;
		Bureaucrat b5("CopyOperatorTest", 70);
		b5 = b2;

		std::cout << "b1= " << b1 << std::endl;
		std::cout << "b2= " << b2 << std::endl;
		std::cout << "b3= " << b3 << std::endl;
		std::cout << "b4= " << b4 << std::endl;
		std::cout << "b5= " << b5 << std::endl;

		std::cout << "\nTEST INCREMENTO, DECREMENTO ED ECCEZIONI\n" << std::endl;
		b1.incrementGrade();
		std::cout << "b1 after increment= " << b1 << std::endl;
		//per testare l'eccezzione scommentare
		//b1.incrementGrade();
		//std::cout << "b1 after 2˚ increment =" << b1 << std::endl;

		b2.decrementGrade();
		std::cout << "b2 after decrement= " << b2 << std::endl;
		//per testare l'eccezzione scommentare
		//b2.decrementGrade();
		//std::cout << "b2 after 2˚ increment =" << b2 << std::endl;

		std::cout << "\nTEST DEI GETTER\n" << std::endl;
		std::cout << "Nome b3 = " << b3.getName() << std::endl;
		std::cout << "Grado b3 = " << b3.getGrade() << std::endl;
	}
	catch (const Bureaucrat::GradeTooHighException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}