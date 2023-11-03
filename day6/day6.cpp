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
		int position = 1;
		for ( auto bit : line ) {
			if (signal_queue.size() == 13) {
				flag = 0;
				//for (auto i : signal_queue) cout << i << " ";
				//cout << endl;
	

				for (auto i : signal_queue){
					int occ = count(signal_queue.begin(), signal_queue.end(), i);
					if ( occ != 1 ) {
						flag = 1;
					}
				}

				if (!flag && find(signal_queue.begin(), signal_queue.end(), bit) == signal_queue.end()) {
					 
					cout << "position = " << position << " bit = " << bit << endl;	
					break;
				}
				signal_queue.pop_front();
				
			}
			signal_queue.push_back(bit);
			position += 1;
		}
	}
	file.close();
}
