#include <iostream>

using namespace std;

int main()
{
    int N , M , sol;
    sol =0;
    cin >> N >> M;

    for(int i = 1; i<= N; i++)
    {
        if(i%M == 0)
        {
            sol += i;   
        }
    }

    cout << sol;
    
}