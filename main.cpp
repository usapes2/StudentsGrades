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
using std::istream;
using std::max;

struct Student_info {
	string name;
	double midterm,final;
	vector<double> homework;
}; 
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

// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw) 
{
	// fill in this part
	// if(read_hw(cin,homework) 
	if(in){
	hw.clear();
	// read hw grades
	double x;
	while (in>>x)
		hw.push_back(x);
	in.clear();
	}
	
	return in;
}

istream& read(istream& is, Student_info& s)
{
	// read and store the student's name and midterm and final exam grades
	is>> s.name >> s.midterm >> s.final;
	read_hw(is,s.homework); // read and store all the student's homework grades
	return is;
}

double grade(const Student_info& s)
{
	return grade(s.midterm,s.final,s.homework);
}

bool compare(const Student_info& x, const Student_info& y){
	return x.name < y.name;
	} // predicate function for sorting by name


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
