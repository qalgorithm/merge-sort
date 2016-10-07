//
//  main.cpp
//  merge_sort
//
//  Created by Quoc Le on 10/7/16.
//  Copyright © 2016 Shizzle. All rights reserved.
//

#include <iostream>
#define MAX 10
int TempArray[MAX];

void Merge(int a[], int Left, int Mid, int Right) {
    // c1, c2: vị trí hiện tại trên dãy con trái, dãy con phải
    int c1, c2;
    // d: vị trí hiện tại trên dãy tạm
    int d;
    for(d=Left, c1=Left, c2=Mid+1; (c1 <= Mid) && (c2 <= Right); d++ ) {
        if (a[c1] < a[c2]) { // lấy phần tử trên dãy con trái
            TempArray[d] = a[c1++];
        }
        else { // lấy phần tử trên dãy con phải
            TempArray[d] = a[c2++];
        } // end if
    } // end for
    // Khi 1 trong 2 dãy đã hết phần tử...
    // Hoàn tất dãy bên trái
    for( ; c1 <= Mid; c1++, d++ ) TempArray[d] = a[c1];
    // Hoàn tất dãy bên phải
    for( ; c2 <= Right; c2++, d++ ) TempArray[d] = a[c2];
    // Sau khi trộn, copy mảng tạm trở lại mảng gốc
    for (d=Left; d<=Right; d++) {
        a[d] = TempArray[d];
    }
} // end of Merge

void MergeSort(int a[], int Left, int Right) {
    int Mid; // Vị trí của phần tử giữa
    if (Left < Right) { // Dãy có > 1 phần tử
        Mid = (Left + Right)/2; // Chia thành 2 dãy ...
        MergeSort(a, Left, Mid); // Trộn 1⁄2 dãy bên trái
        MergeSort(a, Mid+1, Right); // Trộn 1⁄2 dãy bên phải
        Merge(a, Left, Mid, Right); // Trộn 2 dãy lại với nhau
    }
} // end of MergeSort

int main(int argc, const char * argv[]) {
    int a[10] = {11, 31, 42, 22, 55, 5, 56, 67, 89, 12};
    MergeSort(a, 0, 9);
    for (int i = 0; i < 10; i++) {
        std::cout << a[i] << " ";
    }
    return 0;
}
