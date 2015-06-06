#include <iostream>
#include <vector>

using namespace std;
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
    if(intervals.empty()) {
        intervals.push_back(newInterval);
        return intervals;
    }
    if(intervals[0].start > newInterval.end) {
        intervals.insert(intervals.begin(), newInterval);
        return intervals;
    }
    if(intervals[intervals.size() - 1].end < newInterval.start) {
        intervals.push_back(newInterval);
        return intervals;
    }
    vector<Interval> result;
    int i = 0;
    while(intervals[i].end < newInterval.start) {
        result.push_back(intervals[i]);
        i++;
    }
    if(newInterval.end  < intervals[i].start)
    {
        intervals.insert(intervals.begin() + i, newInterval);
        return intervals;
    }
    if(intervals[i].start > newInterval.start)
        intervals[i].start = newInterval.start;
    if(intervals[i].end >= newInterval.end) 
        return intervals;
    intervals[i].end = newInterval.end;
    Interval ival(intervals[i].start, intervals[i].end);
    int j = i + 1;
    while(j < intervals.size() && ival.end >= intervals[j].start)  {
        ival.end = ival.end < intervals[j].end ? intervals[j].end : ival.end;
        j++;
    }
    result.push_back(ival);
    result.insert(result.end(), intervals.begin() + j, intervals.end());
    return result;
}

int main() {
    vector<Interval> ivals;
    Interval v1(0,4),v2(7,12),v3(6,7),v4(8,10),v5(12,16),v(0,5);
    ivals.push_back(v1);
    ivals.push_back(v2);
    // ivals.push_back(v3);
    // ivals.push_back(v4);
    // ivals.push_back(v5);
    vector<Interval> r = insert(ivals, v);
    for (int i = 0; i < r.size(); ++i)
    {
        cout<<'['<<r[i].start<<','<<r[i].end<<']'<<'\t';
    }
    cout<<endl;
    return 0;
}
