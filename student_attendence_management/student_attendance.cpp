#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
       
using namespace std;

int studentLogin();
int adminLogin();
int adminView();
int registerStudent();
int listStudents();


////////////////////////////////////////////////////////////////////////////////
// Main Function
////////////////////////////////////////////////////////////////////////////////
int main()
{
    while(1)
    {
    
        // system("clear");
        cout << " Welcome to Student Attendance Management System! \n" << endl;
        cout << " ------------------------------------------------ \n" << endl;
    
        cout << " 1. Student Login " << endl;
        cout << " 2. Admin Login " << endl;
        cout << " 0. Exit " << endl;

        int choice;
        cout << " Please enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: studentLogin();
                    break;
            case 2: adminLogin();
                    break;
            case 0: exit(0);
                    break;
            default: cout << " Invalid choice !! " << endl;
            getchar();
        }
    }
    return 0;
}


///////////////////////////////////////////////////////////////////////////////
// Student Login Function
///////////////////////////////////////////////////////////////////////////////
int studentLogin()
{
    cout << " -------- Student Login -------- " << endl;
    string username, password;

    cout << " Enter username : ";
    cin >> username;
    cout << " Ener password : ";
    cin >> password;

    // int res = checkStudentCredentials(username, password);
    int res = 0;
    if(res == 0)
    {
        cout << " Username and password are not matched !! " << endl;
        cout << " Press any key back to Main Menu... " << endl;
        return 0;
    }

    return 0;
}


///////////////////////////////////////////////////////////////////////////////
// Admin Login Function
///////////////////////////////////////////////////////////////////////////////
int adminLogin()
{
    cout << " -------- Admin Login -------- " << endl;
    string username, password;

    cout << " Enter username : ";
    cin >> username;
    cout << " Ener password : ";
    cin >> password;

    if(username == "admin" && password == "Asdf123$")
    {
        cout << " Admin login successfully !" << endl;
        adminView();
    }
    else
    {
        cout << " Error! Invalid Credintials.." << endl;
        cout << " Press any key back to Main Menu.. " << endl;
        getchar();
        getchar();
    }

    return 0;
}


///////////////////////////////////////////////////////////////////////////////
// Admin View Function
///////////////////////////////////////////////////////////////////////////////
int adminView()
{
    int goBack = 0;
    while(1)
    {
        cout << " 1. Register a student " << endl;
        cout << " 2. List all students " << endl;
        cout << " 0. Back to Main Menu.. " << endl;

        int choice;
        cout << " Please enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1: registerStudent();
                    break;
            case 2: listStudents();
                    break;
            case 0: goBack = 1;
                    break;
            default: cout << "\n Invalid choice. Please enter again. " << endl;
            getchar();
        }

        if(goBack == 1)
        {
            break;
        }
    }

    return 0;
}


///////////////////////////////////////////////////////////////////////////////
// Register A Student
///////////////////////////////////////////////////////////////////////////////
int registerStudent()
{
    cout << "\n -------- Form to Register a student! -------- \n";

    string first_name, last_name, username, password, student_id;
    cout << "\n Enter First Name : ";
    cin >> first_name;
    cout << "\n Enter Last Name : ";
    cin >> last_name;
    cout << "\n Enter Username : ";
    cin >> username;
    cout << "\n Enter password : ";
    cin >> password;
    cout << "\n Enter Student Id : ";
    cin >> student_id;

    // generate a file to store the name of  all students' info files
    ofstream out;
    out.open("db.dat", ios::app);
    out << username << "\n";
    out.close();

    // generate a file to store the registered student's info
    ofstream out_temp;
    string file_name = username + ".dat";
    out_temp.open(file_name.c_str());
    out_temp << first_name << "\n";
    out_temp << last_name << "\n";
    out_temp << username << "\n";
    out_temp << password << "\n";
    out_temp << student_id << "\n";
    out_temp.close();

    cout << "\n Student Registered Successfully !!";
    cout << "\n Please any key to continue.. " << endl;

    return 0;
}


///////////////////////////////////////////////////////////////////////////////
// List all the students
///////////////////////////////////////////////////////////////////////////////
int listStudents()
{
    cout << " -------- List all the students! -------- " << endl;
   
    // check if record already exist...
    ifstream read;
    read.open("db.dat");
    
    if(read)
    {
       int recordFound = 0;
       string line;
       while(getline(read, line))
       {
           char name[100];
           strcpy(name, line.c_str());
           cout << "\n " << name << endl;
       }
    }
    // read.close();
    else
    {
        cout << "\n No Record found ! ";
    }
    read.close();
    cout << "\n Press any key to continue.. ";
    getchar();
    getchar();

    return 0;
}
