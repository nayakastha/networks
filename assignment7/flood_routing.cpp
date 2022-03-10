/* Program to simulate routing using Flooding */ 
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;

//packet structure definition
class packet {
    public:
	int ttl, st;
    string path;
};

//function to implement flooding through all lines
void all_path(vector<vector<int> > g, int s, int d, packet p) {
    
    p.path += " -> " + to_string(s);
	if(s == d) {
		
		p.path += " -> _|_"; //reached destination
        cout << p.path << endl;
        return;
    }
    
    if(p.ttl == 0)
        return;
        
    p.ttl -= 1;
    p.st = s;
    
	for(int i = 0; i <= 4; i++)
        if(g[s][i] == 1)
            all_path(g, i, d, p);
        
}

//function to implement flooding through all lines except incoming line used by packet
void all_path_except_source(vector<vector<int> > g, int prev, int s, int d, packet p) {
    
    p.path += " -> " + to_string(s);
	if(s == d) {
		
		p.path += " -> _|_"; //reached destination
        cout << p.path << endl;
        return;
    }
    
    if(p.ttl == 0)
        return;
        
    p.ttl -= 1;
    p.st = s;
    
	for(int i = 0; i <= 4; i++)
        if(g[s][i] == 1 && prev != i)
            all_path_except_source(g, s, i, d, p);
        
}

//function to implement flooding through choosen best k lines
void all_path_best(vector<vector<int> > g, int s, int d, packet p, vector<vector<bool> > b) {
    
    p.path += " -> " + to_string(s);
	if(s == d) {
	
        p.path += " -> _|_"; //reached destination
		cout << p.path << endl;
        return;
    }
    
    if(p.ttl == 0)
        return;
        
    p.ttl -= 1;
    p.st = s;
    
	for(int i = 0; i <= 4; i++)
        if(g[s][i] == 1 && b[s][i])
            all_path_best(g, i, d, p, b);
        
}

//main function
int main() {
    
    cout<<"Enter Number of nodes in network:    ";
    int n;
    cin>>n;
       
    cout<<"Enter the network Matrix    with(0 and 1):"<<endl;
    vector<vector<int> > graph(n+1, vector<int>(n+1,0));
        
        /*first row and colmn contains nodes(hops) number starting from 1 to n */
        for(int i=1;i<=n;i++){
            graph[0][i]=i;
            graph[i][0]=i;
        }
        /*this is matrix containing the inmforation about connection between hops*/
        /*1 stands for a connection and 0 stands for not connection between two nodes */
        for(int i=1;i<=n;i++){
            cout<<"Row no: "<<i<<endl;
            for(int j=1;j<=n;j++){
                cout<<"Column no:"<<j<<":   ";
                int c;
                cin>>c;
                if(c==0||c==1)    
                    graph[i][j] = c;
                else {
                    cout<<"You entered Other than 0 or 1.\n Enter again.";
                    j -= 1;
                }
            }
    }
    
    int i = 0, j = 1;
    while(i < n+1){
        j = i+1;
        while(j < n+1){
            if(graph[i][j] == 1)
                graph[j][i] = 1;
            
			j++;
        }
        i++;
    }
    
    vector<vector<bool> > best(n, vector<bool>(n,0));
    int k = 2;
	i = 0;
    
	while(i < n+1){
        k = 2;
        j = i+1;
        while(j < n+1 && graph[i][j] == 1 && k > 0){
            best[i][j] = best[j][i] = 1;
            k--;
            j++;
        }
        i++;
	}
    
    packet p;
    p.ttl = 3;
    p.st = 0;
    p.path = "Path followed ";
    cout << "Flooding through all lines:\n";
    all_path(graph, 0, 4, p);
    cout << endl;
    
    p.ttl = 3;
    p.st = 0;
    p.path = "Path followed ";
    cout << "Flooding through all lines except incoming line:\n";
    all_path_except_source(graph, -1, 0, 4, p);
    cout << endl;
    
    p.ttl = 3;
    p.st = 0;
    p.path = "Path followed ";
    cout << "Flooding through best k lines:\n";
    all_path_best(graph, 0, 4, p, best);
    cout << endl;
    cout << "---------End of Program---------\n\n";
    return 0;
}
//end of main
