#include <bits/stdc++.h>
using namespace std;
 
int findAbosulteMinDiff(int arr[], int n)
{
   sort(arr, arr+n);
   int diff = INT_MAX;
   for (int i=0; i<n-1; i++)
      if (arr[i+1] - arr[i] < diff)
          diff = arr[i+1] - arr[i];
   return diff;
}
 
int main()
{
  int t;
   
    cin >> t;
    int arr[t];
    for(int i=0;i<t;i++){
        cin >> arr[i];
    }
   cout  << findAbosulteMinDiff(arr, t);
   return 0;
}
