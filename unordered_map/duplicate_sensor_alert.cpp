#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int size; cin >> size;
    vector<int> zone_numbers;

    for (int i = 0; i < size; i++) {
        int number; cin >> number;
        zone_numbers.push_back(number);
    }

    int k; cin >> k;

    int repeated_alerts = 0;

    unordered_map<int, int> last_apperance;
    for (int i = 0; i < size; i++) {
        int zone_number = zone_numbers[i];

        int last_apperead = -1;
        if (last_apperance.find(zone_number) != last_apperance.end()) {
            last_apperead = last_apperance[zone_number];
        }

        if ((last_apperead != -1) && i - last_apperead <= k) {
            repeated_alerts += 1;
        }

        last_apperance[zone_number] = i;
    }

    cout << repeated_alerts << endl;

    return 0;
}
