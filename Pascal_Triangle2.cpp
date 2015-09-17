#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int getNum(int x, int y) {
        if (x == 0 || x == y) {
            return 1;
        } else if (x == 1 || x == y-1) {
            return y;
        } else {
            return getNum(x-1, y-1) + getNum(x, y-1);
        }
    }
public:
    vector<int> getRow(int rowIndex) {
        int i;
        vector<int> rv;
        rv.clear();
        for (i = 0; i < rowIndex; i++) {
            rv.push_back(getNum(i, rowIndex));
        }
        
        return rv;
    }
};

int main() {
    Solution obj;
    int n;
    cin>>n;
    vector<int> rv = obj.getRow(n);
    for (int i = 0; i < n; i++)
        cout<<rv[i]<<"\t";
    cout<<endl;
}