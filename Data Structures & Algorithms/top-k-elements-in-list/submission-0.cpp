class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        //key : number, value : frequency 
        unordered_map<int, int> freq_map;

        for( int num : nums){

            freq_map[num]++;
        }

        vector<pair<int, int>> freq_list;

        for(auto const& pair : freq_map){

            freq_list.push_back({ pair.second, pair.first});
        }

        sort(freq_list.begin(), freq_list.end(), [](const pair<int, int>& a, const pair<int, int>& b){
            
            return a.first > b.first;

        });

        vector<int> result;
        for(int i = 0; i<k; i++){

            result.push_back(freq_list[i].second);
        }

        return result;
    }

};
