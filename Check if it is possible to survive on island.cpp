/*
Approach: 
Use Greedy approach bcoz buying the food for some consecutive early days is the right direction. Har din jeena hai.

If we can survive for the first 7 days then we can survive any number of days and for that we need to check two things 
-> Check whether we can survive one day or not.(each day counts) 
-> (S >= 7) If we buy food in the first 6 days of the week then we can survive for the week i.e. total food we can buy 
in a week (6*N) is greater then or equal to total food we require to survive in a week (7*M) then we can survive. 

also M should be < N else we won't be able to survive

If any of the above conditions are not true then we can’t survive else the minimum number of days required to buy food 
will be = ceil(total food required/units of food we can buy each day).

TC: O(1) 
SC: O(1)

*/

#include<iostream>

using namespace std;

//our function that uses greedy approach
void survival(int S, int N, int M)
{
	//We can't survive if:
    //we can not buy at least a week supply of food during the first week
    // OR 
	//We can not buy a day supply of food on the first day. (pehle hi din nhi hagna kam se kam)
	
	//corner case jaha apan eliminate ho sakte hai
    if (((N * 6) < (M * 7) && S > 6) || M > N)
    {
    	cout << "We can't survive!\n";
	}
    else 
	{
        // If we can survive then we can buy ceil(F/N) times where F is total units of food required.
		//we know that => (days * N = S * M)
		
        int days = (M * S) / N;
        
        if (((M * S) % N) != 0)
        {
        	days++;
		}
        cout<<"\nWe can survive for => "<<days<<" days.";
    }
}

int main()
{
	//static input rakh raha hu mai yaha
	int S=10,N=16,M=2;
	
	//calling our function
    survival(S,N,M);
	
	return 0;
}

