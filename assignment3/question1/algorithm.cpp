#include<iostream>
#include<unistd.h>
 
using namespace std;
 
int main()
{
    int w,i,f,frames[50];
    cout<<"One-Bit Sliding Window Protocol Simuation\n"<<endl;
    
    //window size = 1;
    w = 1;
 
    cout<<"Enter number of frames to transmit : ";
    cin>>f;
 
    cout<<"Enter "<<f<<" frames : ";
 
    for(i=0;i<f;i++)
        cin>>frames[i];
 
    cout<<"\nWith sliding window protocol the frames will be sent in the following manner (assuming no corruption of frames)"<<endl;
    cout<<"After sending "<<w<<" bit at each stage sender waits for acknowledgement sent by the receiver\n\n";
 
    int receiver[50];
    int i = 0;
    while(i<f)
    {       
            int choice = rand();
            //for simulating failure of frame
            if(choice%1101 != 0)
              receiver[i] = frames[i];
    
            unsigned int microsecond = 1000000;
            usleep(3 * microsecond);
            
            if(receiver[i] == frames[i]){
              cout<<"Acknowledgement of \""<<frames[i]<<"\" is received by sender"<<endl;
              cout<<"Received Frames - ";
              for(int j=0; j<=i; j++ )
              cout<<receiver[j]<<" ";
              cout<<endl<<endl;
              i++;
            }else{
              cout<<"Bit \""<<frames[i]<<"\" is corrupted"<<endl;
              cout<<"Received Frames - ";
              for(int j=0; j<=i; j++ )
              cout<<receiver[j]<<" ";
              cout<<endl<<endl;
            }
       
    }
 
    return 0;
}