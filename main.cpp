/* iterator is a value that
 * identifies a container and an element in the container
 * lets us examine the value stored in that element
 * provides operations for moving between elements in the container
 * restricts the available operations in ways that correspond to what
 * the container can handle efficiently
 */
 
/* for(vector<Student_info>::size_type i=0;i != students.size();++i)
 * 	cout<<students[i].name<<endl;
 
 * for(vector<Student_info>::const_iterator iter = students.begin();
 * 		iter != students.end(); ++iter) {
 * 		cout <<(*iter).name<<endl;
 * 		}
 * for(vector<Student_info>::const_iterator iter = students.begin();
 * 		iter != students.end(); ++iter) {
 * 		cout <<iter->name<<endl;
 * 		}
 *
 *
 * container-type::iterator
 * container-type::const_iterator
 * (*iter).name -- same as -- iter->name
 */

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

// Third try: using iterator but not indx, still potentially slow
vector<Student_info> extract_fails(vector<Student_info> & students)
{
	vector<Student_info> fail;
	vector<Student_info>::iterator iter = students.begin();
		while(iter!=students.end()) {
			if(fgrade(*iter)) {
				fail.push_back(*iter);
				// erase returns an iterator that is positioned on the element that follows the one we just erased.
				iter = students.erase(iter);
			} else 
				++iter;
		}
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
