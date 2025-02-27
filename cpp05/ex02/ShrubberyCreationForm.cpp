#include "ShrubberyCreationForm.hpp"

void ShrubberyCreationForm::executeAction() const{
	std::string fileName;

	fileName = this->getTarget() + "_shrubbery";
	std::ofstream file(fileName.c_str());
	if (file.is_open()){
		file << "   			,@@@@@@@, ";
		file << "   	,,,.   ,@@@@@@/@@,  .oo8888o. ";
		file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\88/8o ";
		file << "   ,%&\%&&%&&%,@@@\@@@/@@@88\88888/88' ";
		file << "   %&&%&%&/%&&%@@\@@/ /@@@88888\88888' ";
		file << "   %&&%/ %&%%&&@@\ V /@@' `88\8 `/88' ";
		file << "   `&%\ ` /%&'    |.|        \ '|8' ";
		file << "   	|o|        | |         | | ";
		file << "   	|.|        | |         | | ";
 		file << "    \\/ ._\//_/__/  ,\_//__\\/.  \_//__/_ ";
		file.close();
	}
	else
		std::cout << "Error: could not open file" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyForm", 145, 137), target(target){
	std::cout << "Shrubbery Form has been created" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), target(other.getTarget()){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other){
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

std::string ShrubberyCreationForm::getTarget(void) const {
	return this->target;
}