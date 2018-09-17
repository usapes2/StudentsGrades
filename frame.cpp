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

vector<string> vcat(const vector<string>& top, const vector<string>& bottom)
{
	// copy the top picture
	vector<string> ret = top;

	// copy entire bottom picture
/*for ( vector<string>::const_iterator it = bottom.begin(); it!=bottom.end(); ++it) {
		ret.push_back(*it);
	}
	return ret; */

	// we can use what library offers us
	ret.insert(ret.end(),bottom.begin(),bottom.end());
	return ret;
}

void printvect(vector<string> v) {
	for( vector<string>::const_iterator it =v.begin(); it != v.end(); ++it)
		cout << *(it) << endl;
}
int main() {

	vector<string> v;
	vector<string> f;
	f.push_back("Random");
	f.push_back("Random");
	f.push_back("Random");
	f.push_back("Random");
	f.push_back("Random");
	f.push_back("Random");
	f.push_back("Random");
	v.push_back("Sapeshka");
	v.push_back("Sapeshka");
	v.push_back("Sapeshka");
	v.push_back("Sapeshka");
	v.push_back("Sapeshka");
	vector<string> newvect = vcat(f,v);

	printvect(frame(newvect));
	
	return 0;

}

