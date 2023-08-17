/**
Since we've given an order already, we can use that to decide the priority of characters,
we don't want to iterate the order again and again, so we are storing the order in a dict,
the we are just checkign one by one if all the element are following the order or not.
**/

#include <bits/stdc++.h>

class Solution {
public:
    bool isSorted(string s1,string s2,string &order){
        int priority[26];
        for(int i=0;i<26;i++){
            priority[order[i]-'a']=i+1;
        }
        int len_s1 = s1.length();
        int len_s2 = s2.length();
        int i=0,j=0;
        while(i<len_s1 && j<len_s2){
            if(s1[i]!=s2[j]){
                if(priority[s1[i]-'a']>priority[s2[j]-'a'])
                    return false;
                else
                    break;
            }
            i++;
            j++;
        }
        if(j==len_s2 && i!=len_s1)
            return false;
        return true;
    }
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0;i<words.size()-1;i++){
            if(!isSorted(words[i],words[i+1],order))
                return false;
        }
        return true;
    }
};