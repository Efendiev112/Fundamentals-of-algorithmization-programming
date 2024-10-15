#include <iostream>
using namespace std;

//int SIZE = 5;



//пузырек
void BubbleSort(int arr[]) {  
    cout << "Sort by bubble ->" << endl;
    bool flag = false;
    for (int i = 0; i < 5 - i; i++) {
        flag = true;
        for (int j = 0; j < 5 - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                flag = false;
            }
        }
        if (flag) break;
    }


}



//сортировка вставками 

void InsertSort(int arr[]) { 
    cout << "Sort by insert ->" << endl;
    for (int i = 1; i < 5; i++) {
        for (int j = i; j > 0; j--) {
            if (arr[j] < arr[j - 1]) {
                swap(arr[j], arr[j - 1]);

            }
            else {
                break;
            }
        }
    }
}



//быстрая сортировка
void QuickSort(int arr[], int start, int end) {
    cout << "Sort by quickSort ->" << endl;
    if (start < end) {
        int opora = arr[end];
        int index = start - 1;

        for (int j = start; j < end; j++) {
            if (arr[j] <= opora) {
                index++;
                swap(arr[index], arr[j]);
            }
        }
        swap(arr[index + 1], arr[end]); 
        int Pindex = index + 1; 

        QuickSort(arr, start, Pindex - 1);
        QuickSort(arr, Pindex + 1, end);
    }
}




//сортировка слиянием
void MergeSort(int arr[], int size) { 
    cout << "Sort by merge ->" << endl;

    if (size < 2) return;
    int MidArr = size / 2; 
    int* RightArr = new int[size - MidArr]; 
    int* LeftArr = new int[MidArr];

    for (int i = 0; i < MidArr; i++) LeftArr[i] = arr[i]; 
    for (int j = MidArr; j < size; j++) RightArr[j - MidArr] = arr[j];

    MergeSort(LeftArr, MidArr); 
    MergeSort(RightArr, size - MidArr);

    int index = 0, j = 0, k = 0; 


    while (index < MidArr && j < size - MidArr) 
    {
        if (LeftArr[index] <= RightArr[j]) arr[k++] = LeftArr[index++];
        else arr[k++] = RightArr[j++];
    }

    while (index < MidArr) 
    {
        arr[k++] = LeftArr[index++];
    }

    while (j < size - MidArr)
    {
        arr[k++] = RightArr[j++];
    }

    delete[] LeftArr; 
    delete[] RightArr;
}





//бинарный поиск
int binarySearch(int arr[], int size, int el) { 
    cout << "binary search ->" << endl;
    int right = size - 1; 
    int left = 0;
    //int mid = left + (right - left) / 2;

    while (left <= right) {
        int mid = left + (right - left) / 2; 

        if (arr[mid] == el) {
            return mid;
        }

        else if (arr[mid] < el) {
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }

    return -1; 
}



void ShowArr(int arr[])
{
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}



int main()
{
    //cout << "bebebebe!\n";
    int arr[] = { 1,5,9,-2,4 };
    ShowArr(arr);
    //BubbleSort(arr);
    //InsertSort(arr);
    //QuickSort(arr,0,4);
    //MergeSort(arr,5);
    binarySearch(arr, 5, 9);
    ShowArr(arr);
}