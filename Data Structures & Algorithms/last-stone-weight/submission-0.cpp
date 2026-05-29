class Solution {
private:
    priority_queue<int> max_heap;

public:
    int lastStoneWeight(vector<int>& stones) {
        for(int stone: stones){
            max_heap.push(stone);
        }
        while (!max_heap.empty() && max_heap.size()>1) {
            int first_stone = max_heap.top();
            max_heap.pop();
            int second_stone =max_heap.top();
            max_heap.pop();
            if(first_stone != second_stone){
                max_heap.push(abs(first_stone-second_stone));
            }
        }
        if(max_heap.empty())
            return 0;
        return max_heap.top();

    }
};