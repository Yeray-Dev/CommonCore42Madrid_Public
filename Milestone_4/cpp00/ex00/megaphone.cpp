#include <iostream>
#include <string>

int main(int argc, char** argv){
	if (argc < 2){
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 1;
	}
	
	for (int j = 1; j < argc; j++){
		std::string str = argv[j];
		for (size_t i = 0; i < str.size(); i++){
			str[i] = std::toupper(str[i]);
		}
		std::cout << str;
	}
	std::cout << "\n";
}
