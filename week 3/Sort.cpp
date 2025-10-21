#include <iostream>
using namespace std;

void Partition(int A[], int left, int right)
{
    // Kiểm tra xem nếu mảng có 1 phần tử thì không cần sắp xếp
    if (left >= right)
        return;

    int pivot = A[(left + right) / 2]; // Chọn phần tử chính giữa dãy làm chốt

    // i là vị trí đầu và j là cuối đoạn
    int i = left, j = right;
    while (i < j)
    {
        while (A[i] < pivot) // Nếu phần tử bên trái nhỏ hơn pivot thì ok, bỏ qua
            i++;
        while (A[j] > pivot) // Nếu phần tử bên phải nhỏ hơn pivot thì ok, bỏ qua
            j--;

        // Sau khi kết thúc hai vòng while ở trên thì chắc chắn
        // vị trí A[i] phải lớn hơn pivot và A[j] phải nhỏ hơn pivot
        // nếu i < j
        if (i <= j)
        {
            if (i < j) // nếu i != j (tức không trùng thì mới cần hoán đổi)
                swap(A[i], A[j]); // Thực hiện đổi chổ ta được A[i] < pivot và A[j] > pivot
            i++;
            j--;
        }
    }

    // Gọi đệ quy sắp xếp dãy bên trái pivot
    Partition(A, left, j);
    // Gọi đệ quy sắp xếp dãy bên phải pivot
    Partition(A, i, right);
}

// Hàm sắp xếp chính
void QuickSort(int A[], int n)
{
    Partition(A, 0, n - 1);
}

void Merge(int A[], int left, int mid, int right)
{
    int n1 = mid - left + 1; 
    int n2 = right - mid; 

    // Tạo hai mảng tạm để lưu hai mảng con
    int *LeftArr = new int[n1];
    int *RightArr = new int[n2];

    // Sao chép phần tử 2 mảng con vào mảng tạm
    for (int i = 0; i < n1; i++)
        LeftArr[i] = A[left + i];
    for (int i = 0; i < n2; i++)
        RightArr[i] = A[mid + 1 + i];

    // current là vị trí hiện tại trong mảng A
    int i = 0, j = 0, current = left;

    // Trộn hai mảng vào nhau theo đúng thứ tự
    while (i < n1 && j < n2)
        if (LeftArr[i] <= RightArr[j])
            A[current++] = LeftArr[i++];
        else
            A[current++] = RightArr[j++];

    // Nếu mảng thứ nhất còn phần tử thì copy nó vào mảng A
    while (i < n1)
        A[current++] = LeftArr[i++];

    // Nếu mảng thứ hai còn phần tử thì copy nó vào mảng A
    while (j < n2)
        A[current++] = RightArr[j++];

    // Xóa hai mảng tạm đi
    delete[] LeftArr, RightArr;
}

// Hàm chia đôi mảng và gọi hàm trộn
void _MergeSort(int A[], int left, int right)
{
    // Kiểm tra xem còn chia đôi mảng được không
    if (left < right)
    {
        // Tìm phần tử chính giữa
        // left + (right - left) / 2 tương đương với (left + right) / 2
        // việc này giúp tránh bị tràn số với left, right quá lớn
        int mid = left + (right - left) / 2;
 
        // Sắp xếp mảng thứ nhất
        _MergeSort(A, left, mid);
        // Sắp xếp mảng thứ hai
        _MergeSort(A, mid + 1, right);

        // Trộn hai mảng đã sắp xếp
        Merge(A, left, mid, right);
    }
}

// Hàm sắp xếp chính, được gọi khi dùng merge sort
void MergeSort(int A[], int n)
{
    _MergeSort(A, 0, n - 1);
}