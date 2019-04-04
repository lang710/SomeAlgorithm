#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int longest_path(int num_node,int *value,vector<pair<int,int>> edge){
    //节点序号从1～num_node
    //value下标从0～num_node-1
    //获取每个点的父节点
    int father[num_node];
    father[0]=-1;
    
    int f_node,s_node;
    for(int i=0;i<num_node;i++){
        f_node=edge[i].first;
        s_node=edge[i].second;
        father[s_node-1]=f_node;
    }
    
    int leaf[num_node];
    int leaf_length=0;
    for(int i=0;i<num_node;i++)
        leaf[i]=0;
    for(int i=0;i<num_node-1;i++)
        leaf[edge[i].first-1]=1;
    for(int i=0;i<num_node;i++){
        leaf[leaf_length]=i+1;
        leaf_length++;
    
    int max=0x80000000,sum;
    int f1[num_node],f2[num_node];      //记录叶子i,j的所有父节点
    int l1,l2,current;                  //记录叶子i,j的父节点个数（包括自身）
    for(int i=0;i<leaf_length-1;i++)
        for(int j=i+1;j<leaf_length;j++){
            l1=0;           
            current=leaf[i];
            while(curren!=-1){
                f1[l1]=current;
                l1++;
                current=father[current-1];
            }
            l2=0;           
            current=leaf[j];
            while(current!=-1){
                f2[l2]=current;
                l2++;
                current=father[current-1];
            }
            sum=1;
            if(l1>l2){
                for(int k=0;k<l1-l2;k++)
                    sum*=value[f1[k]-1];
                for(int k=0;k<l2;k++){
                    if(f2[k]!=f1[l1-l2+k])
                        sum*=value[f2[k]-1]*value[f1[l1-l2+k]-1];
                    else{
                        sum*=value[f2[k]-1];
                        break;
                    }
                }
            }else{
                for(int k=0;k<l2-l1;k++)
                    sum*=value[f2[k]-1];
                for(int k=0;k<l1;k++){
                    if(f1[k]!=f2[l2-l1+k)
                        sum*=value[f1[k]-1]*value[f2[l2-l1+k]-1];
                    else{
                        sum*=value[f1[k]-1];
                        break;
                    }
                }
            }
            if(sum>max)
                max=sum;
        }
    return max;
}

int main(){
    int num_node;
    cin>>num_node;
    int *value=new int[num_node]l
    for(int i=0;i<num_node;i++)
        cin>>value[i];
    vector<pair<int,int>> edge(num_node-1);
    int father,son;
    for(int i=0;i<num_node-1;i++){
        cin>>father>>son;
        edge[i]=make_pair(father,son);
    }
    
    int l_path=longest_path(num_node,value,edge);
    cout<<l_path;
    
    return 0;
}
