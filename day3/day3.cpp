#include <cctype>
#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <string>

using namespace std;

int get_badge_val(char c){
	int badge_val;
	cout << c << endl;
	cout << (int) c << endl;
	if (isupper(c)) {
		badge_val = (int) c - 38;
	}
	else {
		badge_val = (int) c - 96; 
	}
	cout << badge_val << endl;
	return badge_val;
}


int main(int argc, char* argv[]) {
	if (argc < 2) return -1;
		
	ifstream file(argv[1]);
	string line;
	int badge_val_tot = 0;
	int mod = 0;
	string bag1;
	string bag2;
	string bag3;
	while(std::getline(file, line)) {
		cout << line << endl;
		switch (mod % 3){
		case (0): 
			bag1 = std::move(line); 
			break;
		case (1): 
			bag2 = std::move(line);
			break;
		case (2):
			bag3 = std::move(line); 
			for (auto c : bag1){
					if ( bag2.find_first_of(c) != string::npos && bag3.find_first_of(c) != string::npos) {
						cout << c << endl;
						badge_val_tot += get_badge_val(c);
						break;
					}
			}
		}
		mod += 1;
	}
	cout << "badge tot: " << badge_val_tot << endl;
	file.close();
}
