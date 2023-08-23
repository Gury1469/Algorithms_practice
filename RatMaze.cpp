#include<iostream>
using namespace std;

bool isSafe(int** map,int x,int y)
{
    if(map[x][y]==0)
        return 0;
    return 1;
}
bool RatMaze(int** map,int x,int y,int n,int** path)
{
    if(x>=n || y>=n || x<0 || y<0)
    {
        return 0;
    }
    if(x==n-1 && y==n-1 && map[x][y]==1)
    {
        path[x][y]=1;
        return true;
    }
   
   
        if(isSafe(map,x,y))
        {
        
            path[x][y]=1;

            if(RatMaze(map,x+1,y,n,path) || RatMaze(map,x,y+1,n,path))
                return true;
               
            path[x][y]=0;
        }
   
    
    
    return false;
}

int main()
{
    int n;
    cin>>n;
    int** map=new int*[n];
    for(int i=0;i<n;i++)
        map[i]=new int[n];

    int** path=new int*[n];
    for(int i=0;i<n;i++)
        path[i]=new int[n];

    //initializing resulting path arrray to 0
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            path[i][j]=0;
        }
    }
    
     //initializing map of the maze as input
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>map[i][j];
        }
    }
    RatMaze(map,0,0,n,path);
       
    //output the resulting path array
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<path[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}