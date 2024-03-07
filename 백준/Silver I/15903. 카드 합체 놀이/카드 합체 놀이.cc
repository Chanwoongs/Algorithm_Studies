#include <queue> 
#include <iostream>
#include <algorithm>

using namespace std; 

typedef long long ll; 

priority_queue<ll, vector<ll>, greater<ll>> pq;
int n, m;
ll a, res;

int main() 
{
	cin >> n >> m;
    
	for (int i = 0; i < n; i++) 
    {
		cin >> a; 
		pq.push(a); 
	}
    
	while (m--) 
    {
		ll num1 = pq.top(); 
		pq.pop(); 
		ll num2 = pq.top(); 
    	pq.pop();    
        
        ll sum = num1 + num2;
        
		pq.push(sum); 
		pq.push(sum); 
	}
    
	while (pq.size()) 
    {
		res += pq.top(); 
		pq.pop(); 
	}
    
	cout << res << '\n'; 
}
