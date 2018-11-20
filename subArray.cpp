#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <climits>

#define N 10

using namespace std;


int maxSubArray3(int a[], int n){ //Time Complexity O(n^#)
    
    int ans = INT_MIN;
    for(int sub_array_size = 1;sub_array_size<=n;sub_array_size++){
        for(int start_index = 0; start_index < n;start_index++){
            if(start_index + sub_array_size > 0)
                break;
            int sum = 0;
            for(int i = start_index; i < (start_index + sub_array_size);i++)
                sum = sum + a[i];
            ans = max(ans,sum);
        }
    }

    return ans;


}//end of maxSubArray


int maxSubArray2(int a[], int n){ //Time complexity O(n^2)
    int ans = INT_MIN;

    for(int start_index = 0; start_index < n; start_index++){
        int sum = 0;
        cout << " current start_index :" << start_index << endl;
        for(int sub_array_size = 1;sub_array_size <= n; sub_array_size++){
            if(start_index + sub_array_size > n)
                break;
            sum = a[start_index + sub_array_size -1];
            ans = max(ans,sum);
        }
    }

    return ans;

}





















int main(){

    int a[N];

    
    srand(time(NULL));
    


        for(int i=0;i<N;i++){
            
            a[i] = rand() % 200 - 100;
        
         }

        cout <<"Array a : " <<endl;
          for(int i=0;i<N;i++){
            cout<< a[i] << " ";
        }

        cout << endl;
    
        
        cout<<"Time Complexity O(n^3)" <<endl;
        cout<<maxSubArray3(a,N)<<"\n";
        cout << endl;
        cout << endl;

        cout<< "Time Complexity O(n^2)" <<endl;
        cout<<maxSubArray2(a,N)<<"\n";
        
        
        
        
        
        
        
        
        /*

        //cout <<"sum " << sumArray(a,N) << endl;

        cout << "Sorted :" << endl;
        cout << SortArray(a,N) ;
        cout << endl;
        */
     
    

}//end main