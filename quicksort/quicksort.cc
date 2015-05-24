#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T>
class QuickSort{
public:
    void sort(vector<T>& a, int l, int r)
    {
        if(r<=l) return;
        int lt = l, gt = r;

        T pv = a[l];
        int i = l;
        while(i<=gt)
        {
            if(a[i] == pv) 
                i++;
            else if(a[i] < pv)
                swap(a[lt++], a[i++]); 
            else
                swap(a[i],a[gt--]);  
        }

        sort(a,l,lt-1); 
        sort(a,gt+1,r);
    }

    void sort(vector<T>& a) 
    {
        if(a.empty()) return;  

        sort(a,0,a.size()-1); 
    }

};

int main()
{
    vector<int> a= {4,6,8,9,0,5,3,2,4,5,6,7,8,4,5,3,2,5,6,7,8};
    vector<int> b=a;

    QuickSort<int> qs;
    qs.sort(a);

    sort(b.begin(), b.end());

    for(const int n: a)
        cout<<n<<" ";
    cout<<endl;
    for(const int n: b)
        cout<<n<<" ";
    cout<<endl;
}
