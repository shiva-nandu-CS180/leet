class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
     map<int, int > mp;
     for(int it : nums){
          mp[it]++;
          if(mp[it]>1){
            return it;
          }
     }
     return -1;
    }
};