class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int n = people.size();
        int front = 0;
        int back = n-1;
        int number_of_boats = 0;
        while(front <= back){
            if(people[front]+people[back]<=limit){
                number_of_boats++;
                front++;
                back--;
            }else {
                number_of_boats++;
                back--;
            }
        }
        return number_of_boats;
    }
};