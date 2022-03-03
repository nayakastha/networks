/* Program to implement Bit-map protocol in C++ */
#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;


int main() {
 
	int i, N;
	cout << "Enter the number of transmitting stations: ";
	cin >> N;
	int Stn[N];
	bool flag = false;
	char op;
	do {
		cout<<"\nEnter status of stations :\n";
		for (i = 0; i < N; i++) {
    		cout << "Station " << i+1 << " : ";
    		cin >> Stn[i];
		}
		
		//stations having bit 1 in their corresponding slot during contention period will transmit 
		for (i = 0; i < N; i++) {
    		if(Stn[i] == 1) {
        		cout << "\nStation " << i+1 << " is ready to transmit.";
        		flag |= true;
        	}
		}
		if(!flag)
			cout << "No transmitting station available.\n";
		
		flag = false;	
		cout << "\nWant to continue for next contention period ? (Y/N) : ";
		cin >> op;
	}	
	while(op == 'y'|| op == 'Y');
	cout << "------------End of program------------\n";
	getch();
	return 0;
}
