#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;



struct Move {
	int amount;
	int from;
	int to;
	Move(int amount_, int from_, int to_) : amount(amount_), from(from_), to(to_){};
};

void print_piles(vector<vector<char>> piles) {

	for (int i = 0; i < piles.size(); i++) {
		cout << "pile " << i+1 << ":";
		for (auto j : piles[i]) cout << " " << j;
		cout << endl;
	}
}



int main(int argc, char* argv[]) {
	if (argc < 2) return -1;
		
	ifstream file(argv[1]);
	string line;
	std::vector<string> lines;
	while(std::getline(file, line)) {
		lines.push_back(line); 
	}
	file.close();

	int num_of_piles, count;
	count = 0;
	for (auto line : lines) {
		if (line[1] == '1') {
			num_of_piles = stoi(string(line, line.length()-3, line.length()-2));
			break;
		}
		count += 1;
	}
	vector<vector<char>> piles(num_of_piles);
	
	for (int i = count - 1; i >= 0; i--) {
		for (int j = 0; j < num_of_piles; j++){
			if (lines[i][(j*4)+1] != ' ') {
				piles[j].push_back(lines[i][(j*4)+1]);
			}
		}
	}

  vector<char> holder;
	vector<string> moves(lines.begin() + count + 2, lines.end());
	for (auto move : moves) {
		int amount = stoi(string(move, 5, move.find("from")-1));
		int from = stoi(string(move, move.find("from")+5, move.find("to")-1));
		int to = stoi(string(move, move.find("to")+3, move.length()));
		holder.clear();
		for (int i = 0; i < amount; i++) {
			char temp = piles[from-1].back();
			//holder.push_back(temp);
			piles[to-1].push_back(temp);
			piles[from-1].pop_back();
		}/*
		for (int i = 0; i < amount; i++) {
			char temp = holder.back();
			piles[to-1].push_back(temp);
			holder.pop_back();
		}
		*/
	}
for (auto i : piles) cout << i.back();
cout << endl;
}
