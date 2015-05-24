#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class MSDradix
{
public:
    MSDradix():th(100){}
    MSDradix(int threshold):th(threshold){}
    void sort(vector<string>& a)
    {
        if(a.empty()) return;
        vector<string> aux(a.size());
        sort(a, aux, 0, a.size()-1, 0);
    }

    void sort(vector<string>& a, vector<string>& aux, int start, int end, int d)
    {
        if(start>=end) return;          

        // stwich to insertion sort if the size is too small 
        if((end-start+1)<th)
        {
            for(int i = start; i <end; i++) 
                for(int j = i+1; j>start && (a[j].substr(d)<a[j-1].substr(d)); j--)
                    swap(a[j],a[j-1]);
            return; 
        }
        
        int R = 257;
        vector<int> count(R+1);
        for(int i = start; i <= end; i++)
            count[(d==a[i].size())?1:(a[i][d]+2)]++; 
        for(int i = 0; i < R; i++)
            count[i+1]+=count[i];
        for(int i = start; i <= end; i++)
            aux[start + count[(d==a[i].size())?0:(a[i][d]+1)]++] = a[i];
        copy(aux.begin()+start,aux.begin()+end+1,a.begin()+start);
        
        for(int i = 0; i < R-1; i++)
            sort(a,aux,start+count[i],start+count[i+1]-1,d+1);
    }
private:
    int th;
};

int main()
{
    vector<string> a = {"itpw9",",vnq@","=5)=c","bdci","","~id0","~","bdc","4lvd","a0c-","a1",",vnp","=5)=a","bdc@","itp","4l","4lv"};    
    vector<string> b = a;
    for(const string& s: a)
        cout<<s<<" ";
    cout<<endl;

    MSDradix msdradix;  
    msdradix.sort(a);
    std::sort(b.begin(),b.end());
    for(const string& s: a)
        cout<<s<<" ";
    cout<<endl;
    for(const string& s: b)
        cout<<s<<" ";
    cout<<endl;

}
