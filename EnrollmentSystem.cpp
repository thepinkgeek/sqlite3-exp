#include "Database.h"
#include "Student.h"

class EnrollmentSystem { 
	private:
		Database<Student> *db;	
	public:
		EnrollmentSystem();
		void showAllStudents();
		bool insertStudentToDatabase(char* name, char* course);
		bool deleteStudentFromDatabase(int studentId);
		void queryStudentById(int studentId);
};

EnrollmentSystem :: EnrollmentSystem() {
	db = new Database<Student>((char*)"students.db");
}

void EnrollmentSystem :: showAllStudents() {
	vector<Student> students = db -> doQuery((char*)"select * from students"); 
	
	cout << "Id || Name  || Course || " << endl;

	for(int i = 0; i < students.size(); i++) {
		cout << students[i].getId();
		cout << students[i].getName();
		cout << students[i].getCourse();
	}
}

bool insertStudentToDatabase(char* name, char* course) {
	return true;
}

bool EnrollmentSystem :: deleteStudentFromDatabase(int studentId) {
	return true;
}

void EnrollmentSystem :: queryStudentById(int studentId) {

}

int main() {
		
	return 0;
}


