#include <iostream>
using namespace std;
class Triangle
{
private:
	int length1;
	int length2;
	int length3;
public:
	Triangle(int,int,int);
	void Display();					//输出三角形的边长
	int Judege();					//判断能否构成三角形
	int Perimeter();				//求三角形的周长
	int Size();						//求三角形的面积
	void type();					//判断三角形的类型
	/*int GetLength1();
	int GetLength2();
	int GetLength3();*/
};
Triangle::Triangle(int a,int b,int c)
{
	length1 = a;
	length2 = b;
	length3 = c;
}
//int Triangle::GetLength1()
//{
//	return length1;
//}
//int Triangle::GetLength2()
//{
//	return length2;
//}
//int Triangle::GetLength3()
//{
//	return length3;
//}
int Triangle::Judege()
{
	int i;
	if (length1 + length2 > length3&&length1 + length3 > length2&&length2 + length3 > length1&&length1 - length2 < length3&&length1 - length3< length2&&length2 - length3 < length1)
	{
		i = 1;
		/*cout << "能构成三角形" << endl;*/
	}
	else
	{
		i = 0;
		/*cout << "不能构成三角形" << endl;*/
	}
	return i;
}
int Triangle::Perimeter()
{
	int perimeter;
	perimeter = length1 + length2 + length3;
	return perimeter;
}
int Triangle::Size()
{
	int size;
	int c;
	int p;
	c = length1 + length2 + length3;
	p = c / 2;
	size =sqrt(p*(p-length1)*(p-length2)*(p-length3));
	return size;
}
void Triangle::type()
{
	if (length1*length1 + length2 * length2 >= length3 * length3 || length1 * length1 + length3 * length3 >= length2 * length2 || length2 * length2 + length3 * length3 >= length1 * length1)
	{
		if (length1*length1 + length2 * length2 == length3 * length3 || length1 * length1 + length3 * length3 == length2 * length2 || length2 * length2 + length3 * length3 == length1 * length1)
		{
			cout << "该三角形为直角三角形" << endl;
		}else
		cout << "该三角形为锐角三角形" << endl;
	}
	else if (length1*length1 + length2 * length2 < length3 * length3 || length1 * length1 + length3 * length3 < length2 * length2 || length2 * length2 + length3 * length3 < length1 * length1)
	{
		cout << "该三角形为钝角三角形" << endl;
	}
}
void Triangle::Display()
{
	cout << "length1=" << length1 << endl;
	cout << "length2="<< length2 << endl;
	cout << "length3=" <<length3 << endl;
}
int main()
{
	int a, b, c;
	cout << "请输入三角形的三个边长：" << endl;
	cin >> a >> b >> c;
	Triangle Triangle(a,b,c);
	Triangle.Display();
	if (Triangle.Judege() == 1)							//若构不成三角形则不需要进行相关计算，节省时间
	{
		cout << "能构成三角形" << endl;
		cout << "该三角形的周长为：" << Triangle.Perimeter() << endl;
		cout << "该三角形的面积为：" << Triangle.Size() << endl;
		Triangle.type();
	}
	else if (Triangle.Judege() == 0)
	{
		cout << "不能构成三角形" << endl;
	}
	system("pause");
	return 0;
}