#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
#include<vector>

using namespace std;

bool space(char c) 
{
	return isspace(c);
}

bool not_space(char c) 
{
	return !isspace(c);
}

bool comma(char c) 
{
	return ispunct(c);
}

bool not_comma(char c) 
{
	return !ispunct(c);
}

void printvect(vector<string> v) {
	for( vector<string>::reverse_iterator it =v.rbegin(); it != v.rend(); ++it)
		cout << *(it) << endl;
}
vector<string> split(const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;
	iter i= str.begin();

	while (i != str.end()) {
		// ignore leading blanks
		i=find_if(i,str.end(),not_comma);

		// find end of next word
		iter j = find_if(i,str.end(),comma);

		// copy the characters in [i,j)
		if (i != str.end())
			ret.push_back(string(i,j));
		i=j;
	}
	return ret;
}
	
vector<string> split2(const string& str)
{
	typedef string::const_iterator iter;
	vector<string> ret;
	iter i= str.begin();

	int k = 0;
	while (i != str.end()) {
		if ( k==1) { break ;}
		// ignore leading blanks
		i=find_if(i,str.end(),not_comma);

		// find end of next word
		iter j = find_if(i,str.end(),comma);

		// copy the characters in [i,j)
		if (i != str.end())
			ret.push_back(string(i,j));
		i=j;
		k++;
	}
	return ret;
}
	


int main() {
	string s;
	while (getline(cin,s)) {
		vector<string> v = split2(s);
		// write each word in v
		for(vector<string>::iterator iter = v.begin() ;
			iter != v.end(); ++iter)
			cout << *iter <<endl; 
	}
	return 0;
}
