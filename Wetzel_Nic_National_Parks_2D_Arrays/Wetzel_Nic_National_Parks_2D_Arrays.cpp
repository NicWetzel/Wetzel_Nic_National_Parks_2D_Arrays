// Nic Wetzel
// April 22, 2021
// National Parks 2D Arrays
// This program calculates and analyzes the data from the number of visitors to a national park in Maine.

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// Function prototypes for each menu option.

void showTable(int[12][9], string[12]);
void recNonRecVisitors(int[12][9]);
void tentAndRV(int[12][9], string[12]);
void recVisitorsMonth(int[12][9], string[12]);


int main()
{   // Variables for menu choice and arrays.

    int choice;
    int visitors[12][9];
    string months[12];

    cout << "Visitors to Acadia National Park" << endl;

    // Loop to display menu and to call function depending on menu choice.
    do
    {
        cout << "Enter 1 to display data" << endl;
        cout << "Enter 2 to display total number of recreation and non recreational visitors" << endl;
        cout << "Enter 3 to display total tent and RV campers by month" << endl;
        cout << "Enter 4 to display the number of recreational visitors for a certain month" << endl;
        cout << "Enter any other number to exit" << endl;
        cout << endl;
        cin >> choice;


        if (choice == 1)
        {
            showTable(visitors, months);           // Function call to display the chart.
        }
        else if (choice == 2)
        {
            recNonRecVisitors(visitors);          // Function call to display the rec and non rec visitors.
        }
        else if (choice == 3)
        {
            tentAndRV(visitors, months);          // Function call to display the tent and RV campers.

        }
        else if (choice == 4)
        {
            recVisitorsMonth(visitors, months);   // Function call to display the month and amount of visitors for that month.
        }

    } while (choice == 1 || choice == 2 || choice == 3 || choice == 4);

    // If statement to exit program if choice is not one of the menu options.
    if (choice != 1 && choice != 2 && choice != 3 && choice != 4)
    {
        return 0;
    }
}

// Function to display the chart of visitors.
void showTable(int visitors[12][9], string months[12])
{
    // Files to read visitors and months from.
    ifstream visitorsFile;
    ifstream monthsFile;
    // Opens both files to get visiotr information anf months from.
    visitorsFile.open("AcadiaVisitors.txt");
    monthsFile.open("Months.txt");

    cout << "Visitors to the Park by Month and Type:\n" << endl;
    // Cout statement to display the chart headings.
    cout << left << setw(14) << "Month" << setw(10) << "T Rec" << setw(10) << "T Non-Rec" << setw(14) << "Con Lodge"
        << setw(10) << "Tent" << setw(7) << "RV" << setw(10) << "Con Camp" << setw(12) << "BackCounty"
        << setw(11) << "Misc Camp" << setw(11) << "T Overnite" << endl;
    // Loop to get months and display them for chart.
    for (int row = 0; row < 12; row++)
    {
        monthsFile >> months[row];
        cout << left << setw(15) << months[row];
        // Loop to get visitor numbers from file and display them.
        for (int col = 0; col < 9; col++)
        {
            visitorsFile >> visitors[row][col];
            cout << left << setw(11) << visitors[row][col];
        }

        cout << endl;
    }

    cout << endl;
}
// Function to total and display all rec and non rec visitors.
void recNonRecVisitors(int visitors[12][9])
{
    // Variable to hold the total number of visiotrs.
    int total = 0;

    ifstream visitorsFile;
    ifstream monthsFile;
    // Opens the files to read visitor numbers and months.
    visitorsFile.open("AcadiaVisitors.txt");
    monthsFile.open("Months.txt");
    // Loop to go through the rows and columns to get visitor numbers.
    for (int row = 0; row < 12; row++)
    {
        for (int col = 0; col < 9; col++)
        {
            visitorsFile >> visitors[row][col];

            if (col > 1)
            {
                visitors[row][col] = 0;
            }
            else
            {
                total += visitors[row][col];   // Totals the number of visitors.
            }
        }
    }
    // Displays the total number of visitors. 
    cout << "\nThe total number of recreational and non-recreational visitors: " << total << endl;
    cout << endl;
    // Closes both files.
    visitorsFile.close();
    monthsFile.close();
}
// Function to display the tent and RV campers.
void tentAndRV(int visitors[12][9], string months[12])
{
    // Variable to hold the total number.
    int total = 0;
    
    ifstream visitorsFile;
    ifstream monthsFile;

    visitorsFile.open("AcadiaVisitors.txt");
    monthsFile.open("Months.txt");

    cout << "\nTotal Tent and RV Campers by Month " << endl;
    // Loop to get the months and visitor numbers to total and display them.
    for (int row = 0; row < 12; row++)
    {
        monthsFile >> months[row];
        cout << right << setw(12) << months[row];

        for (int col = 0; col < 9; col++)
        {
            visitorsFile >> visitors[row][col];

            if (col == 3 || col == 4)
            {
                total += visitors[row][col];
            }   
        }
        cout << right << setw(13) << total;
        total = 0;                            // Resets total for each loop.
        cout << endl;
    }
    
    cout << endl;
    // Closes files.
    visitorsFile.close();
    monthsFile.close();
}
// Function to display totals for a given month entered by user.
void recVisitorsMonth(int visitors[12][9], string months[12])
{
    // Variables for month choice and to hold the total for that month.
    string choice;
    int total = 0;

    ifstream visitorsFile;
    ifstream monthsFile;

    visitorsFile.open("AcadiaVisitors.txt");
    monthsFile.open("Months.txt");

    cout << "Enter the month you want the number of recreational visitors" << endl;
    cin >> choice;
    // Loop to get the month entered and validate that it is a correct month then display the total for that month.
    for (int row = 0; row < 12; row++)
    {
        monthsFile >> months[row];

        for (int col = 0; col < 9; col++)
        {
            visitorsFile >> visitors[row][col];

            if (choice == months[row] && col == 0)
            {
                total += visitors[row][col]; 
                cout << "For the month of " << months[row] << " there were " << total << " recreational visitors.";
            }
        }
        // If statement to validate month entered. displays main menu if incorrect month is entered.
        if (choice != "January" && choice != "February" && choice != "March" && choice != "April" && choice != "May" && choice != "June" && choice != "July" && choice != "August" && choice != "September" && choice != "October" && choice != "November" && choice != "December")
        {
            cout << "Month not found, start over.";
            break;
        }
    }

    cout << endl;
    cout << endl;
    // Closes files.
    visitorsFile.close();
    monthsFile.close();
}