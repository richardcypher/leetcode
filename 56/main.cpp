#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

bool compare(Interval i1, Interval i2) {
    if(i1.start != i2.start)
        return i1.start < i2.start;
    else
        return i1.end < i2.end;
}

 vector<Interval> merge(vector<Interval>& intervals) {
    std::vector<Interval> result;
    if(intervals.empty())
        return result;
    if(intervals.size() == 1)
        return intervals;
    sort(intervals.begin(), intervals.end(), compare);
    int i = 0;
    while(i < intervals.size()) {
        int j = i + 1;
        for (j; j < intervals.size(); ++j)
        {
            if(intervals[j].start > intervals[i].end) 
                break;
            intervals[i].end = intervals[i].end > intervals[j].end ? intervals[i].end: intervals[j].end;
        }
        Interval ival(intervals[i].start, intervals[i].end);
        result.push_back(ival);
        i = j;
    }
    return result;
 }

 int main() {
    Interval i1(1,3),i2(2,6),i3(8,10),i4(15,18);
    std::vector<Interval> v;
    v.push_back(i1);
    v.push_back(i2);
    v.push_back(i3);
    v.push_back(i4);
    std::vector<Interval> r = merge(v);
    for (int i = 0; i < r.size(); ++i)
    {
        cout<<r[i].start<<','<<r[i].end<<'\t';
    }
    cout<<endl;
    return 0;
 }