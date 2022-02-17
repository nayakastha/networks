#include<iostream>
#include<math.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
using namespace std;

int k = 1, Time[10], curr_time = 1, sent[10], ready[10], in[10], i1 = 0, ct = 0, coll = 0, s = 0;
int pA_cpt = 0, sA_cpt = 0; //completion times for pure Aloha and slotted Aloha respectively

//function to implement pure Aloha
void pureAloha(int n) {
  
  int i;
  cout << "The Frame time assumed is 2 seconds\n\n";
  
  for(i = 0; i < n; i++) {
	Time[i] = (rand()%10+1);
	sent[i] = 0;  
	ready[i] = 0;
	cout << "Sender Station " << i+1 << " will send frame at t = " << Time[i] << "seconds.\n";
  }
  while(s == 0) {
  
  	for(i = 0; i < n; i++) {
		if(curr_time == Time[i] && sent[i] == 0)
			ready[i] = 1;
  	}
  
  	for(i = 0; i < n; i++) {
	
		if(ready[i] == 1 && ct == 0) {
		
			ct = 1;
			in[i1] = i;
			i1++;
		}
	 
		else if(ready[i] == 1 && ct == 1) {
		
			coll = 1;
			in[i1] = i;
			i1++;
		}
  	}
  	for(i = 0; i < n; i++) {
	
		if(Time[i] == curr_time+1 && sent[i] == 0 && ct == 1) {
		
			in[i1] = i;
			i1++;
			coll = 1;
		}
  	}
  
  	if(coll == 1) {
		cout << "Collision Occured at senders\n";
  
  		for(i = 0; i <= i1-1; i++) {
    
			Time[in[i]] = Time[in[i]] + k;
    		cout <<"\t" << in[i] + 1;
    		k = k*2;
  		}
  	
		if(i1 > 1)
			cout << "\nThe new time for the collided senders are:\n";
  
  		for(i = 0; i <= i1-1; i++) {
	
			cout << "Sender Station" << in[i]+1 << " -> " << Time[in[i]] << "\n";
  		}
  	}
  
  	if(coll != 1 && ct == 1) {
	
		sent[in[i1-1]] = 1;
		cout << "Sender Station" << in[i1-1]+1 << " has sent the packet\n\n";
		s = 1;
  	}
  	
	for(i = 0; i < n; i++) {
	
		if(sent[i] == 0)
			s = 0;
  	}
 	curr_time++;
  
 	for(i = 0; i < n; i++)
		ready[i] = 0;
  
  	ct = 0;
  	coll = 0;
  	i1 = 0;
 	}
  
  	//total completion time 
  	for(i = 0; i < n; i++)
  		pA_cpt = max(pA_cpt, Time[i]);
}

//function to implement slotted Aloha protocol
void slottedAloha(int n) {
  
  int i;
  cout <<"The Frame time assumed is 1 second\n\n";
  
  for(i = 0; i < n; i++) {
	
	Time[i] = (rand()%10+1);
	sent[i] = 0;  
	ready[i] = 0;
	cout << "Sender Station" << i+1 << " will send the frame at t = " << Time[i] << "seconds.\n";
  }
  while(s == 0) {
  	for(i = 0; i < n; i++) {
		if(curr_time == Time[i] && sent[i] == 0)
			ready[i] = 1;
  	}
  
  	for(i = 0; i < n; i++) {
		
		if(ready[i] == 1 && ct == 0) {
			ct = 1;
			in[i1] = i;
			i1++;
	 	}
	 	
		else if(ready[i] == 1 && ct == 1) {
			coll = 1;
			in[i1] = i;
			i1++;
	 	}
  	}	
  
  	if(coll == 1) {
	 	cout << "\nCollision Occured at senders\n";
  		for(i = 0; i <= i1-1; i++) {
	 	
			Time[in[i]] = Time[in[i]]+k;
	 		cout << "\t" << in[i]+1;
	 		k = k*2;
  		}
  	
		if(i1 > 1)
	 		cout << "\nThe new time for the collided senders are:\t";
  			for(i = 0; i <= i1-1; i++){
	 
	 			cout << "\nSender Station" << in[i]+1 << " -> " << Time[in[i]];
  		}
  	}
  	
	if(coll != 1 && ct == 1) {
	 	sent[in[i1-1]] = 1;
	 	cout << "\nSender Station" << in[i1-1]+1 << " has sent the packet";
	 	s = 1;
  	}
  	for(i = 0; i < n; i++) {
	 
		if(sent[i] == 0)
			s = 0;
  	}
  
  	curr_time++;
  	for(i = 0; i < n; i++)
		ready[i] = 0;
  
  	ct = 0;
  	coll = 0;
  	i1 = 0;
  }
  
  //total completion time 
  for(i = 0; i < n; i++)
  	sA_cpt = max(sA_cpt, Time[i]);
}

//main function
int main() {
  
  srand(time(0));
  int no_of_senders;
  double g_avg;
  cout << "Enter the # of senders : ";
  cin >> no_of_senders;
  
  cout << "Implementing Pure Aloha protocol:\n";
  pureAloha(no_of_senders);
  cout << "\nG_average : ";
  g_avg = (double)(2*no_of_senders)/pA_cpt;
  cout << g_avg << endl;
  cout << "Throughput achieved by Pure Aloha : " << (double)(g_avg * expf(-2*g_avg)) << endl;
  
  cout << "\nImplementing Slotted Aloha protocol:\n";
  slottedAloha(no_of_senders);
  cout << "\nG_average : ";
  g_avg = (double)no_of_senders/sA_cpt;
  cout << g_avg << endl;
  cout << "Throughput achieved by Slotted Aloha : " << (double)(g_avg * expf(-g_avg)) << endl;
  
  
  cout << "\n-------End of Program-------\n";
  getch();
  return 0;}
  