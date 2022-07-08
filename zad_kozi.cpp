#include <iostream>
#include <vector>
#include <algorithm>

void min_capacity(unsigned n, unsigned k, int goats[]) {
    int max_goat = goats[0];
    for (int i = 0; i < n; i++) {
        if (goats[i] > max_goat) {
            max_goat = goats[i];
        }
    }
    long int cap = max_goat;
    while (true) {
        
    }
}

int get_and_remove_max(std::vector<int>& goats, int capacity_left) {
    for (int i = 0; i < goats.size(); i++) {
        if (goats[i] <= capacity_left) {
            int temp = goats[i];
            goats.erase(goats.begin() + 1);
            return temp;
        }
    }
    return -1;
}

bool can_pass(int capacity, unsigned n, unsigned k, int goats[]) {
    std::vector<int> goats_temp;
    std::copy(goats, goats + n, goats_temp);
    std::sort(goats_temp.begin(), goats_temp.end());
    for (int i = 0; i < k; i++) {
        int temp_capacity{ capacity };
        while (capacity) {
            int result= get_and_remove_max(goats_temp, capacity);
            if (result == -1) {
                break;
            }
            capacity -= result;
        }
        if (goats_temp.empty()) {
            return true;
        }
    }
    return false;
}

int main()
{
    std::cout << "Hello World!\n";
}


