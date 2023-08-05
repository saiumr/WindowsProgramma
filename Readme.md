# Windows Programing

## 了解Windows程序设计  

都是学习的示例程序，学习资源来自 ~~[C语言中文网(打不开了)](http://c.biancheng.net/cpp/html/2848.html)~~  
注意：编译不成功需要加入编译参数`-mwindows`，并且运行直接挂后台  
  
投敌了，用[Windows Docs](https://docs.microsoft.com/zh-cn/windows/win32/learnwin32/windows-coding-conventions)  
前面写的放到[old](./old/)里面了，新开始的文件都在[examples](./examples/)里面  
  
写的一些有意思的小Demo都在[utilities](./utilities/)里面  

## popoCat & Anya Cursor  

[SetSystemCursor](https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setsystemcursor)  
注意：SetSystemCursor每次设置Cursor之后都会把资源清除，所以后续要使用同一资源必须重新Load（或许有更好的解决方式，但我刚学并不了解）  
  
[在线ps](https://ps.gaoding.com/#/)  
  
[在线png转cur](https://convertio.co/zh/cur-converter/)  
  
### Auto-start  
win+R，输入Shell:startup，把可执行文件的快捷方式放进去就好了  
  
### Simple customization  
使用assets/sample.psd文件，在线ps制作png图  
把鼠标指针对准popoCat左耳尖就好了    
把图片转换成cur文件替换exe文件下的cur文件  

PS: Nice Windows Docs！

