#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define ITEMNUM 100



#define ElemType int

//冒泡排序
void Bubblesort(ElemType R[], int n, int &comp_num, int &move_num)
{
	int i, j, flag = 1;     //当flag为0，则停止排序
	ElemType temp;
	for (i = 0; i < n - 1; i++){                      //i表示趟数，最多n-1趟
		flag = 0;
		for (j = 1; j < n - i; j++){      //表示每趟比较次数n-i-1
			comp_num++;
			if (R[j] < R[j - 1]){         //发生逆序
				temp = R[j];
				R[j] = R[j - 1];
				R[j - 1] = temp;    //交换
				move_num += 3;
				flag = 1; //标记发生了交换
			}
		}
		if (flag == 0) break;
	}
}

//快速排序
void quicksort(ElemType R[], int left, int right, int &comp_num, int &move_num)         //快速排序
{
	int i = left, j = right;
	ElemType temp = R[i];
	while (i<j){
		while ((R[j]>temp) && (i<j))
		{
			j--;
			comp_num++;
		}
		comp_num++;

		if (i < j){
			R[i++] = R[j];
			move_num++;
		}


		while ((R[i] < temp) && (i<j)){
			i++;
			comp_num++;
		}

		if (i<j){
			R[j--] = R[i];
			move_num++;
		}
	}


	//一次划分得到基准值的正确位置
	R[i] = temp;
	move_num++;
	if (left < i - 1)
		quicksort(R, left, i - 1, comp_num, move_num);             //递归调用左子区间
	if (i + 1 < right)
		quicksort(R, i + 1, right, comp_num, move_num);             //递归调用右子区间

}

//归并排序
void merge(ElemType R[], ElemType A[], int s, int m, int t, int &comp_num, int &move_num)
//对两个子区间R[s]~R[m]和R[m+1]~R[t]合并，结果存入A中
{
	int i, j, k;
	i = s; j = m + 1; k = s;
	while ((i <= m) && (j <= t))
	{
		comp_num++;

		if (R[i] <= R[j]){
			A[k] = R[i]; i++; k++;
			move_num++;
		}
		else{
			A[k] = R[j]; j++; k++;
			move_num++;
		}
	}
	while (i <= m){                  //复制第一个区间中剩下的元素
		A[k] = R[i]; i++; k++;
		move_num++;
	}
	while (j <= t){          //复制第二个区间中剩下的元素
		A[k] = R[j]; j++; k++;
		move_num++;
	}
}

//希尔排序
void ShellSort(ElemType R[], int n, int &comp_num, int &move_num)
{
	int i, j, d, k;
	ElemType temp;
	d = n / 2;   //d取初值n/2
	while (d>0)
	{
		comp_num++;
		for (i = d; i<n; i++)
		{
			j = i - d;
			while (j >= 0 && R[j]>R[j + d])
			{
				temp = R[j];
				R[j] = R[j + d];
				R[j + d] = temp;
				j = j - d;
				move_num++;
			}
		}
		printf("    d=%d:   ", d);//输出每一趟排序的结果
		for (k = 0; k<n; k++)
		{
			printf("%3d", R[k]);
		}
		printf("\n");
		d = d / 2;             //递减增量d
	}
}


void mergepass(ElemType R[], ElemType A[], int n, int c, int &comp_num, int &move_num)
//对R数组做一趟归并，结果存入A数组中，n为元素个数，c为区间长度
{
	int i, j;
	i = 0;
	while (i + 2 * c - 1 <= n - 1){          //长度均为c的两个区间合并成一个区间
		merge(R, A, i, i + c - 1, i + 2 * c - 1, comp_num, move_num);
		i += 2 * c;
	}
	if (i + c - 1 < n)   //长度不等的两个区间合并成一个区间
		merge(R, A, i, i + c - 1, n - 1, comp_num, move_num);
	else{
		for (j = i; j <= n - 1; j++)         //仅剩一个区间时，直接复制到A中
		{
			A[j] = R[j];
			move_num++;
		}
	}
}



void mergesort(ElemType R[], int n, int &comp_num, int &move_num)
{
	int c = 1;
	ElemType A[ITEMNUM];

	while (c < n){
		mergepass(R, A, n, c, comp_num, move_num);  //一次合并，结果存入A中
		c *= 2;  //区间长度扩大一倍
		mergepass(A, R, n, c, comp_num, move_num);   //再次合并，结果存入R中
		c *= 2;
	}
}



void print(ElemType R[], int n)
{
	for (int i = 0; i <= n - 1; i++){
		if (i % 10 == 0){
			printf("\n");
		}
		printf("%6d", R[i]);
	}
	printf("\n");
}





void producerandom(ElemType T[ITEMNUM])
{
	time_t t;
	srand(time(&t));   //time()返回从某点开始到现在的秒数，返回值与t的值一样
	for (int i = 0; i <= ITEMNUM; i++)
		T[i] = rand() % 1000;                 //产生的随机数
	print(T, ITEMNUM);                      //输出随机数
}


//折半查找
int BinSearch(ElemType R[], ElemType k)
{
	int low = 0, high = ITEMNUM - 1, mid;
	while (low <= high){
		mid = (low + high) / 2;
		if (R[mid] == k)      //查找成功返回
			return mid;
		if (R[mid] > k)  //继续在R[low..mid-1]中查找
			high = mid - 1;
		else
			low = mid + 1;  //继续在R[mid+1..high]中找
	}
	return -1;
}

void clear()      //自动清屏
{
	system("pause");
	system("cls");
}
void showmenu()
{
	printf("\n\n");
	printf("            ------排序与查找------            \n");
	printf("**********************************************\n");
	printf("*           1------ 产生随机数               *\n");
	printf("*           2------冒泡排序                  *\n");
	printf("*           3------快速排序                  *\n");
	printf("*           4------归并排序                  *\n");
	printf("*           5------希尔排序                  *\n");
	printf("*           6------查找                      *\n");
	printf("*                                            *\n");
	printf("*           0------退出                      *\n");
	printf("**********************************************\n");
	printf("请选择菜单号(0--6):");
}


void Sort_Search()
{
	ElemType R[ITEMNUM], T[ITEMNUM];
	int comp_num, move_num;            //比较和移动次数
	int i;
	char choice = 'N';

	int randfl = 0;   //随机数产生标志，0无，1有
	int sorted = 0;      //已排序标志

	while (choice != '0'){
		showmenu();
		flushall();
		scanf("%c", &choice);
		switch (choice){
		case '1':
			printf("\n\t产生随机数.......\n");
			producerandom(T);
			randfl = 1;  //随机数已产生
			sorted = 0;   //未排序
			//clear();
			break;
		case '2':
			if (randfl == 0){
				printf("\n\t请产生随机数\n");
			}
			else{
				printf("\n\t冒泡排序\n");
				comp_num = 0; move_num = 0;
				for (i = 0; i < ITEMNUM; i++) R[i] = T[i];
				Bubblesort(R, ITEMNUM, comp_num, move_num);
				print(R, ITEMNUM);
				printf("\t 数据比较次数：%d\t,数据移动次数：%d\t\n", comp_num, move_num);
				sorted = 1;                             //已排序
			}
			//clear();
			break;
		case '3':
			if (randfl == 0){
				printf("\n\t  请先产生随机数\n");
			}
			else{
				printf("\n\t快速排序\n");
				comp_num = 0; move_num = 0;
				for (i = 0; i < ITEMNUM; i++) R[i] = T[i];
				quicksort(R, 0, ITEMNUM - 1, comp_num, move_num);
				print(R, ITEMNUM);
				printf("\t数据比较次数为：%d\t,数据移动次数为：%d\n", comp_num, move_num);
				sorted = 1;

			}
			//clear();
			break;
		case '4':
			if (randfl == 0){
				printf("\n\t请产生随机数\n");
			}
			else{
				printf("\n\t归并排序\n");
				comp_num = 0; move_num = 0;
				for (i = 0; i < ITEMNUM; i++) R[i] = T[i];
				mergesort(R, ITEMNUM, comp_num, move_num);
				print(R, ITEMNUM);
				printf("\t数据比较次数为：%d\t,数据移动次数为：%d\n", comp_num, move_num);
				sorted = 1;
			}
			//clear();
			break;
		case'5':
			if (randfl == 0)
			{
				printf("\n\t请产生随机数\n");
			}
			else
			{
				printf("\n\t希尔排序\n");
				comp_num = 0; move_num = 0;
				for (i = 0; i < ITEMNUM; i++) R[i] = T[i];
				mergesort(R, ITEMNUM, comp_num, move_num);
				print(R, ITEMNUM);
				printf("\t数据比较次数为：%d\t,数据移动次数为：%d\n", comp_num, move_num);
				sorted = 1;
			}
			break;
		case '6':
			if (sorted == 0){
				printf("\n\t随机数还没排序呢！\n");
			}
			else{
				printf("\n\t折半查找\n");
				printf("\n\t请输入要查找的元素：");
				ElemType key;
				int sit;
				scanf("%d", &key);
				sit = BinSearch(R, key);
				if (sit != -1){
					printf("\t\t找到该元素，它的位序是：%d\n", sit + 1);
				}
				else{
					printf("\t\t查找失败\n");
				}
			}
			//clear();
			break;

		case '0':
			printf("\n\t程序结束！\n");
			break;
		default:
			printf("\n\t输入错误，请重新输入！\n");
		}
		if (choice != '0'){
			flushall();
			//printf("\t\t 按回车键继续......\n");
			clear();
			scanf("%c", &choice);
		}
	}
}


}


