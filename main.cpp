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
#include <direct.h>
#include <ctime>

#include <unistd.h>
using namespace std;


struct Course {
    string name;
    string title;
    int credits;
    double mark;
    char grade;
};

struct studentID {
    string id;
};

class Student {
public:
    string id;
    string name;
    string department;
    string level;
    string session;
    string sex;
    string state;
    string nationality;

    Course semester1[13]; // array of 5 courses for 1st semester
    Course semester2[13]; // array of 5 courses for 2nd semester

    // constructor to initialize the Student object
    Student(string i, string n, string d, string l, string m, string k, string p, string h) : id(i), name(n), department(d), level(l), session(m), sex(k), state(p), nationality(h) {}

    // add more member functions as needed (e.g., getters, setters, etc.)
};

char assignGrade(int score) {
  if (score >= 70) {
    return 'A';
  } else if (score >= 60) {
    return 'B';
  } else if (score >= 50) {
    return 'C';
  } else if (score >= 40) {
    return 'D';
  } else if (score >= 35) {
    return 'E';
  } else {
    return 'F'; 
  }
}

double getGradePoint(char grade) {
	double gradePoint;
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
            	break;
            case 'F':
                gradePoint = 0.0;
                break;
        }
        
        return gradePoint;
}

void populateStudents(vector<Student>& students, Student demoStudents[], Course courses[], int numberOfStudents) {
    int arraySize = numberOfStudents;
    srand(static_cast<unsigned int>(time(0)));
    cout << "Adding " << arraySize << " to database... \n";
    
    usleep(900000);

    for (int i = 0; i < arraySize; i++) {
        Student newStudent = demoStudents[i];
        

        // Assign predefined courses to each student
        for (int j = 0; j < 13; j++) {
            int mark1 = rand() % (75 - 35 + 1) + 35;
            Course semester1Course;
            semester1Course.name = courses[j].name;
            semester1Course.title = courses[j].title;
            semester1Course.credits = courses[j].credits;
            semester1Course.mark = mark1;
            semester1Course.grade = assignGrade(mark1);
            newStudent.semester1[j] = semester1Course;
            
            int mark2 = rand() % (75 - 35 + 1) + 35;
            Course semester2Course;
            semester2Course.name = courses[j + 13].name;
			semester2Course.title = courses[j + 13].title;
            semester2Course.credits = courses[j + 13].credits;
            semester2Course.mark = mark2;
            semester2Course.grade = assignGrade(mark2);
            newStudent.semester2[j] = semester2Course;
        }

        students.push_back(newStudent);
    }
    
    cout << "Students populated successfully!\n" << endl;
}

void generateTranscript(Student student){
		cout << "\n\t\t\t\t     UNIVERSITY OF MAIDUGURI \n\t\t\t\t    (FACULTY OF ENGINEERING) \n\t\t\t\tDEPARTMENT OF COMPUTER ENGINEERING\n";
        cout << "\nName: " << student.name << "\t\t\t\t\t\t\tSex: " << student.sex << endl;
		cout << "Student ID: " << student.id << "\t\t\t\t\t\tState: "<< student.state << endl;
        cout << "Session: " << student.session << "\t\t\t\t\t\t\tNationality: " << student.nationality << endl;
        cout << endl;
        
        cout << "  Part 2: 1st Semester:" << endl;
        cout << "Course Code\tCourse Title\t\t\t  Score\tUnits\tGrade\t(GP)\t(U.GP)\tRemark" << endl;
        int firstSemesterCredits = 0;
        int secondSemesterCredits = 0;
        
    	double ugp1;
    	int ugp2;
        for (int j = 0; j < 13; j++) {
	        int units = student.semester1[j].credits;
	        
        	double gradePoint = getGradePoint(student.semester1[j].grade);
	
	        ugp1 += (gradePoint * units);
	        
        	string remark;
        	if (gradePoint < 1) {
        		remark = "Fail";
			}else {
				remark = "Pass";
			}
            cout << setw(10) << left << student.semester1[j].name << setw(40) << left << student.semester1[j].title << " " <<  student.semester1[j].mark << "\t "<< student.semester1[j].credits << "\t " << student.semester1[j].grade << "\t " << gradePoint << "\t " << gradePoint * (student.semester1[j].credits) << "\t " << remark << endl;
            firstSemesterCredits += student.semester1[j].credits;
        }
        cout <<"\t  Total: " << "\t\t\t\t\t" << firstSemesterCredits << "\t\t\t " << ugp1 << ".00" << endl;
        // Print semester 1 grades
    int as1 = 0, bs1 = 0, cs1 = 0, ds1 = 0, es1 = 0, fs1 = 0;
    for (int i = 0; i < 13; i++) {
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

        cout << endl;

        cout << "Part 2: 2nd Semester:" << endl;
        cout << "Course Code\tCourse Title\t\t\t  Score\tUnits\tGrade\t(GP)\t(U.GP)\tRemark" << endl;
        for (int j = 0; j < 13; j++) {
        	double gradePoint = getGradePoint(student.semester2[j].grade);
        	int units = student.semester2[j].credits;
	
	        ugp2 += (gradePoint * units);
	        
        	string remark;
        	if (gradePoint < 1) {
        		remark = "Fail";
			}else {
				remark = "Pass";
			}
            cout << setw(10) << left << student.semester2[j].name << setw(40) << left << student.semester2[j].title << " "<< student.semester2[j].mark << "\t " << student.semester2[j].credits << "\t " << student.semester2[j].grade << "\t " << gradePoint << "\t " << gradePoint * (student.semester2[j].credits) << "\t " << remark << endl;
            secondSemesterCredits += student.semester2[j].credits;
        }
        cout <<"\t  Total: " << "\t\t\t\t\t" << secondSemesterCredits << "\t\t\t " << ugp2 << ".00" << endl;
        // Print semester 2 grades
	    int as2 = 0, bs2 = 0, cs2 = 0, ds2 = 0, es2 = 0, fs2 = 0;
	    for (int i = 0; i < 13; i++) {
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
        cout << endl;
       
    double totalCredits = firstSemesterCredits + secondSemesterCredits;
    double totalGradePoints = ugp1 + ugp2;
    double cgpa = totalGradePoints / totalCredits;
	
	cout << " SUMMARY OF RESULT:\n";
    cout << "  Cummulative Units: \t\t\t" << totalCredits << endl;
    cout << "  Cummulative Product: \t\t\t" << totalGradePoints << endl;
    cout << "  Cummulative Grade Point Average: \t" << fixed << setprecision(2) << cgpa << endl;
    cout << endl;
    
    cout << " Grades Count:\n";
    cout << "   Semester\tA's\tB's\tC's\tD's\tE's\tF's\n";
    cout << "   First:\t " << as1 << "\t " << bs1 << "\t " << cs1 << "\t " << ds1 << "\t " << es1 << "\t " << fs1 << endl;
    cout << "   Second:\t " << as2 << "\t " << bs2 << "\t " << cs2 << "\t " << ds2 << "\t " << es2 << "\t " << fs2 << endl;
    cout << endl;
}

void getAllStudents(vector<Student> students) {
    cout << "You have the following students: \n";
    int columns = 5;
    int rows = (students.size() + columns - 1) / columns; // Calculate the number of rows needed

    int count = 1; // Initialize a counter to number the students
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            int index = i * columns + j;
            if (index < students.size()) {
                cout << setw(3) << count << ". " << setw(10) << students[index].id << " ";
                count++; // Increment the counter
            } else {
                cout << setw(15) << " "; // Print a blank space if there's no student
            }
        }
        cout << "\n";
    }
    cout << "\n";
}

void generateTranscriptFile(Student student, string filename) {
    ofstream file;
    
    file.open(filename.c_str());

    if (!file.is_open()) {
    	cout << "Error opening file for writing: " << strerror(errno) << endl;
    	return;
	}
    	file << "\n\t\t\t\t     UNIVERSITY OF MAIDUGURI \n\t\t\t\t    (FACULTY OF ENGINEERING) \n\t\t\t\tDEPARTMENT OF COMPUTER ENGINEERING\n";
        file << "\nName: " << student.name << "\t\t\t\t\t\t\tSex: " << student.sex << endl;
		file << "Student ID: " << student.id << "\t\t\t\t\t\tState: "<< student.state << endl;
        file << "Session: " << student.session << "\t\t\t\t\t\t\tNationality: " << student.nationality << endl;
        file << endl;
        
        file << "Part 2: 1st Semester:" << endl;
        file << "Course Code\tCourse Title\t\t\t  Score\tUnits\tGrade\t(GP)\t(U.GP)\tRemark" << endl;
        int firstSemesterCredits = 0;
        int secondSemesterCredits = 0;
        
    	double ugp1;
    	int ugp2;
        for (int j = 0; j < 13; j++) {
	        int units = student.semester1[j].credits;
	        
        	double gradePoint = getGradePoint(student.semester1[j].grade);
	
	        ugp1 += (gradePoint * units);
	        
        	string remark;
        	if (gradePoint < 1) {
        		remark = "Fail";
			}else {
				remark = "Pass";
			}
            file << setw(10) << left << student.semester1[j].name << setw(40) << left << student.semester1[j].title << " " << student.semester1[j].mark << "\t "<< student.semester1[j].credits << "\t " << student.semester1[j].grade << "\t " << gradePoint << ".00\t " << gradePoint * (student.semester1[j].credits) << ".00\t " << remark << endl;
            firstSemesterCredits += student.semester1[j].credits;
        }
        file <<"\t  Total: " << "\t\t\t\t\t" << firstSemesterCredits << "\t\t\t " << ugp1 << ".00" << endl;
        // Print semester 1 grades
    int as1 = 0, bs1 = 0, cs1 = 0, ds1 = 0, es1 = 0, fs1 = 0;
    for (int i = 0; i < 13; i++) {
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

        file << endl;

        file << "Part 2: 2nd Semester::" << endl;
        file << "Course Code\tCourse Title\t\t\t  Score\tUnits\tGrade\t(GP)\t(U.GP)\tRemark" << endl;
        for (int j = 0; j < 13; j++) {
        	double gradePoint = getGradePoint(student.semester2[j].grade);
        	int units = student.semester2[j].credits;
	
	        ugp2 += (gradePoint * units);
	        
        	string remark;
        	if (gradePoint < 1) {
        		remark = "Fail";
			}else {
				remark = "Pass";
			}
            file << setw(10) << left << student.semester2[j].name << setw(40) << left << student.semester2[j].title << " "<< student.semester2[j].mark << "\t " << student.semester2[j].credits << "\t " << student.semester2[j].grade << "\t " << gradePoint << ".00\t " << gradePoint * (student.semester2[j].credits) << ".00\t " << remark << endl;
            secondSemesterCredits += student.semester2[j].credits;
        }
        file <<"\t  Total: " << "\t\t\t\t\t" << secondSemesterCredits << "\t\t\t " << ugp2 << ".00" << endl;
        // Print semester 2 grades
	    int as2 = 0, bs2 = 0, cs2 = 0, ds2 = 0, es2 = 0, fs2 = 0;
	    for (int i = 0; i < 13; i++) {
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
        file << endl;
       
    double totalCredits = firstSemesterCredits + secondSemesterCredits;
    double totalGradePoints = ugp1 + ugp2;
    double cgpa = totalGradePoints / totalCredits;
	
	file << " SUMMARY OF RESULT:\n";
    file << "  Cummulative Units: \t\t\t" << totalCredits << endl;
    file << "  Cummulative Product: \t\t\t" << totalGradePoints << endl;
    file << "  Cummulative Grade Point Average: \t" << fixed << setprecision(2) << cgpa << endl;
    file << endl;
    
    file << " Grades Count:\n";
    file << "   Semester\tA's\tB's\tC's\tD's\tE's\tF's\n";
    file << "   First:\t " << as1 << "\t " << bs1 << "\t " << cs1 << "\t " << ds1 << "\t " << es1 << "\t " << fs1 << endl;
    file << "   Second:\t " << as2 << "\t " << bs2 << "\t " << cs2 << "\t " << ds2 << "\t " << es2 << "\t " << fs2 << endl;
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
    
     cout << "Enter student sex: ";
    string sex;
    cin >> sex;

    cout << "Enter school session: ";
    string session;
    cin >> session;

    cout << "Enter student state of origin: ";
    string state;
    cin >> state;

    cout << "Enter student nationality: ";
    string nationality;
    cin >> nationality;

    Student newStudent(id, cname, department, level, session, sex, state, nationality); // create a new Student object with the required arguments

    // Assign grades for each course
    for (int j = 0; j < 13; j++) {
        cout << "Enter score for " << courses[j].name << ": ";
        int score;
        cin >> score;

        Course semester1Course;
        semester1Course.name = courses[j].name;
        semester1Course.title = courses[j].title;
        semester1Course.credits = courses[j].credits;
        semester1Course.mark = score;
        semester1Course.grade = assignGrade(score);
        newStudent.semester1[j] = semester1Course;

        cout << "Enter score for " << courses[j + 13].name << ": ";
        cin >> score;

        Course semester2Course;
        semester2Course.name = courses[j + 13].name;
		semester2Course.title = courses[j].title;
        semester2Course.credits = courses[j + 13].credits;
        semester2Course.mark = score;
        semester2Course.grade = assignGrade(score);
        newStudent.semester2[j] = semester2Course;
    }

    students.push_back(newStudent); // add the new Student object to the vector
    cout << "Student added successfully!" << endl;
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	
	Course courses[] = {
    	{"CPE 201", "Introduction to Computer Engineering", 2},
    	{"CPE 203", "Computer Programming I", 2},
    	{"CPE 205", "Computer Programming I Laboratory", 1},
    	{"EEE 201", "Basic Electrical Engineering II", 2},
    	{"MEE 201", "Engineering Drawing II", 1},
    	{"MEE 203", "Workshop Practice I", 1},
    	{"MEE 205", "Engineering Mechanics I", 2},
    	{"MEE 207", "Materials Science", 2},
    	{"MTH 211", "Mathematical Methods I", 3},
    	{"STT 206", "Basic Statistics I", 3},
    	{"GST 221", "History and Philosophy of Science", 2},
    	{"GST 211", "Communication in English", 2},
    	{"GST 231", "Introductory to Entrepreneurial Skills", 2},
    	{"EEE 202", "Sc. of Elect. and Elect. Eng. Materials", 2},
    	{"CWE 206", "Strength of Materials 1", 3},
    	{"MEE 202", "Engineering Drawing III", 1},
    	{"MEE 206", "Engineering Mechanics II", 2},
    	{"MEE 208", "Thermodynamics 1", 2},
    	{"MEE 210", "Fluid Mechanics 1", 2},
    	{"CPE 202", "Algorithms and Data Structures", 2},
    	{"CPE 204", "Computer Programming II", 2},
    	{"CPE 206", "Computer Programming Laboratory II", 1},
    	{"MTH 212", "Mathematical Methods II", 3},
    	{"GST 212", "Philosophy and Human Existence", 2},
    	{"GST 224", "Peace Studies and Conflict Resolution", 2},
    	{"FEE 290", "In-House Industrial Training", 2}
	};
	
	Student demoStudents[] = {
        {"22/05/04/0020", "John Doe", "Computer Engineering", "200", "2023/2024", "Male", "Ogun", "Nigerian"},
        {"22/05/04/0096", "Jane Smith", "Computer Engineering", "200", "2023/2024", "Female", "Lagos", "Nigerian"},
        {"22/05/04/0193", "Bob Johnson", "Computer Engineering", "200", "2023/2024", "Male", "Oyo", "Nigerian"},
        {"22/05/04/0016", "Alice Brown", "Computer Engineering","200", "2023/2024", "Female", "Osun", "Nigerian"},
        {"22/05/04/0072", "Mike Davis", "Computer Engineering", "200", "2023/2024", "Male", "Ekiti", "Nigerian"},
        {"22/05/04/0074", "Emily Chen", "Computer Engineering", "200", "2023/2024", "Female", "Ondo", "Nigerian"},
        {"22/05/04/1080", "David Lee", "Computer Engineering", "200", "2023/2024", "Male", "Kwara", "Nigerian"},
        {"22/05/04/0003", "Sophia Patel", "Computer Engineering", "200", "2023/2024", "Female", "Niger", "Nigerian"},
        {"22/05/04/0021", "Oliver Kim", "Computer Engineering", "200", "2023/2024", "Male", "Abuja", "Nigerian"},
        {"22/05/04/0048", "Isabella Hall", "Computer Engineering", "200", "2023/2024", "Female", "Rivers", "Nigerian"}
    };
    
    cout << "Welcome to the Transcript Generator!" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Your go-to solution for professional results in seconds!\n" << endl;
	
    vector<Student> students;
    
    while (true) {
    	int studentCount = students.size();
    	
    	if (studentCount == 0) {
		    cout << "No students in the database. Please add entries or use demo data.\n" << endl;
		}
    	
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
                addStudentManually(students, courses);
                break;
            case 2:
            	int numberOfStudents;
            	cout << "Enter the number of students you want to add: ";
            	cin >> numberOfStudents;
                populateStudents(students, demoStudents, courses, numberOfStudents);
                break;
            case 3:
                if (studentCount > 0) {
                    cout << "Enter the student number (1-" << studentCount << "): ";
                    int studentNumber;
                    cin >> studentNumber;
                    if (studentNumber >= 1 && studentNumber <= studentCount) {
                    	int arraySize = 10;
						cout << "Generating... \n";
						
					    usleep(900000);
					    
                        generateTranscript(students[studentNumber - 1]);
                        
                        Student student = students[studentNumber - 1];
                        string filename;
                        
                        time_t now = time(0);
						tm* ltm = localtime(&now);
						stringstream ss;
						
						string str = student.id;
					    replace(str.begin(), str.end(), '/', '_');
//					    cout << str << endl;
						
						string outputDir = "Transcripts";
						
						// Create the directory if it doesn't exist
					    if (_mkdir(outputDir.c_str()) != 0) {
					        if (errno != EEXIST) {
					            std::cerr << "Unable to create directory." << std::endl;
					            return 1;
					        }
					    }
						
						ss << "Transcript_" << str << "_" << student.level << "l_"<< 1900 + ltm->tm_year <<".txt";
						filename = ss.str();
						
						string filePath = outputDir + "/" + filename;
						
						cout << endl;
						generateTranscriptFile(student, filePath);
                        cout << "\nA transcript has been generated with filename: " << filename << ". Would you like to open it? (y/n): ";
					    char response;
					    cin >> response;
					    
					    if (response == 'y' || response == 'Y') {
					        // Open the generated text file
					        #ifdef _WIN32
					            system(("start " + filePath).c_str());
					        #elif __APPLE__
					            system(("open " + filePath).c_str());
					        #elif __linux__
					            system(("xdg-open " + filePath).c_str());
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
    			cout << "Thank you for using the Transcript Generator. We hope it enhances your academic experience!" << endl;
            	return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}


