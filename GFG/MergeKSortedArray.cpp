/*
TC is O(NlogN) where N is total number of elements in all arrays and logN is for merge sort because we are sorting N elements
SC is O(N) for storing all elements in a single array
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    void mer(vector<int> &arr, int start, int mid, int end){
        int n1 = mid - start + 1;
        int n2 = end - mid;

        vector<int> left(n1), right(n2);

        for(int i = 0; i < n1; i++)
            left[i] = arr[start + i];

        for(int j = 0; j < n2; j++)
            right[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = start;

        while(i < n1 && j < n2){
            if(left[i] <= right[j])
                arr[k++] = left[i++];
            else
                arr[k++] = right[j++];
        }

        while(i < n1)
            arr[k++] = left[i++];

        while(j < n2)
            arr[k++] = right[j++];
    }

    void mergesort(vector<int> &arr, int start, int end){
        if(start >= end)
            return;

        int mid = start + (end - start) / 2;

        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        mer(arr, start, mid, end);
    }

    vector<int> mergeArrays(vector<vector<int>> &mat) {
        vector<int> result;

        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[i].size(); j++){
                result.push_back(mat[i][j]);
            }
        }

        mergesort(result, 0, result.size() - 1);
        return result;
    }
};
