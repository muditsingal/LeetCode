#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &vec, int s, int e)
{
    int mid = (s+e)/2;

    int i = 0;
    int j = mid+1;
    vector<int> merged;
    
    while(i <= mid && j <= e)
    {
        if(vec[i] <= vec[j]) {
            merged.push_back(vec[i]);
            i++;
        }
            
        else {
            merged.push_back(vec[j]);
            j++;
        }
    }
    while(i <= mid)
    {
        merged.push_back(vec[i]);
        i++;
    }
    while(j <= e)
    {
        merged.push_back(vec[j]);
        j++;
    }
    for(i = 0; i <= e; i++)
        vec[i] = merged[i];
}

void merge_sort(vector<int> &vec, int s, int e)
{
    if(s >= e)
        return;
        
    int mid = (s+e)/2;
    
    merge_sort(vec, s, mid);
    merge_sort(vec, mid+1, e);
    
    merge(vec, s, e);
}

int main() {
    vector<int> v1 = {22, 51, 11, 3, 4, 89, 66, 2, 27, 77, 62};
    merge_sort(v1, 0, v1.size()-1);
    
    for(auto &elem : v1)
        cout << elem << " ";
    cout << "\n";

    return 0;
}