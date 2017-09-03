
activity = [(1,4), (3,5), (0,6), (5,7), (3,9), (5,9), (6,10), (8,11), (8,12), (2,14), (12,16)]

def recursiveActivitySelector(s,f,k,n):
    activity=[]
    m = k + 1
    while(m<n && s[m]<f[k])
        m = m + 1

    if(m<=n)
        activity.append(m)
        return activity.append(recursiveActivitySelector(s,f,m,n))
    else
        return 
