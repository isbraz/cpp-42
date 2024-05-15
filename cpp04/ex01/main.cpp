#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"


int main(void){
	// Animal *objs[8];

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
	// Dog gabriel(oscar);
	Cat garfield;

	oscar.setIdeas("I am Oscar and want to wag my tale!", 0);
	junior = oscar;
	// gabriel = junior;
	// junior.setIdeas("I am Junior and i want to wag my tale", 0);
	std::cout << oscar.getIdeas(0) << std::endl;
	std::cout << junior.getIdeas(0) << std::endl;
	// garfield.setIdeas("I am feeling lazy!", 0);
	// std::cout << garfield.getIdeas(0) << std::endl;
}