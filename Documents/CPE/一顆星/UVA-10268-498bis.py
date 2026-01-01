#這題毫無疑問用python寫比C++簡單很多
"""
Docstring for UVA-10268-498bis
讀測資讀到EOF -> 用 while True: + try/except EOFError
"""
while True: 
    try:
        ans, power =0, 1
        x = int(input())
        poly = list(map(int, input().strip().split()))  #多項式存成list
        for i in range(len(poly)-2, -1, -1):            #回憶:range(初始值, 最終值的前一個值, 迭代方式)
            ans += poly[i]* (power)* (x ** (power-1))   #多項式微分公式:注意從多項式的1次項開始往多次項看，從常數項會導致ZeroDivisionError
            power += 1                                  #power++
        print(int(ans))    
    except EOFError:
        break
    except ValueError:                                  #保險起見，ValueError也跳掉
        break