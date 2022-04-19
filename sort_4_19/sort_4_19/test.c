#define _CRT_SECURE_NO_WARNINGS 1


//挖坑法快速排序整体
// 分治递归的思想
//这里的参数left是给的数组区间的第一个下标，right是给的数组区间的最后一个下标
void QuickSort(int* a, int left, int right)
{
	if (left >= right)//每次递归结束的条件，left>right就表示该区间已经排好，无需递归了
					 //left=right就表示该区间只有一个数，一个数也能算排好了，无需递归了
	{
		return 0;
	}

	//三数取中，得到了 大小为中间的那个元素的 下标index
	int index = GetMidIndex(a, left, right);//left是第一个元素的下标，right是最后一个元素的下标
	Swap(&a[left], &a[index]);//这里第一个元素和三数取中的元素交换，使得取中的那个数变成了第一个元素
							  //这样我们后面的代码不会改变，依旧是选的第一个元素做关键字，因为已经交换了

	int begin = left, end = right;
	int pivot = begin;//坑的下标
	int key = a[begin];//关键字选该区间的第一个元素可以，最后一个元素也可以，都一样

	while (begin < end)//这里 begin<end 是循环结束的条件
	{
		// 右边找小，放到左边
		while (begin < end && a[end] >= key)//这里的 begin<end 是防止数组越界
			--end;

		// 小的放到左边的坑里，自己形成新的坑位
		a[pivot] = a[end];
		pivot = end;

		// 左边找大
		while (begin < end && a[begin] <= key)
			++begin;

		// 大的放到左边的坑里，自己形成新的坑位
		a[pivot] = a[begin];
		pivot = begin;
	}

	//跳出循环后，把关键字放在相遇的位置上
	pivot = begin;
	a[pivot] = key;//把关键字放进去

	//(区间用下标表示)
	//排好一个数后，把这个 数组区间 分成 左区间 和 右区间
	//如 [left,right] 
	//左区间[left,pivot-1] 已经排好的数的下标pivot 右区间[pivot+1,right]
	//然后采用分治递归的方法，继续将每个区间分为左区间和右区间，直到所有排好
	//有点像二叉树里的前序遍历   根 左子树 右子树

	//在这里优化
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










//左右指针法快速排序整体
//交换
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// 三数取中    left是第一个元素的下标，right是最后一个数组的下标
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;//也可以用除法，一样的

	//考虑所有的情况
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

// 分治递归的思想
//这里的参数left是给的数组区间的第一个下标，right是给的数组区间的最后一个下标
void QuickSort(int* a, int left, int right)
{
	if (left >= right)//每次递归结束的条件，left>right就表示该区间已经排好，无需递归了
					 //left=right就表示该区间只有一个数，一个数也能算排好了，无需递归了
	{
		return 0;
	}

	//三数取中，得到了 大小为中间的那个元素的 下标index
	int index = GetMidIndex(a, left, right);//left是第一个元素的下标，right是最后一个元素的下标
	Swap(&a[left], &a[index]);//这里第一个元素和三数取中的元素交换，使得取中的那个数变成了第一个元素
							  //这样我们后面的代码不会改变，依旧是选的第一个元素做关键字，因为已经交换了

	int begin = left, end = right;
	int key = begin;//key是关键字的下标，关键字选该区间的第一个元素可以，最后一个元素也可以，都一样

	while (begin < end)//这里 begin<end 是循环结束的条件
	{
		// 右边找小
		while (begin < end && a[end] >= key)//这里的 begin<end 是防止数组越界
			--end;


		// 左边找大
		while (begin < end && a[begin] <= key)
			++begin;

		// 交换此时下标begin 和 下标end 对应的数组的元素
		Swap(&a[begin], &a[key]);
	}

	//跳出循环后，交换 关键字 和 begin和end相遇时候下标所指向数组元素
	Swap(&a[begin], &a[end]);//此时begin和end相等

	//(区间用下标表示)
	//排好一个数后，把这个 数组区间 分成 左区间 和 右区间
	//如 [left,right]  此时begin和end相等
	//左区间[left,begin-1] 已经排好的数的下标begin/end 右区间[begin+1,right]
	//然后采用分治递归的方法，继续将每个区间分为左区间和右区间，直到所有排好
	//有点像二叉树里的前序遍历   根 左子树 右子树

	//在这里优化
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










//前后指针法快速排序整体
//交换
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

// 三数取中    left是第一个元素的下标，right是最后一个数组的下标
int GetMidIndex(int* a, int left, int right)
{
	int mid = (left + right) >> 1;//也可以用除法，一样的

	//考虑所有的情况
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

// 分治递归的思想
//这里的参数left是给的数组区间的第一个下标，right是给的数组区间的最后一个下标
void QuickSort(int* a, int left, int right)
{
	if (left >= right)//每次递归结束的条件，left>right就表示该区间已经排好，无需递归了
					 //left=right就表示该区间只有一个数，一个数也能算排好了，无需递归了
	{
		return 0;
	}

	//三数取中，得到了 大小为中间的那个元素的 下标index
	int index = GetMidIndex(a, left, right);//left是第一个元素的下标，right是最后一个元素的下标
	Swap(&a[left], &a[index]);//这里第一个元素和三数取中的元素交换，使得取中的那个数变成了第一个元素
							  //这样我们后面的代码不会改变，依旧是选的第一个元素做关键字，因为已经交换了

	int prev = left, cur = left + 1;//定义一前下标为prev，一后下标为cur
	int key = left;//key是关键字的下标，关键字选该区间的第一个元素可以，最后一个元素也可以，都一样

	while (cur <= right)
	{
		//两个条件同时满足，交换下标cur和prev对应的元素
		if (a[cur] < a[key] && ++prev != cur)
		{
			Swap(&a[cur], &a[cur]);
		}

		++cur;//无论是否交换，cur都往前走一步
	}
	Swap(&a[key], &a[prev]);//跳出循环后，交换 关键字 和 下标prev对应的元素


	//(区间用下标表示)
	//排好一个数后，把这个 数组区间 分成 左区间 和 右区间
	//如 [left,right]  此时已经排好的元素的下标是 prev
	//左区间[left,prve-1] 已经排好的数的下标prev 右区间[prve+1,right]
	//然后采用分治递归的方法，继续将每个区间分为左区间和右区间，直到所有排好
	//有点像二叉树里的前序遍历   根 左子树 右子树

	//在这里优化
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