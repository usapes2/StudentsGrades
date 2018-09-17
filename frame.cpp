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

vector<string> frame(const vector<string>& v) {
	vector<string> ret;
	string::size_type maxlen = width(v);
	string border(maxlen+4,'*');
	
	// write the top border
	ret.push_back(border);

	// write each interior row, bordered by an asterisk and a space
	for (vector<string>::size_type i =0; i!=v.size();++i){
	 ret.push_back("* " + v[i] + string(maxlen-v[i].size(),' ') +" *");
	}

	// write the bottom border
	ret.push_back(border);
	return ret;
}

int main() {

	vector<string> v;
	v.push_back("Sapeshka");
	vector<string> k = frame(v);
	for(int i = 0; i!=k.size();++i)
		cout <<k[i]<<endl; 
	return 0;

}

