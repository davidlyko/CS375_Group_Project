#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <chrono>
#include <experimental/random>
#include <algorithm>

using namespace std;

int LomutoPartition(vector<int> & arr, int start, int end, int & numSwaps){
    int pivot = arr[end];
    int i = start-1;
    for(int j = start; j < end; j++){
        if(arr[j] <= pivot){
            swap(arr[++i], arr[j]);
            numSwaps++;
        }
    }
    swap(arr[i+1], arr[end]);
    numSwaps++;
    return i+1;
}

void LomutoQuicksort(vector<int> & arr, int start, int end, int & numSwaps){
    if(start >= end) return;
    int partitionIndex = LomutoPartition(arr, start, end, numSwaps);
    LomutoQuicksort(arr, start, partitionIndex-1, numSwaps);
    LomutoQuicksort(arr, partitionIndex+1, end, numSwaps);
}

int RandomizedPartition(vector<int> & arr, int start, int end, int & numSwaps){
    int randomPivot = rand()%(end+1 - start) + start;
    swap(arr[randomPivot], arr[end]);
    numSwaps++;
    return LomutoPartition(arr, start, end, numSwaps);
}

void RandomizedQuicksort(vector<int> & arr, int start, int end, int & numSwaps){
    if(start >= end) return;
    int partitionIndex = RandomizedPartition(arr, start, end, numSwaps);
    RandomizedQuicksort(arr, start, partitionIndex-1, numSwaps);
    RandomizedQuicksort(arr, partitionIndex+1, end, numSwaps);
}


int HoarePartition(vector<int> & arr, int start, int end, int & numSwaps){
    int pivot = arr[start];
    int i = start-1;
    int j = end+1;
       
    while(true){
        while(arr[--j] > pivot);
        while(arr[++i] < pivot);
        if(i < j){
            swap(arr[i], arr[j]);
            numSwaps++;
        }
        else{
            return j;
        }
    }
}

void HoareQuicksort(vector<int> & arr, int start, int end, int & numSwaps){
    if(start >= end) return;
    int partitionIndex = HoarePartition(arr, start, end, numSwaps);
    HoareQuicksort(arr, start, partitionIndex, numSwaps);
    HoareQuicksort(arr, partitionIndex+1, end, numSwaps);
}

int NaivePartition(vector<int> & arr, int start, int end){
    vector<int> temp((end - start) + 1);
 
    int pivot = arr[end];
    int index = 0;
       
    for (int i = start; i < end; i++) {
        if (arr[i] <= pivot){
            temp[index++] = arr[i];
        }
    }

    int position = index;
    
    temp[index++] = pivot;
       
    for (int i = start; i <= end; i++){
        if (arr[i] > pivot){
            temp[index++] = arr[i];
        }
    }
 
    for (int i = start; i <= end; ++i) {
        arr[i] = temp[i - start];
    }

    return position+start;
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
    vector<int> sorted_Increasing_10000(10000, 0);
    GenerateIncresingSortedArray(sorted_Increasing_10000);
    string s2 = "Sorted Array of size 10000 whose values are in non-decreasing order";
    inputs.push_back(make_pair(s2, sorted_Increasing_10000));

    //declaring vector of size 1000 which values will be in decreasing order
    vector<int> sorted_Decreasing_1000(1000, 0);
    GenerateDecreasingArray(sorted_Decreasing_1000);
    string s3 = "Array of size 1000 in decreasing order";
    inputs.push_back(make_pair(s3, sorted_Decreasing_1000));

    //declaring vector of size 10000 which values will be in decreasing order
    vector<int> sorted_Decreasing_10000(10000, 0);
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
        return 0;
    }

    if(outStream){
        for(int i = 0; i < inputs.size(); i++){
            outStream << inputs[i].first << endl << endl;


            outStream << "Lomuto Partitioning: " << endl;
            vector<int> temp = inputs[i].second;
            int numSwaps = 0;
            auto start = std::chrono::high_resolution_clock::now();
            LomutoQuicksort(temp, 0, temp.size()-1, numSwaps);
            auto finish = std::chrono::high_resolution_clock::now();
            auto microseconds = std::chrono::duration_cast<std::chrono::microseconds>(finish-start);
            outStream << microseconds.count() << " ";
            if(is_sorted(temp.begin(), temp.end())){
                outStream << "(Sorted) " << numSwaps << endl;
            }
            else{
                outStream << "(Not Sorted)" << endl;
            }


            outStream << "Randomized Partitioning: " << endl;
            vector<int> temp2 = inputs[i].second;
            int numSwaps2 = 0;
            auto start2 = std::chrono::high_resolution_clock::now();
            RandomizedQuicksort(temp2, 0, temp2.size()-1, numSwaps2);
            auto finish2 = std::chrono::high_resolution_clock::now();
            auto microseconds2 = std::chrono::duration_cast<std::chrono::microseconds>(finish2-start2);
            outStream << microseconds2.count() << " ";
            if(is_sorted(temp2.begin(), temp2.end())){
                outStream << "(Sorted) " << numSwaps2 << endl;
            }
            else{
                outStream << "(Not Sorted)" << endl;
            }


            outStream << "Hoares Partitioning: " << endl;
            vector<int> temp3 = inputs[i].second;
            int numSwaps3 = 0;
            auto start3 = std::chrono::high_resolution_clock::now();
            HoareQuicksort(temp3, 0, temp3.size()-1, numSwaps3);
            auto finish3 = std::chrono::high_resolution_clock::now();
            auto microseconds3 = std::chrono::duration_cast<std::chrono::microseconds>(finish3-start3);
            outStream << microseconds3.count() << " ";
            if(is_sorted(temp3.begin(), temp3.end())){
                outStream << "(Sorted) " << numSwaps3 << endl;
            }
            else{
                outStream << "(Not Sorted)" << endl;
            }

            outStream << "Naive Partitioning: " << endl;
            vector<int> temp4 = inputs[i].second;
            auto start4 = std::chrono::high_resolution_clock::now();
            NaiveQuicksort(temp4, 0, temp4.size()-1);
            auto finish4 = std::chrono::high_resolution_clock::now();
            auto microseconds4 = std::chrono::duration_cast<std::chrono::microseconds>(finish4-start4);
            outStream << microseconds4.count() << " ";
            if(is_sorted(temp4.begin(), temp4.end())){
                outStream << "(Sorted)" << endl << endl;
            }
            else{
                outStream << "(Not Sorted)" << endl << endl;
            }
        }
    }
    outStream.close();
    return 0;
}