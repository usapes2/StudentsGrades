#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
//finding the longest string
string::size_type width(const vector<string>& v)
{
	string::size_type maxlen = 0;
	for(vector<string>::size_type i=0;i!=v.size();++i)
		maxlen=max(maxlen,v[i].size());
	return maxlen;
}

int main() {

	vector<string> v;
	v.push_back("Hello");
	v.push_back("123");
	cout << width(v)<<endl;
	return 0;

}

