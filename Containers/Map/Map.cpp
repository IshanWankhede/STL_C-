#include <iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main()
{
    //========================================================
    // 1. Creating Maps
    //========================================================

    map<string, string> mp;                     // Ordered Map
    unordered_map<string, string> ump;          // Unordered Map

    //========================================================
    // 2. Insertion
    //========================================================

    ump["in"] = "India";
    ump["us"] = "United States";

    ump.insert(make_pair("uk", "United Kingdom"));

    pair<string, string> p;
    p.first = "br";
    p.second = "Brazil";

    ump.insert(p);

    cout << "After Insertion" << endl;

    for(auto x : ump)
    {
        cout << x.first << " -> " << x.second << endl;
    }

    cout << "\n";


    //========================================================
    // 3. size()
    //========================================================

    cout << "Size : " << ump.size() << endl;

    cout << "\n";


    //========================================================
    // 4. empty()
    //========================================================

    if(ump.empty())
        cout << "Map is Empty" << endl;
    else
        cout << "Map is NOT Empty" << endl;

    cout << "\n";


    //========================================================
    // 5. Accessing Elements
    //========================================================

    cout << "Using [] : " << ump["in"] << endl;

    cout << "Using at() : " << ump.at("uk") << endl;

    cout << "\n";


    //========================================================
    // 6. Updating Value
    //========================================================

    ump["in"] = "Bharat";

    cout << "Updated Value : "
         << ump["in"] << endl;

    cout << "\n";


    //========================================================
    // 7. find()
    //========================================================

    if(ump.find("us") != ump.end())
        cout << "Key Found" << endl;
    else
        cout << "Key Not Found" << endl;

    cout << "\n";


    //========================================================
    // 8. count()
    //========================================================

    cout << "Count of Key 'br' : "
         << ump.count("br") << endl;

    cout << "Count of Key 'jp' : "
         << ump.count("jp") << endl;

    cout << "\n";


    //========================================================
    // 9. erase()
    //========================================================

    ump.erase("uk");

    cout << "After erase()" << endl;

    for(auto x : ump)
    {
        cout << x.first << " -> "
             << x.second << endl;
    }

    cout << "\n";


    //========================================================
    // 10. Iterator Traversal
    //========================================================

    cout << "Iterator Traversal" << endl;

    unordered_map<string,string>::iterator it;

    for(it = ump.begin(); it != ump.end(); it++)
    {
        cout << it->first
             << " -> "
             << it->second << endl;
    }

    cout << "\n";


    //========================================================
    // 11. Range Based Loop
    //========================================================

    cout << "Range Based Loop" << endl;

    for(auto x : ump)
    {
        cout << x.first
             << " -> "
             << x.second << endl;
    }

    cout << "\n";


    //========================================================
    // 12. swap()
    //========================================================

    unordered_map<string,string> country1;
    country1["A"] = "Apple";
    country1["B"] = "Ball";

    unordered_map<string,string> country2;
    country2["X"] = "Xray";
    country2["Y"] = "Yak";

    country1.swap(country2);

    cout << "After swap()" << endl;

    for(auto x : country1)
        cout << x.first << " -> "
             << x.second << endl;

    cout << "\n";


    //========================================================
    // 13. clear()
    //========================================================

    ump.clear();

    cout << "After clear()" << endl;

    cout << "Size : "
         << ump.size() << endl;

    if(ump.empty())
        cout << "Map is Empty" << endl;
    else
        cout << "Map is NOT Empty" << endl;

    return 0;
}