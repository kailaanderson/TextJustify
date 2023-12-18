// Demonstrates file input and output
// Kaila Anderson
// October 17, 2022
 
#include <iostream>
#include <string>
#include <fstream>

using std::string; using std::cout; using std::cin;
using std::endl; using std::getline; 
using std::ifstream; using std::ofstream; 

void spaceAfterPunctuation(string&, int);
void randomSpace(string&, int);

const int maxSize = 80;

int main() {

	ifstream fin; ofstream fout;
	string infile = "unjustified.txt";
	string outfile = "justified.txt";

	fin.open(infile);
	fout.open(outfile);

	string textFile;

	while (getline(fin, textFile)) {

		int position = 0;
		spaceAfterPunctuation(textFile, position);
		fout << textFile << endl;
	}
}

void spaceAfterPunctuation(string& text, int pos) {
	ofstream fout;
	pos = text.find_first_of("!?.,:");

	
	while ( pos != text.size() - 1 && text.size() < maxSize) {

		text.insert(pos + 1, " ");
		pos = text.find_first_of("?.,:!", pos +1);
		if (pos == string::npos) break;
	}
	if (text.size() < maxSize) {
		randomSpace(text, pos);
		}

}


	void randomSpace(string & text, int pos) {
	pos = 0;
	ofstream fout;

	while (text.size() < maxSize && text.size() > 40) {
		pos = rand() % 80;
		pos = text.find_first_of(" ", pos);
		if (pos != maxSize) //
			text.insert(pos + 1, " ");
	}
	fout << text << endl;
} 



