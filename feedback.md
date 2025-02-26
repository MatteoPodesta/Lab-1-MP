**NG 2/25/2025**
* file name(s) and/or file/folder structure/capitalization do not comply with posted instructions – 2
* average is not accurate; Integer/  integer returns integer double avg=5/2 // is 2 not 2.5 -2
* #106, UI vague, confusing prompts and/or messages: which file? Input/output? -2
```
```
* to ensure accurate results, median function should call sort and work for array with even and odd number of values -2
* readability, comments; do not state obvious, remove outdated code; comments supposed to help and not create unnecessary clutter; "Code never lies, comments sometimes do." - Ron Jeffries” ; what is the purpose of the comments as this(ese) one(s);  -2

```
//for all of these, all we really need is the list, and for it to return a number
//Each list has 10 numbers in it, i would give Other numbers 20 but then I'd have to jump through some unnecessary hoops to make it work
double findAvgNumber(int listName[10], int numCount);
```
* 56-86- redundant -1
* what’s “notes and such”? -1
* #203-207 redundant, should have called sum function -1
* unnecessary variable – unnecessary expense, while(menuChoice!=3) -1

```
exitTime = true;
```
* #38 use exit(EXIT_FAILURE) for better readability 

* test runs not included -10

* If a user enters a value of a wrong data type, the program goes into an infinite loop or  crashes or terminates or prints the menu multiple times ( in menu add cin.clear(); cin.ignore(...);  in  the default case of the switch); validate user input -5
* inadequate and/ insufficient test data/ not all possible cases have been tested: e.g. each record has 4 pieces of data; pow(2,4)->16  possible combinations of valid/invalid and only one of them is a valid record; all menu options should be tested;  no zeros, negative numbers, etc-5
* modularization: each menu option should have its own function -5
*  const; if it is not 1 or 0 make it const -5
* 33-124 redundant convoluted logic; modularization: opening an input file, reading from the input file, storing values, and closing input files should be done in a separate function-5
* 137-147 and other menu options; redundant; what if there are no numbers divisible by 5 and/or 9; should created a function to process one array and call it three times from a function that handles menu option -5
* missing feedback.md –2
