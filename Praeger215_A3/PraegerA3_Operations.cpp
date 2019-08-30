//
// Created by Torin Praeger on 10/17/2018.
//
/*
 *
 *
 *
 *
 *
 */



#include "PraegerA3_Operations.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
using namespace std;

int compare(const void* a, const void* b);
Operations::Operations(string fileName)
//PRE: The fileName string is a string that is the name of a reachable file with its proper extension
//POST: An Operations object is created with the data of the file that it was passed put into the myArray array
//Summary: The constructor  is passed the name of a file with its extension and it will open the file and read in the data from the file
// to a dynamically sized array based on the number of rows and columns in the file, which is found in the file header,
// creating an object to preform anaylsis on the data in the array
//
{
    string buffer;
    ifstream thisFile;
    thisFile.open(fileName);
    if(thisFile.fail()){
        cout<<"Failed to open the file";
        exit(-1);
    }
    thisFile>>buffer;
    thisFile>>nCol;
    thisFile>>buffer;
    thisFile>>nRow;
    thisSize = nCol*nRow;
    this->myArray = new float[thisSize];
    float i = 0;
    while (thisFile.peek() != '0' && thisFile.peek() != '1' && thisFile.peek() != '2' &&
            thisFile.peek() != '3' && thisFile.peek() != '4' && thisFile.peek() != '5' &&
            thisFile.peek() != '6' && thisFile.peek() != '7' && thisFile.peek() != '8' && thisFile.peek() != '9'){
        getline(thisFile,buffer);
    }
    thisSum = 0;
    int maxOne = 0;
    do{
        thisFile>>i;
        myArray[maxOne] = i;
        thisSum += i;

        maxOne++;

    }while (thisFile);

}
float Operations::getSum()
//PRE: The thisSum contains some set of real and positive data
//POST: thisSum is returned
//Summary: A method to return the thisSum data member
//
{
    return thisSum;
}
float Operations::getIndex(int i)
//PRE: This myArray exists and has been filled with proper data and index i is not out of bounds
//POST: The data at index i of the array is returned
//Summary: A method to return the data at a certain index, specified by the user
//
{
    return this->myArray[i];
}
float Operations::getSize()
//PRE: thisSize has some real and positive data
//POST: thisSize is returned
//Summary: A method to return the thisSize data member
//
{
    return thisSize;
}
double Operations::getSTime()
//PRE: The sTime data member contains a real positive value
//POST: The sTime data member is returned
//Summary:A method to return the sTime data member
//
{
    return this->sTime;
}
double Operations::getQTime()
//PRE: The qTime data member contains a real positive value
//POST: The qTime data member is returned
//Summary:A method to return the sTime data member
//
{
    return this->qTime;
}
float Operations::max()
//PRE: The myArray array contains real and positive data members
//POST: The max value of the myArray is found and returned
//Summary: A method to find and return the max value of the myArray array
//
{
    float max = this->myArray[0];
    for (int i = 0; i <thisSize; ++i) {
        if(this->myArray[i] > max) max = this->myArray[i];
    }
    return max;
}
float Operations::min()
//PRE: The myArray array contains real and positive data members
//POST: The min value of the myArray is found and returned
//Summary: A method to find and return the min value of the myArray array
//
{
    float min = this->myArray[0];
    for (int i = 0; i <thisSize; ++i) {
        if(this->myArray[i] < min) min = this->myArray[i];
    }
    return min;
}
float Operations::mean()
//PRE: The myArray array contains real and positive data members
//POST: The mean value of the myArray is found and returned
//Summary: A method to find and return the mean value of the myArray array
//
{
    float mean = thisSum/thisSize;
    return mean;
}
float Operations::median()
//PRE: The myArray array contains real and positive data members
//POST: The median value of the myArray is found and returned
//Summary: A method to find and return the median value of the myArray array using the std::sort method
//
{
    clock_t start,stop;
    start = clock();
    sort(this->myArray,this->myArray + thisSize);
    stop = clock();
    this->sTime = (double) (stop-start) / CLOCKS_PER_SEC;
    return this->myArray[(thisSize/2)];
}

float Operations::qmedian()
//PRE: The myArray array contains real and positive data members
//POST: The median value of the myArray is found and returned
//Summary: A method to find and return the median value of the myArray array using the
// std::qsort method with the compare function as its swap
//
{
    clock_t start,stop;
    start = clock();
    qsort(this->myArray,thisSize,sizeof(float),compare);
    stop = clock();
    this->qTime = (double) (stop-start) / CLOCKS_PER_SEC;
    return this->myArray[(thisSize/2)];
}
int compare(const void* a, const void* b)
//PRE: a and b are real and proper positive values
//POST: a value of -1,0 or 1 is returned depending on the order in which the numbers are in magnitude
//Summary: A function to compare two values and determine which the larger of the two values are
//
{
    float one = *(float*)a;
    float two = *(float*)b;

    if (one < two) return -1;
    if (one == two) return 0;
    return 1;
}
