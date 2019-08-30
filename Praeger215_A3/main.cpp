#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include "PraegerA3_Operations.h"

using namespace std;

int main()
//Main driver function
{

    string fileNameOne, fileNameTwo; //file name variables
    //taking in file names
    cout<<"Enter the name of the first file with the extension: ";
    cin>>fileNameOne;
    cout<<"Enter the name of the second file with the extension: ";
    cin>>fileNameTwo;
    //creating two Operations objects, one for each file
    Operations fileOne(fileNameOne);
    Operations fileTwo(fileNameTwo);
    //Finding which of the files has a larger amount of values and using the smaller as the hmr
    int hmr;
    if(fileOne.getSize() >= fileTwo.getSize()){hmr = fileOne.getSize();}
    else hmr = fileTwo.getSize();
    //solving for the RMSE of the two files
    float RMSE = 0;
    for (int i = 0; i <hmr; ++i)
    {
        RMSE+= pow(fileOne.getIndex(i)-fileTwo.getIndex(i),2);
    }
    //formatted console output
    RMSE = sqrt(RMSE/fileOne.getSize());
    cout<<"-----------------------------------------"<<endl;
    cout<<"The value tables of the two files: "<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"--------------------------------|File 1| |File 2|"<<endl;
    cout<<"Sum values:                     "<<"|"<<setw(8)<<fileOne.getSum()<<"|"<<setw(8)<<fileTwo.getSum()<<"|"<<endl;
    cout<<"Max Values:                     "<<"|"<<setw(8)<<fileOne.max()<<"|"<<setw(8)<<fileTwo.max()<<"|"<<endl;
    cout<<"Min Values:                     "<<"|"<<setw(8)<<fileOne.min()<<"|"<<setw(8)<<fileTwo.min()<<"|"<<endl;
    cout<<"Mean Values:                    "<<"|"<<setw(8)<<fileOne.mean()<<"|"<<setw(8)<<fileTwo.mean()<<"|"<<endl;
    cout<<"Median Values found with Sort:  "<<"|"<<setw(8)<<fileOne.median()<<"|"<<setw(8)<<fileTwo.median()<<"|"<<endl;
    cout<<"The times of the sorts:         "<<"|"<<setw(8)<<fileOne.getSTime()<<"|"<<setw(8)<<fileTwo.getSTime()<<endl;
    cout<<"Median Values found with QSort: "<<"|"<<setw(8)<<fileOne.qmedian()<<"|"<<setw(8)<<fileTwo.qmedian()<<"|"<<endl;
    cout<<"The times of the qsorts:        "<<"|"<<setw(8)<<fileOne.getQTime()<<"|"<<setw(8)<<fileTwo.getQTime()<<"|"<<endl;
    cout<<"The RMSE value of the two files:"<<"|"<<setw(8)<<RMSE<<"|"<<endl;


    return 0;
}
