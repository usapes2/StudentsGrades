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
//	ret.insert(ret.end(),bottom.begin(),bottom.end());

//	Yet another way to do this using copy functions from Alg
	copy(bottom.begin(),bottom.end(),back_inserter(ret));
	return ret;
}

void printvect(vector<string> v) {
	for( vector<string>::reverse_iterator it =v.rbegin(); it != v.rend(); ++it)
		cout << *(it) << endl;
}

void printvectrev(vector<string> v) {
	for( vector<string>::const_iterator it =v.begin(); it != v.end(); ++it)
		cout << *(it) << endl;
}
vector<string> hcat(const vector<string>& left, const vector<string>& right)
{
	vector<string> ret;

	// add 1 to leave a space between pictures
	string::size_type width1 = width(left) + 1;
	
	// indices to look at elemtents from left and right respectivly
	vector<string>::size_type i=0,j=0;

	// continue untill we've seen all rows from both pictures
	while ( i != left.size() || j != right.size()) {
	// construct new string to hold characters from both pictures
		string s;

	// copy a row from the left hand side, if there is one
		if(i != left.size())
			s+= left[i++];
		// pad to full width
		s+= string(width1 - s.size(),' ');

	// copy a row from the right hand side, if there is one
		if(j != right.size())
			s+= right[j++];
		ret.push_back(s);
	}
	
	return ret;

}



int main() {

	vector<string> v;
	v.push_back("1");
	v.push_back("2");
	v.push_back("3");
	v.push_back("4");
	v.push_back("5");
	v.push_back("6");
	vector<string> f(v);
	printvect(vcat(f,v));

	return 0;

}

