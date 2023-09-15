#include "readfile.h"




void print_file_line_by_line(std::ifstream& file) {
	if (file.is_open()) {

		std::string line;
		while (std::getline(file, line)) {
			std::cout << line << std::endl;
		}
	}
}
