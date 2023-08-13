/*
Since we want to get the min length of the subarray that contains the degree of the array, the first step would be to find the degree of the array.After finding degree, we want to find the min continuous subarray containing the count as degree, that would be possible if all the element of the degree are there.A simple mistake here could be to consider only one element having degree as count, but there might be a case where multiple elements have degree as count.For instance : 1 2 2 3 3 3 2 Here both 2 and 3 have degree as 3, if we were only considering say 2, then the min continuous subarray would be of length 2 2 3 3 2 i.e 5, but since 3 also has degree as 3, the length could be minimised to 3 3 3 i.e 3, which would be answer to the example
*/

int findShortestSubArray(vector<int> &nums)
{
    unordered_map<int, int> m;
    int maxCount = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        m[nums[i]] += 1;
        maxCount = max(maxCount, m[nums[i]]);
    }

    map<int, pair<int, int> > indexes;
    for (int i = 0; i < nums.size(); i++)
    {
        if (m[nums[i]] == maxCount)
        {
            if (indexes.find(nums[i]) == indexes.end())
            {
                indexes[nums[i]].first = i;
            }
            indexes[nums[i]].second = i;
        }
    }

    int minCount = INT_MAX;
    for (auto element : indexes)
    {
        minCount = min(minCount, element.second.second - element.second.first + 1);
    }

    return minCount;
}