#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;


int main(int argc, char* argv[]) {
	if (argc < 2) return -1;
		
	ifstream file(argv[1]);
	string line;
	while(std::getline(file, line)) {
		cout << line << endl;	
	}
	file.close();
}
