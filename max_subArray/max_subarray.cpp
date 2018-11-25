// max subarray problem

#include <climits> // INT_MIN
#include <iostream>
#include <random>
#include <chrono> 

#define N 1000

using namespace std;
using namespace std::chrono;

// O(n^3) (naive implementation)
int max_sub1(int a[], int n) {
  int max = INT_MIN;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int sum = 0;
      for (int k = i; k <= j; k++) {
        sum += a[k];
      }
      if (sum > max) {
        max = sum;
      }
    }
  }
  return max;
}

//O(n^2)
int max_sub2(int a[],int n){
    int ans = INT_MIN;
    for(int i = 0;i < n;i++){
        int sum = 0;
        for(int j = 1; j <=n;j++ ){
            if(i + j > n)
                break;
            sum += a[i + j -1];
            ans = max(ans,sum);

        }
    }
    return ans;
}//end max_sub2


int max_sub3(int a[],int n){	// O(n)

	int ans = a[0],sum = 0;
	for(int i = 1;i < n; ++i)	
		ans = max(ans,a[i]);	
	if(ans<0)				
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





//O(NlogN)
int max_sub4(int a[],int n)	
{
	if(n==1)
	{
		return a[0];
	}
	int m = n/2;
	int left_MSS = max_sub4(a,m);
	int right_MSS = max_sub4(a+m,n-m);
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


int main() {
  random_device device;
  mt19937 generator(device());
  //   mt19937 generator(42); // for reproducible results
  uniform_int_distribution<int> distribution(-10000, 10000);
  int a[N];
  for (int i = 0; i < N; i++) {
    a[i] = distribution(generator);
  }
  cout << "max subarray of " << N << " values" << endl;
 
  auto t1 = high_resolution_clock::now(); 
  cout << "O(n^3):   " << max_sub1(a, N) << endl;
  auto t2 = high_resolution_clock::now();
  auto duration1 = duration_cast<microseconds>(t2-t1).count();
  cout << "Time elapsed: " << duration1 << " microseconds " << duration1/1000000.0 << " seconds" << endl;


  auto t3 = high_resolution_clock::now(); 
  cout << "O(n^2):   " << max_sub2(a, N) << endl;
  auto t4 = high_resolution_clock::now();
  auto duration2 = duration_cast<microseconds>(t4-t3).count();
  cout << "Time elapsed: " << duration2 << " microseconds " << duration2/1000000.0 << " seconds" << endl;
  

  auto t5 = high_resolution_clock::now(); 
  cout << "O(n):   " << max_sub4(a, N) << endl;
  auto t6 = high_resolution_clock::now();
  auto duration3 = duration_cast<microseconds>(t6-t5).count();
  cout << "Time elapsed: " << duration3 << " microseconds " << duration3/1000000.0 << " seconds" << endl;


  auto t7 = high_resolution_clock::now(); 
  cout << "O(nlogN):   " << max_sub3(a, N) << endl;
  auto t8 = high_resolution_clock::now();
  auto duration4 = duration_cast<microseconds>(t8-t7).count();
  cout << "Time elapsed: " << duration4 << " microseconds " << duration4/1000000.0 << " seconds" << endl;
  





}