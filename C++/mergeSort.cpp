#include <iostream>
#include <vector>
#include <algorithm> 
#include <iterator> 
using namespace std;

int main(){
vector<int> merge(vector<int> left, vector<int> right);
vector<int> mergeSort(vector<int> arr) ;
vector<int> arr{99,32,32,6,1,2,9,3,23,9,9,9};

vector<int> sorted ; 
sorted = mergeSort(arr) ;
   for (int i=0; i<sorted.size(); i++) 
       cout << sorted[i] << " "; 

}





vector<int> merge(vector<int> left, vector<int> right) { 
    vector<int> mergedArr ;
    for(int i = 0 , j = 0 ; i < left.size() || j < right.size();) {
        if(i < left.size() && j < right.size()) {
            if(left[i]<right[j]) {
                mergedArr.push_back(left[i]);
                i++;
            } 
            else {
                mergedArr.push_back(right[j]);
                j++;
            }
        } 
        
        else if(i>=left.size()) {
            for(int l = j ; l < right.size();l++) {
                mergedArr.push_back(right[l]);
                j++;
            }
        } 

        else if(j>=right.size()){
            for(int l = i ; l < left.size();l++) {
                mergedArr.push_back(left[l]) ;
                 i++;
            }
        }
    } 

    return mergedArr ; 
} 


vector<int> mergeSort(vector<int> arr) {
    if(arr.size()<=1) {
        return arr ;
    } 

    int mid = arr.size()/2 ; 
    
    //C++ Equivalent to using js Slices
    vector<int> lefthalf(arr.begin(),arr.begin()+mid);
    vector<int> righthalf(arr.begin()+mid,arr.begin()+arr.size());
    lefthalf = mergeSort(lefthalf);
    righthalf = mergeSort(righthalf); 

    return merge(lefthalf,righthalf) ; 

}