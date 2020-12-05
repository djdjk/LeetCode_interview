#include<iostream>
#include<vector>
#include<string>

using  namespace std;

void rotate(vector<vector<int> >& matrix) {//这里的 & 是”引用“的意思。对引用的操作与对变量直接操作完全一样，可以改变传入参数
    int N = matrix.size();
    for(int i = 0; i < N;i++)
    {
        for(int j = i; j< N;j++)
        {
            int tem = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tem;
        }
    }

    for(int i = 0; i < N/2 ; i++)
    {
        for(int j = 0 ; j<N; j++)
        {
            int tem = matrix[j][i];
            matrix[j][i] = matrix[j][N-1-i];
            matrix[j][N-1-i] = tem;
        }
    }

}

int main()
{   
    int list[] = {1,2,3,4,5,6,7,8,9};
    vector<int> a(list,list+3), b(list+3,list+6), c(list+6,list+9);
    vector<vector<int> > m ;
    m.push_back(a); m.push_back(b); m.push_back(c);
    for(int i=0; i< m.size(); i++)//输出二维动态数组 
    {
        for(int j=0;j<m[i].size();j++)
        {
            cout<<m[i][j]<<" ";
        }
        cout<<"\n";
    }
}