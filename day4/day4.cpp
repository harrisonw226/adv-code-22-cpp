#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

struct bound {
	bound():lower(0),upper(0){};
	bound(int first, int second): lower(first), upper(second){};
	inline void fill(int first, int second){ lower = first; upper = second;};
	void fill(string line) {
		lower = stoi(string(line, 0, line.find_first_of('-')));
		upper = stoi(string(line, line.find_first_of('-')+1, line.length()));
	}
	int contains(bound other) {
		if (other.lower <= lower && other.upper >= upper)
			return 1;
		if (other.lower >= lower && other.upper <= upper)
			return 1;
		return 0;

	}
	int lower;
	int upper;
	
};


int main(int argc, char* argv[]) {
	if (argc < 2) return -1;
		
	ifstream file(argv[1]);
	string line;
	bound bound1, bound2;
	int sum = 0;
	while(std::getline(file, line)) {
		//cout << line << endl;
		
		bound1.fill(string(line, 0, line.find_first_of(',')));
		bound2.fill(string(line, line.find_first_of(',')+1, line.length()));
		//cout << bound1.contains(bound2) << endl;
		sum += bound1.contains(bound2);
	}
	cout << sum << endl;
	file.close();
}
