#include <iostream>
#include <vector>
#include <cassert>

// next are not necessary for indexMinPQ
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <climits>
using namespace std;

class indexMinPQ
{
public:
    indexMinPQ(int N)
    :_idx2int(N,-1)
    ,_int2idx(N,-1)
    ,_size(0)
    ,_N(N)
    {
    }
    void insert(int idx, int val)
    {
        assert(idx < _N);
        _idx2int[idx] = _size; 
        _int2idx[_size] = idx;
        _key.push_back(val);
        _size++;
        swim(_size-1);
    }
    void decreaseKey(int idx, int val)
    {
        assert(idx<_N);
        swim(_idx2int[idx]); 
    }

    bool contains(int idx)
    {
        return _idx2int[idx]>=0;
    }

    int delMin()
    {
        assert(!isEmpty());
        if(_size==1)
        {
            return removekey(0);
        }
        else
        {
            swapkey(0,_size-1); 
            int tmp = removekey(_size-1);     
            sink(0);
            return tmp;
        }
    }

    bool isEmpty()
    {
        return _key.empty(); 
    }

    int size()
    {
        return _size;
    }

    int min()
    {
        assert(!isEmpty()); 
        return _key[0];
    }
private:
    indexMinPQ():_N(0){}
    inline int p(int i)
    {
        return (i-1)/2;
    }
    inline int l(int i)
    {
        return i*2 + 1; 
    }
    inline int r(int i)
    {
        return i*2 + 2; 
    }
    int removekey(int i)
    {
        assert(i == _size-1); 
        _idx2int[_int2idx[i]] = -1; 
        int tmp = _int2idx[i];
        _int2idx[i] = -1;
        _key.pop_back();
        _size--;
        return tmp;
    }
    void swapkey(int i, int j)
    {
        swap(_key[j],_key[i]);  
        swap(_idx2int[_int2idx[j]],_idx2int[_int2idx[i]]);
        swap(_int2idx[j],_int2idx[i]); 
    }
    void swim(int i)
    {
        while(i!=0 && _key[p(i)] > _key[i] ) 
        {
            swapkey(i,p(i)); 
            i = p(i);
        }
    }
    void sink(int i)
    {
        while(i <= _size/2-1)    
        {
            int i_min = (_key[i]<_key[l(i)])?i:l(i);
            if(r(i)<_size)
                i_min = (_key[i_min]<_key[r(i)])?i_min:r(i);
            if(i_min != i)
            {
                swapkey(i,i_min);
                i = i_min;
            }
            else
                break;
        }
    }

    vector<int> _key;
    vector<int> _idx2int;
    vector<int> _int2idx;
    int _size;
    const int _N;
};

int main()
{
    cout<<"indexMinPQ testing"<<endl;
    int N = 1000;
    srand(time(NULL));
    indexMinPQ pq(N);
    vector<int> test;
    
    for(int i = 0; i < 100; i++) 
    {
        int idx = rand()%N; 
        int val = rand()*((rand()%2)?1:-1);
        if(!pq.contains(idx))
        {
            cout<<"insert ("<<idx<<","<<val<<")"<<endl;
            pq.insert(idx,val);
            test.push_back(val);
            int vec_min=INT_MAX;
            for(const int test_val: test)
                vec_min = min(vec_min, test_val); 
            if(vec_min != pq.min())
            {
                cout<<"vec_min: "<<vec_min<<endl;
                cout<<"pq.min: "<<pq.min()<<endl;
                return -1; 
            }
            
        }
    }
    cout<<"success"<<endl;
}
