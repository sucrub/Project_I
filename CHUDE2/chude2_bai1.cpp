#include<bits/stdc++.h>
#include<fstream>
#include<time.h>
#include<iomanip>
using namespace std;

int N = 10000000;

/////////////////////////////////////////////////////

int partition_2_way(int *a, int low, int high) {

    // lay diem moc la gia tri cuoi
    int pivot = a[high];
    int i = low;
    for(int j = low; j < high; j++) { // duyet tat ca cac so
    
        if(a[j] < pivot) {
            i = i + 1;
            swap(a[i], a[j]);
        }
    }
    // dua pivot ve vi tri dung cua no
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quick_sort_2_way(int *a, int low, int high) {

    if(low >= high) return;
    // pi la diem moc
    int pi = partition_2_way(a, low, high);
    // lap lai o hai ben
    quick_sort_2_way(a, low, pi - 1);
    quick_sort_2_way(a, pi + 1, high);
}

///////////////////////////////////////////////////////////////

void partition_3_way(int *a, int low, int high, int& i, int& j) { //[low , i] - [i + 1 , j - 1] - [j , high]

    i = low - 1, j = high;
    int p = low - 1, q = high;
    // v = phan tu cuoi
    int v = a[high];
 
    while (true) {

        // tim so dau tien >= v tu trai qua phai
        while (a[++i] < v) //bo qua, o yen vi tri do, con tro i di chuyen neu so do nho hon v
            ;
 
        // tim so dau tien <= v tu phai qua trai
        while (v < a[--j])
            if (j == low)
                break;
 
        // neu i va j di qua nhau thi xet xong
        if (i >= j)
            break;
 
        // Swap de so nho hon sang ben trai, so to hon sang ben phai
        swap(a[i], a[j]);

        // Cho tat cac cac so bang pivot ve dau array va dem bang bien p
        if (a[i] == v) {

            p++;
            swap(a[p], a[i]);
        }
 
        // Cho tat ca cac so bang pivot ve cuoi array va dem bang bien j
        if (a[j] == v) {

            q--;
            swap(a[j], a[q]);
        }
    }
 
    // Dua pivot ve vi tri dung
    swap(a[i], a[high]);
 
    // Dua cac phan tu bang pivot o dau ve dung vi tri
    j = i - 1;
    for (int k = low; k < p; k++, j--)
        swap(a[k], a[j]);
 
    // Dua cac phan tu bang pivot o cuoi ve dung vi tri
    i = i + 1;
    for (int k = high - 1; k > q; k--, i++)
        swap(a[i], a[k]);
}
 
void quick_sort_3_way(int *a, int low, int high) {

    if (high <= low) return;
 
    int i, j;
 
    partition_3_way(a, low, high, i, j);
 
    quick_sort_3_way(a, low, j);
    quick_sort_3_way(a, i, high);
}

//////////////////////////////////////////////////////

int main() {

    cout << setprecision(10);
    clock_t start, end;
    double time_use;

    int index1 = 0;
    ifstream f1;
    f1.open(to_string(N) + ".txt");
    int *a = new int[N];
    int *b = new int[N];
    while(!f1.eof()) {
        int n;
        f1 >> n;
        a[index1] = n;
        b[index1] = n;
        index1++;
    }
    start = clock();
    quick_sort_2_way(a, 0, N - 1);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "quicksort 2 way " << N << " numbers: " << time_use << endl;

    start = clock();
    quick_sort_3_way(b, 0, N - 1);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "quicksort 3 way " << N << " numbers: " << time_use << endl;
    delete []a;
    delete []b;
    f1.close();
}