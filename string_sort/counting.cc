#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template<class T>
class CountingSort
{
public:
    void sort(vector<T>& a, int R)
    {
        if(a.empty()) return;
        vector<int> count(R+1, 0); 
        vector<T> aux(a.size());
        for(const T& i: a)
            count[i+1]++; 
        for(int i = 0; i < R; i++)
            count[i+1] += count[i];
        for(const T& i: a)
            aux[count[i]++]=i;
        copy(aux.begin(), aux.end(), a.begin());
    }
};


int main()
{
    vector<char> a = {'a','b','e','g','v','r','h','j','a','c','x','e','u','i'};
    vector<char> b = a;
    for(const char& c: a)
        cout<<c<<' ';
    cout<<endl;
    CountingSort<char> sort;
    sort.sort(a,256);
    for(const char& c: a)
        cout<<c<<' ';
    cout<<endl;
    std::sort(b.begin(),b.end());
    for(const char& c: b)
        cout<<c<<' ';
    cout<<endl;

}

