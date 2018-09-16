#include<string>
#include<iostream>
#include<vector>
#include"grade.h"
#include"Student_info.h"
#include"median.h"
#include<cctype>
using namespace std;

vector<string> split(const string& s)
{
	vector<string> ret;
	typedef string::size_type string_size;
	string_size i=0;

// invariant: we have processed characters[original value of i,i)
	while(i != s.size()) {
// ignore leading blanks
//invariant: characters in range[original i, current i) are all spaces
	while(i!=s.size() && isspace(s[i]))
		++i;

// find end of next word
	string_size j = i;
// invariant: none of t!e characters in range [original j, current j) is a space
	while(j != s.size() && !isspace(s[j]))
			j++;
// if we found some nonwhitespace characters
	if(i !=j) {
		// copy from s starting at i and taking j-i chars
		ret.push_back(s.substr(i,j-i));
		i=j;
	}
	}
	return ret;
}

int main () {
	//string s("1 2 3 4 5 6 7 8 9");
	string s ;
	// read and split each line of input
	while (getline(cin,s)) {
		vector<string> v = split(s);
		// write each word in v
		for(vector<string>::iterator iter = v.begin() ;
			iter != v.end(); ++iter)
			cout << *iter <<endl; 
	}

	return 0;
}
