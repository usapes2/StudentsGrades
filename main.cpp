#include<iomanip>
#include<ios>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;

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
	// the number and sum of grades read so far
	int count = 0;
	double sum = 0;

	// revised version of the excerpt:
	double x;
	vector<double> homework;

	// invariant: homework contains all the hws grades read so far
	while ( cin>>x) 
		homework.push_back(x);

	typedef vector<double>::size_type vec_sz; // give alias named vec_sz for the vector<double>::size_type
	vec_sz size = homework.size();            // create variable size and assign the size of the hw vector to it 
	// verify that we have some data before we find the median
	if ( size == 0 ){
		cout << endl<<"Your must enter your grades. "
			"Please try again."<<endl;;
		return 1;
	} 

	// calculating median
	sort(homework.begin(), homework.end()); // sort fund defined in algortithm include
	// finding mid elemet or elements of the sorted data to compute median
	vec_sz mid = size/2;	
	double median;
	median = size % 2 == 0 ? (homework[mid] + homework[mid-1])/2
		:homework[mid];
	// write the result 
	streamsize prec = cout.precision();
	cout << " Your final grade is "<< setprecision(3)
		<<0.2*midterm + 0.4 *final + 0.4*median
		<< setprecision(prec) <<endl;

	return 0;
}
