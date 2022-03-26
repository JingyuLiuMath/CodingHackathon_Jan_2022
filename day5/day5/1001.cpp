#include<iostream>
#include<math.h>
#include<stack>
#include<cstring>

using namespace std;

int num[125] = { 0 };
int product[125] = { 0 };
int product1[125] = { 0 };
int trans[125] = { 0 };
// num��product�������� ��λ-ʮλ-... 

void Adjust(int* trans, int i);
void OneMult(int* product, int onenum);
void Add(int* product, int* trans);
void Mult(int* product, int* num);

int main()
{
	string R;
	int n;
	while (cin >> R >> n)
	{
		memset(num, 0, sizeof(num));
		memset(product, 0, sizeof(product));
		memset(product1, 0, sizeof(product1));
		memset(trans, 0, sizeof(trans));
		product[0] = 1;
		int e = 0; // R = int * 10^(-e) 
		int flag = 0;
		string R1;
		// ȥ��'.'
		for (int start = 0; start < R.size(); start++)
		{
			if (flag == 1)
			{
				e++;
			}
			if (R[start] == '.')
			{
				flag = 1;
			}
			else
			{
				R1 += R[start];
			}
		}
		// ����
		for (int i = 0; i < R1.size(); i++)
		{
			num[i] = int(R1[R1.size() - i - 1] - '0');
		}
		// ���˷�
		for (int k = 0; k < n; k++)
		{
			Mult(product, num);
		}
		// �������
		e = e * n;
		stack<int> zhengshu;
		stack<int> xiaoshu;
		int flag1 = 0; // flagxiaoshuΪ1��ʾ��С������
		for (int i = 0; i < e; i++)
		{
			if (flag1 == 0)
			{
				if (product[i] != 0)
					flag1 = 1;
			}
			if (flag1 == 1)
			{
				xiaoshu.push(product[i]);
			}
		}
		for(int i = e; i < 125; i++)
		{
			zhengshu.push(product[i]);
		}
		int output; 
		int flagzhengshu = 1; // flagzhengshu����ȥ��ǰ���0
		while (!zhengshu.empty())
		{
			output = zhengshu.top();
			zhengshu.pop();
			if (flagzhengshu == 1)
			{
				if (output != 0)
				{
					flagzhengshu = 0;
					cout << output;
				}
			}
			else
				cout << output;
		}
		if (flag1 == 1)
		{
			cout << ".";
			while (!xiaoshu.empty())
			{
				output = xiaoshu.top();
				xiaoshu.pop();
				cout << output;
			}
		}
		cout << endl;
	}
	return 0;
}

// ��trans��������������ƶ�i��
void Adjust(int* trans, int i)
{
	for (int j = 124; j >= i; j--)
	{
		trans[j] = trans[j - i];
	}
	for (int j = i - 1; j >= 0; j--)
	{
		trans[j] = 0;
	}
}

// ��һ������
void OneMult(int* product, int onenum)
{
	for (int i = 123; i >= 0; i--)
	{
		int temp = product[i] * onenum;
		product[i] = temp % 10;
		product[i + 1] += temp / 10;
	}
}

// �����ӷ�
void Add(int* product, int* trans)
{
	for (int i = 0; i < 124; i++)
	{
		int temp = product[i] + trans[i];
		product[i] = temp % 10;
		product[i + 1] += temp / 10;
	}
}

// �����˷�
void Mult(int* product, int* num)
{
	memcpy(product1, product, 125 * sizeof(int));
	memset(product, 0, 125 * sizeof(int));
	for (int i = 0; i < 123; i++)
	{
		if (num[i] == 0)
			continue;
		else
		{
			memcpy(trans, product1, 125 * sizeof(int));
			OneMult(trans, num[i]);
			Adjust(trans, i);
			Add(product, trans);
		}
	}
}

