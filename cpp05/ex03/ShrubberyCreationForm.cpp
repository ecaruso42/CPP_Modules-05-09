#include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::executeAction() const{
	std::string fileName;

	fileName = this->getTarget() + "_shrubbery";
	std::ofstream file(fileName.c_str());
	if (file.is_open()){
		file << "   			,@@@@@@@, " << std::endl;
		file << "   	,,,.   ,@@@@@@/@@,  .oo8888o. " << std::endl;
		file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888888/8o " << std::endl;
		file << "   ,%&&%&&%&&%,@@@@@@@/@@@88888888/88' " << std::endl;
		file << "   %&&%&%&/%&&%@@@@@/ /@@@88888888888' " << std::endl;
		file << "   %&&%/ %&%%&&@@\' V /@@' `8888 `/88' " << std::endl;
		file << "   `&%\' ` /%&'   |.|        \' '|8' " << std::endl;
		file << "   	|o|        | |         | | " << std::endl;
		file << "   	|.|        | |         | | " << std::endl;
 		file << "    \\/ ._\'//_/__/  ,\'_//__\\/.  \'_//__/_ " << std::endl;
		file.close();
	}
	else
		std::cout << "Error: could not open file" << std::endl;
}

static AForm* create(std::string target) { 
	return new ShrubberyCreationForm(target); 
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyForm", 145, 137), target(target){
	std::cout << "Shrubbery Form has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.getTarget()){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	(void) other;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

std::string ShrubberyCreationForm::getTarget(void) const {
	return this->target;
}