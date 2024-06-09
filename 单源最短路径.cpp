#include<iostream>

using namespace std;

const int inf = INT_MAX; 

void Dijkstra(int n,int source,int *dist,int *prev,int c[5][5])
{
	bool s[n]; 
	for(int i=0; i<n; i++){
		dist[i] = c[source][i]; 
		s[i] = i == source ? true : false;
		prev[i] = dist[i] == inf ? -1 : source; 
	} 

	for(int i=1; i<n; i++)
	{
		int minDist = inf;
		int newNode;
		
		for(int j=0; j<n; j++){	
			
			if(!s[j] && dist[j]<minDist){
				newNode = j;
				minDist = dist[newNode];
			}
		}
		s[newNode] = true;
		
		for(int j=0; j<n; j++){
			if(!s[j] && c[newNode][j]<inf){
				int newDist = dist[newNode] + c[newNode][j];
				if( newDist < dist[j] ){
				    dist[j] = newDist;
					prev[j] = newNode;
				}
			}
		} 
	} 
}

int main()
{	
	int c[5][5]={
					{0,10,inf,30,100},
					{inf,0,50,inf,inf},
					{inf,inf,0,inf,10},
					{inf,inf,20,0,60},
					{inf,inf,inf,inf,0}
				};
	int n = 5;
	int dist[n];
	int prev[n];
	int source = 0;
	
	Dijkstra(n,source,dist,prev,c);	
	cout<<"源点到各点的最短距离为：";
	for(int i=0; i<n; i++){
		cout<<dist[i]<<" ";
	}
	return 0;
}

