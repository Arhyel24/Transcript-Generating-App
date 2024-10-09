# Transcript Generating App

## Overview

The Transcript Generating App is a C++ program designed to generate a transcript for students in a two-semester session. Developed by a team of six students, including John Doe, Jane Smith, Bob Johnson, and Alice Brown, it serves as a group project for the CPE 206 course at the University of Maiduguri (Unimaid).

## Problem Addressed

This application addresses the need for an efficient and accurate system to generate transcripts for students. It eliminates the manual processes involved in calculating grades, CGPA, and generating transcripts, which can be time-consuming and error-prone. The app features a user-friendly interface for inputting student and course information, calculates grades and CGPA, and generates comprehensive transcripts.

## Libraries Used

The Transcript Generating App utilizes the following C++ libraries:

- **iostream**: Provides input/output (I/O) functionality for user interaction.
- **fstream**: Facilitates file input/output (I/O) operations.
- **string**: Offers a class for convenient string manipulation.
- **cmath**: Contains mathematical functions for calculations like absolute value and trigonometric functions.

## Project Workflow

The project workflow involved several key stages:

1. **Requirements Gathering**: Clarified project specifications and requirements.
2. **Design**: Created the program architecture, including data structures and algorithms.
3. **Implementation**: Developed the program in C++ based on the designed architecture.
4. **Testing**: Conducted thorough testing to ensure functionality and eliminate errors.
5. **Debugging**: Fixed issues that arose during testing.
6. **Deployment**: Deployed the program and generated a sample transcript to demonstrate functionality.

## Program Functionality

The Transcript Generating App performs the following functions:

- **Student Information Input**: Prompts the user for student ID, name, department, and level.
- **Course Information Input**: Prompts for course code, name, credit unit, and grade for each semester.
- **Grade Calculation**: Calculates the number of grades (A, B, etc.) in each semester.
- **CGPA Calculation**: Computes the CGPA for the session using the formula: `CGPA = (Total Grade Points / Total Credit Units)`.
- **Transcript Generation**: Creates a comprehensive transcript including student information, course details, grades, and CGPA, both displayed on the console and saved in a text file.
- **Open Text File Option**: Provides an option to open the generated text file.

## Program Output

The generated transcript follows this format:
```Transcript for [Student Name] - [Student ID] - [Department] Level [Level]```
```Session: 2022/2023```

```Semester 1:```
```[Course Code] - [Course Name] - [Credit Unit] - [Grade]```
...

```Semester 2:```
```[Course Code] - [Course Name] - [Credit Unit] - [Grade]```
...

```CGPA: [CGPA]```


## Algorithm

1. **Student Information Input**
   - Create a `Student` object to store information.
   - Prompt for ID, name, department, and level.
   - Validate input data.

2. **Course Information Input**
   - Create a `Course` object for course details.
   - Prompt for course code, name, credit unit, and grade.
   - Validate input data and store it in a `std::vector<Course>`.

3. **Semester Information Input**
   - Create a `Semester` object.
   - Calculate grades using a `std::map<char, int>`.
   - Store semester information in a `std::vector<Semester>`.

4. **Transcript Generation**
   - Create a `Transcript` object.
   - Generate the transcript header and body.
   - Calculate overall CGPA.
   - Store transcript information in a `std::string`.

5. **Transcript Output**
   - Display the transcript on the console using `std::cout`.
   - Write to a file using `std::ofstream`.
   - Provide an option to open the generated text file.

## Conclusion

The Transcript Generating App is a comprehensive tool that effectively generates transcripts for students. Its user-friendly interface, accurate calculations, and detailed output make it a valuable resource for educational institutions. The collaborative effort of the team has resulted in a high-quality program that meets and exceeds expectations.
