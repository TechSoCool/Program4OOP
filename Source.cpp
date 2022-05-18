// Name: Sterling Gerard
// Submit Date: March 13, 2022 
// Objective: Write a program that uses an arrays of at least 20 string . 
// It should call a function that uses the linear search algorithm to locate one of the name. Read list of name from an input file call "StudentName.txt"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include<string>
#include <ctime>
#include <vector>

using namespace std;


int linearSearch(string names[], string search, int cnt, int& comparisionCnt);
void binarySearchlinearSearch(string names[], string search, int cnt, int& comparisionCnt);

//+++++++++++++++++Main Program++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
int main()
{
    //Declaring variables
    const int SIZE = 20;
    string names[SIZE];
    string search;
    int cnt = 0, comparisionCnt = 0;
    ifstream dataIn;
    ofstream dataOut;

    dataIn.open("Names.txt");
    //checking whether the file name is valid or not
    if (dataIn.fail())
    {
        cout << "** File Not Found **";
        return 1;
    }
    else
    {
        dataOut.open("out.txt");
        //Reading the data from the file
        while (getline(dataIn, names[cnt]))
        {
            cnt++;
        }
        dataIn.close();

        // user enter name to search
        cout << "Enter Name to search :";
        getline(cin, search);

        int index = linearSearch(names, search, cnt, comparisionCnt);
        if (index != -1)
        {

            cout << "No of comparisions in Linear Search :" << comparisionCnt << endl;
            comparisionCnt = 0;
            binarySearchlinearSearch(names, search, cnt, comparisionCnt);
            cout << "No of comparisions in Binary Search :" << comparisionCnt << endl;

            dataOut << "No of comparisions in Linear Search :" << comparisionCnt << endl;
            dataOut << "No of comparisions in Binary Search :" << comparisionCnt << endl;
            dataOut.close();
        }
        else
        {

            cout << search << " not found in the array" << endl;
            dataOut << search << " not found in the array" << endl;
            dataOut.close();
        }

    }
    return 0;
}
// linear search through the elements
int linearSearch(string names[], string search, int cnt, int& comparisionCnt)
{

    for (int i = 0; i < cnt; i++)
    {

        if (names[i].compare(search) == 0)
        {

            return i;
        }
        comparisionCnt++;
    }
    return -1;
}

// binary search through the elements 
void binarySearchlinearSearch(string names[], string search, int cnt, int& comparisionCnt)
{
    int low = 0;
    int flag = 0, pos;
    int high = cnt - 1;
    while (high >= low) {
        int middle = (low + high) / 2;
        if (names[middle].compare(search) == 0) {
            flag = 1;
            pos = middle;
            break;
        }

        if (names[middle].compare(search) < 0) {
            low = middle + 1;
            comparisionCnt++;
        }
        if (names[middle].compare(search) > 0) {
            high = middle - 1;
            comparisionCnt++;
        }

    }

}