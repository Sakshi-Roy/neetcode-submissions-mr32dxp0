class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        // Use an unordered_map to store groups of anagrams.
        // The key will be the sorted version of a string (its canonical form).
        // The value will be a vector of strings that share that canonical form (i.e., are anagrams).
        
        std::unordered_map<std::string, std::vector<std::string>> anagram_groups;

        // Iterate through each string in the input array.
        for (const std::string& s : strs) {
            // Create a temporary string that is a copy of the current string 's'.
            std::string sorted_s = s;
            // Sort the temporary string to get its canonical form.
            // Example: "act" -> "act", "cat" -> "act", "pots" -> "opst"
            std::sort(sorted_s.begin(), sorted_s.end());

            // Use the sorted string as the key to add the original string 's'
            // to the corresponding group in the map.
            anagram_groups[sorted_s].push_back(s);
        }

        // After populating the map, collect all the groups (values of the map)
        // into the result vector.
        std::vector<std::vector<std::string>> result;
        for (auto const& [key, val] : anagram_groups) {
            result.push_back(val);
        }

        return result;
    }
};
