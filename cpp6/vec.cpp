#include <iostream>
#include <vector>
#include <map>
#include <string>



int main(){
	// std::vector <std::string>test;

	// test.push_back("ismael");
	// test.push_back("lucas");
	// test.push_back("iael");
	// test.push_back("mael");
	// test.push_back("ael");
	// std::cout <<  test.size() << std::endl;

	std::map <std::string, int>teste;

	teste["ismael"] = 10;

	std::cout << teste.size() << std::endl;

	std::cout << teste.find("ismael")->first << std::endl;
}
