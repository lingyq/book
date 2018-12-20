#include <iostream>  
#include <string>  
using namespace std;

int main(void)
{
	cout<<"\033[43;35;5mabc\033[0m"<<endl;
	cout<<"\33[43m\33[35m\33[5mabc\33[0m"<<endl;
	cout<<"\033[1m\33[7m"<<" abc "<<"\033[0m"<<endl;
	return 0;
}