#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isSafe(int **arr, int x, int y, int n)
{
  if (x < n && y < n && arr[x][y] == 1)
  {
    return true;
  }
  else{
    return false;
  }
}
bool rat(int **arr, int x, int y, int n, int **solArr)
{
  if (x == n - 1 && y == n - 1)
  {
    solArr[x][y] = 1;
    return true;
  }

  else if (isSafe(arr, x, y, n))
  {
    solArr[x][y] = 1;
    if (rat(arr, x + 1, y, n, solArr))
    {
      return true;
    }
    if (rat(arr, x, y + 1, n, solArr))
    {
      return true;
    }
    solArr[x][y] = 0;
    return false;
  }
   else {
     return false;}

}

int main()
{
  int n;
  cin >> n;
  int **arr = new int *[n];
  for (int i = 0; i < n; i++)
  {
    arr[i] = new int[n];
  }
 
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> arr[i][j];
    }
  }
  int **solArr=new int*[n];
  for (int i = 0; i < n; i++)
  {
    solArr[i]=new int[n];
    for (int j = 0; j < n; j++)
    {
      solArr[i][j] = 0;
    }
  }

  if (rat(arr, 0, 0, n, solArr))
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cout << solArr[i][j]<<" ";
      } cout<<endl;
    }
  }
  else{ cout<<"No possible path"<<endl;}
    return 0;
  }


/* sample cases:

4 
1 1 1 1
1 1 0 1
0 0 0 0
1 1 1 1
 
output:
 
No possible path


3
1 0 1
1 1 1
1 1 1

output
1 0 0 
1 0 0 
1 1 1 

5
1 0 0 0 1
1 1 0 1 0
1 1 1 0 1
1 1 1 1 1
 

output
1 0 0 0 0 
1 0 0 0 0 
1 0 0 0 0 
1 1 1 1 1 
0 0 0 0 1 */
