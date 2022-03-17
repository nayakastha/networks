/* Program to implement shortest path routing algorithm */
#include<bits/stdc++.h>
using namespace std;

int dist_mat[100][100];
int trans_rate = pow(10, 6); //transmission rate in m/sec

//Node structure definition
struct Node {
	
	int par_node, dist;
};

//utility function
int minDist(Node Arr[], bool set[], int N) {
	
	int mn = INT_MAX, min_idx;
	for(int i = 0; i < N; i++) {
		
		if(set[i] == false && Arr[i].dist <= mn)
			mn = Arr[i].dist, min_idx = i;
	}
	return min_idx;
}

//function to implement node initialisation
Node* nodeInitialisation(int& N) {
	
	cout << "Enter the no of nodes for the network: ";
	cin >> N;
	Node* Arr;
	Arr = (Node*)malloc(N*sizeof(Node));
	return Arr;
}

//function to create the distance matrix
//Here the distance is considered in kilometres
void createDistanceMatrix(Node Arr[], int N){
    
    for(int i = 0; i < N; i++){
        
		int t_dist = rand()%50 + 1;
        dist_mat[i][(i+1)%N] = t_dist;
        dist_mat[(i+1)%N][i] = t_dist;
    }

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(dist_mat[i][j])
            	continue;
            int wt = rand()%50 + 1;
            dist_mat[i][j] = wt;
            dist_mat[j][i] = wt;
        }
    }

}

//function to find the routing path using djikstra
void Routing(Node Arr[], int dist_mat[100][100], int N, int src) {
	
	bool set[N];
	for(int i = 0; i < N; i++) {
		Arr[i].dist = INT_MAX;
		Arr[i].par_node = -1;
		set[i] = false; 
	}
	
	Arr[src].dist = 0;
	
	for(int ct = 0; ct < N-1; ct++)  {
		
		int u = minDist(Arr, set, N);
		set[u] = true;
		for(int v = 0; v < N; v++) {
			
			if(!set[v] && dist_mat[u][v] && Arr[u].dist != INT_MAX && (Arr[u].dist + dist_mat[u][v] < Arr[v].dist)) {
			
				Arr[v].dist = Arr[u].dist + dist_mat[u][v];
				Arr[v].par_node = u;
			}
		}
	}
}

//function to print the shortest path from source to destination
void shortestPathFromSrcToDest(Node Arr[], int dest) {
	
	vector<int> path;
	int i = dest;
	while(i != -1) {
		
		path.push_back(i);
		i = Arr[i].par_node;
	}

	reverse(path.begin(), path.end());
	cout << "Path followed : ";
	for(i = 0; i < path.size() - 1; i++) {
		cout << path[i] << " --> ";
	}
	cout << path[i] << "\nDistance : " << Arr[dest].dist << " kms, Time to transmit : " << (double)(Arr[dest].dist * 1000)/trans_rate << " secs\n\n";
}

//main function
int main() {
	
	srand(time(NULL));
	memset(dist_mat, 0, 100*100*sizeof(int));
	Node* Arr;
	int size;
	Arr = nodeInitialisation(size);
	cout << "\nFollowing shortest path routing algorithm,\nCreating nodes...\n";
	createDistanceMatrix(Arr, size);
	cout << "Computing distance matrix...\n";
	Routing(Arr, dist_mat, size, 0);
	cout << "Computing routing table...\n";
	
	cout << "\nPaths followed:\n";
	for(int i = 1; i < size; i++) {
		shortestPathFromSrcToDest(Arr, i);
	}
	return 0;
}
//end of main
