#include <hanoi.h>

int main() 
{
  int n;
  cout << "Enter number of discs: ";
  cin >> n;
  
  Hanoi * hanoi;

  try { 
    hanoi = new Hanoi(n);
  }
  catch (const invalid_argument & exc) {
    cout << exc.what() << '\n';
    return -1;
  }
  cout << "Do you want automatic mode? (y/n): ";
  char c;
  cin >> c;
  cin.ignore();
  cout << '\n';

  if (tolower(c) == 'y') 
    hanoi -> solve();
  
  else if (tolower(c) == 'n')  {
    int count = 0;
    while (not hanoi -> areMovedAllDiscs()) {
      hanoi -> print();
      try {
        hanoi -> move();
      }
      catch(const invalid_argument & exc) {
        cout << exc.what() << '\n';
        continue;
      }
      count++;
    }
    hanoi -> print();
    cout << "Steps: " << count << ' ' << "Expected: " << (1ll << hanoi -> size()) - 1 << '\n';
  }
  cout << "Done!" << '\n'; 
  return 0;
}