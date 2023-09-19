#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>

using namespace std;

enum hand{
	R = 0,
	P = 1,
	S = 2,
};


int main(int argc, char* argv[]) {
	if (argc < 2) return -1;
		
	ifstream file(argv[1]);
	string line;
	int tot_score = 0;
	int hand_score = 0;
	int rslt_score = 0;
	hand opp_hand;
	hand your_hand;
	while(std::getline(file, line)) {
		//cout << line << endl;	
		switch( line[0] ){
			case ('A'): opp_hand = R; break;
			case ('B'): opp_hand = P; break;
			case ('C'): opp_hand = S; break;
		}
		switch( line[2] ){
			case ('X'): your_hand = R; hand_score = 1; break;
			case ('Y'): your_hand = P; hand_score = 2; break;
			case ('Z'): your_hand = S; hand_score = 3; break;
		}
		//cout << your_hand - opp_hand << endl;
		switch ( your_hand - opp_hand ){
		case (-2): rslt_score = 6; break;
		case (-1): rslt_score = 0; break;
		case (0): rslt_score = 3; break;
		case (1): rslt_score = 6; break;
		case (2): rslt_score = 0; break;
		}
		//cout << hand_score << " " << rslt_score << " " << hand_score + rslt_score << endl;
		tot_score += hand_score + rslt_score;
		//cout << "-------------" << endl;
	}
	cout << "part 1 final score: " << tot_score << endl;
	file.close();
}
