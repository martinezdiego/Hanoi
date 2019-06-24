#include <hanoi.h>

Hanoi::Hanoi(int n) 
  : pegs(vector<stack<int>>(3, stack<int>())), height(n)
{
  if (n <= 0) 
    throw invalid_argument("invalid number of discs");

  for (int i = n; i > 0; i--) 
    pegs[0].push(i);  
}

Hanoi::Hanoi(const Hanoi & h)
  : pegs(h.pegs), height(h.height)
{
  // empty
}

Hanoi::Hanoi(Hanoi && h)
  : pegs(std::move(h.pegs)), height(0)
{
  swap(height, h.height);
}

Hanoi & Hanoi::operator = (const Hanoi & h)
{
  if (&h == this)
    return *this;
  
  pegs = h.pegs;
  height = h.height;

  return *this;
}

Hanoi & Hanoi::operator = (Hanoi && h)
{
  swap(pegs, h.pegs);
  swap(height, h.height);

  return *this;
}

int Hanoi::size() const 
{
  return height;
}

bool Hanoi::areMovedAllDiscs() const 
{
  return pegs[2].size() == size();
}

void Hanoi::print()
{
  vector<stack<int>> t = pegs;

  for (int i = size(); i > 0; i--) {
    for (int j = 0; j < 3; j++) {
      if (j) 
        cout << '\t';
      
      if (t[j].empty())
        continue;

      if (t[j].size() == i)
        cout << t[j].top(), t[j].pop();
    }
    cout << '\n';
  }
  for (int j = 0; j < 3; j++) {
    if (j) cout << '\t';
    cout << '_';
  }
  cout << '\n';
  cout << 'A' << '\t' << 'B' << '\t' << 'C';
  cout << "\n\n";
}

void Hanoi::move() 
{ 
  char src, dst;
  
  cout << "from: ";
  cin >> src;

  cout << "to: ";
  cin >> dst;

  if (!isdigit(src) or !isdigit(dst))
      throw invalid_argument("invalid input");

  src -= '0' + 1;
  dst -= '0' + 1;

  if (src < 0 or size() <= src) 
    throw invalid_argument("out of range");

  if (dst < 0  or size() <= dst) 
    throw invalid_argument("out of range");
  

  if (src == dst) 
    throw invalid_argument("invalid range");

  if (pegs[src].empty()) 
    throw invalid_argument("source's peg is empty");

  if (pegs[dst].empty())
    pegs[dst].push(pegs[src].top()), pegs[src].pop();
  
  else {
    if (pegs[dst].top() < pegs[src].top()) 
      throw invalid_argument("destination's top is greater");

    pegs[dst].push(pegs[src].top()), pegs[src].pop();
  }
}

void Hanoi::solve() {
  int n = size(), count = 0;
  print();
  cout << "Steps: " << count << " Remaining: " << (1ll << size()) - 1 - count << "\n";
  cout << "Enter to continue..." << '\n';
  getchar();
  solve(n, 0, 2, 1, count);
}

void Hanoi::solve(int n, int src, int dst, int aux, int & count)
{
  if (n == 1)  {
    count ++;
    pegs[dst].push(pegs[src].top()); 
    pegs[src].pop();
    print();
    cout << "Steps: " << count << " Remaining: " << (1ll << size()) - 1 - count << "\n";
    cout << "Enter to continue..." << '\n';
    getchar();
  }
  else {
    solve(n-1, src, aux, dst, count); 
    solve(1, src, dst, aux, count); 
    solve(n-1, aux, dst, src, count);
  }
}
