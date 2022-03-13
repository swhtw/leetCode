// problem url
#include <iostream>
#include "Utility.h"

using namespace std;

int main()
{

	//"wordgoodgoodgoodbestword"
//["word", "good", "best", "good"]
	string s = "wordgoodgoodgoodbestword";
	vector<string> words = { "word", "good", "best", "good" };
	findSubstring(s, words);
	return 0;
}