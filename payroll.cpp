#include<iostream>
#include<string>
#include<sstream>
#include<fstream>
using namespace std;
int NoOfEmployee = 0;
struct Employee
{
	char employeeID[4];
	char name[50];
	char address[100];
	char department[50];
	long int departmentID;
	int designation;
	int DaysWorked;
	int OffDays;
	int AdditionalOffDays;
	float basicPay;
	float dailySalary;
	float GrossPay;
	double tax;
	float UtilityAllowance;
	float HouseRentAllowance;
	float leaveWOP;
	float netPay;
	string designation_[20];
};
const int m_emp = 50;
Employee emp[m_emp];

int code = 1234;
void changeCode()
{
	int previousCode;
	cout << "Enter previous code: ";
	cin >> previousCode;
	if (previousCode == code)
	{
		cout << "Enter new code: ";
		cin >> code;
		cout << "Code updated successfully!";
	}
}
void designation()
{
	int des;
	cout << "1. Head of department\n2. Manager\n3. Officer\n";
	cout << "Enter the designation";
	cin >> des;
	switch (des)
	{
	case 1:
		emp[NoOfEmployee].designation = 1;
		emp[NoOfEmployee].basicPay = 375000;
		emp[NoOfEmployee].GrossPay;
		
		emp[NoOfEmployee].UtilityAllowance = emp[NoOfEmployee].basicPay * 10 / 100;
		emp[NoOfEmployee].HouseRentAllowance= emp[NoOfEmployee].basicPay * 20 / 100;
		emp[NoOfEmployee].GrossPay = emp[NoOfEmployee].basicPay + emp[NoOfEmployee].UtilityAllowance + emp[NoOfEmployee].HouseRentAllowance;
		
		break;
	case 2:
		emp[NoOfEmployee].designation = 2;
		emp[NoOfEmployee].basicPay = 120000;
		emp[NoOfEmployee].UtilityAllowance = emp[NoOfEmployee].basicPay * 10 / 100;
		emp[NoOfEmployee].HouseRentAllowance = emp[NoOfEmployee].basicPay * 20 / 100;
		emp[NoOfEmployee].GrossPay = emp[NoOfEmployee].basicPay + emp[NoOfEmployee].UtilityAllowance + emp[NoOfEmployee].HouseRentAllowance;
		break;
	case 3:
		emp[NoOfEmployee].designation = 1;
		emp[NoOfEmployee].basicPay = 70000;
		emp[NoOfEmployee].GrossPay;
		emp[NoOfEmployee].UtilityAllowance = emp[NoOfEmployee].basicPay * 10 / 100;
		emp[NoOfEmployee].HouseRentAllowance = emp[NoOfEmployee].basicPay * 20 / 100;
		emp[NoOfEmployee].GrossPay = emp[NoOfEmployee].basicPay + emp[NoOfEmployee].UtilityAllowance + emp[NoOfEmployee].HouseRentAllowance;
		break;
	default:
		cout << "Invalid response, try again:" << endl;
		designation();
	}
}
void OpenFile() {
	ifstream myfile("employee.txt");
	if (myfile.is_open()) {
		int i = 0;
		string line;
		while (getline(myfile, line)) {
			istringstream iss(line);
			string token;
			for (int j = 0; getline(iss, token, ',') && j < 4; ++j) {
				switch (j) {
						case 0:
							strcpy_s(emp[i].employeeID, token.c_str());
							break;
						case 1:
							strcpy_s(emp[i].name, token.c_str());
							break;
						case 2:
							strcpy_s(emp[i].department, token.c_str());
							break;
						case 3:
							strcpy_s(emp[i].address, token.c_str());
				}
			}
			++i;
			if (i >= m_emp) {
				break;
			}
		}
		myfile.close();
	}
	else {
		cout << "Unable to open file." << std::endl;
	}
}
void Insert()
{
	cout << "Enter the details of the employee: " << endl;
	cout << "ID: ";
	cin.ignore();
	cin.getline(emp[NoOfEmployee].employeeID, 4);
	cout << "Name: ";
	cin.getline(emp[NoOfEmployee].name, 50);
	cout << "Department: ";
	cin.getline (emp[NoOfEmployee].department,50);
	cout << "Designation: ";
	designation();
	cin.ignore();
	cout << "Address: ";
	cin.getline(emp[NoOfEmployee].address, 100);
	cout <<"Employee details added successfully!";

	NoOfEmployee++;
}
void Delete()
{
	string remove;
		int counter=0;
	int i, j;
	cout << "Enter employee ID of the employee you want to remove: ";
	cin.ignore();
	getline(cin,remove);
	for (i = 0; i <= NoOfEmployee; i++)
	{
		if (emp[i].employeeID == remove)
		{
			counter++;
			break;
		}
	}
	for (j = i + 1; j <= NoOfEmployee; j++, i++)
	{
		strcpy_s(emp[i].employeeID, emp[j].employeeID);
		strcpy_s(emp[i].name, emp[j].name);
		strcpy_s(emp[i].department , emp[j].department);
		strcpy_s(emp[i].address , emp[j].address);
		emp[i].DaysWorked = emp[j].DaysWorked;
		emp[i].AdditionalOffDays = emp[j].AdditionalOffDays;
		emp[i].leaveWOP = emp[j].leaveWOP;
		emp[i].OffDays = emp[j].OffDays;
		emp[i].designation = emp[j].designation;
		emp[i].basicPay = emp[j].basicPay;
		emp[i].dailySalary = emp[j].dailySalary;
		emp[i].GrossPay= emp[j].GrossPay;
		emp[i].netPay = emp[j].netPay;
		emp[i].tax = emp[j].tax;
		emp[i].UtilityAllowance = emp[j].UtilityAllowance;
		emp[i].HouseRentAllowance = emp[j].HouseRentAllowance;
	}
	NoOfEmployee--;
	cout << "Employee removed successfully!";
	if (counter==0)
	{
		cout << "No employee record found against the ID."<<endl;
	}
}
void display()
{
	
	int counter = 0;
	cout << "No. |  ID  |   NAME     | DEPARTMENT |     ADDRESS     | DESIGNATION |BASE SALARY|" << endl << "--------------------------------------------------------------------------------\n";
	
	for(int i = 0; i < m_emp&& emp[i].employeeID[0] != '\0'; ++i)
		
	{
		
		cout << "  " << counter + 1 << "    " << emp[i].employeeID << "       " << emp[i].name << "       " << emp[i].department << "            " << emp[i].address << "          " << emp[i].designation << "         " << emp[i].GrossPay << endl;
		counter++;
	}
	if (NoOfEmployee == 0)
	{
		cout << "No record found." << endl;
	}
}
void search()
{
	string find;
	int counter = 0;
	cout << "Enter employee ID to search: "<<endl;
	cin.ignore();
	getline(cin,find);
	for (int i = 0; i < NoOfEmployee; i++)
	{
		if (emp[i].employeeID == find)
		{
			cout << "No. |  ID  |    NAME     | DEPARTMENT |     ADDRESS     |DESIGNATION|BASE SALARY|" << endl << "--------------------------------------------------------------------------------\n";
			cout << "  " << counter + 1 << "    " << emp[i].employeeID << "         " << emp[i].name << "     " << emp[i].department << "            " << emp[i].address << "         " << emp[i].designation << "       " << emp[i].GrossPay << endl;
			counter++;
			break;
		}
	}
		if(counter==0)
		{
			cout << "No record found against the employee ID you entered." << endl;
		}
	
}
void edit()
{
	string find;
	int counter = 0;
	cout << "Enter employee ID to edit: " << endl;
	cin.ignore();
	getline(cin, find);
	for (int i = 0; i < NoOfEmployee; i++)
	{
		if (emp[i].employeeID == find)
		{
			counter++;
			cout << "Edit the employee record: " << endl;
			cout << "Name: ";
			cin.ignore();
			cin.getline(emp[i].name, 50);
			cout << "Department: ";
			cin.ignore();
			cin.getline(emp[i].department, 50);
			cout << "Designation: ";
			designation();
			cout << "Address: ";
			cin.ignore();
			cin.getline(emp[i].address, 100);
			cout << "Employee details added successfully!";
		}
		if (counter == 0)
		{
			cout << "No record found against the employee ID you entered." << endl;
		}
	}
}

int Attendance() {
	const int MaxDays = 31;
	int daysInMonth = 25;
	string ID;
	cout << "Enter the employee ID to mark attendance: ";
	cin >> ID;
	for (int i = 0; i < NoOfEmployee; i++) {
		if (emp[i].employeeID == ID) {
			int attendance[MaxDays] = { 0 };
			emp[i].DaysWorked = 0;
			if (daysInMonth <= 0 || daysInMonth > MaxDays) {
				cout << "Invalid number of working days." << endl;
				return 1;
			}
			for (int day = 1; day <= daysInMonth; ++day) {
				char attendanceStatus;
				cout << "Day " << day << ": Enter attendance status (P for present, A for absent): ";
				cin >> attendanceStatus;
				attendanceStatus = toupper(attendanceStatus);
				if (attendanceStatus == 'P') {
					attendance[day - 1] = 1;
					emp[i].DaysWorked++;
				}
				else if (attendanceStatus != 'A') {
					cout << "Invalid attendance status. Please enter 'P' for present or 'A' for absent." << endl;
					return 1;
				}
			}
			cout << "\nTotal days worked by " << emp[i].name << ": " << emp[i].DaysWorked << endl;
			return 0;  
		}
	}
	cout << "Employee not found." << endl;
	return 1;  
}
void payroll()
{
	int daysInMonth = 25;
	const int paidOffDays = 3;
		string ID;
		cout << "Enter employee ID to generate payslip: ";
		cin >> ID;
		for (int i = 0; i < NoOfEmployee; i++)
		{
			if (emp[i].employeeID == ID)
			{
				emp[i].AdditionalOffDays= daysInMonth - emp[i].DaysWorked-paidOffDays;
				emp[i].dailySalary = emp[i].basicPay / 30;
				emp[i].leaveWOP = emp[i].dailySalary * emp[i].AdditionalOffDays;
					emp[i].GrossPay = emp[i].basicPay+ emp[i].HouseRentAllowance+ emp[i].UtilityAllowance;
					emp[i].tax = (emp[i].GrossPay) * 35 / 100;
					emp[i].netPay = emp[i].GrossPay -emp[i].leaveWOP - emp[i].tax;
					cout << "===========================================" << endl;
					cout << "                 PAYSLIP" << endl;
					cout << "-------------------------------------------" << endl;
					cout << "Employee ID: " << emp[i].employeeID << "     Name: " << emp[i].name << endl;
					cout << "Department: " << emp[i].department << endl;
					cout << "-------------------------------------------" << endl;
					cout << "Earnings:\n\n" ;
					cout << "Basic pay: Rs. " << emp[i].basicPay << endl;
					cout << "Utilty allowance: Rs." << emp[i].UtilityAllowance << endl;
					cout << "HouseRent allowance: Rs." << emp[i].HouseRentAllowance << endl<<endl;
					cout << "Gross pay: Rs. " << emp[i].GrossPay << endl << endl;
					cout << "Deductions: \n\n";
					cout<< "Income tax: Rs. " << emp[i].tax << endl;
					cout << "Leave without pay: Rs. " << emp[i].leaveWOP << endl << endl;
					cout << "Total deductions: Rs. " << emp[i].leaveWOP + emp[i].tax << endl << endl;
					cout << "Net pay: Rs. "<<emp[i].netPay << endl;
					cout << "===========================================" << endl;
			}
		}
	
	
	
}
void SaveToFile()
{
	ofstream myfile;
	myfile.open("employee.txt");
	for (int i = 0; i < NoOfEmployee; i++)
	{
		if (emp[i].employeeID == "\0")
		{
			break;
		}
		else
		{
			myfile << emp[i].employeeID + string(",") + emp[i].name + string(",") +emp[i].department + string(",") +emp[i].address  << endl;
		}
	}
}

void Admin()
{
	int choice;
	
	do {
		cout << "\nEnter your choice: " << endl;
		cout << "1. Add new employee." << endl;
		cout << "2. Display list of all employees." << endl;
		cout << "3. Search for an employee." << endl;
		cout << "4. Edit an employee's record." << endl;
		cout << "5. Delete an employee record." << endl;
		cout << "6. Mark attendance." << endl;
		cout << "7. Generate payroll slip." << endl;
		cout << "8. Change your password." << endl;
		cout << "9. Save and exit." << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			Insert();
			break;
		case 2:
			display();
			break;
		case 3:
			search();
			break;
		case 4:
			edit();
			break;
		case 5:
			Delete();
			break;
		case 6:
			Attendance();
			break;
		case 7:
			payroll();
			break;
		case 8:
			changeCode();
			break;
		}
	} while (choice != 9);
	SaveToFile();
	cout << "Exiting...saving to file." << endl;
}

int main()
{
	int pwd;
	OpenFile();
	cout << "Enter password to login: ";
	cin >> pwd;
	if (pwd == code)
	{
		cout << "Login successful!" << endl;
		Admin();
	}
	else
	{
		cout << "Incorrect password." << endl;
	}
	return 0;
}
	
