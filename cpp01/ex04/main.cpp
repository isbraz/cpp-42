#include <iostream>
#include <fstream>
#include <string>
#include <istream>

void	changeString(std::string &content, std::string s1, std::string s2)
{
	size_t pos = content.find(s1);
    while (pos != std::string::npos)
    {
        content.erase(pos, s1.size());
        content.insert(pos, s2);
        pos = content.find(s1, pos + s2.size());
    }
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Wrong number of arguments!" << std::endl;
		return (0);
	}
	if (!av[2][0])
	{
		std::cout << "Empty parameter!" << std::endl;
		return (0);
	}
	std::ifstream file(av[1]);
	std::istreambuf_iterator<char> begin(file), end;
	if (!file)
		std::cerr << "Could not open the file" << std::endl;
	//send the content of the file to the string content using the class string and the class ifstreambuf_iterator.
	std::string content((begin), end);

	//change the string
	changeString(content, av[2], av[3]);

	//create a file
	std::string fileName = av[1];
	fileName.append(".replace");
	std::ofstream newFile(fileName.c_str());
	newFile << content;
	newFile.close();
}


//three arguments -> filename , s1 , s2;