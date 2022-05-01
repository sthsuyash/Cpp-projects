#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <typeinfo>
#include <windows.h>
using namespace std;

// the class that stores data
class Student
{
protected:
     int rollno;
     string name;
     int Maths, Statistics, Discrete_Structures, Microprocessor, OOP;
     double average;
     char grade[2];

public:
     void getdata(int);
     void showdata() const;
     double calculate_sum() const;
     void calculate();
     int retrollno() const;
}; // Student class ends here

double Student::calculate_sum() const
{
     return (Maths + Statistics + Discrete_Structures + Microprocessor + OOP);
}

void Student::calculate()
{
     average = calculate_sum() / 5.0;

     if (average >= 90)
          strcpy(grade, "A+");
     else if (average >= 80 && average < 90)
          strcpy(grade, "A");
     else if (average >= 70 && average < 80)
          strcpy(grade, "B+");
     else if (average >= 60 && average < 70)
          strcpy(grade, "B");
     else if (average >= 50 && average < 60)
          strcpy(grade, "C+");
     else if (average >= 40 && average < 50)
          strcpy(grade, "C");
     else if (average >= 30 && average < 40)
          strcpy(grade, "D+");
     else if (average >= 20 && average < 30)
          strcpy(grade, "D");
     else if (average >= 10 && average < 20)
          strcpy(grade, "E");
     else
          strcpy(grade, "F");
}

void Student::getdata(int rollno)
{
     this->rollno = rollno;
     cout << "Enter Student's name: ";
     cin.ignore();
     getline(cin, name);
     cout << "\nAll marks should be out of 100" << endl;
     cout << "Enter marks in Mathematics: ";
     cin >> Maths;
     cout << "Enter marks in Statistics: ";
     cin >> Statistics;
     cout << "Enter marks in Discrete Structures: ";
     cin >> Discrete_Structures;
     cout << "Enter marks in Microprocessor: ";
     cin >> Microprocessor;
     cout << "Enter marks in OOP: ";
     cin >> OOP;
     calculate();
     cout << endl
          << "------------------------------------------" << endl
          << endl;
}

void Student::showdata() const
{
     cout << endl
          << "------------------------------------------" << endl
          << endl;
     cout << "Student Details:" << endl;
     cout << "Roll number : " << rollno << endl
          << "Name : " << name << endl
          << endl;
     cout << "Marks in Subjects:" << endl;
     cout << "Mathematics : " << Maths << endl
          << "Statistics : " << Statistics << endl
          << "Discrete Structures : " << Discrete_Structures << endl
          << "Microprocessor : " << Microprocessor << endl
          << "OOP : " << OOP << endl;
     cout << left << setw(10) << "Total : ";
     printf("%.2lf", calculate_sum());
     cout << "\t" << setw(10);
     printf("Average Marks : %.2lf\n", average);
     cout << setw(10) << "Grade : " << grade << endl;
}

int Student::retrollno() const
{
     return rollno;
}

// function declaration1
void create_Student(int);
void display_sp(int);     // display particular record
void display_all();       // display all records
void delete_Student(int); // delete particular record
void change_Student(int); // edit particular record
int roll();
void goto_main();

// MAIN
int main()
{
     system("color 9");
     cout << setprecision(2);
     char choice;
     int num;
     system("cls");
     cout << "\t\t";
     for (size_t i = 0; i < 58; i++)
     {
          cout << "\xB2";
     }
     cout << "\n\t\t\xB2\xB2\t\t\t\t\t\t\t\xB2\xB2";
     cout << "\n\t\t\xB2\xB2\t\t\tMAIN MENU\t\t\t\xB2\xB2" << endl;
     cout << "\t\t\xB2\xB2\t\t\t\t\t\t\t\xB2\xB2\n";
     cout << "\t\t\xB2\xB2\t\t1. Create Student record\t\t\xB2\xB2" << endl;
     cout << "\t\t\xB2\xB2\t\t2. Search Student record\t\t\xB2\xB2" << endl;
     cout << "\t\t\xB2\xB2\t\t3. Display all Students records\t\t\xB2\xB2" << endl;
     cout << "\t\t\xB2\xB2\t\t4. Delete Student record\t\t\xB2\xB2" << endl;
     cout << "\t\t\xB2\xB2\t\t5. Modify Student record\t\t\xB2\xB2" << endl;
     cout << "\t\t\xB2\xB2\t\t6. Exit\t\t\t\t\t\xB2\xB2" << endl;
     cout << "\t\t\xB2\xB2\t\t\t\t\t\t\t\xB2\xB2" << endl;
     cout << "\t\t";
     for (size_t i = 0; i < 58; i++)
     {
          cout << "\xB2";
     }
     cout << endl;

     cout << "\n\t\tEnter your Choice (1/2/3/4/5/6) : ";
     cin >> choice;
     system("cls");

     switch (choice)
     {
     case '1':
          num = roll();
          create_Student(num);
          break;
     case '2':
          num = roll();
          display_sp(num);
          break;
     case '3':
          display_all();
          break;
     case '4':
          num = roll();
          delete_Student(num);
          break;
     case '5':
          num = roll();
          change_Student(num);
          break;
     case '6':
          cout << "Exiting, Thank you!";
          exit(0);
     default:
          cout << "\a\n\nPlease enter a valid option!!" << endl;
          goto_main();
     }
     return 0;
}

int roll()
{
     int roll;
     cout << "Enter Student's roll number: ";
     cin >> roll;
     return roll;
}

void goto_main()
{
     cout << "\nPress any Key to goto Main menu" << endl;
     cin.ignore();
     cin.get();
     system("cls");
     cout << "\nRedirecting to main menu . ";
     for (size_t i = 0; i < 5; i++)
     {
          Sleep(200);
          cout << ". ";
     }
     main();
}

// write Student details to file
void create_Student(int num)
{
     bool found = false;
     Student stud;
     ifstream file;
     file.open("Student.dat", ios::binary | ios::in);
     if (!file)
          goto create;
     while (!file.eof() && found == false)
     {
          file.read(reinterpret_cast<char *>(&stud), sizeof(Student));
          if (stud.retrollno() == num)
          {
               cout << "\aEntered roll number is already in the data. Please try again with another roll number!" << endl;
               found = true;
          }
     }
create:
     if (found == false)
     {
          ofstream file;
          file.open("Student.dat", ios::binary | ios::app);
          stud.getdata(num);
          file.write(reinterpret_cast<char *>(&stud), sizeof(Student));
          cout << "\nStudent record has been created successfully!" << endl;
     }
     file.close();
     goto_main();
}

// read file records
void display_all()
{
     Student stud;
     ifstream inFile;
     inFile.open("Student.dat", ios::binary);
     if (!inFile)
     {
          cout << "\aFile could not be opened !!";
          goto_main();
     }
     cout << "\n\n\n\tDISPLAYING ALL RECORDS\n\n";
     while (inFile.read(reinterpret_cast<char *>(&stud), sizeof(Student)))
     {
          stud.showdata();
     }
     cout << endl
          << "------------------------------------------" << endl
          << endl;
     inFile.close();
     goto_main();
}

// read specific record based on roll number
void display_sp(int n)
{
     Student stud;
     ifstream iFile;
     iFile.open("Student.dat", ios::binary);
     if (!iFile)
     {
          cout << "File could not be opened!!\n";
          goto_main();
          return;
     }
     bool flag = false;
     while (iFile.read(reinterpret_cast<char *>(&stud), sizeof(Student)))
     {
          if (stud.retrollno() == n)
          {
               stud.showdata();
               flag = true;
          }
     }
     iFile.close();
     if (flag == false)
     {
          cout << "\n\n\aRecord does not exist";
     }
     goto_main();
}

// modify record for specified roll number
void change_Student(int n)
{
     bool found = false;
     Student stud;
     fstream file;
     file.open("Student.dat", ios::binary | ios::in | ios::out);
     if (!file)
     {
          cout << "\aFile could not be opened.\n";
          goto_main();
     }
     while (!file.eof() && found == false)
     {
          file.read(reinterpret_cast<char *>(&stud), sizeof(Student));
          if (stud.retrollno() == n)
          {
               stud.showdata();
               cout << "\nEnter new Student details:" << endl;
               stud.getdata(n);
               int pos = (-1) * static_cast<int>(sizeof(stud));
               file.seekp(pos, ios::cur);
               file.write(reinterpret_cast<char *>(&stud), sizeof(Student));
               cout << "\n\nRecord Updated";
               found = true;
          }
     }
     file.close();
     if (found == false)
     {
          cout << "\n\n\aRecord Not Found ";
     }
     goto_main();
}

// delete record with particular roll number
void delete_Student(int n)
{
     Student stud;
     ifstream inputFile;
     inputFile.open("Student.dat", ios::binary);
     if (!inputFile)
     {
          cout << "\aFile could not be opened!!\nPress any Key to goto Main menu";
          cin.ignore();
          cin.get();
          goto_main();
          return;
     }
     ofstream outputFile;
     outputFile.open("Temp.dat", ios::out);
     inputFile.seekg(0, ios::beg);
     while (inputFile.read(reinterpret_cast<char *>(&stud), sizeof(Student)))
     {
          if (stud.retrollno() != n)
          {
               outputFile.write(reinterpret_cast<char *>(&stud), sizeof(Student));
          }
     }
     outputFile.close();
     inputFile.close();
     remove("Student.dat");
     rename("Temp.dat", "Student.dat");
     cout << "\n\nRecord Deleted .." << endl;
     goto_main();
}