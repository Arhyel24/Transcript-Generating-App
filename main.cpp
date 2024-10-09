#include <iostream>
#include <ostream>
#include <sstream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <iterator>
#include <ctime>

#include <unistd.h>
using namespace std;


struct Course {
    string name;
    int credits;
    char grade;
};

class Student {
public:
    string id;
    string name;
    string department;
    string level;

    Course semester1[5]; // array of 5 courses for 1st semester
    Course semester2[5]; // array of 5 courses for 2nd semester

    // constructor to initialize the Student object
    Student(string i, string n, string d, string l) : id(i), name(n), department(d), level(l) {}

    // add more member functions as needed (e.g., getters, setters, etc.)
};

double getGradePoint(char grade) {
	double gradePoint = 0.0;
        switch (grade) {
            case 'A':
                gradePoint = 5.0;
                break;
            case 'B':
                gradePoint = 4.0;
                break;
            case 'C':
                gradePoint = 3.0;
                break;
            case 'D':
                gradePoint = 2.0;
                break;
            case 'E':
            	gradePoint = 1.0;
            case 'F':
                gradePoint = 0.0;
                break;
        }
        
        return gradePoint;
}

void populateStudents(vector<Student>& students, Student demoStudents[], Course courses[]) {
    
	int arraySize = 10;
	cout << "Adding " << arraySize << " to database... \n";
	
    usleep(900000);

    
        for (int i = 0; i < arraySize; i++) {
            Student newStudent = demoStudents[i];

            // Assign predefined courses to each student
            char grades[] = {'A', 'B', 'C', 'D', 'E', 'F'};
            
            for (int j = 0; j < 5; j++) {
                Course semester1Course;
                semester1Course.name = courses[j].name;
                semester1Course.credits = courses[j].credits;
                semester1Course.grade = grades[rand() % 6];
                newStudent.semester1[j] = semester1Course;

                Course semester2Course;
                semester2Course.name = courses[j + 5].name;
                semester2Course.credits = courses[j + 5].credits;
                semester2Course.grade = grades[rand() % 6];
                newStudent.semester2[j] = semester2Course;
            }

            students.push_back(newStudent);
        }
        
        cout << "Students populated successfully!\n" << endl;
    
}

void generateTranscript(Student student){
	cout << "Student ID: " << student.id << endl;
        cout << "Name: " << student.name << endl;
        cout << "Department: " << student.department << endl;
        cout << "Level: " << student.level << endl;
        cout << endl;
        
        cout << "  1st Semester Courses:" << endl;
        cout << "\tCourse\t\t\tUnits\t\tGrade" << endl;
        int fistSemesterCreadits = 0;
        int secondSemesterCreadits = 0;
        for (int j = 0; j < 5; j++) {
            cout << "\t" << student.semester1[j].name << "\t\t" << student.semester1[j].credits << "\t\t" << student.semester1[j].grade << endl;
            fistSemesterCreadits += student.semester1[j].credits;
        }
        cout << "\t\tTotal Credits: " << fistSemesterCreadits << endl;
        // Print semester 1 grades
    int as1 = 0, bs1 = 0, cs1 = 0, ds1 = 0, es1 = 0, fs1 = 0;
    for (int i = 0; i < 5; i++) {
        switch (student.semester1[i].grade) {
            case 'A':
                as1++;
                break;
            case 'B':
                bs1++;
                break;
            case 'C':
                cs1++;
                break;
            case 'D':
                ds1++;
                break;
            case 'E':
                es1++;
                break;
            case 'F':
                fs1++;
                break;
        }
    }
    cout << "1st Semester Grades Count: ";
    cout <<  as1 << " A's, ";
    cout <<  bs1 << " B's, ";
    cout << cs1 << " C's, ";
    cout << ds1 << " D's, ";
    cout << es1 << " E's, and ";
    cout << fs1 << " F's.";
        cout << endl;

        cout << "\n  2nd Semester Courses:" << endl;
        cout << "\tCourse\t\t\tUnits\t\tGrade" << endl;
        for (int j = 0; j < 5; j++) {
            cout << "\t" << student.semester2[j].name << "\t\t" << student.semester2[j].credits << "\t\t" << student.semester2[j].grade << endl;
            secondSemesterCreadits += student.semester2[j].credits;
        }
        cout << "\t\tTotal Units: " << secondSemesterCreadits << endl;
        // Print semester 2 grades
	    int as2 = 0, bs2 = 0, cs2 = 0, ds2 = 0, es2 = 0, fs2 = 0;
	    for (int i = 0; i < 5; i++) {
	        switch (student.semester2[i].grade) {
	            case 'A':
	                as2++;
	                break;
	            case 'B':
	                bs2++;
	                break;
	            case 'C':
	                cs2++;
	                break;
	            case 'D':
	                ds2++;
	                break;
	            case 'E':
	                es2++;
	                break;
	            case 'F':
	                fs2++;
	                break;
	        }
	    }
	    cout << "2nd Semester Grades Count: ";
	    cout <<  as2 << " A's, ";
	    cout <<  bs2 << " B's, ";
	    cout << cs2 << " C's, ";
	    cout << ds2 << " D's, ";
	    cout << es2 << " E's, and ";
	    cout << fs2 << " F's.";
        cout << endl;
        
        double totalGradePoints = 0.0;
    int totalCredits = 0;

    // Calculate grade points for 1st semester
    for (int j = 0; j < 5; j++) {
        char grade = student.semester1[j].grade;
        int credits = student.semester1[j].credits;

        double gradePoint = getGradePoint(grade);

        totalGradePoints += gradePoint * credits;
        totalCredits += credits;
    }

    // Calculate grade points for 2nd semester
    for (int j = 0; j < 5; j++) {
        char grade = student.semester2[j].grade;
        int credits = student.semester2[j].credits;

        double gradePoint = getGradePoint(grade);

        totalGradePoints += gradePoint * credits;
        totalCredits += credits;
    }
    
    double cgpa = totalGradePoints / totalCredits;

    cout << "  CGPA: " << fixed << setprecision(2) << cgpa << endl;
    cout << "  Credits: " << totalCredits << endl;
    cout << "  Grade Ponts: " << totalGradePoints << endl;
    cout << endl;
}

void getAllStudents(vector<Student> students) {
    cout << "You have the following students: \n";
    for (size_t i = 0; i < students.size(); ++i) {
        cout << i + 1 << ". " << students[i].id << " ";
    }
    cout << "\n\n";
}

void generateTranscriptFile(Student student, string filename) {
    ofstream file;
    
    file.open(filename.c_str());

    if (!file.is_open()) {
        cout << "Error: Unable to open file for writing." << endl;
        return;
    }

    file << "Student ID: " << student.id << endl;
    file << "Name: " << student.name << endl;
    file << "Department: " << student.department << endl;
    file << "Level: " << student.level << endl;
    file << endl;

    file << "  1st Semester Courses:" << endl;
    file << "\tCourse\t\t\tUnits\t\tGrade" << endl;
    int firstSemesterCredits = 0;
    int secondSemesterCredits = 0;
    for (int j = 0; j < 5; j++) {
        file << "\t" << student.semester1[j].name << "\t\t" << student.semester1[j].credits << "\t\t" << student.semester1[j].grade << endl;
        firstSemesterCredits += student.semester1[j].credits;
    }
    file << "\t\tTotal Credits: " << firstSemesterCredits << endl;

    // Print semester 1 grades
    int as1 = 0, bs1 = 0, cs1 = 0, ds1 = 0, es1 = 0, fs1 = 0;
    for (int i = 0; i < 5; i++) {
        switch (student.semester1[i].grade) {
            case 'A':
                as1++;
                break;
            case 'B':
                bs1++;
                break;
            case 'C':
                cs1++;
                break;
            case 'D':
                ds1++;
                break;
            case 'E':
                es1++;
                break;
            case 'F':
                fs1++;
                break;
        }
    }
    file << "1st Semester Grades Count: ";
    file << as1 << " A's, ";
    file << bs1 << " B's, ";
    file << cs1 << " C's, ";
    file << ds1 << " D's, ";
    file << es1 << " E's, and ";
    file << fs1 << " F's.";
    file << endl;

    file << "\n  2nd Semester Courses:" << endl;
    file << "\tCourse\t\t\tUnits\t\tGrade" << endl;
    for (int j = 0; j < 5; j++) {
        file << "\t" << student.semester2[j].name << "\t\t" << student.semester2[j].credits << "\t\t" << student.semester2[j].grade << endl;
        secondSemesterCredits += student.semester2[j].credits;
    }
    file << "\t\tTotal Units: " << secondSemesterCredits << endl;

    // Print semester 2 grades
    int as2 = 0, bs2 = 0, cs2 = 0, ds2 = 0, es2 = 0, fs2 = 0;
    for (int i = 0; i < 5; i++) {
        switch (student.semester2[i].grade) {
            case 'A':
                as2++;
                break;
            case 'B':
                bs2++;
                break;
            case 'C':
                cs2++;
                break;
            case 'D':
                ds2++;
                break;
            case 'E':
                es2++;
                break;
            case 'F':
                fs2++;
                break;
        }
    }
    file << "2nd Semester Grades Count: ";
    file << as2 << " A's, ";
    file << bs2 << " B's, ";
    file << cs2 << " C's, ";
    file << ds2 << " D's, ";
    file << es2 << " E's, and ";
    file << fs2 << " F's.";
    file << endl;

    double totalGradePoints = 0.0;
    int totalCredits = 0;

    // Calculate grade points for 1st semester
    for (int j = 0; j < 5; j++) {
        char grade = student.semester1[j].grade;
        int credits = student.semester1[j].credits;

        double gradePoint = getGradePoint(grade);

        totalGradePoints += gradePoint * credits;
        totalCredits += credits;
    }

    // Calculate grade points for 2nd semester
    for (int j = 0; j < 5; j++) {
        char grade = student.semester2[j].grade;
        int credits = student.semester2[j].credits;
        
        double gradePoint = getGradePoint(grade);

        totalGradePoints += gradePoint * credits;
        totalCredits += credits;
    }

    double cgpa = totalGradePoints / totalCredits;

    file << "  CGPA: " << fixed << setprecision(2) << cgpa << endl;
    file << "  Credits: " << totalCredits << endl;
    file << "  Grade Points: " << totalGradePoints << endl;
    file << endl;

    file.close();
}

void addStudentManually(vector<Student>& students, Course courses[]) {
    cout << "Enter student ID: ";
    string id;
    cin >> id;

    cout << "Enter student name: ";
    string cname;
    cin >> cname;

    cout << "Enter student department: ";
    string department;
    cin >> department;

    cout << "Enter student level: ";
    string level;
    cin >> level;

    Student newStudent(id, cname, department, level); // create a new Student object with the required arguments

    // Assign grades for each course
    for (int j = 0; j < 5; j++) {
        cout << "Enter grade for " << courses[j].name << ": ";
        char grade;
        cin >> grade;

        Course semester1Course;
        semester1Course.name = courses[j].name;
        semester1Course.credits = courses[j].credits;
        semester1Course.grade = grade;
        newStudent.semester1[j] = semester1Course;

        cout << "Enter grade for " << courses[j + 5].name << ": ";
        cin >> grade;

        Course semester2Course;
        semester2Course.name = courses[j + 5].name;
        semester2Course.credits = courses[j + 5].credits;
        semester2Course.grade = grade;
        newStudent.semester2[j] = semester2Course;
    }

    students.push_back(newStudent); // add the new Student object to the vector
    cout << "Student added successfully!" << endl;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	Course courses[] = {
    	{"Math 101", 3},
    	{"English 101", 2},
    	{"Computer 101", 4},
    	{"History 101", 1},
    	{"Biology 101", 4},
    	{"Math 102", 3},
    	{"English 102", 3},
    	{"Computer 102", 2},
    	{"History 102", 3},
    	{"Biology 102", 4}
	};
	
	Student demoStudents[] = {
        {"S001", "John Doe", "Computer Science", "200"},
        {"S002", "Jane Smith", "Mathematics", "200"},
        {"S003", "Bob Johnson", "Electrical Engineering", "400"},
        {"S004", "Alice Brown", "Computer Science","100"},
        {"S005", "Mike Davis", "Mechanical Engineering", "300"},
        {"S006", "Emily Chen", "Civil Engineering", "200"},
        {"S007", "David Lee", "Computer Science", "400"},
        {"S008", "Sophia Patel", "Mathematics", "100"},
        {"S009", "Oliver Kim", "Electrical Engineering", "300"},
        {"S010", "Isabella Hall", "Computer Science", "200"}
    };
	
    vector<Student> students;
    
    while (true) {
    	int studentCount = students.size();
    	
        cout << "What do you want to do?" << endl;
        if (studentCount ==0) 
        	cout << "You have 0 students in the database, PLease add or populate with demo!\n";
        cout << "1. Add a student" << endl;
        cout << "2. Populate student array" << endl;
        cout << "3. Generate student Transcript" << endl;
        cout << "4. View all students" << endl;
        cout << "5. Exit" << endl;
        cout << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                addStudentManually(students, courses);
                break;
            case 2:
                populateStudents(students, demoStudents, courses);
                break;
            case 3:
                if (studentCount > 0) {
                    cout << "Enter the student number (1-" << studentCount << "): ";
                    int studentNumber;
                    cin >> studentNumber;
                    if (studentNumber >= 1 && studentNumber <= studentCount) {
                        generateTranscript(students[studentNumber - 1]);
                        
                        Student student = students[studentNumber - 1];
                        string filename;
                        time_t now = time(0);
						tm* ltm = localtime(&now);
						stringstream ss;
						ss << "Transcript_" << student.id << "_" << student.level << "_"<< 1900 + ltm->tm_year << "_" << 1 + ltm->tm_mon << "_" << ltm->tm_mday <<".txt";
						filename = ss.str();
						generateTranscriptFile(student, filename);
						cout << filename;
                        cout << "\nA transcript has been generated. Would you like to open it? (y/n): ";
					    char response;
					    cin >> response;
					    
					    if (response == 'y' || response == 'Y') {
					        // Open the generated text file
					        #ifdef _WIN32
					            system(("start " + filename).c_str());
					        #elif __APPLE__
					            system(("open " + filename).c_str());
					        #elif __linux__
					            system(("xdg-open " + filename).c_str());
					        #endif
					    } else {
					        cout << "Transcript saved to file. You can open it manually later.\n" << endl;
					    }
                    } else {
                        cout << "Invalid student number.\n" << endl;
                    }
                } else {
                    cout << "No students added yet.\n" << endl;
                }
                break;
            case 4: 
            	if (studentCount == 0) {
            		cout << "No students in the database\n\n";
            		break;
            	}
            	getAllStudents(students);
            	break;
            case 5: 
            	return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}


