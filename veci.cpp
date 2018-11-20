#include <iostream>
#include <list>
#include <set>

using namespace std;

int main(){

    int x;
    cin >> x;
    list<int> digits;
    set<int> adigit;
    while(x){
        int digit = x % 10;
        digits.push_front(digit);
        x /= 10;
    }
    
    for(auto digit : digits) {
        cout << digit << " " << endl;
         adigit.insert(digit);   
    }

    
       




}