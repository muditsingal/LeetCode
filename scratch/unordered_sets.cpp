#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> us1;
    unordered_set<string> ss;
    unordered_set<char> usc;

    us1.insert(5);
    us1.insert(50);
    us1.insert(2);
    us1.insert(69);
    us1.insert(6);
    us1.insert(15);
    us1.insert(15);
    us1.insert(15);

    ss.insert("hello");
    ss.insert("dont");
    ss.insert("dont");
    ss.insert("dont");
    ss.insert("dont");
    ss.insert("know");
    ss.insert("WWbc");
    ss.insert("Works");
    ss.insert("just");
    ss.insert("random");


    for(unordered_set<int>::iterator it = us1.begin(); it != us1.end(); it++)
    {
        cout << *it << " ";
    }
    if(us1.find(533) != us1.end())
        cout << "Element found!" << endl;
    
    ss.erase("dont");
    cout << ss.count("dont");


    return 0;
}

