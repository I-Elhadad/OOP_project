# University Management System

The University Management System is a C++ console application designed to manage university-related data, including departments, professors, students, and courses.

## Table of Contents

- [Features](#features)
- [Getting Started](#getting-started)
- [Usage](#usage)
- [Class Overview](#class-overview)
- [Contributing](#contributing)
- [License](#license)

## Features

- Manage departments with information such as name, capacity, and required GPA.
- Add, remove, and update professors' data, including name, age, gender, salary, and degree.
- Track students' records with details like name, age, gender, level, and GPA.
- Create, delete, and update courses, including course name, code, hours, prerequisites, and professor.
- Store and retrieve university data using an efficient data structure.

## Getting Started

1. Clone this repository to your local machine:

   ```bash
   git clone https://g...content-available-to-author-only...b.com/Ameensakr/University-Management-System.git
Compile the C++ source code using your preferred C++ compiler (e.g., g++):
g++ main.cpp -o university_management
Run the compiled executable:
./university_management
Usage
Upon running the program, you will have access to various options for managing departments, professors, students, and courses.
Follow the on-screen instructions to add, remove, or update data in the system.
You can also use the provided sample data as a starting point for testing the program.
Class Overview
Department: Represents a university department with attributes such as name, capacity, and required GPA.
Person: Base class for Student and Professor classes, containing common attributes like name, ID, age, and gender.
Student: Derived class from Person, representing a student with additional attributes like level and GPA.
Professor: Derived class from Person, representing a professor with attributes like salary, degree, and department.
Course: Represents a university course with attributes like name, code, hours, prerequisites, students, and a professor.
University: Manages the university data, including vectors of students, professors, courses, and departments. Provides methods for adding, removing, and updating data.
Contributing
If you'd like to contribute to this project, please follow these steps:

Fork the repository on GitHub.
Clone your forked repository to your local machine.
Create a new branch for your changes: git checkout -b feature/new-feature.
Make your changes and commit them: git commit -m "Add new feature".
Push your changes to your fork: git push origin feature/new-feature.
Create a pull request on the original repository.
License
This project is licensed under the MIT License - see the LICENSE file for details.
Please make sure to replace "your-username" with your actual GitHub username and customize the content as needed to accurately represent your project.
﻿

