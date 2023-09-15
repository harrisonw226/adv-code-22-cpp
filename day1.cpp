#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>





int main(int argc, char* argv[]) {

	int num_to_sum = 1;
	if (argc > 1) {
		num_to_sum = atoi(argv[1]);
	}


	std::ifstream  file("./day1.txt");
	
	std::vector<int> max(num_to_sum);

	int current,tmp = 0;
	std::string line;
	while(std::getline(file, line)) {
		if (line != ""){
			current += stoi(line);
			continue;
		}
		for (int i = 0; i < max.size(); i++) {
			if (current > max[i]) {
				//std::cout << "new max " << current << " " << i << std::endl;
				tmp = max[i];
				max[i] = current;
				current = tmp;
				continue;
			}
		}
		current = 0;
	}

	file.close();
	for (int i : max) std::cout << "top "<< num_to_sum << ": " << i << std::endl;
	std::cout << std::accumulate(max.begin(), max.end(),0)  << std::endl;
}
