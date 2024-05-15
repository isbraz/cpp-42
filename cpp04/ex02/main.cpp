#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


int main(void){
	// AAnimal test;

	// const Animal* d = new Dog();
	// const Animal* c = new Cat();

	// // delete d; //hould not create a leak
	// // delete c;

	// for(int i = 0; i < 8 ; i++){
	// 	if (i < 4)
	// 		objs[i] = new Dog();
	// 	else
	// 		objs[i] = new Cat();
	// }
	// for (int i = 0; i <  8; i++){
	// 	delete objs[i];
	// }

	Dog oscar;
	Dog junior;
	Cat garfield;

	oscar.setIdeas("Oscar: i want to wag my tale!", 0);
	junior = oscar;
	std::cout << junior.getIdeas(0) << std::endl;
	std::cout << oscar.getIdeas(0) << std::endl;
	garfield.setIdeas("Garfield : i am feeling lazy!", 0);
	std::cout << garfield.getIdeas(0) << std::endl;
}