#ifndef STUDENT_H
#define STUDENT_H

#include<string>
#include<cstdlib>

using namespace std;

class Student {
	private:
		int id;
		char* name;
		char* course;
		
		void initialize(int id, char* name, char* course);

	public:
		Student();
		Student(int id, char* name, char* course);
		Student(char* parameters[], int paramLength);
		int getId();
		const char* getName();
		const char* getCourse();
};

Student :: Student(int id, char* name, char* course) {
	initialize(id, name, course);
}

void Student :: initialize(int id, char* name, char* course) {
	this -> id = id;
	this -> name = name;
	this -> course = course;
}

Student :: Student(char* parameters[], int paramLength) {
	if(paramLength == 3) {
		initialize(atoi(parameters[0]),
			parameters[1],
			parameters[2]);
	}	
}

Student :: Student() {
	this ->	id = -1;
	this -> name = NULL;
	this -> course = NULL;
}

int Student :: getId() {
	return this -> id;
}


const char* Student :: getName() {
	string nameCopy(this -> name);

	return nameCopy.c_str();
}

const char* Student :: getCourse() {
	string courseCopy(this -> course);
	
	return courseCopy.c_str();
}



#endif
