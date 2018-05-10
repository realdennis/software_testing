# Software Testing
[![Build Status](https://travis-ci.org/realdennis/software_testing.svg?branch=master)](https://travis-ci.org/realdennis/software_testing)

## triangle

為了能夠**Test-Driven Development**，所以希望能透過各種test case去反覆精進feature code。

**這次作業主要會做幾種面向的測試:**
- Boundary Value
- Equivalence Case
- Decision Table

一開始的feature code設定成不管輸入任意三個integer都會回傳Not a Triangle，這是一開始的測資。
## Decision Table測試

-   3 impossible cases
-   3 to fail the triangle property
-   one to get an equilateral triangle
-   one to get a scalene triangle
-   3 to get isosceles triangle

    
        EXPECT_EQ(tri(1, 4, 5), "Not a triangle");
        EXPECT_EQ(tri(3, 4, 5), "Scalene");
        EXPECT_EQ(tri(1, 1, 1), "Equilateral");
        EXPECT_EQ(tri(3, 3, 5), "Isosceles");
![](https://i.imgur.com/wNVcmR5.png)


很顯然的只有Not a triangle會過，**但其實這樣也是錯的**，（不代表真的有驗證），所以第一步，我決定在feature code裡頭新增一個判定是否為三角形的檢驗：

    int isATriangle(int a, int b,int c){
	    if(a<(b+c) && b<(a+c) && c<(a+b)) return 1;	
	    return 0;
    }
當我們發現只要找到任一邊大於甚至等於剩餘的兩邊之和時，這三邊絕對不是三角形。

## 實現Scalene的判斷
在確定三邊為三角形之後，我建立了一個新的Function typeOfTriangle希望這個function能幫我確認三角形的種類。

Scalene的Case為三邊不相等

    if(a!=b && b!=c && c!=a) return "Scalene";
只要我們對三邊倆倆做檢查即可確定

	else return "Another case";
其他的case我們先回傳Another case好了。

![](https://i.imgur.com/zXaEO6X.png)

果不其然被Google test挑出來

顯然這兩個Case過不了關 test failed
所以我們去把這兩個Case實作出來吧！

## 實現Equilateral
Equilateral的case為三邊相等

    if(a==b&&b==c)	return "Equilateral";
值得一提的是原本我的寫法是

    if(a==b && b==c && c==a)//但其實前兩者成立第三個statement必定成立

那麼another case 就會是**Isosceles**。

所以這個typeOfTriangle的function會是這個樣子：

    if(a!=b && b!=c && c!=a) return "Scalene";
	else if(a==b && b==c) return "Equilateral";
	return "Isosceles";//another case
ok，最終在google test裡顯示的是三者皆ok，我們用三種case實作了這個功能，但是還需要更多更多的測試。

## Equivalence Class測試

-   invalid data
-   normal/robust

Strong Normal
-   multiple fault assumption

Weak Robust
-   weak: single fault assumption
-   robust: invalid values

Strong Robust
-   Strong: multiple faults
-   Robust: invalid values


## Boundary Value測試

-   Normal boundary are {1,2,199,200}
-   Robust values {0,201}

**best known specification-based testing
thinking: range-based test case ? how ?**

>    Take 200 as an upper bound
>    Normal boundary are {1,2,199,200}
>    Robust values {0,201}

在strong robust的test case (201,201,1)無法通過測試，因為feature code沒有做好boundary，於是去把feature補上。
![](https://i.imgur.com/kptCC1r.png)


## 實現邊界規範

在isATriangle function中補上boundary check

	//boundary test
	if(a>200 || b>200 || c>200)	return 0;

## 完成
![](https://i.imgur.com/J7LR1Wj.png)
