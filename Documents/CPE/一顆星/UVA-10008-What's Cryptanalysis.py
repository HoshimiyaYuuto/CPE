n=int(input())
d1={}   #alphabet:num
d2={}   #num:alphabet
for _ in range(n):
    tmp=input().strip() #讀每行輸入
    tmp=tmp.upper()     #轉成大寫
    for chr in tmp:
        if not chr.isalpha():   #排除非字母的字元
            continue
        if chr in d1.keys():    #更新d1內容
            d1[chr]+=1
        else:
            d1[chr]=1
for key,val in d1.items():      #將d1的key,value反轉
    if val not in d2.keys():    #注意:可能多個字母對應同個數量，若d2的key沒該數量就建一個空list
        d2[val]=[]
    d2[val].append(key)         #把字母丟進d2內對應數量的list中
lst=list(d2.items())            #把d2轉乘list
lst.sort(reverse=True)          #排序(降冪)
for num,al in lst:
    al.sort()                   #對應到同個數量的字母依字元大小輸出
    for a in al:
        print(a,num)