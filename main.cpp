#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
#include <map>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <ctime>

using namespace std;


struct Course {
    char name[50];
    int credits;
    char grade;
};

struct Student {
	string id;
	string name;
	string department;
	string level;
	struct Course semester1[5]; // array of 5 courses for 1st semester
    struct Course semester2[5]; // array of 5 courses for 2nd semester
};

struct Course courses[] = {
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

void populateStudents(Student students[], int& studentCount, Student demoStudents[], int demoStudentCount) {
    if (studentCount + demoStudentCount <= 10) {
        for (int i = 0; i < demoStudentCount; i++) {
            students[studentCount-1] = demoStudents[i];

            // Assign predefined courses to each student
            for (int j = 0; j < 5; j++) {
                students[studentCount-1].semester1[j] = courses[j];
                students[studentCount-1].semester2[j] = courses[j + 5];

                // assign random grade for each course
                char grades[] = {'A', 'B', 'C', 'D', 'E', 'F'};
                students[studentCount-1].semester1[j].grade = grades[rand() % 6];
                students[studentCount-1].semester2[j].grade = grades[rand() % 6];
            }

            studentCount++;
        }
        cout << "Students populated successfully!\n" << endl;
    } else {
        cout << "Maximum number of students reached.\n" << endl;
    }
}


void generateTranscript(Student student){
	cout << "Student ID: " << student.id << endl;
        cout << "Name: " << student.name << endl;
        cout << "Department: " << student.department << endl;
        cout << "Level: " << student.level << endl;
        cout << endl;
        
        cout << "  1st Semester Courses:" << endl;
        cout << "\tCourse\t\t\tCredits\t\tGrade" << endl;
        int fistSemesterCreadits = 0;
        int secondSemesterCreadits = 0;
        for (int j = 0; j < 5; j++) {
            cout << "\t" << student.semester1[j].name << "\t\t" << student.semester1[j].credits << "\t\t" << student.semester1[j].grade << endl;
            fistSemesterCreadits += student.semester1[j].credits;
        }
        cout << "\t\t\tTotal Creadits" << endl;
        cout << "\t\t\t\t" << fistSemesterCreadits << endl;
        cout << endl;

        cout << "  2nd Semester Courses:" << endl;
        cout << "\tCourse\t\t\tCredits\t\tGrade" << endl;
        for (int j = 0; j < 5; j++) {
            cout << "\t" << student.semester2[j].name << "\t\t" << student.semester2[j].credits << "\t\t" << student.semester2[j].grade << endl;
            secondSemesterCreadits += student.semester2[j].credits;
        }
        cout << "\t\t\t\tTotal Creadits" << endl;
        cout << "\t\t\t\t" << secondSemesterCreadits << endl;
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

void getAllStudents(Student students[]) {
	cout << "You have the following students: \n";
	for (int i=0; i<10; i++) {
		cout << i + 1 << ". " << students[i].id << " ";
	}
	cout << "\n\n";
}

void addStudentManually(Student students[], int& studentCount, Course courses[]) {
    if (studentCount < 10) {
        cout << "Enter student ID: ";
        string id;
        cin >> id;
        students[studentCount].id = id;

        cout << "Enter student name: ";
        string name;
        cin >> name;
        students[studentCount].name = name;

        cout << "Enter student department: ";
        string department;
        cin >> department;
        students[studentCount].department = department;

        cout << "Enter student level: ";
        string level;
        cin >> level;
        students[studentCount].level = level;

        // Assign grades for each course
        for (int j = 0; j < 5; j++) {
            cout << "Enter grade for " << courses[j].name << ": ";
            char grade;
            cin >> grade;
            students[studentCount].semester1[j].name = courses[j].name;
            students[studentCount].semester1[j].credits = courses[j].credits;
            students[studentCount].semester1[j].grade = grade;

            cout << "Enter grade for " << courses[j + 5].name << ": ";
            cin >> grade;
            students[studentCount].semester2[j].name = courses[j + 5].name;
            students[studentCount].semester2[j].credits = courses[j + 5].credits;
            students[studentCount].semester2[j].grade = grade;
        }

        studentCount++;
        cout << "Student added successfully!" << endl;
    } else {
        cout << "Maximum number of students reached." << endl;
    }
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
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
	
    Student students[10];
    int studentCount = 1;
    
    while (true) {
        cout << "What do you want to do?" << endl;
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
                addStudentManually(students, studentCount, courses);
                break;
            case 2:
                populateStudents(students, studentCount, demoStudents, 6);
                break;
            case 3:
                if (studentCount > 0) {
                    cout << "Enter the student number (1-" << studentCount << "): ";
                    int studentNumber;
                    cin >> studentNumber;
                    if (studentNumber >= 1 && studentNumber <= studentCount) {
                        generateTranscript(students[studentNumber - 1]);
                    } else {
                        cout << "Invalid student number." << endl;
                    }
                } else {
                    cout << "No students added yet." << endl;
                }
                break;
            case 4: 
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


