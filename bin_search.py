def binsearch(l,h,key,arr):
    if l==h:
        if arr[l]==key:
            return l
        else:
            return -1
    else:
        mid=(l+h)//2
        if arr[mid]==key:
            return mid
        elif arr[mid]>key:
            return binsearch(l,mid-1,key,arr)
        else:
            return binsearch(mid+1,h,key,arr)


if __name__=="__main__":
    arr=[1,2,3,4,5,6,7,8,9]
    key=5
    l=0
    h=len(arr)-1
    print(binsearch(l,h,key,arr))



    