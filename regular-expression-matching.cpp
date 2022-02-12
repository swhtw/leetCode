// https://leetcode.com/problems/regular-expression-matching/
#include "Utility.h"

bool isMatch0(string s, string p) {
	smatch m;
	regex e("^" + p + "$");
	return std::regex_match(s, m, e);
}

bool isMatch(string s, string p) {
	bool mustMatch = true;
	string::iterator sit = s.begin();
	string::iterator pit = p.begin();
	string::iterator restartPoint = p.end();
	while (sit != s.end() && pit != p.end())
	{
		if (*pit == '.')
		{
			if (*(pit + 1) == '*') // .*
			{
				mustMatch = false;
				pit += 2;
				restartPoint = pit; // set restart point
			}
			else // .
			{
				++sit;
				++pit;
			}
		}
		else if (*pit == '*') // a*
		{
			while (*sit == *(sit - 1))
			{
				++sit;
			}
			++pit;
		}
		else
		{
			if (*(sit++) != *(pit++))
			{
				if (pit == p.end())
				{
					return false;
				}
				else if (*pit == '*')
				{
					++pit;
				}
				else
				{
					if (mustMatch)
					{
						return false;
					}
					else
					{
						pit = restartPoint;
					}
				}
			}
		}
	}
	return true;
}

bool isMatch2(string s, string p) {
	bool mustMatch = true;
	string::iterator sit = s.begin();
	string::iterator pit = p.begin();
	while (sit != s.end() && pit != p.end())
	{
		if (*pit == '.' && *(pit + 1) == '*') 
		{ 
			pit += 2;
			if (*pit >= 'a' && *pit <= 'z')
			{
				if (*(pit + 1) != '*')
				{
					sit = std::find(sit, s.end(), *pit);
					if (sit == s.end())
					{
						return false;
					}
					++sit;
					++pit;
				}
				else
				{
					while (*sit == *pit)
					{
						++sit;
					}
					pit += 2;
				}
				
			}
		}
		else if (*pit == '.')
		{
			++sit;
		}
		else
		{
			if (*(sit++) != *(pit++))
			{
				if (*pit != '*')
				{
					return false;
				}
			}
		}
		
	}
}