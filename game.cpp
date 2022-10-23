#include <bits/stdc++.h>
using namespace std;


int throwTheBall(vector<int> receiver, long seconds) {
    vector<int> pattern;
    unordered_set<int> seen;
    int curr = 0;
    seen.insert(curr);
    pattern.push_back(curr+1);
    while(true) {
        curr = receiver[curr] - 1;
        if (seen.find(curr) != seen.end()) {
            pattern.push_back(curr+1);
            break;
        }
        pattern.push_back(curr+1);
        seen.insert(curr);
    }
    int start = 0;
    while(pattern[start] != pattern.back()) {
        start++;
    }
    int non_repeating_length = start;
    int repeating_length = pattern.size() - start - 1;
    //now you can make the repeating part of the sequence and non repeating part of the sequence and answer the value accordingly
    return 0;
}

int main() {
    vector<int> receiver{ 2,4,1,2,3 };
    cout<<throwTheBall(receiver, 6)<<endl;
    return 0;
}