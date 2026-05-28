/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * };
 */

class Solution {
 public:
  int minMeetingRooms(
      vector<Interval>& intervals) {

    if (intervals.empty()) {
      return 0;
    }

    sort(intervals.begin(),
         intervals.end(),
         [](const Interval& a,
            const Interval& b) {
              return a.start < b.start;
         });

    priority_queue<
        int,
        vector<int>,
        greater<int>> min_heap;

    int max_rooms = 0;

    for (const Interval& interval
         : intervals) {

      const int start =
          interval.start;

      const int end =
          interval.end;

      // Reuse room if earliest
      // meeting already finished.
      if (!min_heap.empty() &&
          min_heap.top() <= start) {

        min_heap.pop();
      }

      min_heap.push(end);

      max_rooms =
          max(max_rooms,
              static_cast<int>(
                  min_heap.size()));
    }

    return max_rooms;
  }
};