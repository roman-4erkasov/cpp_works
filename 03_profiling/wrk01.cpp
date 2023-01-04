// Заголовок cstdlib понадобится для функции rand,
// выдающей случайные числа.
/**
 * compile: g++ -std=c++17 wrk01.cpp
 * run: time ./a.out
 * 
 * original time:
 * real    0m0.779s
 * user    0m0.755s
 * sys     0m0.011s
 * 
 * time without cout:
 * real    0m1.424s
 * user    0m0.752s
 * sys     0m0.012s
 * 
 * time without CountPops:
 * real    0m1.304s
 * user    0m0.766s
 * sys     0m0.010s
 * 
 * time without ReverseVector:
 * real    0m0.503s
 * user    0m0.011s
 * sys     0m0.007s
 * 
 * time without AppendRandom:
 * real    0m0.677s
 * user    0m0.003s
 * sys     0m0.006s
*/
#include <cstdlib>
#include <iostream>
#include <vector>

using namespace std;

vector<int> ReverseVector(const vector<int>& source_vector) {
    vector<int> res;
    for (int i : source_vector) {
        res.insert(res.begin(), i);
    }

    return res;
}

// Функция считает количество ненулевых чисел в массиве
int CountPops(const vector<int>& source_vector, int begin, int end) {
    int res = 0;

    for (int i = begin; i < end; ++i) {
        if (source_vector[i]) {
            ++res;
        }
    }

    return res;
}

void AppendRandom(vector<int>& v, int n) {
    for (int i = 0; i < n; ++i) {
        // Получаем случайное число с помощью функции rand.
        // Конструкцией (rand() % 2) получим целое число в диапазоне 0..1.
        // В C++ имеются более современные генераторы случайных чисел,
        // но в данном уроке не будем их касаться.
        v.push_back(rand() % 2);
    }
}

int main() {
    vector<int> random_bits;

    // Операция << для целых чисел это сдвиг всех бит в двоичной
    // записи числа. Запишем с её помощью число 2 в степени 17 (131072)
    static const int N = 1 << 17;

    // Заполним вектор случайными числами 0 и 1.
    //AppendRandom(random_bits, N);

    // Перевернём вектор задом наперёд.
    //vector<int> reversed_bits = ReverseVector(random_bits);

    // Посчитаем процент единиц на начальных отрезках вектора.
    //for (int i = 1, step = 1; i <= N; i += step, step *= 2) {
        // Чтобы вычислить проценты мы умножаем на литерал 100. типа double.
        // Целочисленное значение функции CountPops при этом автоматически
        // преобразуется к double, как и i.
        //double rate = CountPops(reversed_bits, 0, i) * 100. / i;
        //cout << "After "s << i << " bits we found "s << rate << "% pops"s << endl;
    //}
}
