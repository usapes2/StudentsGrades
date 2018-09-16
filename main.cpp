#include<iomanip>
#include<ios>
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stdexcept>
#include "median.h"
#include "Student_info.h"
#include "grade.h"


using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;
using std::sort;
using std::domain_error;
using std::istream;
using std::max;

// coumpute the median of a vector<double>
// note that calling this function copies the entire argument vector
// read homework grades from an input stream into a vector<double>

// predicate to determine whether a student failed
vector<Student_info> extract_fails(vector<Student_info> & students)
{
	vector<Student_info> pass,fail;

	for(vector<Student_info>::size_type i=0;i != 0; ++i) {
		if (fgrade(students[i])) 
			fail.push_back(students[i]);
		else 
		 	pass.push_back(students[i]);
		}	

	students = pass;
	return fail;
}	


int main() 
{
	vector<Student_info> students;
	Student_info record;
	string::size_type maxlen = 0;

	// read and store all the records, and find the length of the longest name
	while (read(cin,record)) {
		maxlen = max(maxlen,record.name.length());
		students.push_back(record);
	}

	// alphabetize the records
	sort(students.begin(),students.end(),compare);
	
	for (vector<Student_info>::size_type i=0; i!=students.size();++i){
		// write the name, padded on the right to maxlen + 1 characters
		cout << students[i].name
			<<string(maxlen+1-students[i].name.size(),' ');

		// compare and write the grade
	try {
		double final_grade = grade(students[i]);
		streamsize prec = cout.precision();
		cout << " Your final grade is "<< setprecision(3)
		<< final_grade
		<< setprecision(prec) <<endl; } catch (domain_error e) {
			cout << e.what();
		}
	cout << endl;
	}

	return 0; 
}
