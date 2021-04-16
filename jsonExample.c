#include <iostream>
#include <string.h>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

int main()
{
    // jdEmployees
    json jdEmployees =
    {
        {"firstName","Sean"},
        {"lastName","Brown"},
        {"StudentID",21453},
        {"Department","Computer Sc."}
    };

    // Access the values
    string fName = jdEmployees.value("firstName", "oops");
    string lName = jdEmployees.value("lastName", "oops");
    int sID = jdEmployees.value("StudentID", 0);
    string dept = jdEmployees.value("Department", "oops");
   
    // Print the values
    cout << "First Name: " << fName << endl;
    cout << "Last Name: " << lName << endl;
    cout << "Student ID: " << sID << endl;
    cout << "Department: " << dept << endl;

    cout << jdEmployees.dump() << endl;
    string jsonString = jdEmployees.dump();
    json parsedJson = json::parse(jsonString);

    cout << "First Name: " << parsedJson.value("firstName", "oops") << endl;
    cout << "Last Name: " << parsedJson.value("lastName", "oops") << endl;
    cout << "Student ID: " << parsedJson.value("StudentID", 0) << endl;
    cout << "Department: " << parsedJson.value("Department", "oops") << endl;
          
    return 0;
}