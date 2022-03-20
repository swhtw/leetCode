// problem url
#include "Utility.h"
#include <iostream>
using namespace std;

int main()
{
	string s = "wordgoodgoodgoodbestword";
	vector<string> words = { "word", "good", "best", "good" };
	vector<int> result = findSubstring(s, words);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << ", ";
	}
	cout << endl;
	return 0;
}