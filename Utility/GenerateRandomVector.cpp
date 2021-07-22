#include <vector>
#include <iostream>
#include <random>
#include <algorithm>

using namespace std;

vector<int> GenerateRandomVector(int size, int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    vector<int> values(size);
    uniform_int_distribution<> dis(min, max);
    generate(values.begin(), values.end(), [&](){ return dis(gen); });
    return values;
}

int main()
{
    int count = 100;
    vector<int> randomVector = GenerateRandomVector(count, 0, 20);
    for (int i : randomVector) {
        cout << i << endl;
    }
}
