#include <iostream>
#include <list>
#include <set>
#include <cstring> 
#include <algorithm> 

using namespace std;


void swap(char *a,char *b){
    char temp = *a;
    *a = *b;
    *b = temp;

}



void findNext(char number[], int n){
    int i , j;
    for (i = n -1; i > 0; i--){
        if(number[i] > number[i-1])
            break;
    }
    if(i==0){
        cout << "next number is not possible";
        return;
    }
    int x = number[i-1], smallest = i;
    for(j = i+1; j<n;j++)
        if(number[j]> x && number[j] < number[smallest])
            smallest = j;
    
    swap(&number[smallest], &number[i-1]);
    sort(number + i,number + n);
    cout << "Next number with the same set of digits is " << number <<endl;
    return ;


}





int main(){

    int x;
    cin >> x;
    list<int> digits;
    set<int> adigit;
    int sum = 0;
    while(x){
        int digit = x % 10;
       digits.push_front(digit);
        x /= 10;
        
    }
    

    
    for(auto digit : digits) {
        cout << digit << " " << endl;
         adigit.insert(digit);   
    }
    
    int n = adigit.size();

    cout << "size is " << n << endl;
    
    
    
    return 0;
     



}