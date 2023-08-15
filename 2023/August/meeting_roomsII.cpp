/**
 From the question I knew right away that we had to sort the array of intervals by the 
 start time, then maybe the last meeting end time could help me decide whether the current
 meeting would overlap, that would've been a mistake, as there is a possibility that the meetings
 before it are also running when the current meeting starts. So then I knew I had to check the last
 time of the previous meetings, but there is no point in keeping all the last meetings end time, 
 the I got to thinking which meetings end time can I eliminate, obviously that have been completed before
 the current start time, i.e start time > prev end time. How about if I keep all the previous end times in a
 sorted manner, say in an increasing order, then it would be simple for me to decide which end times to eliminate
 and which ones to keep. Good so now we had reached the conclusion that the end times are kept in a sorted increasing
 order, now the next question that comes is how do we enter the current end time, we want to insert the current end
 time to the current sorted order, currently we were eliminating end times using the start time, but that wouldn
 t help us to place the end time in the increasing order, because it's possible start time > prev end time but there 
 might be multiple end times smaller than the current end time. How about we use heap in that case. So that's what
 I did and it solved all my issues.
 **/


#include <bits/stdc++.h>
class Solution {
public:
struct meetingInstance{
    int start;
    int end;    
};
    static bool comp(meetingInstance m1, meetingInstance m2)
    {
        if(m1.start<m2.start)
        {
            return true;
        }
        return false;
    }

    int minMeetingRooms(vector<vector<int>>& intervals) {
        int n = intervals.size();
        meetingInstance meetings[n];
        for(int i=0;i<n;i++)
        {
            meetings[i].start = intervals[i][0];
            meetings[i].end = intervals[i][1];
        }
        sort(meetings, meetings+n, comp);
        priority_queue<int, vector<int>, greater<int> > pq;
        int maxCount=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int end = meetings[i].end;
            int start = meetings[i].start;
            while(!pq.empty() && start >= pq.top())
            {
                pq.pop();
            }
            pq.push(end);
            int curSize = pq.size();
            if(curSize>maxCount)
            {
                //cout<<"here";
                maxCount = pq.size();
            }
        }

        return maxCount;

    }
};