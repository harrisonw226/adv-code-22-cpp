#include <cctype>
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;


int main(int argc, char* argv[]) {
	if (argc < 2) return -1;
		
	ifstream file(argv[1]);
	string line;
	int badge_val = 0;
	int badge_val_tot = 0;
	while(std::getline(file, line)) {
		cout << line << endl;
		string bag1 = string(line, 0, (line.length())/2);
		string bag2 = string(line, (line.length())/2, line.length());
		
		for (auto c : bag1) {
			if ( bag2.find_first_of(c) != std::string::npos){ 
				cout << c << endl;
				cout << (int) c << endl;
				if (isupper(c)) {
					badge_val = (int) c - 38;
				}
				else {
					badge_val = (int) c - 96; 
				}
				cout << badge_val << endl;
				badge_val_tot += badge_val;
				break;
			}
		}

	}
	cout << "total: " << badge_val_tot << endl;
	file.close();
}
