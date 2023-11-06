#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
#include <unordered_map>
#include <string>

using namespace std;
class Directory;


unordered_map<string,Directory*> dirs;

class File {
	public:
		string name;
		int size;
		bool isDir;
		File(string _name, int _size, bool _isDir) {
			name = _name;
			size = _size;
			isDir = _isDir;
		}
		friend ostream& operator<<(ostream &out, const File &file) {
			out<<file.name<<": " <<file.size;
			return out;
		}
		virtual int getSize() {
			return size; 
		};
};


class Directory : public File {
 	private:
		Directory* parent;
		vector<File *> files;
	public:
		Directory(string _name, Directory* _parent): File(_name, 0 , 1) {
			parent = _parent;
		}
		~Directory() {
			//cout << "deleting " << name << endl;
			for (auto file : files) {
				//cout << "removing " << file->name << endl;
				if (file && (file->isDir == 0)) {
					delete file;
				}
			}
			files.clear();
		}
		void addFile(string name, int size) {
			File* file = new File(name, size, 0);
			//cout << *file << endl;
			files.push_back(file);
		}
		void addFile(File* file) {
			//cout << *file << endl;
			files.push_back(file);
		}
		int getSize() {
			int sum = 0;
			for ( File *file : files ) {
				sum += file->getSize();
			}
			return sum;
		}
		inline Directory* getParent() { return parent; }; 
};


Directory* newDir(string name, Directory* parent) {
	Directory* dir = new Directory(name, parent);
	dirs[name] = dir;
	return dir;

}



int main(int argc, char* argv[]) {
	if (argc < 2) return -1;
		
	ifstream file(argv[1]);
	string line;
	Directory* root = newDir("/", nullptr);
	Directory* currDir = root;
	while(std::getline(file, line)) {
		if (line[0] == '$') {
			if (line[2] == 'c') {
				if (line[5] == '.') {
					currDir = currDir->getParent();	
					//cout << "moving to " << currDir->name << endl;
					continue;
				}
				else {
					string dirName = currDir->name + string(line, 5) + "/";
					//cout << "moving to " << dirName << endl;
					currDir = dirs[dirName];
					continue;
				}
			}
			continue;
		}
		if (line[0] == 'd') {
				string dirName = currDir->name + string(line, 4) + "/";
				//cout << "new dir " << dirName << endl;
				Directory* dir = newDir(dirName, currDir);
				currDir->addFile(dir);
				continue;
		}

		int fileSize = stoi(string(line,0,line.find_first_of(' ')));
		string fileName = string(line,line.find_first_of(' ')+1, line.length());
		currDir->addFile(fileName, fileSize);
	}
	file.close();
	cout << "TOTALS" << endl;
	int sum = 0;
	for (auto i : dirs){
		//cout << i.first << " : " << i.second->getSize() << endl;
		if (i.second->getSize() <= 100000) { 
			sum += i.second->getSize();
		}
	}
	cout << "Sum of dirs <= 100000 : " << sum << endl;
	
	int neededSpace = 30000000 - (70000000 - dirs["/"]->getSize());
	cout << "Space needed : " << neededSpace << endl;

	int minSize = 30000000;
	for (auto i : dirs) {
		int size = i.second->getSize();
		if (size < minSize && size > neededSpace) {
			minSize = size;
		}
	}

	cout << "Min sized Dir : " << minSize << endl;

	for (auto i : dirs){
		delete i.second;
	}
}
