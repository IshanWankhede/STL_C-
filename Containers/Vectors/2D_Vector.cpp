#include<iostream>
#include<vector>
using namespace std;

int main(){

    vector<vector<int> > arr(5, vector<int>(4,0)); 
    // 2d array created 
    // with 5 rows 
    // with 4 columns
    // with intital values of each cell as 0

    int totalRows = arr.size();
    int totalColumns = arr[0].size();

    cout << "Total Rows: " << totalRows << endl;
    cout << "Total Columns: " << totalColumns << endl;
    
    vector<vector<int> > brr(4);

    brr[0] = vector<int>(4);
    brr[1] = vector<int>(2);
    brr[2] = vector<int>(5);
    brr[3] = vector<int>(3);

    int totalRowCount = brr.size();

    // int  totalColumnCount = brr[i].size();

    return 0;
}