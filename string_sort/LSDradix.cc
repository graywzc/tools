#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


class LSDradix
{
public:
    void sort(vector<string>& a, int W)
    {
        int R = 256; 
        int N = a.size();
        vector<string> aux(N);
        for(int d = W-1; d>=0; d--)
        {
            vector<int> count(R+1);
            for(const string& s: a)    
                count[s[d]+1]++;
            for(int i = 0; i < R; i++)
                count[i+1] += count[i];
            for(const string& s: a)
                aux[count[s[d]]++] = s;  
            copy(aux.begin(),aux.end(),a.begin());
        }
    }
};

int main()
{
    vector<string> a = {"abcd","fesc","fhju","gbcs","nowx","sert","jfie","xopw","owpx","jemq"};
    vector<string> b = a;

    for(const string& s: a) 
        cout<<s<<" ";
    cout<<endl;

    LSDradix lsdradix;
    lsdradix.sort(a,4);
    for(const string& s: a) 
        cout<<s<<" ";
    cout<<endl;
    std::sort(b.begin(),b.end());
    for(const string& s: b) 
        cout<<s<<" ";
    cout<<endl;

}
