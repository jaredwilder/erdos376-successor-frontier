#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>
using boost::multiprecision::cpp_int;

// Independent successor implementation: convert n to base-b digits, then
// lexicographically find the least allowed digit string >= n via backtracking.
cpp_int successor(cpp_int n,int b,int maxd){
    if(n<=0) return 0;
    std::vector<int> d;
    cpp_int t=n;
    while(t>0){ cpp_int q=t/b; d.push_back((t-q*b).convert_to<int>()); t=q; }
    std::reverse(d.begin(),d.end());
    int L=d.size();
    std::vector<int> out(L,0);
    // DFS is deterministic and follows lexicographic order. State (pos,tight).
    std::function<bool(int,bool)> go = [&](int pos,bool tight)->bool{
        if(pos==L) return true;
        int low = tight ? d[pos] : 0;
        for(int x=low;x<=maxd;x++){
            out[pos]=x;
            bool nt = tight && (x==d[pos]);
            if(go(pos+1,nt)) return true;
        }
        return false;
    };
    if(!go(0,true)){
        // No same-length solution. Leading 1 followed by zeros is least longer one.
        cpp_int z=1; for(int i=0;i<L;i++) z*=b; return z;
    }
    cpp_int v=0; for(int x:out){v*=b;v+=x;} return v;
}

bool allowed(cpp_int n,int b,int maxd){
    while(n>0){cpp_int q=n/b; int r=(n-q*b).convert_to<int>(); if(r>maxd)return false;n=q;}return true;
}
cpp_int p10(int D){cpp_int z=1;while(D--)z*=10;return z;}
int main(int ac,char**av){
    int D=ac>1?std::stoi(av[1]):100;
    cpp_int x=p10(D); unsigned long long it=0;
    auto st=std::chrono::steady_clock::now();
    for(;;){
        cpp_int a=successor(x,3,1),b=successor(x,5,2),c=successor(x,7,3);
        cpp_int y=std::max(a,std::max(b,c));
        if(y==x)break; x=y; ++it;
    }
    double sec=std::chrono::duration<double>(std::chrono::steady_clock::now()-st).count();
    std::string s=x.convert_to<std::string>();
    std::cout<<"D="<<D<<" it="<<it<<" sec="<<sec<<" digits="<<s.size()
             <<" good="<<(allowed(x,3,1)&&allowed(x,5,2)&&allowed(x,7,3))<<"\n"<<s<<"\n";
}
