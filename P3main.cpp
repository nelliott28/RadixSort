#include<iostream>
#include<string>
#include<chrono>
using namespace std;
using namespace std::chrono;

//Find Max String Length
int findMaxSize(string *a, int s){
    int max = 0;
    for (int i = 0; i < s; i++){
        if (a[i].length() > max){
            max = a[i].length();
        }
    }
    return max;
}

//Adds Place Value Zeros
void appendZeros(string *a, int s, int size){
    for (int i = 0; i < size; i++){
        if (a[i].length() < s){
            string temp = "";
            for (int j = 0; j < s - a[i].length(); j++){
                temp += "0";
            }
            a[i] = temp + a[i];
        }
    }
}

//Removes Place Value Zeros
void removeZeros(string *a, int s, int size){
    for (int i = 0; i < size; i++){
        int count = 0;
        for (int j = 0; j < a[i].length(); j++){
            if (a[i][j] == '0'){
                count++;
            }
            else{
                break;
            }
        }
        a[i] = a[i].substr(count, a[i].length());
    }
}

void radixSort(string *a, int s, int size){
    string temp[size];
    int vIndex = 0;
    int aIndex = 0;
    
    appendZeros(a, s, size); //Adds Place Value Zeros

    //Radix Sort Algorithm
    for (int i = 0; i < s; i++){
        while (vIndex < 10){
            for (int j = 0; j < size; j++){
                if (int(a[j][s - i - 1]) - '0' == vIndex && a[j].length() >= i){
                    temp[aIndex] = a[j];
                    aIndex++;
                }
            }
            vIndex++;
        }
        aIndex = 0;
        vIndex = 0;
        for (int i = 0; i < size; i++){
            a[i] = temp[i];
        }
    }

    removeZeros(a, s, size); //Removes Place Value Zeros
    
    //Print Sorted Array
    for (int i = 0; i < size; i++){
        cout << a[i] << ", ";
    }
    cout << endl;
}

int main(){
    string arr[10] = {"32", "120", "3", "12", "5423", "1342", "762", "89", "12", "1"};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    auto s1 = high_resolution_clock::now(); //START CLOCK
    radixSort(arr, findMaxSize(arr, arrSize), arrSize);
    auto e1 = high_resolution_clock::now(); //END CLOCK
    auto d1 = duration_cast<microseconds>(e1 - s1); //FIND CLOCK DIFF.

    cout << d1.count() << "us" << endl; //PRINT CLOCK DIFF.

    return 0;
}