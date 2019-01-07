#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <chrono>
#include <unordered_set>
#include <set>

#define N 1000000

using namespace std;
using namespace std::chrono;
int main(){

    //long seed = 4242;
    long seed = time(NULL);
    mt19937 mt(seed);
    uniform_int_distribution<int> dist(0,10000);
    int A[N];
    for(int i=0;i<N;i++){
        A[i] = dist(mt);
       // cout<<A[i]<<endl;

    }

    auto t1 = high_resolution_clock::now();

    vector<int> v;
    for(int i=0;i<N;i++){
        v.push_back(A[i]);
    }
    sort(v.begin(),v.end());

    int c=0;
    for(int i=0;i<N;i++){
        int x = dist(mt);
        bool f = binary_search(v.begin(),v.end(),x);
        if(!f)
            c++;
    

    }
    cout<<"Items not found" << c << endl;
    auto t2 = high_resolution_clock::now();
    cout<<"Elapsed time "<<(t2-t1).count() / 1E9 << endl;




    //set
    auto t3 = high_resolution_clock::now();

    set<int , greater <int> > vSet;

    set<int, greater<int> > :: iterator itr;
    
    for(int i=0;i<N;i++){
        vSet.insert(A[i]);
    }
    

    int d=0;
    for(itr = vSet.begin();itr!= vSet.end();++itr){
       int x = dist(mt);
       for(int i=0;i<N;i++){
            if (vSet.find(x) == vSet.end()) 
                d++;
       }
        
        //cout<< '\t' << *itr;
    }
       
    //cout <<endl;
    //cout<<vSet.size()<<endl;
    cout<<"Items not found : "<< d <<endl;
    auto t4 = high_resolution_clock::now();
    cout<<"Elapsed time "<<(t4-t3).count() / 1E9 << endl;
    





    //unordered_set
    auto t5 = high_resolution_clock::now();
    
    unordered_set<int> mySet;
    for(int i=0;i<N;i++){
        mySet.insert(A[i]);
    }
    int e=0;
    unordered_set<int> :: iterator itr2;
    for(itr2 = mySet.begin();itr2 != mySet.end();itr2++){
        int g = dist(mt);
        for(int i=0;i<N;i++){
            if(mySet.find(g)==mySet.end())
                e++;
        }
            
            //cout<< (*itr2)<<endl;
    }
    
    //cout<<mySet.size()<<endl;

    cout<<"Items not found : "<< e <<endl; 
    auto t6 = high_resolution_clock::now();
    cout<<"Elapsed time "<<(t6-t5).count() / 1E9 << endl;





















}//end main