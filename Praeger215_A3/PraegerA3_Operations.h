//
// Created by Torin Praeger on 10/17/2018.
//
/*Programmer: Torin Praeger
 *
 * Summary: The program is created to read in a set of DEM values from two pairs of files and run certain statistical
 * diagnostics on them to find the maximum values, the minimum values, the median values, the time that the median
 * values take to compute with different algorithms and the Root Mean Square Error between the two files
 *
 *
 */
#include <fstream>
#include <iostream>


#ifndef PRAEGER215_A3_PRAEGERA3_OPERATIONS_H
#define PRAEGER215_A3_PRAEGERA3_OPERATIONS_H

#include <cstdlib>

class Operations {

public:
    Operations(std::string name); //constructor
    float getSum(); //method to return the sum
    float getIndex(int);
    float getSize();
    double getSTime();
    double getQTime();
    float mean(); //method to calculate and return the mean
    float max(); //method to calculate and return the max
    float min(); //method to calculate and return the min
    float median(); //method to calculate and return median, using std::sort
    float qmedian();//method to calculate and return median, using std::qsort

private:
    float *myArray; //pointer to myArray, to be dynamically sized in CTOR
    int thisSize, nRow, nCol; //number of rows and columns and their product
    float thisSum; //the size of each file
    double sTime = 0; //the time the sort takes
    double qTime = 0; //the time the qsort takes


};


#endif //PRAEGER215_A3_PRAEGERA3_OPERATIONS_H
