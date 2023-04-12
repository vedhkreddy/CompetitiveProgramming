#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
using namespace std;
#define pq priority_queue

struct cow {
  int seniority, arrival, time;
  friend bool operator < (const cow& c1, const cow&c2) {
	return (c1.seniority > c2.seniority);
  }
} ;

bool cmp (cow c1, cow c2)
{
  return (c1.arrival < c2.arrival);
}

int main ()
{
  ifstream cin("convention2.in");
  ofstream cout("convention2.out");

  int N;
  cin >> N;
  cow cows[N];
  for (int i=0; i<N; i++) {
	cin >> cows[i].arrival >> cows[i].time;
	cows[i].seniority = i;
  }
  sort (cows, cows+N, cmp);

  int t = 0;
  int cur = 0;
  int ans = 0;
  pq<cow> waiting;
  while ((cur < N)||(!waiting.empty())) {
	if ((cur < N) && (cows[cur].arrival < t))
	{
	  waiting.push (cows[cur]);
	  cur++;
	}
	else if (!waiting.empty())
	{
	  cow next_cow = waiting.top();
	  ans = max (t - next_cow.arrival, ans);
	  t += next_cow.time;
	  waiting.pop();
	}
	else
	{
	  t = cows[cur].arrival + cows[cur].time;
	  cur++;
	}
  }

  cout << ans;
}
