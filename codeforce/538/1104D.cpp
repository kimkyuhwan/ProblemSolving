#include <iostream>
#include <string>
using namespace std;
#define START_NUMBER_A 500000001
#define START_NUMBER_B 500000000
string str;
int l=1,r=1000000000;
int main(){
	int a=START_NUMBER_A,b=START_NUMBER_B,ans=2; // 1 ~ 10^9 5*10^8 5*10^8+1 , 5*10^8
	while(cin>>str){
		if(str=="start"){
			a=START_NUMBER_A,b=START_NUMBER_B;
			while(l!=r){
				int m = (l+r)/2;
				cout<<"? "<<m<<" "<<m+1<<endl;
				cin>>str;
				if(str=="y"){ // R range
					l=m+1;
				}
				else if(str=="x"){
					r=m;
				}
				else if(str=="e"){
					return 0;
				}
			}
			cout<<"! "<<a<<" "<<b<<endl;
		}
		else if(str=="end" || str=="mistake"){
			return 0;
		}
	}
}