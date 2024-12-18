#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main()
{
    set<int> s1;
    set<string> ss;
    set<char> sc;
    set<vector<int>> sints;
    cout << "Is s1 empty: " << s1.empty() << endl;
    s1.insert(6);
    s1.insert(2);
    s1.insert(9);
    s1.insert(19);
    s1.insert(19);
    s1.insert(19);
    s1.insert(32);
    s1.insert(61);
    s1.insert(57);
    s1.insert(65);
    s1.insert(26);

    ss.insert("hello");
    ss.insert("dont");
    ss.insert("know");
    ss.insert("WWbc");
    ss.insert("Works");
    ss.insert("just");
    ss.insert("random");

    sc.insert('h');
    sc.insert('a');
    sc.insert('6');
    sc.insert('j');
    sc.insert('q');
    sc.insert('z');
    sc.insert('A');
    sc.insert('H');

    sints.insert({7,3,8,9});
    sints.insert({7,2,2,9});
    sints.insert({2,8,1,3});
    sints.insert({4,3,1,8});
    sints.insert({5,5,3,6});
    sints.insert({6,5,4,7});



    cout << "Is s1 empty: " << s1.empty() << endl;
    cout << "S1 using auto element : " << endl;

    for(auto& elem : s1)
        cout << elem << " ";

    cout << endl;

    cout << "SS using iterator : " << endl;
    for(set<char>::iterator it = sc.begin(); it != sc.end(); it++)
        cout << *it << " ";

    cout << endl;
    cout << "Current size of s1: " << s1.size() << endl;

    return 0;
}

