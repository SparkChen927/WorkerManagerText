# WorkerManager

**请先在项目属性--》常规--》平台工具集选择已安装的工具链**

由于微软在VS2013中不建议再使用C/C++的传统库函数scanf,strcpy,sprintf等，所以直接使用这些库函数会提示C4996错误。

 

VS建议采用带_s的函数，如scanf_s、strcpy_s，但这些并不是标准C/C++函数。要想继续使用此函数，需要添加 _CRT_SECURE_NO_WARNINGS这个预定义。

 

在项目 -> 属性 -> C/C++->预处理器 -> 预处理器定中添加 _CRT_SECURE_NO_WARNINGS：

