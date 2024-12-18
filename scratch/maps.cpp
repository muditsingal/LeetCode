#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, int> um1;
    um1["sdf"] = 6;
    um1.insert(std::make_pair("y",1));
    
    std::map<std::string, int> m1;
    std::map<std::string, int, std::greater<std::string>> m2;
    std::map<std::vector<int>, int, std::greater<std::vector<int>>> m3;
    std::map<int, int> num_fz;
    num_fz.insert(std::make_pair(2, 55));
    num_fz.insert(std::make_pair(7, 65));
    num_fz.insert(std::make_pair(3, 69));
    num_fz.insert(std::make_pair(5, 73));
    num_fz.insert(std::make_pair(1, 82));

    m1.insert(std::make_pair("jhonson", 55));
    m1.insert(std::make_pair("harish", 65));
    m1.insert(std::make_pair("groot", 69));
    m1.insert(std::make_pair("APle", 541));
    m1.insert(std::make_pair("APLe", 242));
    // std::cout << m1.find("jhonson");

    m3.insert(std::make_pair(std::vector<int>{4,5,6},5));
    m3.insert(std::make_pair(std::vector<int>{1,4,6},7));
    m3.insert(std::make_pair(std::vector<int>{2,2,3},9));
    m3.insert(std::make_pair(std::vector<int>{2,1,3},11));
    // m3.insert(std::make_pair(std::vector<int>{1,4,6},69));
    m3[std::vector<int>{1,4,6}] = 69;
    // m3[std::vector<int>{3,4,1}] = 56;

    // for(auto it = m1.begin(); it != m1.end(); it++)
    // {
    //     m2.insert(std::make_pair(it->first, it->second));
    // }

    
    // for(auto it = num_fz.begin(); it != num_fz.end(); it++)
    // {
    //     std::cout << it->first << " " << it-> second << "\n";
    // }
    // std::cout << "\n" << "\n";

    // for(auto it = m1.begin(); it != m1.end(); it++)
    // {
    //     std::cout << it->first << " " << it-> second << "\n";
    // }
    // std::cout << "\n" << "\n";

    // for(auto it = m2.begin(); it != m2.end(); it++)
    // {
    //     std::cout << it->first << " " << it-> second << "\n";
    // }
    // std::cout << "\n" << "\n";

    for(auto it = m3.begin(); it != m3.end(); it++)
    {
        for(auto& fi : it->first)
            std::cout << fi << " ";
        std::cout << " " << it->second << "\n";
    }


    return 0;
}