def next_allowed(n,b,a):
    if n<=0:return 0
    digs=[];x=n
    while x:
        digs.append(x%b);x//=b
    digs=digs[::-1];L=len(digs);out=[0]*L
    for i,d in enumerate(digs):
        if d<=a:
            out[i]=d;continue
        j=i-1
        while j>=0 and out[j]>=a:j-=1
        if j>=0:
            out[j]+=1
            for k in range(j+1,L):out[k]=0
        else:
            return b**L
        break
    v=0
    for d in out:v=v*b+d
    return v

def good(n):
    for b,a in [(3,1),(5,2),(7,3)]:
        x=n
        while x:
            if x%b>a:return False
            x//=b
    return True

def next_common(x,maxit=10000000, trace=False):
    for it in range(maxit):
        ys=[next_allowed(x,3,1),next_allowed(x,5,2),next_allowed(x,7,3)]
        y=max(ys)
        if y==x:
            return x,it
        if trace and (it<20 or it%10000==0):print(it,x,ys,y)
        x=y
    return None,maxit

if __name__=='__main__':
 import sys,time
 x=int(sys.argv[1]) if len(sys.argv)>1 else 1
 for j in range(int(sys.argv[2]) if len(sys.argv)>2 else 20):
  t=time.time(); y,it=next_common(x); print(j,y,it,'sec',time.time()-t,'good',good(y) if y else None); x=y+1
