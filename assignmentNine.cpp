#include <iostream>
#include<cstring>
using namespace std;

int main()
{
	int m, n;

    cin >> m >> n; // m = capacity of bag n = number of item

    int arrw [n]; 
    int arrv [n];
    for(int i =0; i<n; i++)
    {
        cin>> arrw[i] >> arrv[i]; // arrw= weight of object, arrv= value of object
    }

    int k [m+1]; // 1D array used instead of 2D array

    memset(k,0,sizeof(k)); //memorization array

    for(int i =1; i<n+1;i++) //n
    {
        for(int w=m; w>=0; w--){ //m
            
            //if( i ==0|| w ==0) // n =0 or w =0
              //  k[i][w]=0;

            if(arrw[i-1]<=w) //weight of object< = w
            k[w]= max(k[w], k[w-arrw[i-1]]+arrv[i-1]);    //fill the array 
        }
    }

			cout << k[m];// But it doesnot give correct answer where M=8 n =4 and arrw ={1,2,5,6} and arrv ={2,3,4,5} output should be 8 but it gives 9
	return 0;
}
