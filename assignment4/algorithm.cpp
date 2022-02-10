#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>

using namespace std;

#define TOT_FRAMES 50
#define FRAMES_SEND 10

class sel_repeat
{
    private:
        int fr_send_at_instance;
        int arr[TOT_FRAMES];
        int send[FRAMES_SEND];
        int rcvd[FRAMES_SEND];
        char rcvd_ack[FRAMES_SEND];
        int sw;
        int rw;
    public:
        void input();
        void sender(int);
        void receiver(int);
        void case1();
        void case2();
};

void sel_repeat::input()
{
    int n;
    int m;
    int i;
    cout<<"Enter the number of bits in the seuence number : ";
    cin>>n;
    m  =  pow(2,n);
    int t  =  0;
    fr_send_at_instance  =  (m/2);
    for(i = 0; i < TOT_FRAMES; i++)
    {
        arr[i] = t;
        t = (t+1)%m;
    }
    for(i = 0; i < fr_send_at_instance; i++)
    {
        send[i] = arr[i];
        rcvd[i] = arr[i];
        rcvd_ack[i] = 'n';
    }
    rw = sw = fr_send_at_instance;
    sender(m);
}

void sel_repeat::sender(int m)
{
    for(int i = 0;i<fr_send_at_instance;i++)
    {
        if(rcvd_ack[i] == 'n')
        cout<<"SENDER : Frame "<<send[i]<<" is sent\n";
    }
    receiver(m);
}

void sel_repeat::receiver(int m)
{
    time_t t;
    int f;
    int j;
    int f1;
    int a1;
    char ch;
    srand((unsigned)time(&t));
    for(int i = 0;i<fr_send_at_instance;i++)
    {
        if(rcvd_ack[i] == 'n')
        {
            f = rand()%10;
            if(f != 5)
            {
                for(int j = 0;j<fr_send_at_instance;j++)
                if(rcvd[j] == send[i])
                {
                    cout<<"Reciever : Frame "<<rcvd[j]<<" recieved correctly\n";
                    rcvd[j] = arr[rw];
                    rw = (rw+1)%m;
                    break;
                }
                int j;
                if(j == fr_send_at_instance)
                    cout<<"Reciever : Duplicate frame "<<send[i]<<" discarded\n";
                a1 = rand()%5;
                if(a1 == 3)
                {
                    cout<<"(Acknowledgement "<<send[i]<<" lost)\n";
                    cout<<"(Sender timeouts --> Resend the frame)\n";
                    rcvd_ack[i] = 'n';
                }
                else
                {
                    cout<<"(Acknowledgement "<<send[i]<<" recieved)\n";
                    rcvd_ack[i] = 'p';
                }
            }
            else
            {
                int ld = rand()%2;
                if(ld == 0)
                {
                    cout<<"RECEIVER : Frame "<<send[i]<<" is damaged\n";
                    cout<<"RECEIVER : Negative Acknowledgement "<<send[i]<<" sent\n";
                }
                else
                {
                    cout<<"RECEIVER : Frame "<<send[i]<<" is lost\n";	
                    cout<<"(Sender timeouts --> Resend the frame)\n";
                }
                rcvd_ack[i] = 'n';
            }
        }
    }
    for(int j = 0;j<fr_send_at_instance;j++)
    {
        if(rcvd_ack[j] == 'n')
            break;
    }
    int i = 0;
    for(int k = j;k<fr_send_at_instance;k++)
    {	
        send[i] = send[k];	
        if(rcvd_ack[k] == 'n')
            rcvd_ack[i] = 'n';
        else
            rcvd_ack[i] = 'p';
        i++;
    }
    
    if(i != fr_send_at_instance)
    {
        for(int k = i;k<fr_send_at_instance;k++)
        {
            send[k] = arr[sw];
            sw = (sw+1)%m;
            rcvd_ack[k] = 'n';
        }
    }

    cout<<"Want to continue? Yes:y\t No:n\n";
    cin>>ch;
    cout<<"\n";
    if(ch == 'y')
    sender(m);
}


void sel_repeat:: case1()
{
    int n,m,i;
    cout<<"Enter the number of bits in sequence number: ";
    cin>>n;
    m = pow(2,n);
    int t = 0;
    fr_send_at_instance = (m/2);
    for(i = 0;i<TOT_FRAMES;i++)
    {
        arr[i] = t;
        t = (t+1)%m;
    }
    for(i = 0;i<fr_send_at_instance;i++)
    {
        send[i] = arr[i];
        rcvd[i] = arr[i];
        rcvd_ack[i] = 'n';
    }
    rw = sw = fr_send_at_instance;
    for(int i = 0;i<fr_send_at_instance;i++)
    {
        if(rcvd_ack[i] == 'n')
        cout<<"SENDER : Frame "<<send[i]<<" is sent\n";
    }
    time_t ti;
    int f,j,f1,a1;
    char ch;
    srand((unsigned)time(&ti));
    for(int i = 0;i<fr_send_at_instance;i++)
    {
        if(rcvd_ack[i] == 'n')
        {
            f = rand()%10;
            for(int j = 0;j<fr_send_at_instance;j++)
            if(rcvd[j] == send[i])
            {
                cout<<"Reciever : Frame "<<rcvd[j]<<" recieved correctly\n";
                cout<<"(Acknowledgement "<<send[i+1]<<" recieved)\n\n";
                rcvd[j] = arr[rw];
                rw = (rw+1)%m;
                break;
            }
            int j;
            if(j == fr_send_at_instance)
              cout<<"Reciever : Duplicate frame "<<send[i]<<" discarded\n";            
            rcvd_ack[i] = 'p';
        }
    }
}

void sel_repeat:: case2()
{
    int n,m,i;
    cout<<"Enter the number of bits in sequence number : ";
    cin>>n;
    m = pow(2,n);
    int t = 0;
    fr_send_at_instance = (m/2);
    for(i = 0;i<TOT_FRAMES;i++)
    {
        arr[i] = t;
        t = (t+1)%m;
    }
    for(i = 0;i<fr_send_at_instance;i++)
    {
        send[i] = arr[i];
        rcvd[i] = arr[i];
        rcvd_ack[i] = 'n';
    }
    rw = sw = fr_send_at_instance;

    for(int i = 0;i<fr_send_at_instance;i++)
    {
        if(rcvd_ack[i] == 'n')
            cout<<"SENDER : Frame "<<send[i]<<" is sent\n";
    }
        
    time_t ti;
    int f,j,f1,a1;
    char ch;
    srand((unsigned)time(&ti));
    for(int i = 0;i<fr_send_at_instance;i++)
    {
        if(rcvd_ack[i] == 'n')
        {
            f = rand()%10;
            if(f != 5)
            {
                for(int j = 0;j<fr_send_at_instance;j++)
                if(rcvd[j] == send[i])
                {
                    cout<<"Reciever : Frame "<<rcvd[j]<<" recieved correctly\n";
                    rcvd[j] = arr[rw];
                    rw = (rw+1)%m;
                    break;
                }
                int j;
                if(j == fr_send_at_instance)
                    cout<<"Reciever : Duplicate frame "<<send[i]<<" discarded\n";
                a1 = rand()%5;
                if(a1 == 3)
                {
                    cout<<"(Acknowledgement "<<send[i]<<" lost)\n";
                    cout<<"(Sender timeouts --> Resend the frame)\n\n";
                    rcvd_ack[i] = 'n';
                }
                else
                {
                    cout<<"(Acknowledgement "<<send[i]<<" recieved)\n\n";
                    rcvd_ack[i] = 'p';
                }
            }
            else
            {
                int ld = rand()%2;
                if(ld == 0)
                {
                    cout<<"RECEIVER : Frame "<<send[i]<<" is damaged\n";
                    cout<<"RECEIVER : Negative Acknowledgement "<<send[i]<<" sent\n";
                }
                else
                {
                    cout<<"RECEIVER : Frame "<<send[i]<<" is lost\n";	
                    cout<<"(Sender timeouts --> Resend the frame)\n";
                }
                rcvd_ack[i] = 'n';
            }
        }
    }
    for(int j = 0;j<fr_send_at_instance;j++)
    {
        if(rcvd_ack[j] == 'n')
            break;
    }
    i = 0;
    for(int k = j;k<fr_send_at_instance;k++)
    {	
        send[i] = send[k];	
        if(rcvd_ack[k] == 'n')
            rcvd_ack[i] = 'n';
        else
         rcvd_ack[i] = 'p';
        i++;
    }
    if(i != fr_send_at_instance)
    {
        for(int k = i;k<fr_send_at_instance;k++)
        {
            send[k] = arr[sw];
            sw = (sw+1)%m;
            rcvd_ack[k] = 'n';
        }
    }
    cout<<"Want to continue? Yes:y\t No:n\n";
    cin>>ch;
    cout<<"\n";
    if(ch == 'y')
    sender(m);
}

int main()
{
sel_repeat sr;
int a = 1;
while(a<= 2)
   {
    cout<<"1.Print Acknowledgment"<<endl;
    cout<<"2.Print the frame lost and retransmit frames if asked"<<endl;
    cout<<"3.Exit"<<endl;
    cout<<"Enter your choice: ";
    cin>>a;
    switch(a)
    {
    case 1:
     sr.case1();
     break;
    case 2:
     sr.case2();
     break;
    default:
     break;
    }
 }
}