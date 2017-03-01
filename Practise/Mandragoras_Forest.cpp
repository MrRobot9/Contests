#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;




long calculate(vector<unsigned long> sequence,long n){
    long long exp = sequence[n-1]*(n),temp;
    long str =n-2;
    temp = sequence[n-1];
     while(str>=0){
         temp += sequence[str];
         exp= max(exp,temp*(str+1));
         if(temp*(str+1)<exp){
             break;
         }
         str --;
}
    return exp;
}

inline
void use_io_optimizations()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

int main() {
    
    use_io_optimizations();
    
    long t,n;
    cin >> t;
    
    while(t--){
        cin >> n;
       vector<unsigned long> sequence(n);
        
        for (auto& element : sequence)
    {
        cin >> element;
    }
        
        long long result;
        
       sort(sequence.begin(), sequence.end());
       result = calculate(sequence,n);
        
       cout<<result<<endl;
        
        
    }
    return 0;
}
