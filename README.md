# CADImitation
本项目为冯家乐大作业

# Utils
#### static std::string cstring2String(CString& str)
``` 
将CString转换为std::string
```
#### static CString string2CString(std::string& str)
``` 
将std::string转换为CString
```
#### static int string2Int(std::string& str)
``` 
将std::string转换为int
```
#### static std::string int2String(int data)
``` 
将int转换为std::string
如果用户输入非法，抛出异常
```

# CMainFrm
#### void onDrawCircle()
```
处理单击drawCircle按钮时的事件  
打开一个对话框，让用户输入圆的半径和圆心坐标，调用ChileView的addCircle函数  
使用try-catch语句来处理用户输入的数据的合法性 
```
#### void onClearLine()
``` 
调用ChildView类的clearLine()方法来清除画布上的所有线段  
```
#### void OnClearCircles()
```
调用ChildView类的clearCircles()方法来清除画布上的所有圆  
```
#### void onClearAll()
```
调用ChildView类的clearAll()方法来画出所有的线段和圆  
```

# GetCircleDataDialog
### 成员变量
- std::string x 圆心横坐标
- std::string y 圆心纵坐标 
- std::string radius  半径

### 接口
#### std::string getX() const
```
返回圆心横坐标
```
#### std::string getY() const
```
返回圆心纵坐标
```
#### std::string getRadius() const
```
返回圆的半径
```
#### void setX(CString& x)
```
设置圆心横坐标
```
#### void setY(CString& y)
```
设置圆心纵坐标
```
#### void setRadius(CString& radius)
```
设置圆的半径
```
#### void OnBnClickedOk()
```
处理单击确定按钮时的事件  
获取用户数据并使用Utils::cstring2String()方法将CString转换为std::string  
保存到成员变量中  
```

# Circle
自定义变量，用于存储圆的信息
# Line
自定义变量，用于存储线段的信息

# CChildView
### 成员变量
- std::vector<Circle> circles 用于存储圆的信息
- std::vector<Line> lines 用于存储线段的信息
- bool needClear = false 用于标记是否需要清除画布
- CPoint currentPoint 用于存储当前鼠标的坐标
- CPoint lastPoint 用于存储上一次鼠标点击时的坐标

### 接口
#### void drawCoordinate(CClientDC &dc)
```
在窗口左下角绘制鼠标坐标
```
#### void drawExistLine(CClientDC &dc)
```
在窗口上绘制已经存在的线段  
已存在的线被存储在lines中  
```
#### void drawCurrentLine(CClientDC &dc)
```
在窗口上绘制当前的线段  
当前的线段是指用户单击鼠标时的点与当前鼠标所在的点的连线  
```
#### void drawCircle(CClientDC& dc)
```
在窗口上绘制已经存在的圆  
已存在的圆被存储在circles中  
```
#### void clearLine()
```
清除画布上的所有线段  
实现的手段是清空lines中的所有元素  
```
#### void clearCircle()
```
清除画布上的所有圆  
实现的手段是清空circles中的所有元素  
```
#### void clearAll()
```
清空所有元素  
实现的手段是清空lines和circles中所有的元素  
```
#### void addCircle(int x, int y, int r)
```
往circles添加一个circle对象    
```
#### void addLine(CPoint start, CPoint end)
```
往lines添加一个line对象    
```
#### void OnLButtonDown(UINT, CPoint)
```
处理鼠标按下事件  
第一次按下时记录鼠标坐标到currentPoint中  
第二次按下时调用addLine()方法添加直线  
```
#### void OnMouseMove(UINT nFlags, CPoint point)
```
更新鼠标当前坐标
```
#### void OnDraw()
```
绘制圆与直线  
当鼠标第一次按下后，会绘制当前线段，并且会清空画布  
```
#### void OnTimer(UINT_PTR nIDEvent)
```
每隔80ms触发一次OnDraw()进行重绘
```