#include <iostream>
using namespace std;

//array of integers to hold values
int arr[20];
int cmp_count = 0; // number of comparasiom
int mov_count = 0; // number of data movement
int n;

void input() {
	while (true)
	{
		cout << "Masukan panjang element array: ";
		cin >> n;

		if (n <= 20)
			break;
		else
			cout << "\nMasukan panjang array adalah 0" << endl;
	}

	cout << "\n===================" << endl;
	cout << "\nEnter Array Element" << endl;
	cout << "\n===================" << endl;

	for (int i = 0; i < n; i++)
	{
		cout << "<" << (i + 1) << ">";
		cin >> arr[i];
	}
}
// swap the element at index z with the element at index y
void swap(int x, int y)
{
	int temp;

	temp = arr[x];
	arr[x] = arr[y];
	arr[y] = temp;
}
void q_short(int low, int high)
{
	int pivot, i, j;
	if (low > high)// Langkah 1
		return;

	//Partition the list into two parts:
	//one containing element less that or equal to pivot 
	//Outher consyainning elments greather than pivot

	pivot = arr[low];//langkah 2

	i = low + 1;//langkah 1
	j = high;//langkah 4

	while (i <= j)//langkah 10
	{
		//seach for an element grater than pivot
		while ((arr[i] <= pivot) && (i <= high))//langkah 5
		{
			i++;//langkah 6
			cmp_count++;
		}
		cmp_count++;
		//search for an element greater then pivot 
		while ((arr[i] > pivot) && (j >= low))// langkah 7
		{
			j--;// langkah 8
			cmp_count++;
		}
		cmp_count++;
		if (i < j) // langkah 9
			// if the greater elemnet is on the left of the element
		{
			//swap the elemnt at index i whit the element at index j
			swap(i, j);
			mov_count++;
		}
	}
	// j now conntaint the index of the last ement in the sorted list
	if (low < j)//langkah 11
	{
		//move the pivot to its correct position in the list
		swap(low, j);
		mov_count++;
	}
	//sort the list on the left of pivot using quck sort
	q_short(low, j - 1);//langkah 12

	//sort the list on the right of pivot using quick sort
	q_short(j + 1, high);//langkah 13


}
void display() {
	cout << "\n=============================" << endl;
	cout << "Serted Array" << endl;
	cout << "\n=============================" << endl;


	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}

	cout << "\n\nNumber of comparasions: " << cmp_count << endl;
	cout << "Number of data movements : " << mov_count << endl;
}
int main()
{
	input();
	//Sort the array using quick sort
	q_short(0, n - 1);
	display();
	system("pause");

	return 0;
}