#include<iomanip>
#include<ios>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdexcept>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;
using std::domain_error;

// coumpute the median of a vector<double>
// note that calling this function copies the entire argument vector
double median(vector<double> vec)
{
	typedef vector<double>::size_type vec_sz; // give alias named vec_sz for the vector<double>::size_type
	vec_sz size = vec.size();// create variable size and assign the size of the hw vector to it 
	if ( size == 0 )
		throw domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());
	vec_sz mid = size/2;	

	return 	size % 2 == 0 ? (vec[mid] + vec[mid-1])/2 :vec[mid];
}

double grade(double midterm,double final, double homework)
{
	return 0.2*midterm + 0.4*final + 0.4*homework ;
}

double grade(double midterm, double final, const vector<double>& hw )
{
	if (hw.size() == 0 )
		throw domain_error("student has done no homework");
	return grade(midterm,final,median(hw));
}

int main() 
{
	// ask for and read the student's name
	cout << "Please enter your first name: ";
	string name;
	cin >> name;
	cout << "Hello,"<<name<<"!"<<endl;

	// ask for and read the midterm and final grades
	cout << "Pleae enter your midterm and final exam grades: ";
	double midterm,final;
	cin>>midterm>>final;

	// ask for the homework grades
	cout << "Enter all your homework grades,"
		"followd by end-of-file: ";

	double x;
	vector<double> homework;

	// invariant: homework contains all the hws grades read so far
	while ( cin>>x) 
		homework.push_back(x);

	streamsize prec = cout.precision();
	cout << " Your final grade is "<< setprecision(3)
		<<0.2*midterm + 0.4 *final + 0.4*median(homework)
		<< setprecision(prec) <<endl;

	return 0;
}
