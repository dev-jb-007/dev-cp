#include <bits/stdc++.h>
using namespace std;

int rand(int a, int b) { return a + rand() % (b - a + 1); }

int main(int argc, char *argv[]) {
  srand(atoi(argv[1])); // atoi(s) converts an array of chars to int
  
 int n=rand(1,10);
    int k=rand(1,min(50,n));
    cout<<n<<" "<<k<<endl;
    for(int i=0;i<n;i++)
    {
		int hell=rand(1,3);
		if(hell==1)
		{
			cout<<"?";
		}
		else if(hell==2)
		{
			cout<<"1";
		}
		else{
			cout<<"0";
		}
	}
	cout<<endl;
}
