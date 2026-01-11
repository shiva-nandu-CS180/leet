class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        unordered_map<int, int> nge; 
      
        for(int i =nums2.size()-1;i>=0;i--){
            while(!s.empty()&&s.top()<=nums2[i]){
                s.pop();
            }
                if(s.empty()){
                    nge[nums2[i]]=-1;
                }
                else{
                    nge[nums2[i]]=s.top();
                }
                s.push(nums2[i]);
                    
            
        }
           vector<int> result;
        for(int num : nums1) {
            result.push_back(nge[num]);
        } 
return result;
    }
};