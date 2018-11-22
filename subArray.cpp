#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <climits>

#define N 10

using namespace std;


int maxSubArray3(int a[],int n)	{	//Overall Time Complexity O(n^3)

	int ans = INT_MIN;							// #include<climits>
	for(int sub_array_size = 1;sub_array_size <= n; ++sub_array_size)		//O(n)
	{
		for(int start_index = 0;start_index < n; ++start_index)				//O(n)
		{
			if(start_index+sub_array_size > n)	//Subarray exceeds array bounds
				break;
			int sum = 0;
			for(int i = start_index; i < (start_index+sub_array_size); i++)	//O(n)
				sum+= a[i];
			ans = max(ans,sum);
		}
	}
	return ans;
}



int maxSubArray2(int a[],int n){	//Overall Time Complexity O(n^2)

	int ans = INT_MIN;
	for(int start_index = 0;start_index < n; ++start_index)					//O(n)		
	{
		int sum = 0;
		for(int sub_array_size = 1;sub_array_size <= n; ++sub_array_size)	//O(n)	
		{
			if(start_index+sub_array_size > n)	//Subarray exceeds array bounds
				break;
			sum+= a[start_index + sub_array_size - 1];	//Last element of the new Subarray
			ans = max(ans,sum);
		}
	}
	return ans;
}

int maxSubArrayN(int a[],int n){	//Overall Time Complexity O(n)

	int ans = a[0],sum = 0;
	for(int i = 1;i < n; ++i)	//Check if all are negative
		ans = max(ans,a[i]);	
	if(ans<0)					//if Max < 0 return Max
		return ans;
	ans = 0;
	for(int i = 0 ;i < n; ++i)
	{
		if(sum + a[i] > 0)
			sum+=a[i];
		else
			sum  = 0;
		ans = max(ans,sum);	
	}
	return ans;
}


int maxSubArrayLogN(int a[],int n)	
{
	if(n==1)
	{
		return a[0];
	}
	int m = n/2;
	int left_MSS = maxSubArrayLogN(a,m);
	int right_MSS = maxSubArrayLogN(a+m,n-m);
	int leftsum = INT_MIN, rightsum = INT_MIN, sum=0;
	for(int i=m;i < n; i++)
	{
		sum += a[i];
		rightsum = max(rightsum,sum);
	}
	sum = 0;
	for(int i= (m-1);i >= 0; i--)
	{
		sum += a[i];
		leftsum = max(leftsum,sum);
	}
	int ans = max(left_MSS,right_MSS);
	return max(ans,leftsum+rightsum);
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
        cout << endl;
        cout << endl;
    
        
        cout<<"Time Complexity O(n^3)" <<endl;
        cout<<maxSubArray3(a,N)<<"\n";
        cout << endl;
        cout << endl;

        cout<< "Time Complexity O(n^2)" <<endl;
        cout<<maxSubArray2(a,N)<<"\n";
        cout << endl;
        cout << endl;


        cout<<"Time Complexity O(n)" <<endl;
        cout<<maxSubArrayN(a,N)<<"\n";
        cout << endl;
        cout << endl;

        cout<<"Time Complexity O(logn)" <<endl;
        cout<<maxSubArrayLogN(a,N)<<"\n";
        cout << endl;
        cout << endl;
        
    
}//end main