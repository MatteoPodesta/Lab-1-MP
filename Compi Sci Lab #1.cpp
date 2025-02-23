#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;

//for all of these, all we really need is the list, and for it to return a number
//Each list has 10 numbers in it, i would give Other numbers 20 but then I'd have to jump through some unessesary hoops to make it work
double findAvgNumber(int listName[10], int numCount);
int findMedianNumber(int listName[10], int numCount);
int findSumNumbers(int listName[10], int numCount);

void printListConsole(int listName[10], int numCount, int optionChosen, ofstream &outfile);
void sortNumberList(int listName[10], int numCount);

int main()
{
    //in order to check to see if a list is empty, variables will be set in place to count the variables in the lists 
    int fiveCount = 0;
    int nineCount = 0;
    int otherCount = 0;

    int tempCounter = 0;
    int tempNumber;
    bool exitTime = false;
    int selectionChosen;

    //Arrays the numbers are stored in
    int divByFive[10];
    int divByNine[10];
    int otherNumbers[10];

    //file reading stuff
    ifstream infile;
    infile.open("numberFiles.dat");
    if (!infile) {
        cout << "Cannot open file" << endl;
        exit(1);
    }

    //outfile stuff
    ofstream outfile;
    outfile.open("sillyFile.dat");

    infile >> tempNumber;

    //i put <= 10 which caused a stack overflow and alot of problems
    while (infile) {

        if (tempNumber % 5 == 0 && fiveCount < 10) {

            divByFive[fiveCount] = tempNumber;
            fiveCount++;
            

            if (tempNumber % 9 == 0 && nineCount < 10) {

                divByNine[nineCount] = tempNumber;
                nineCount++;

            }
        }
        else if (tempNumber % 9 == 0 && nineCount < 10) {

            divByNine[nineCount] = tempNumber;
            nineCount++;

        }
        else if (otherCount < 10){

            otherNumbers[otherCount] = tempNumber;
            otherCount++;

        }
        tempCounter++;
        infile >> tempNumber;
       
    }
    //when there is nothing inside the numbers file, the tempCounter remains at 0,
    //so it means that I can have it when tempCounter is at 0 after the whole infile thing, 
    //it means the file is empty and it can be shown

    if (tempCounter == 0) {

        cout << "There are no numbers in the file, please fix that and try again.\n";

    }
    else {
        //this is just to make sure that the lists are okay or if they dont work or now
        //this piece of code also changes the numbers for the functions to work properly
        //reminder to change this into a function if you remember to
        if (fiveCount > 10) {

            cout << "Warning: The list of numbers divisible by 5 is overloaded, some numbers may be missing.\n";
            fiveCount = 10;

        }
        else if (fiveCount == 0) {

            cout << "Warning: The list of numbers divisible by 5 is empty.\n";

        }
        if (nineCount > 10) {

            cout << "Warning: The list of numbers divisible by 9 is overloaded, some numbers may be missing.\n";
            nineCount = 10;

        }
        else if (nineCount == 0) {

            cout << "Warning: The list of numbers divisible by 9 is empty.\n";

        }
        if (otherCount > 10) {

            cout << "Warning: The list of other numbers is overloaded, some numbers may be missing.\n";
            otherCount = 10;
        }
        else if (otherCount == 0) {

            cout << "Warning: The list of other numbers is empty.\n";
            

        }

        //have a exit boolean to determine wether its done or not?
        //testing works
        while (!exitTime) {

            cout << "Main Menu - Please select one of the following options by typing in the option's number:\n1.Print the lists with:\n   Median\n   Average\n   Sum\n2.Sort the Lists\n3.Quit and have lists on an output file\n\nSelection:";
            cin >> selectionChosen;

            //switch statement
            switch (selectionChosen) {

            case 1:
                cout << "List of numbers divisible by 5: " << endl;
                printListConsole(divByFive, fiveCount, selectionChosen, outfile);
                cout << "Sum: " << findSumNumbers(divByFive, fiveCount) << endl << "Average: " << findAvgNumber(divByFive, fiveCount) << endl << "Median: " << findMedianNumber(divByFive, fiveCount) << endl << endl;
                
                cout << "List of numbers divisible by 9: " << endl;
                printListConsole(divByNine, nineCount, selectionChosen, outfile);
                cout << "Sum: " << findSumNumbers(divByNine, nineCount) << endl << "Average: " << findAvgNumber(divByNine, nineCount) << endl << "Median: " << findMedianNumber(divByNine, nineCount) << endl << endl;

                cout << "List of all other numbers: " << endl;
                printListConsole(otherNumbers, otherCount, selectionChosen, outfile);
                cout << "Sum: " << findSumNumbers(otherNumbers, otherCount) << endl << "Average: " << findAvgNumber(otherNumbers, otherCount) << endl << "Median: " << findMedianNumber(otherNumbers, otherCount) << endl << endl;
                break;
            case 2:
                cout << "Sorted list of numbers divisible by 5: " << endl;
                sortNumberList(divByFive, fiveCount);
                cout << "Sorted list of numbers divisible by 9: " << endl;
                sortNumberList(divByNine, nineCount);
                cout << "Sorted list of other numbers: " << endl;
                sortNumberList(otherNumbers, otherCount);
                break;
            case 3:
                outfile << "List of numbers divisible by 5: " << endl;
                printListConsole(divByFive, fiveCount, selectionChosen, outfile);
                outfile << "Sum: " << findSumNumbers(divByFive, fiveCount) << endl << "Average: " << findAvgNumber(divByFive, fiveCount) << endl << "Median: " << findMedianNumber(divByFive, fiveCount) << endl << endl;

                outfile << "List of numbers divisible by 9: " << endl;
                printListConsole(divByNine, nineCount, selectionChosen, outfile);
                outfile << "Sum: " << findSumNumbers(divByNine, nineCount) << endl << "Average: " << findAvgNumber(divByNine, nineCount) << endl << "Median: " << findMedianNumber(divByNine, nineCount) << endl << endl;

                outfile << "List of all other numbers: " << endl;
                printListConsole(otherNumbers, otherCount, selectionChosen, outfile);
                outfile << "Sum: " << findSumNumbers(otherNumbers, otherCount) << endl << "Average: " << findAvgNumber(otherNumbers, otherCount) << endl << "Median: " << findMedianNumber(otherNumbers, otherCount) << endl << endl;

                exitTime = true;
                break;
            default:
                cout << "Invalid option, please input a valid option.\n\n";
                break;
            }

        }

    }

    return 0;

}
//function defenitions-----------------------------------------------------------------------------------------------------------------------------------------------------

//can I put a function inside of a function? - I dont think so, Ill just copy the code from findSumNumbers
int findSumNumbers(int listName[10], int numCount) {
    int sumOfNumbers = 0;

    for (int i = 0; i < numCount; i++) {

        sumOfNumbers = sumOfNumbers + listName[i];
        

    }
    return sumOfNumbers;
}
double findAvgNumber(int listName[10], int numCount) {
    double avgNumber = 0;
    int tempNumber = 0;
    if (numCount != 0) {

        for (int i = 0; i < numCount; i++) {

            avgNumber = tempNumber + listName[i];

        }
        avgNumber = tempNumber / numCount;

    }
    
    return avgNumber;

}
//i may have to make the bubble sorting code twice, once in here and another for the sort option
int findMedianNumber(int listName[10], int numCount) {
    int temp;
    int median;

    for (int i = 0; i < numCount; i++) {
        for (int j = i + 1; j < numCount; j++) {

            if (listName[j] < listName[i]) {

                temp = listName[i];
                listName[i] = listName[j];
                listName[j] = temp;
            }

        }

    }
    //5 is the middle of the list, since there is 10 numbers in it
    if (numCount == 0) {

        median = 0;
    }
    else {

        median = listName[numCount / 2];

    }
    
    return median;
}
//I will have to duplicate this so i can put it into an outfile, or i can work around having 2 functions and have what option is chosen decide if its output into a outfile or console
void printListConsole(int listName[10], int numCount, int optionChosen, ofstream &outfile) {

    if (optionChosen == 1) {

        for (int i = 0; i < numCount; i++) {

            cout << listName[i] << endl;

        }

    }
    else if (optionChosen == 3) {

        for (int i = 0; i < numCount; i++) {

            outfile << listName[i] << endl;

        }

    }
    

}
void sortNumberList(int listName[10], int numCount) {
    
    int temp;
    for (int i = 0; i < numCount; i++) {
        for (int j = i + 1; j < numCount; j++) {

            if (listName[j] < listName[i]) {

                temp = listName[i];
                listName[i] = listName[j];
                listName[j] = temp;
            }

        }

    }

    for (int i = 0; i < numCount; i++) {

        cout << listName[i] << endl;

    }
}
//notes and such-----------------------------------------------------------------------------------------------------------------------------------------------------
//1.
//get numbers from input file (numbers only) and put in arrays:
    //numbers divisible by 5 - 10 numbers - divByFive
    //numbers divisible by 9 - 10 numebrs - divByNine
    //the rest of the numbers - 20 numbers - otherNumbers
//1.5
//Make sure there are situations for
    //No numbers divisible by 5
    //No numbers divisible by 9
    //No numbers at all (empty file)
    //Too many numbers to fit into each array
//2.
//Create a menu with the options with switch statements:
    //Print Values stored in each array along with:
        //Average - getAverage
        //Median - getMedian
        //sum of all numbers in array - getSum
    //Print values in each array sorted in ascending order
    //Quit and write arrays and their stats onto an output file
//okay so i have an idea to do "if divisible by 5, then [add to array number function], else if divisible by 9, then....etc" - I realised there was an easier way. ignore this 11 PM thinking
//behold my genius: I put a minus on accident in the bubble sorting and spent an hour freaking out trying to fix it