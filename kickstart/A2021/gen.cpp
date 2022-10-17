#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1])+21); // atoi(s) converts an array of chars to int
  cout<<1<<endl;
	int r=rand(1,3);
	int c=rand(1,3);
	cout<<r<<" "<<c<<endl;
    for(int i=0;i<r;i++)
    {
		for(int j=0;j<c;j++){
			int p=rand(0,5);
			cout<<p<<" ";
		}
		cout<<endl;
	}
}
