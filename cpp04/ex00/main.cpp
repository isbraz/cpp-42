#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"


int main(void){
	// Animal* animal1 = new Animal();
    // Animal* animal2 = new Dog();

    // animal1->makeSound(); 
    // animal2->makeSound();

    // delete animal1;
    // delete animal2;

    
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* wa = new WrongAnimal();
	const WrongAnimal* w = new WrongCat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	//////////////////
	wa->makeSound();
	w->makeSound();


	delete meta;
	delete j;
	delete i;
	delete wa;
	delete w;
}