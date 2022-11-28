#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <chrono>

using namespace std;

int LomutoPartition(){
    //TODO
}

void LomutoQuicksort(vector<int> & arr, int start, int end){
    if(start >= end) return;
    int partitionIndex = LomutoPartition();
    LomutoQuicksort(arr, start, partitionIndex-1);
    LomutoQuicksort(arr, partitionIndex+1, end);
}

int RandomizedPartition(vector<int> & arr, int start, int end){
    //TODO
}

void RandomizedQuicksort(vector<int> & arr, int start, int end){
    if(start >= end) return;
    int partitionIndex = RandomizedPartition(arr, start, end);
    RandomizedQuicksort(arr, start, partitionIndex-1);
    RandomizedQuicksort(arr, partitionIndex+1, end);
}


int HoarePartition(vector<int> & arr, int start, int end){
    //TODO

}

void HoareQuicksort(vector<int> & arr, int start, int end){
    if(start >= end) return;
    int partitionIndex = HoarePartition(arr, start, end);
    HoareQuicksort(arr, start, partitionIndex-1);
    HoareQuicksort(arr, partitionIndex+1, end);
}

int NaivePartition(vector<int> & arr, int start, int end){
    //TODO
}

void NaiveQuicksort(vector<int> & arr, int start, int end){
    if(start >= end) return;
    int partitionIndex = NaivePartition(arr, start, end);
    NaiveQuicksort(arr, start, partitionIndex-1);
    NaiveQuicksort(arr, partitionIndex+1, end);
}

void GenerateIncresingSortedArray(vector<int> & arr){
    int num = 1;
    for(int i = 0; i < arr.size(); i++){
        arr[i] = num++;
    }
}

void GenerateDecreasingArray(vector<int> & arr){
    int num = arr.size()+1;

    for(int i = 0; i < arr.size(); i++){
        arr[i] = num--;
    }
}

void GenerateRandomArray(vector<int> & arr){
    for(int i = 0; i < arr.size(); i++){
        arr[i] = rand();
    }
}

void GenerateSingleValueArray(vector<int> & arr){
    for(int i = 0; i < arr.size(); i++){
        arr[i] = 1;
    }
}


int main(int argc, char * argv[]){
    
    vector<pair<string, vector<int>>> inputs;

    //declaring vector of size 1000 which values will be in non-decreasing order
    vector<int> sorted_Increasing_1000(1000, 0);
    GenerateIncresingSortedArray(sorted_Increasing_1000);
    string s = "Sorted Array of size 1000 whose values are in non-decreasing order";
    inputs.push_back(make_pair(s, sorted_Increasing_1000));

    //declaring vector of size 1000 which values will be in non-decreasing order
    vector<int> sorted_Increasing_10000(1000, 0);
    GenerateIncresingSortedArray(sorted_Increasing_10000);
    string s2 = "Sorted Array of size 10000 whose values are in non-decreasing order";
    inputs.push_back(make_pair(s2, sorted_Increasing_10000));

    //declaring vector of size 1000 which values will be in decreasing order
    vector<int> sorted_Decreasing_1000(1000, 0);
    GenerateDecreasingArray(sorted_Decreasing_1000);
    string s3 = "Array of size 1000 in decreasing order";
    inputs.push_back(make_pair(s3, sorted_Decreasing_1000));

    //declaring vector of size 10000 which values will be in decreasing order
    vector<int> sorted_Decreasing_10000(1000, 0);
    GenerateDecreasingArray(sorted_Decreasing_10000);
    string s4 = "Array of size 10000 in decreasing order";
    inputs.push_back(make_pair(s4, sorted_Decreasing_10000));

    //declaring a vector of size 1000 whose values will be in random order
    vector<int> random_1000(1000, 0);
    GenerateRandomArray(random_1000);
    string s5 = "Array of size 1000 whose values will be in random order";
    inputs.push_back(make_pair(s5, random_1000));

    //declaring a vector of size 10000 whose values will be in random order
    vector<int> random_10000(10000, 0);
    GenerateRandomArray(random_10000);  
    string s6 = "Array of size 10000 whose values will be in random order";
    inputs.push_back(make_pair(s6, random_10000));

    //declaring a vector of size 1000 whose values are all the same
    vector<int> single_1000(1000, 0);
    GenerateSingleValueArray(single_1000);
    string s7 = "Array of size 1000 whose values are all the same";
    inputs.push_back(make_pair(s7, single_1000));

    //declaring a vector of size 10000 whose values are all the same
    vector<int> single_10000(10000, 0);
    GenerateSingleValueArray(single_10000);
    string s8 = "Array of size 10000 whose values are all the same";
    inputs.push_back(make_pair(s8, single_10000));

    string outputFile = argv[1];

    ofstream outStream;

    try{
        outStream.open(outputFile);
    }
    catch(exception ex){
        cout << "Unable to open file: " << outputFile << endl;
        return;
    }

    if(outStream){
        for(int i = 0; i < inputs.size(); i++){
            outStream << inputs[i].first << endl << endl;


            outStream << "Lomuto Partitioning: " << endl;
            vector<int> temp = inputs[i].second;
            auto start = std::chrono::high_resolution_clock::now();
            LomutoQuicksort(temp, 0, temp.size()-1);
            auto finish = std::chrono::high_resolution_clock::now();
            auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
            outStream << microseconds << endl;

            outStream << "Randomized Partitioning: " << endl;
            vector<int> temp2 = inputs[i].second;
            auto start2 = std::chrono::high_resolution_clock::now();
            RandomizedQuicksort(temp2, 0, temp2.size()-1);
            auto finish2 = std::chrono::high_resolution_clock::now();
            auto microseconds2 = std::chrono::duration_cast<std::chrono::microseconds>(finish2-start2);
            outStream << microseconds2 << endl;


            outStream << "Hoares Partitioning: " << endl;
            vector<int> temp3 = inputs[i].second;
            auto start3 = std::chrono::high_resolution_clock::now();
            HoareQuicksort(temp3, 0, temp3.size()-1);
            auto finish3 = std::chrono::high_resolution_clock::now();
            auto microseconds3 = std::chrono::duration_cast<std::chrono::microseconds>(finish3-start3);
            outStream << microseconds3 << endl;

            outStream << "Naive Partitioning: " << endl;
            vector<int> temp4 = inputs[i].second;
            auto start4 = std::chrono::high_resolution_clock::now();
            NaiveQuicksort(temp4, 0, temp4.size()-1);
            auto finish4 = std::chrono::high_resolution_clock::now();
            auto microseconds4 = std::chrono::duration_cast<std::chrono::microseconds>(finish4-start4);
            outStream << microseconds4 << endl;
        }
    }
    outStream.close();
}