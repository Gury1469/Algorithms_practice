#include<iostream>

using namespace std;

int findSum(int* arr,int* sol,int n)
{   
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(sol[i]==1)
            sum+=arr[i];
    }
    return sum;
}

bool sumOfSubset(int* arr,int n,int sum,int x,int* sol)
{
    
    int temp_sum=findSum(arr,sol,n);

    if(temp_sum==sum)
        return true;
    
    int temp=x;
    while(temp<n)
    {
        if(temp_sum+arr[temp]<=sum)
        {
            sol[temp]=1;
            
            temp++;
            if(sumOfSubset(arr,n,sum,temp,sol))
            {
                cout<<"adding "<<arr[temp]<<endl;
                return true;
            }
            

            
            sol[temp-1]=0;
           
        }
         return 0;
    }
    return false;
    
}

int main()
{
    int arr[6]={3,34,4,12,5,2};
    int sol[6]={0,0,0,0,0,0};
    sumOfSubset(arr,6,20,0,sol);
    for(int i=0;i<5;i++)
    {
        if(sol[i]==1)
            cout<<arr[i]<<" ";
    }
    cout<<"done";
    return 0;
}