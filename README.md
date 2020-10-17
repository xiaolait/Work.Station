# 铁路站点选择

该项目一共3个工程  
1.Station：用C#编写的窗口工程，即该项目的主体工程。该项目生成Station.dll文件，不能直接运行，项目用于创建站点选择窗口，并返回相应站点的经纬信息。  
2.StationCpp：用托管C++编写，主要用于将c#接口转换为标准C接口。该项目生成StationCpp.dll文件，不能直接运行。  
3.StationTest：用C++编写，用于加载运行StationCpp.dll->Station.dll，最终获取经纬信息。  
