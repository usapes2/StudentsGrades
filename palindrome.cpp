#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool is_pali(const string& s)
{
	return equal(s.begin(),s.end(),s.rbegin());
}

int main() {
	cout << is_pali("car");
	cout << is_pali("civic");
	return 0;
}
