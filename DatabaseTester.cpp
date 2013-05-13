#include "Database.h"
#include "Student.h"
#include<vector>
#include<iostream>


using namespace std;
int main() {
	Database<Student> db((char*)"students.db");
	cout << "connection done. " << endl;
	vector<Student> students = db.doQuery((char*)"select * from students");		
	for(int i = 0; i < students.size(); i++) {
		cout << students.at(i).getId();
		cout << students.at(i).getName();
		cout << students.at(i).getCourse() << endl;
		
	}	
	return 0;
}
