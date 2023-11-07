#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <array>

#define ARRHEIGHT 9
#define ARRWIDTH 9

using namespace std;
array<array<int,ARRHEIGHT>, ARRWIDTH> treeHeights;
array<array<int,ARRHEIGHT>, ARRWIDTH> treeVisible = {0};

int main(int argc, char* argv[]) {
	if (argc < 2) return -1;
		
	ifstream file(argv[1]);
	string line;
	int lineNo = 0;
	while(std::getline(file, line)) {
		//cout << line << endl;
		for (int i = 0; i < ARRWIDTH; i++) {
			int height = stoi(string(line, i, 1));
			//cout << height << endl;
			treeHeights[lineNo][i] = height;

		}
		lineNo++;
	}
	file.close();


	for (int i = 0; i < ARRHEIGHT; i++) {
		treeVisible[i][0] |= 1;
		treeVisible[i][ARRWIDTH-1] |= 1;
	}
	for (int i = 0; i < ARRWIDTH; i++) {
		treeVisible[0][i] |= 1;
		treeVisible[ARRHEIGHT-1][i] |= 1;
	}

	int max;
// from left
	for (int i = 1; i < ARRHEIGHT - 1; i++) {
		max = treeHeights[i][0];
		for (int j = 1; j < ARRWIDTH - 1; j++) {
			if (max < treeHeights[i][j]) {
				treeVisible[i][j] |= 1;
				max = treeHeights[i][j];
			}
		}
	}
// from top 
	for (int j = 1; j < ARRWIDTH - 1; j++) {
		max = treeHeights[0][j];
		for (int i = 1; i < ARRHEIGHT - 1; i++) {
			if (max < treeHeights[i][j]) {
				treeVisible[i][j] |= 1;
				max = treeHeights[i][j];
			}
		}
	}
// from right
	for (int i = ARRHEIGHT-2; i > 0; i--) {
		max = treeHeights[i][ARRWIDTH-1];
		for (int j = ARRWIDTH-2; j > 0; j--) {
			if (max < treeHeights[i][j]) {
				treeVisible[i][j] |= 1;
				max = treeHeights[i][j];
			}
		}
	}
// from bottom
	for (int j = ARRWIDTH-2; j > 0; j--) {
		max = treeHeights[ARRHEIGHT-1][j];
		for (int i = ARRHEIGHT-2; i > 0; i--) {
			if (max < treeHeights[i][j]) {
				treeVisible[i][j] |= 1;
				max = treeHeights[i][j];
			}
		}
	}


	for (int i = 0; i < ARRHEIGHT; i++) {
		for (int j = 0; j < ARRWIDTH; j++) {
			cout << treeVisible[i][j];
		}
		cout << endl;
	}

	auto sum = std::accumulate(treeVisible.cbegin(), treeVisible.cend(), 0, [](auto lhs, const auto& rhs) {
    return std::accumulate(rhs.cbegin(), rhs.cend(), lhs);
		});
	cout << sum << endl;
}
