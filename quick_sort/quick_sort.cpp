#include <iostream>
#include <vector>

using namespace std;

int pivot(vector<int> &vec, int s, int e)
{
    int p = s;
    int i, j = e;
    for(i = s+1; i <= e; i++)
        if(vec[i] <= vec[s])
            p += 1;
            
    swap(vec[s], vec[p]);
    i = 0;
    j = e;
    while(i < j)
    {
        if(vec[i] > vec[p] && vec[j] < vec[p])
        {
            swap(vec[i], vec[j]);
            i++;
            j--;
            continue;
        }
        if(vec[i] <= vec[p])
            i++;
        if(vec[j] > vec[p])
            j--;
    }
    return p;
}

void quick_sort(vector<int> &vec, int s, int e)
{
    if(s >= e)
        return;
        
    //place the pivot element to the right position
    int p = pivot(vec, s, e);
    
    //quick sort the left half
    quick_sort(vec, s, p - 1);
    
    //quick sort the right half
    quick_sort(vec, p + 1, e);
}

int main() {
    vector<int> v1 = {54, 23, 21, 56, 7, 89, 68, 11, 13, 3, 77};
    for(auto &elem: v1)
        cout << elem << " ";
        
    cout << "\n";
    
    quick_sort(v1, 0, v1.size() - 1);
    
    for(auto &elem: v1)
        cout << elem << " ";
        
    cout << "\n";

    return 0;
}