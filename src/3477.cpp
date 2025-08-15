#include <vector>

using namespace std;

class Solution3477 {
   public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int remaining_part = 0;
        int baskets_size = baskets.size();
        for (int fruit : fruits) {
            bool found = false;
            for (int idx = 0; idx < baskets_size; idx++) {
              if (baskets.at(idx) >= fruit) {
                  baskets[idx] = -1;
                  found = true;
                  break;
              }
            }
            if (!found) {
              remaining_part++;
            }
        }

        return remaining_part;
    }
};