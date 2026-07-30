def counting_sort(arr):
    if not arr :
        return []
    max_val=max(arr)
    count=[0]*(max_val+1)
    for num in arr:
        count[num]+=1
    for i in range(1,len(count)):
        count[i]+=count[i-1]
    output=[0]*len(arr)
    for num in reversed(arr):
        output[count[num]-1]=num
        count[num]-=1
    return output

a=[432,54,21,4,34,4,243,45,34423,423,4234,3,243,35]
print(counting_sort(a))