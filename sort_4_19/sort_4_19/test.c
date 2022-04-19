#define _CRT_SECURE_NO_WARNINGS 1


//�ڿӷ�������������
// ���εݹ��˼��
//����Ĳ���left�Ǹ�����������ĵ�һ���±꣬right�Ǹ���������������һ���±�
void QuickSort(int* a, int left, int right)
{
	if (left >= right)//ÿ�εݹ������������left>right�ͱ�ʾ�������Ѿ��źã�����ݹ���
					 //left=right�ͱ�ʾ������ֻ��һ������һ����Ҳ�����ź��ˣ�����ݹ���
	{
		return 0;
	}

	//����ȡ�У��õ��� ��СΪ�м���Ǹ�Ԫ�ص� �±�index
	int index = GetMidIndex(a, left, right);//left�ǵ�һ��Ԫ�ص��±꣬right�����һ��Ԫ�ص��±�
	Swap(&a[left], &a[index]);//�����һ��Ԫ�غ�����ȡ�е�Ԫ�ؽ�����ʹ��ȡ�е��Ǹ�������˵�һ��Ԫ��
							  //�������Ǻ���Ĵ��벻��ı䣬������ѡ�ĵ�һ��Ԫ�����ؼ��֣���Ϊ�Ѿ�������

	int begin = left, end = right;
	int pivot = begin;//�ӵ��±�
	int key = a[begin];//�ؼ���ѡ������ĵ�һ��Ԫ�ؿ��ԣ����һ��Ԫ��Ҳ���ԣ���һ��

	while (begin < end)//���� begin<end ��ѭ������������
	{
		// �ұ���С���ŵ����
		while (begin < end && a[end] >= key)//����� begin<end �Ƿ�ֹ����Խ��
			--end;

		// С�ķŵ���ߵĿ���Լ��γ��µĿ�λ
		a[pivot] = a[end];
		pivot = end;

		// ����Ҵ�
		while (begin < end && a[begin] <= key)
			++begin;

		// ��ķŵ���ߵĿ���Լ��γ��µĿ�λ
		a[pivot] = a[begin];
		pivot = begin;
	}

	//����ѭ���󣬰ѹؼ��ַ���������λ����
	pivot = begin;
	a[pivot] = key;//�ѹؼ��ַŽ�ȥ

	//(�������±��ʾ)
	//�ź�һ�����󣬰���� �������� �ֳ� ������ �� ������
	//�� [left,right] 
	//������[left,pivot-1] �Ѿ��źõ������±�pivot ������[pivot+1,right]
	//Ȼ����÷��εݹ�ķ�����������ÿ�������Ϊ������������䣬ֱ�������ź�
	//�е�����������ǰ�����   �� ������ ������

	//�������Ż�
	if (pivot - 1 - left > 10)
	{
		QuickSort(a, left, pivot - 1);
	}
	else
	{
		InsertSort(a + left, pivot - 1 - left + 1);
	}

	if (right - (pivot + 1) > 10)
	{
		QuickSort(a, pivot + 1, right);
	}
	else
	{
		InsertSort(a + pivot + 1, right - (pivot + 1) + 1);
	}

}










//����ָ�뷨������������
//����
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// ����ȡ��    left�ǵ�һ��Ԫ�ص��±꣬right�����һ��������±�
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;//Ҳ�����ó�����һ����

	//�������е����
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

// ���εݹ��˼��
//����Ĳ���left�Ǹ�����������ĵ�һ���±꣬right�Ǹ���������������һ���±�
void QuickSort(int* a, int left, int right)
{
	if (left >= right)//ÿ�εݹ������������left>right�ͱ�ʾ�������Ѿ��źã�����ݹ���
					 //left=right�ͱ�ʾ������ֻ��һ������һ����Ҳ�����ź��ˣ�����ݹ���
	{
		return 0;
	}

	//����ȡ�У��õ��� ��СΪ�м���Ǹ�Ԫ�ص� �±�index
	int index = GetMidIndex(a, left, right);//left�ǵ�һ��Ԫ�ص��±꣬right�����һ��Ԫ�ص��±�
	Swap(&a[left], &a[index]);//�����һ��Ԫ�غ�����ȡ�е�Ԫ�ؽ�����ʹ��ȡ�е��Ǹ�������˵�һ��Ԫ��
							  //�������Ǻ���Ĵ��벻��ı䣬������ѡ�ĵ�һ��Ԫ�����ؼ��֣���Ϊ�Ѿ�������

	int begin = left, end = right;
	int key = begin;//key�ǹؼ��ֵ��±꣬�ؼ���ѡ������ĵ�һ��Ԫ�ؿ��ԣ����һ��Ԫ��Ҳ���ԣ���һ��

	while (begin < end)//���� begin<end ��ѭ������������
	{
		// �ұ���С
		while (begin < end && a[end] >= key)//����� begin<end �Ƿ�ֹ����Խ��
			--end;


		// ����Ҵ�
		while (begin < end && a[begin] <= key)
			++begin;

		// ������ʱ�±�begin �� �±�end ��Ӧ�������Ԫ��
		Swap(&a[begin], &a[key]);
	}

	//����ѭ���󣬽��� �ؼ��� �� begin��end����ʱ���±���ָ������Ԫ��
	Swap(&a[begin], &a[end]);//��ʱbegin��end���

	//(�������±��ʾ)
	//�ź�һ�����󣬰���� �������� �ֳ� ������ �� ������
	//�� [left,right]  ��ʱbegin��end���
	//������[left,begin-1] �Ѿ��źõ������±�begin/end ������[begin+1,right]
	//Ȼ����÷��εݹ�ķ�����������ÿ�������Ϊ������������䣬ֱ�������ź�
	//�е�����������ǰ�����   �� ������ ������

	//�������Ż�
	if (begin - 1 - left > 10)
	{
		QuickSort(a, left, begin - 1);
	}
	else
	{
		InsertSort(a + left, begin - 1 - left + 1);
	}

	if (right - (begin + 1) > 10)
	{
		QuickSort(a, begin + 1, right);
	}
	else
	{
		InsertSort(a + begin + 1, right - (begin + 1) + 1);
	}

}










//ǰ��ָ�뷨������������
//����
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// ����ȡ��    left�ǵ�һ��Ԫ�ص��±꣬right�����һ��������±�
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;//Ҳ�����ó�����һ����

	//�������е����
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if (a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else // a[left] > a[mid]
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}

// ���εݹ��˼��
//����Ĳ���left�Ǹ�����������ĵ�һ���±꣬right�Ǹ���������������һ���±�
void QuickSort(int* a, int left, int right)
{
	if (left >= right)//ÿ�εݹ������������left>right�ͱ�ʾ�������Ѿ��źã�����ݹ���
					 //left=right�ͱ�ʾ������ֻ��һ������һ����Ҳ�����ź��ˣ�����ݹ���
	{
		return 0;
	}

	//����ȡ�У��õ��� ��СΪ�м���Ǹ�Ԫ�ص� �±�index
	int index = GetMidIndex(a, left, right);//left�ǵ�һ��Ԫ�ص��±꣬right�����һ��Ԫ�ص��±�
	Swap(&a[left], &a[index]);//�����һ��Ԫ�غ�����ȡ�е�Ԫ�ؽ�����ʹ��ȡ�е��Ǹ�������˵�һ��Ԫ��
							  //�������Ǻ���Ĵ��벻��ı䣬������ѡ�ĵ�һ��Ԫ�����ؼ��֣���Ϊ�Ѿ�������

	int prev = left, cur = left + 1;//����һǰ�±�Ϊprev��һ���±�Ϊcur
	int key = left;//key�ǹؼ��ֵ��±꣬�ؼ���ѡ������ĵ�һ��Ԫ�ؿ��ԣ����һ��Ԫ��Ҳ���ԣ���һ��

	while (cur <= right)
	{
		//��������ͬʱ���㣬�����±�cur��prev��Ӧ��Ԫ��
		if (a[cur] < a[key] && ++prev != cur)
		{
			Swap(&a[cur], &a[cur]);
		}

		++cur;//�����Ƿ񽻻���cur����ǰ��һ��
	}
	Swap(&a[key], &a[prev]);//����ѭ���󣬽��� �ؼ��� �� �±�prev��Ӧ��Ԫ��


	//(�������±��ʾ)
	//�ź�һ�����󣬰���� �������� �ֳ� ������ �� ������
	//�� [left,right]  ��ʱ�Ѿ��źõ�Ԫ�ص��±��� prev
	//������[left,prve-1] �Ѿ��źõ������±�prev ������[prve+1,right]
	//Ȼ����÷��εݹ�ķ�����������ÿ�������Ϊ������������䣬ֱ�������ź�
	//�е�����������ǰ�����   �� ������ ������

	//�������Ż�
	if (prev - 1 - left > 10)
	{
		QuickSort(a, left, prev - 1);
	}
	else
	{
		InsertSort(a + left, prev - 1 - left + 1);
	}

	if (right - (prev + 1) > 10)
	{
		QuickSort(a, prev + 1, right);
	}
	else
	{
		InsertSort(a + prev + 1, right - (prev + 1) + 1);
	}

}