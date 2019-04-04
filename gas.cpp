#include <iostream>
using namespace std;

//主要使用遍历，递归实现
void find(int num_gas,int *get_gas,int *dis_gas,int remain,int need,int pos,int least,int &result){
    if(remain>=need)
        if(least<result)
            result=least;
        return;
    }
    
    if(pos==0)
        remain-=dis_gas[pos];
        need-=dis_gas[pos];
    }else{
        remain-=dis_gas[pos]-dis_gas[pos-1];
        need-=dis_gas[pos]-dis_gas[pos-1];
    }
    if(remain>=0){
        if(remain>=dis_gas[pos+1]-dis_gas[pos])
            find(num_gas,get_gas,dis_gas,remain,need,pos+1,least,result);
        find(num_gas,get_gas,dis_gas,remain+get_gas[pos],need,pos+1,least+1,result);
    }
}

int least_gas(int num_gas,int *get_gas,int *dis_gas,int remain,int need){
    int tar=dis_gas[0];
    int rem=remain;
    for(int i=0;i<num_gas-1;i++)
        if(rem<tar)
            return -1;
        tar=dis_gas[i+1]-dis_gas[i];
        rem=rem-tar+get_gas[i];
    }
    rem=rem-tar+get_gas[num_gas-1];
    if(rem<need-dis_gas[num_gas-1])
        return -1;
    
    int least=0,pos=0,result=num_gas;
    find(num_gas,get_gas,dis_gas,remain,need,pos,least,result);
    return result;
}

int main(){
    int num_gas;
    cin>>num_gas;
    int *get_gas=new int[num_gas];
    for(int i=0;i<num_gas;i++)
        cin>>get_gas[i];
    int remain,need;
    cin>>remain>>need;
    
    int least_num=least_gas(num_gas,get_gas,dis_gas,dis_gas,remain,need);
    cout<<least_num;
    return 0;
}
