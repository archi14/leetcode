/**
 * Though a fairly easy question, it's good because it has multiple edge cases that someone has to take
 * care of. If not thought of carefully, they might be missed, well as I missed them. One thing is for sure
 * when a negative element is encountered, we have to check all previous positive elements and remove the ones
 * that are smaller than the current element, seems like the work of a stack to me, what if the previous element is 
 * negative, Well technically that is possible only when there is no positive element before that.
 * Another important point is we don't care about the positive numbers that are coming after negative numbers, since they'd
 * be moving in the opposite directions.
 * **/

#include <stdc++.h>

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> q;
        int n=asteroids.size();

        for(int i=0;i<n;i++)
        {
            int cur = asteroids[i];
            if(cur<0)
            {
                while(!q.empty() && q.top()>0 && q.top()<abs(cur))
                {
                    q.pop();
                }

                if(!q.empty() && q.top()>0)
                {
                    if(q.top()==abs(cur))
                    {
                        q.pop();
                    }
                }else
                {
                    q.push(cur);
                }
            }else
            {
                    q.push(cur); 
            }
        }
        vector<int> ans;
        
        while(!q.empty())
        {
            ans.push_back(q.top());
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};