#include <boost/multiprecision/cpp_int.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <string>
using boost::multiprecision::cpp_int;
cpp_int next_allowed(cpp_int n,int b,int a){
    if(n<=0)return 0; std::vector<unsigned char>d;
    while(n>0){cpp_int q=n/b; d.push_back((unsigned char)(n-q*b).convert_to<unsigned>()); n=q;}
    std::reverse(d.begin(),d.end()); int L=d.size(); std::vector<unsigned char>o(L,0);
    for(int i=0;i<L;i++){
        if(d[i]<=a){o[i]=d[i]; continue;}
        int j=i-1; while(j>=0 && o[j]>=a)--j;
        if(j>=0){o[j]++; for(int k=j+1;k<L;k++)o[k]=0;}
        else {cpp_int z=1; for(int k=0;k<L;k++)z*=b; return z;}
        break;
    }
    cpp_int v=0; for(auto z:o){v*=b;v+=z;} return v;
}
bool good(cpp_int n){for(auto [b,a]: std::vector<std::pair<int,int>>{{3,1},{5,2},{7,3}}){cpp_int x=n;while(x>0){cpp_int q=x/b;int r=(x-q*b).convert_to<int>();if(r>a)return false;x=q;}}return true;}
cpp_int p10(int D){cpp_int z=1; while(D--)z*=10; return z;}
int main(int ac,char**av){for(int z=1;z<ac;z++){int D=std::stoi(av[z]);cpp_int x=p10(D);auto t=std::chrono::steady_clock::now();unsigned long long it=0;while(true){cpp_int a=next_allowed(x,3,1),b=next_allowed(x,5,2),c=next_allowed(x,7,3);cpp_int y=std::max(a,std::max(b,c));if(y==x)break;x=y;++it;}double sec=std::chrono::duration<double>(std::chrono::steady_clock::now()-t).count();std::string s=x.convert_to<std::string>();std::cout<<"D="<<D<<" it="<<it<<" sec="<<sec<<" digits="<<s.size()<<" good="<<good(x)<<"\n"<<s<<"\n";}}
