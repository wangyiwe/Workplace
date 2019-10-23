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
	void Display();					//��������εı߳�
	int Judege();					//�ж��ܷ񹹳�������
	int Perimeter();				//�������ε��ܳ�
	int Size();						//�������ε����
	void type();					//�ж������ε�����
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
		/*cout << "�ܹ���������" << endl;*/
	}
	else
	{
		i = 0;
		/*cout << "���ܹ���������" << endl;*/
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
			cout << "��������Ϊֱ��������" << endl;
		}else
		cout << "��������Ϊ���������" << endl;
	}
	else if (length1*length1 + length2 * length2 < length3 * length3 || length1 * length1 + length3 * length3 < length2 * length2 || length2 * length2 + length3 * length3 < length1 * length1)
	{
		cout << "��������Ϊ�۽�������" << endl;
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
	cout << "�����������ε������߳���" << endl;
	cin >> a >> b >> c;
	Triangle Triangle(a,b,c);
	Triangle.Display();
	if (Triangle.Judege() == 1)							//������������������Ҫ������ؼ��㣬��ʡʱ��
	{
		cout << "�ܹ���������" << endl;
		cout << "�������ε��ܳ�Ϊ��" << Triangle.Perimeter() << endl;
		cout << "�������ε����Ϊ��" << Triangle.Size() << endl;
		Triangle.type();
	}
	else if (Triangle.Judege() == 0)
	{
		cout << "���ܹ���������" << endl;
	}
	system("pause");
	return 0;
}