/*
 * SearchString.cpp
*
 */

#include "StringSearch.h"

void prefixFunction(string pattern, int pi[]){

	int m = pattern.length();
	int k;
	pi[0] = -1;
	for (int i = 1; i < m; i++)
	{
		k = pi[i - 1];
		while (k >= 0)
		{
			if (pattern[k] == pattern[i - 1])
				break;
			else
				k = pi[k];
		}
		pi[i] = k + 1;
	}
}

bool KMP(string pattern, string target){
	int m = pattern.length();
	int n = target.length();
	int pi[m];
	prefixFunction(pattern, pi);
	int i = 0;
	int k = 0;
	while (i < n)
	{
		if (k == -1)
		{
			i++;
			k = 0;
		}
		else if (target[i] == pattern[k])
		{
			i++;
			k++;
			if (k == m)
				return true;
		}
		else
			k = pi[k];
	}
	return false;

}


