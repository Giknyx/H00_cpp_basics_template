#include <iostream>   // cout
#include <algorithm>  // copy, fill

#include "tasks.hpp"

// ИСПОЛЬЗОВАНИЕ ЛЮБЫХ ДРУГИХ БИБЛИОТЕК НЕ СОВЕТУЕТСЯ И МОЖЕТ ПОВЛИЯТЬ НА ВАШИ БАЛЛЫ

using std::cout;
using std::fill;
using std::copy;

// Задание 1
void swap_args(int *lhs, int *rhs) {
    if (!lhs || !rhs) {
        return;
    }
    int temp = *rhs;
    *rhs = *lhs;
    *lhs = temp;
}

// Задание 2
int **allocate_2d_array(int num_rows, int num_cols, int init_value) {
    if (num_cols <= 0 || num_rows <= 0) {
        return nullptr;
    }
    int **array_2d = new int *[num_rows];
    for (int row_index = 0; row_index < num_rows; ++row_index) {
        array_2d[row_index] = new int[num_cols];
        fill(array_2d[row_index], array_2d[row_index] + num_cols, init_value);
    }
    return array_2d;
}

// Задание 3
bool copy_2d_array(int **arr_2d_source, int **arr_2d_target, int num_rows, int num_cols) {
    if (!arr_2d_source || !arr_2d_target || !*arr_2d_target || !*arr_2d_source) {
        return false;
    }
    if (num_rows <= 0 || num_cols <= 0) {
        return false;
    }
    for (int row_index = 0; row_index < num_rows; ++row_index) {
        copy(arr_2d_source[row_index], arr_2d_source[row_index] + num_cols, arr_2d_target[row_index]);
    }
    return true;
}

// Задание 4
void reverse_1d_array(vector<int> &arr) {
    int arr_size = arr.size();
    int temp;
    for (int i = 0; i < arr_size/2; i++) {
        temp = arr[i];
        arr[i] = arr[arr_size - i - 1];
        arr[arr_size - i - 1] = temp;
    }
}

// Задание 5
void reverse_1d_array(int *arr_begin, int *arr_end) {
    if (!arr_begin || !arr_end) {
        return;
    }
    int temp;
    while (arr_begin < arr_end) {
        temp = *arr_end;
        *arr_end = *arr_begin;
        *arr_begin = temp;
        arr_begin++;
        arr_end--;
    }
}

// Задание 6
int *find_max_element(int *arr, int size) {
    if (!arr || size <= 0) {
        return nullptr;
    }
    int *max = arr;
    int *element = arr;
    for (int i = 1; i < size; i++) {
        element++;
        if (*element > *max) {
            max = element;
        }
    }
    return max;
}

// Задание 7
vector<int> find_odd_numbers(vector<int> &arr) {
    if (arr.empty()) {
        return {};
    }
    vector<int> res;
    for (int element : arr) {
        if (element % 2 != 0) {
            res.push_back(element);
        }
    }
    return res;
}

// Задание 8
vector<int> find_common_elements(vector<int> &arr_a, vector<int> &arr_b) {
    if (arr_a.empty() || arr_b.empty()) {
        return {};
    }
    vector<int> res;
    bool flag = true;
    for (int element_a : arr_a) {
        for (int element_b : arr_b) {
            if (element_a == element_b) {  // Можно упростить, при совпадении добавлять элемент в res и удаляя все его копии из arr_b
                for (int i : res) {
                    if (i == element_a) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    res.push_back(element_a);
                    flag = true;
                    break;
                }
                flag = true;
            }
        }
    }
    return res;
}
