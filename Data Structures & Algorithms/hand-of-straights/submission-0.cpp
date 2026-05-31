class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0)
            return false;
        sort(hand.begin(), hand.end());
        unordered_map<int, int> freq;
        for (int card : hand) {
            freq[card]++;
        }
        vector<int> active;
        for (int card : hand) {
            if (freq[card] == 0)
                continue;
            if (active.empty()) {
                active.push_back(card);

            } else if (card == active.back()) {
                continue;
            } else if (card == active.back() + 1) {
                active.push_back(card);
            } else {
                return false;
            }
            while (active.size() == groupSize) {
                for (int value : active) {
                    freq[value]--;
                }
                vector<int> next_active;
                for (int value : active) {
                    if (freq[value] > 0)
                        next_active.push_back(value);
                }
                active = move(next_active);
                if (!active.empty()) {
                    if (active.back() - active.front() !=
                        static_cast<int>(active.size()) - 1) {
                        return false;
                    }
                }
            }
        }
        return active.empty();
    }
};
