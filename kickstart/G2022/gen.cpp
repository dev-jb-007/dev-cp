#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1])+21); // atoi(s) converts an array of chars to int
  cout<<1<<endl;
	int n=rand(1,4);
	cout<<n<<endl;
    for(int i=0;i<n;i++)
    {
		int r=rand(1,11);
		cout<<r<<" ";
	}
}
