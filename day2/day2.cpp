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
		//cout << your_hand - opp_hand << endl;
		switch ( line[2] ){
		case ('X'): 
			switch( line[0] ){
				case ('A'): hand_score = 3; break;
				case ('B'): hand_score = 1; break;
				case ('C'): hand_score = 2; break;
			}
			rslt_score = 0; 
			break;

		case ('Y'): 
			switch( line[0] ){
				case ('A'): hand_score = 1; break;
				case ('B'): hand_score = 2; break;
				case ('C'): hand_score = 3; break;
			}
			rslt_score = 3; 
			break;
		case ('Z'): 
			switch( line[0] ){
				case ('A'): hand_score = 2; break;
				case ('B'): hand_score = 3; break;
				case ('C'): hand_score = 1; break;
			}
			rslt_score = 6; 
			break;
		}
		//cout << hand_score << " " << rslt_score << " " << hand_score + rslt_score << endl;
		tot_score += hand_score + rslt_score;
		//cout << "-------------" << endl;
	}
	cout << "part 2 final score: " << tot_score << endl;
	file.close();
}
