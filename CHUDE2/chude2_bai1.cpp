#include<bits/stdc++.h>
#include<fstream>
#include<time.h>
#include<iomanip>
using namespace std;

int N = 1000000;

int partition_2_way(int *a, int low, int high) {

    int pivot = a[high];
    int i = low;
    for(int j = low; j < high; j++) {
        if(a[j] < pivot) {
            i = i + 1;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

void quick_sort_2_way(int *a, int low, int high) {

    if(low >= high) return;
    int pi = partition_2_way(a, low, high);
    quick_sort_2_way(a, low, pi - 1);
    quick_sort_2_way(a, pi + 1, high);
}

void partition_3_way(int *a, int low, int high, int& i, int& j)
{
    i = low - 1, j = high;
    int p = low - 1, q = high;
    int v = a[high];
 
    while (true) {
        // From left, find the first element greater than
        // or equal to v. This loop will definitely
        // terminate as v is last element
        while (a[++i] < v)
            ;
 
        // From right, find the first element smaller than
        // or equal to v
        while (v < a[--j])
            if (j == low)
                break;
 
        // If i and j cross, then we are done
        if (i >= j)
            break;
 
        // Swap, so that smaller goes on left greater goes
        // on right
        swap(a[i], a[j]);
 
        // Move all same left occurrence of pivot to
        // beginning of array and keep count using p
        if (a[i] == v) {
            p++;
            swap(a[p], a[i]);
        }
 
        // Move all same right occurrence of pivot to end of
        // array and keep count using q
        if (a[j] == v) {
            q--;
            swap(a[j], a[q]);
        }
    }
 
    // Move pivot element to its correct index
    swap(a[i], a[high]);
 
    // Move all left same occurrences from beginning
    // to adjacent to arr[i]
    j = i - 1;
    for (int k = low; k < p; k++, j--)
        swap(a[k], a[j]);
 
    // Move all right same occurrences from end
    // to adjacent to arr[i]
    i = i + 1;
    for (int k = high - 1; k > q; k--, i++)
        swap(a[i], a[k]);
}
 
// 3-way partition based quick sort
void quick_sort_3_way(int *a, int low, int high)
{
    if (high <= low)
        return;
 
    int i, j;
 
    // Note that i and j are passed as reference
    partition_3_way(a, low, high, i, j);
 
    // Recur
    quick_sort_3_way(a, low, j);
    quick_sort_3_way(a, i, high);
}

int main() {

    // cout << setprecision(20);
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
    quick_sort_2_way(a, 0, N);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "quicksort 2 way " << N << " numbers: " << time_use << endl;

    start = clock();
    quick_sort_3_way(b, 0, N);
    end = clock();
    time_use = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "quicksort 3 way " << N << " numbers: " << time_use << endl;

    delete []a;
    delete []b;
    f1.close();
}