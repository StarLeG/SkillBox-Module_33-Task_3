#include "menu.h"
#include "registry.h"


int main()
{
	int input = 0;
	menu();
	std::cout << "Your choice: ";
	std::cin >> input;
	Registry<std::string, int> registry;

	while (input != -1)
	{
		switch (input)
		{
		case Command::EXIT :
			std::cout << "BAY!" << std::endl;
			input = -1;
			return 0;
		case Command::ADD:


			break;
		case Command::FIND:
			break;
		case Command::PRINT:
			break;
		case Command::REMOVE:
			break;
		default:
			break;
		}
		menu();
		std::cout << "Your choice: ";
		std::cin >> input;
	}
	return 0;
}
