t=int(input())
for i in range (1,t+1):
    ans=0
    s=input()
    og=s
    tens=int(pow(10,len(s)-1))
    f=0 # 0 default, 1 for going up and -1 for going down
    for j in range(len(s)):
        n=ord(s[j])-ord('0')
        if f==0:
            if n%2==1 and n!=9 and n!=1:
                #print(chr(ord(s[j])+1))
                ans+=tens
                f=1
            elif n%2==1 and n==9:
                #print(chr(ord(s[j])-1))
                ans+=tens
                f=-1
            elif n%2==1 and n==1:
                f=-2
                #ans+=3*tens
            else:
                f=0
        elif f==1:
            #print(0)
            ans-=tens*n
        elif f==-1:
            #print(0)
            ans+=tens*n
        elif f==-2:
            ans+=tens*3
            f=-3
        elif f==-3:
            ans+=tens*(8-n)
        tens=tens/10
    print("Case #{}:".format(i),int(ans))

