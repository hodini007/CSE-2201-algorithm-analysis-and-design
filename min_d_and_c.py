arr=[432,54,21,4,34,4,243,45,34423,423,4234,3,243,35]
l=0
r=len(arr)-1
def dc(l,r):
    if l==r:
        return arr[l]
    mid=(l+r)//2
    left=dc(l,mid)
    right=dc(mid+1,r)
    return min(left,right)
print(dc(l,r))

def max_dc(l,r):
    if l==r:
        return arr[l]
    mid=(l+r)//2
    left=max_dc(l,mid)
    right=max_dc(mid+1,r)
    return max(left,right)
print(max_dc(l,r))


def min_max(l,r):
    if l==r:
        return arr[l],arr[l]
    mid=(l+r)//2
    left_min,left_max=min_max(l,mid)
    right_min,right_max=min_max(mid+1,r)
    return min(left_min,right_min),max(left_max,right_max)
print(min_max(l,r))
