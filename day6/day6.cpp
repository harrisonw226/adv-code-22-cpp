#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <deque>
#include <algorithm>
using namespace std;


int main(int argc, char* argv[]) {
	if (argc < 2) return -1;
	
	ifstream file(argv[1]);
	string line;
	deque<char> signal_queue;
	bool flag = 0;
	while(std::getline(file, line)) {
		int count = 1;
		for ( auto bit : line ) {
			if (signal_queue.size() == 3) {
				flag = 0;
				//for (auto i : signal_queue) cout << i << " ";
				//cout << endl;
				if (signal_queue[0] == signal_queue[1] || signal_queue[0] == signal_queue[2] || signal_queue[1] == signal_queue[2]) {
					flag = 1;
				}

				if (!flag && find(signal_queue.begin(), signal_queue.end(), bit) == signal_queue.end()) {
					 
					cout << "count = " << count << " bit = " << bit << endl;	
					break;
				}
				signal_queue.pop_front();
				
			}
			signal_queue.push_back(bit);
			count += 1;
		}
	}
	file.close();
}
