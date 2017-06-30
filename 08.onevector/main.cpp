#include <iostream>
using namespace std;

template<typename Object>   //模板声明，其中Object为类型参数
class  Vector
{
private:
    int theSize;                         //实际数据大小
    int theCapacity;                     //实际容器容量大小
    Object *objects;                     //基本数组
public:
    enum { SPACE_CAPACITY = 16 };        //默认容量大小
    
    explicit Vector(int initSize = 0)    //单参数构造函数要用explicit()避免类型在后台转换
        : theSize(initSize), theCapacity(initSize + SPACE_CAPACITY) {
        objects = new Object[theCapacity];
    }
    Vector(const Vector& rhs) : objects(NULL) {    //复制构造函数--调用operator=对已有的Vector进行复制
        operator = (rhs);
    }
    ~Vector() {
        delete[] objects;
    }

    const Vector& operator = (const Vector& rhs) //重载赋值运算符
    {
        if (this != &rhs)                        //避免复制自身--混淆检验
        {
            delete []objects;                    //删除旧的内存空间
            theSize = rhs.size();                //生成同样的样本大小
            theCapacity = rhs.theCapacity;       //生成同样的容量大小

            objects = new Object[capacity()];    //生成与所复制的Vector同样容量的新数组
            for (int k = 0; k < size(); k++)
                objects[k] = rhs.objects[k]; 
        }
        return *this;
    }
    
    void resize(int newSize)
    {
        if (newSize > theCapacity)        //重置大小
            reserve(newSize * 2 + 1);     //新大小
        theSize = newSize;
    }

    void reserve(int newCapacity)
    {
        if (newCapacity < theSize)        //至少和（样本大小）一样大
            return;

        Object *oldArray = objects;       //oldArray--用于复制旧数组内容
        objects = new Object[newCapacity];
        for (int k = 0; k < theSize; k++)
            objects[k] = oldArray[k];

        theCapacity = newCapacity;
        delete []oldArray;
    }

    Object& operator[] (int index)
    {
        return objects[index];
    }
    const Object& operator[] (int index) const
    {
        return objects[index];
    }

    bool empty() const {
        return size() == 0;
    }
    
    int size() const {
        return theSize;
    }
    int capacity() const {
        return theCapacity;
    }
    void push_back(const Object& x) {
        if (theSize == theCapacity)
            reserve(2 * theCapacity + 1);
        objects[theSize++] = x;
    }
    
    void pop_back() {
        theSize--;
    }
    const Object& back() const {
        return objects[theSize - 1];
    }
    
    typedef Object *iterator;
    typedef const Object *const_iterator;

    iterator begin() {
        return &objects[0];
    }
    const_iterator begin() const {
        return &objects[0];
    }
    iterator end() {               //尾后的不存在的指针
        return &objects[size()];     
    }
    const_iterator end() const {
        return &objects[size()];
    }
};

int main()
{
    Vector<int> test;
    int data;
    while (cin >> data)
    {
        test.push_back(data);
    }
    Vector<int>::iterator it;
    for (it = test.begin(); it != test.end(); ++it)
        cout << *it << " ";
    cout << endl;
    cout << "pop_one.....\n";
    test.pop_back();
    cout << test.back() << endl;
    return 0;
}
