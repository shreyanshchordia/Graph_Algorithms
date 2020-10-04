/*test cases
For Input:
9
your output is: 
2
For Input:
4
your output is: 
2
*/
// { Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends


//User function Template for C++

class Solution{   
public:
    int minimumStep(int n){
        //complete the function here
        int count=0;
        //here we backtrack in most lucid and layman language based o inverting the instructions given above
        while(n>1)//if n>1 then still we have not reached the node 1
        {
            if(n%3==0)//if number is multiple of 3 then give priority even though it has soome positive result on substracting it
            {
                n/=3;//go to the node which is to the current node /3 position 
                ++count;                
            }
            else//else go to the current position -1 which is the only option  remaining of connectivity
            {
                n-=1;//go to the node which is to the current node-1 position
                ++count;//each count++ means one more edge added to the shortest path traversal
            }
        }
        return count;
    }
};

// { Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minimumStep(n) << endl;
    
    }
    return 0; 
} 

  // } Driver Code Ends
