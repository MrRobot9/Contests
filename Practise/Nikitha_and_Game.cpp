#include <cmath> 
#include <cstdio> 
#include <vector> 
#include <iostream> 
#include <algorithm> 
#include <iostream> 
#include <vector>

 using namespace std;

long partition(vector < unsigned long > sequence, long sum) {
  int points = 0;
  long temp = 0, index = 0;
  bool isPart = false;

  for (auto i = sequence.begin(); i != sequence.end(); ++i) {
    index++;
    temp = * i + temp;
    if (((sum / 2) == temp) && sum != 0 && sum != 1) {
      points++;
      isPart = true;
      break;
    }
  }
  if (!isPart) {
    return 0;
  }

  vector < unsigned long > split_lo(sequence.begin(), sequence.begin() + index);
  vector < unsigned long > split_hi(sequence.begin() + index, sequence.end());
  return points + max(partition(split_lo, temp), partition(split_hi, sum - temp));
}

inline
void use_io_optimizations() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
}

int main() {
  use_io_optimizations();

  unsigned int length;
  unsigned long sum = 0;
  int t;

  cin >> t;

  while (t--) {
    cin >> length;
    vector < unsigned long > sequence(length);

    for (auto & element: sequence) {
      cin >> element;
      sum = sum + element;
    }

    if (sum == 0) {
      cout << length - 1;
    } else {
      int p;
      p = partition(sequence, sum);
      cout << p << endl;
      sum = 0;
    }
  }
  return 0;
}
