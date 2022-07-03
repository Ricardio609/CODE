# 常见排序算法
## 非线性时间比较类
### 插入排序
#### 直接插入排序
#### 希尔排序
### 选择排序
#### 选择排序
#### 堆排序
### 交换排序
#### 冒泡排序
#### 快速排序
### 归并排序
## 线性时间比较类
### 计数排序
### 基数排序
### 桶排序

## 性能分析
![](https://typoracole.oss-cn-guangzhou.aliyuncs.com/blogimage-master/blogimage-master/https_/gitee.com/zheng-guijun/blogimage/202201122059726.png)
### TODO
测试代码，准备改写
```
void TestOP()
{
    srand(time(0));
    const int N = 100000;//测试数据个数
    int* a1 = (int*)malloc(sizeof(int) * N);
    int* a2 = (int*)malloc(sizeof(int) * N);
    int* a3 = (int*)malloc(sizeof(int) * N);
    int* a4 = (int*)malloc(sizeof(int) * N);
    int* a5 = (int*)malloc(sizeof(int) * N);
    int* a6 = (int*)malloc(sizeof(int) * N);
    int* a7 = (int*)malloc(sizeof(int) * N);
    int* a8 = (int*)malloc(sizeof(int) * N);
    //给开辟数组赋值
    for (int i = 0; i < N; ++i)
    {
        a1[i] = rand();
        a2[i] = a1[i];
        a3[i] = a1[i];
        a4[i] = a1[i];
        a5[i] = a1[i];
        a6[i] = a1[i];
        a7[i] = a1[i];
        a8[i] = a1[i];
    }
    //数组排序并计算时间花费
    int begin1 = clock();
    InsertSort(a1, N);
    int end1 = clock();
 
    int begin2 = clock();
    ShellSort(a2, N);
    int end2 = clock();
 
    int begin3 = clock();
    SelectSort(a3, N);
    int end3 = clock();
 
    int begin4 = clock();
    HeapSort(a4, N);
    int end4 = clock();
 
    int begin5 = clock();
    QuickSort(a5, 0, N - 1);
    int end5 = clock();
 
    int begin6 = clock();
    MergeSort(a6, N);
    int end6 = clock();
 
    int begin7 = clock();
    BubbleSort(a7, N);
    int end7 = clock();
 
    int begin8 = clock();
    CountSort(a8, N);
    int end8 = clock();
    //展示数据
    printf("InsertSort:%d\n", end1 - begin1);
    printf("ShellSort:%d\n",  end2 - begin2);
    printf("SelectSort:%d\n", end3 - begin3);
    printf("HeapSort:%d\n",   end4 - begin4);
    printf("QuickSort:%d\n",  end5 - begin5);
    printf("MergeSort:%d\n",  end6 - begin6);
    printf("BubbleSort:%d\n", end7 - begin7);
    printf("CountSort:%d\n",  end8 - begin8);
    //释放数组
    free(a1);
    free(a2);
    free(a3);
    free(a4);
    free(a5);
    free(a6);
    free(a7);
    free(a8);
}
 
int main()
{
    TestOP();
    return 0;
}
```