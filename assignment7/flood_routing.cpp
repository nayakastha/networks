#include <bits/stdc++.h>

using namespace std;

/*hopCount function will decide the life time for frame to live in network*/
int hopCount(int m[10][10], int n){
        int h=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                h += m[i][j];
            }
        }
        h -= n;
        h = ((h % 2) == 0) ? ( h/2 ):( h/2+1 );
        return h;
}

/*this function show the network in matrix form which you entered*/
void showNetworkMatrix(int m[10][10], int n){
        cout<<"\n\nNetwork Matrix 1st row and colomn showing nodes(or hops) id\n\n";
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 && j==0)
                    cout<<"nodes-   ";
                else if(j==0)
                    cout<<m[i][j]<<"        ";
                else 
                    cout<<m[i][j]<<"    ";
            }
            cout<<endl;
        }
}

void check(int m[10][10], int n, int ps, int s, int d, int h){ 
     //m-network matrix 
     //n-number of nodes 
     //ps - denoted previous node
     //s-new source node 
     //d- destination node
     //h- time remain to live in network
        int i = s;
        if(h==0||s==d)
            return;
        for(int j=1;j<=n;j++){
            if(m[i][j]==1&&j!=i&&j!=ps) 
                cout<<j<<"    ";
        }
        cout<<"\n\n";
        for(int j=1;j<=n;j++){
            if(m[i][j] == 1 && j != i && j != ps) 
                check(m, n, s, j, d, (h-1));
        }
}

void FloodAlgo(int m[10][10], int n, int s, int d, int h){
        cout<<"\n\n"<<s<<"\n\n";
        check(m, n, 0, s, d, h); 
        //check function search the next node and repeat till it not got the destination address or hopcount will become zero;
}


int main()
{
        cout<<"Enter Number of nodes in network:    ";
        int n;
        cin>>n;
        /*1 stands for a connection and 0 stands for not connection between two nodes */
        cout<<"Enter the network Matrix    with(0 and 1):"<<endl;
        int network[10][10];
        
        /*first row and colmn contains nodes(hops) number starting from 1 to n */
        for(int i=1;i<=n;i++){
            network[0][i]=i;
            network[i][0]=i;
        }
        /*this is matrix containing the inmforation about connection between hops*/
        for(int i=1;i<=n;i++){
            cout<<"Row no: "<<i<<endl;
            for(int j=1;j<=n;j++){
                cout<<"Column no:"<<j<<":   ";
                int c;
                cin>>c;
                if(c==0||c==1)    
                    network[i][j] = c;
                else {
                    cout<<"You entered Other than 0 or 1.\n Enter again.";
                    j -= 1;
                }
            }
        }
        showNetworkMatrix(network,n);
        int h = hopCount(network,n);
        cout<<"Maximum Life of frame : "<<h<<endl;
        int c;
        do{
            cout<<" Enter the source node id : ";
            cin>>c;
            if(c==0||c>n)
                cout<<"Entered wrong id number not available in network.try again.\n Re";
       
        }while(c==0||c>n);
        int s=c; //source node id variable
        do{
            cout<<" Enter the destination node id : ";
            cin>>c;
            if(c==0||c>n)
                cout<<"Entered wrong id number not available in network.try again.\n Re";
       
        }while(c==0||c>n);
        int d = c; //destination node id variable
        FloodAlgo(network,n,s,d,h);
        return 0;
    }

 
