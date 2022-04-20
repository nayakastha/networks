#include<bits/stdc++.h>
using namespace std;
#define n 20

queue<int> lb;

int getCurrentCapacity(){
	return lb.size();
}

int getLeakedPacket(){
	int packet = lb.front();
	lb.pop();
	return packet;
}

int main(){
	int number_of_packets;
	cout<<"Enter the number of packets to be transmitted through the network : ";
	cin>>number_of_packets;
	cout<<endl;
	int bucket_size;
	cout<<"Enter the size of your leaky bucket : ";
	cin>>bucket_size;
	cout<<endl;
	
	do{
		if(number_of_packets > 0 && getCurrentCapacity() < bucket_size){
			int input = rand() % 5 + 2;
		    for(int i=0; i<input; i++)
		    	{		    		
					lb.push(rand() % 100);
		    		cout<<lb.back()<<" is pushed into the bucket."<<endl;
				}
		    number_of_packets -= input;
		}
		else if(getCurrentCapacity() >= bucket_size)
			cout<<endl<<"The bucket is full and overflowing.."<<endl;
		cout<<"-----"<<endl;	
		cout<<"the leaky bucket size is : "<<getCurrentCapacity()<<endl;
		cout<<"the leaked packet is : "<<getLeakedPacket()<<endl<<endl;
		
	}while(!lb.empty());
	return 0;
}
