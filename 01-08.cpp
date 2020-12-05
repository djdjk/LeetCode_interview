#include<iostream>
#include<vector>

using namespace std;

void setZeroes(vector<vector<int> >& matrix) {
    int n = matrix.size();int n1 = matrix[0].size();
    // cout << "n为" << n << endl;
    vector<int> tem;
    for(int i = 0 ;i< n ;i++)
    {
        for(int j = 0 ;j <n1; j++)
        {
            if(matrix[i][j] == 0)
            {
                tem.push_back(i);
                tem.push_back(j);
                    
            }
        }
    }

    for(int i = 0; i< tem.size(); i++)
    {
        if(i%2 == 0 ){
            for(int k = 0 ;k < n1;k++)
                matrix[tem[i]][k] = 0;
        }

        if(i%2 == 1){
            for(int k = 0 ;k < n;k++){
                matrix[k][tem[i]] = 0;
            }
        }
    }
}

// 另有一种原地的方式，将第一行第一列存储为零的行号和列号（置零），最后检测一行一列元素是否为零

int main()
{
    // int arr[] = {1,1,1,1,0,1,1,1,1};
    int arr[] = {0,1,2,0,  3,4,5,2,  1,3,1,5};
    vector<int> a(arr,arr+4),b(arr+4,arr+8), c(arr+8,arr+12);
    vector<vector<int> > m ;
    m.push_back(a);m.push_back(b);m.push_back(c);
    // m[1] = a;
    for(int i=0; i< m.size(); i++)//输出二维动态数组 
    {
        for(int j=0;j<m[i].size();j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }
    setZeroes(m);
    for(int i=0; i< m.size(); i++)//输出二维动态数组 
    {
        for(int j=0;j<m[i].size();j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }
    


}   
