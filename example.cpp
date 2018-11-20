#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

#define N 1000000


using namespace std;

bool has_duplicates(int a[], int n){
    int c=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(i==j)
                continue;
            if(a[i]==a[j])
                c++;
        }

    return c/2;


}//end has_duplicates

bool has_duplicates2(int a[], int n){
    int c=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++){
            if(a[i]==a[j])
                c++;
        }

    return c;


}//end has_duplicates2

bool has_duplicates3(int a[], int n){
    sort(a, a+n);
    int c=0;
    for(int i=0;i<n-1;i++){
     if (a[i]==a[i+1])
            c++;
    }
return c;    
    


}//end has_duplicates3



int main(){

    clock_t t1=clock(),t2;
    int a[N];
    srand(time(NULL));
    for(int i=0; i<N; i++){
        a[i] = rand() % 2000000 - 1000000;
    }//end 1st for


    cout << has_duplicates3(a,N) << endl;

    t2=clock();
    cout << "Time " << (double) (t2-t1)/CLOCKS_PER_SEC << endl;



    /*
    for(int i=0; i<N; i++){
        cout<<a[i] << endl;
    }//end 2nd for
    */

}//end of main