#include "menu.h"
#include "registry.h"


int main()
{
	Registry<std::string, int> MyReg;
	Registry<int, std::string> MyReg_1;
	try
	{
		MyReg.add("Apple", 10);
		MyReg.add("Pear", 2);
		MyReg.add("Pear", 12);
		MyReg.add("Plum", 8);
		MyReg.add("Peach", 7);
		MyReg.print();
		MyReg.print(MyReg.find("Plum"));
		MyReg.print(MyReg.find("Orange"));
		MyReg.remove("Plum");
		MyReg.print();


		MyReg_1.add(1,"Apple");
		MyReg_1.add(2,"Pear");
		MyReg_1.add(3,"Plum");
		MyReg_1.add(4,"Peach");
		MyReg_1.print();





	}
	catch (std::invalid_argument& ex)
	{
		std::cerr << "Invalid argument " << ex.what() << std::endl;
	}
	return 0;
}

