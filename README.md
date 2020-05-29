# 5月29日下午更新
新增：

序偶类数据文件（第一个数字表示是序偶类 第二第三个数字分别表示序偶的第一个和第二个元素的类型）

序偶集合类文件输入(仅支持<int，int>)其他的有问题 无法输入
少于或等于集合
整除集合
```.cpp
    void Less_or_equal_relationship_print();       //少于或等于
    void Divisive_relationship_print();            //整除
    
    SET1.Less_or_equal_relationship_print();       //少于或等于   
    SET1.Divisive_relationship_print();
```

# 5月29日凌晨更新
新增集合 全域关系 恒等关系 空关系
```.cpp
    //set_vision1.h更新
    void Global_relationship_Print();              //集合的全域关系
    void Identity_relationship_Print();            //集合的恒等关系
    void Empty_Relationship_Print();               //空关系
    

    SET1.Global_relationship_Print();//全域
    SET1.Identity_relationship_Print(); //恒等
    SET1.Empty_Relationship_Print();//空
```
# 5月28日更新

新增 序偶对类 实现序偶类与SET类的连接 可直接通过<<重载输出SET类中存储的序偶对(重载两次)

可完成两个SET的笛卡尔积
