class Solution {
public:

    string encode(vector<string>& strs) {

       string encoded = "" ;

       for(string& s: strs){
         encoded+= to_string(s.length());
         encoded+= '*';
         encoded+= s;
       }

       return encoded;
    }

    vector<string> decode(string s) {
       vector<string> decoded;
       int i =0;

       while(i<s.length()){

         int j = i;
   
        while(j< s.length() && s[j]!='*'){

            j++;
        }

        if (j == s.length()) {
            // Handle error, e.g., throw an exception or return an empty vector
            // For competitive programming, often just return empty.
            return {};
        }

        string length_str = s.substr(i, j-i);
        int len = stoi(length_str);

        int start_idx = j+1;

        if (start_idx + len > s.length()) {
            // Malformed or truncated string
            return {};
        }

        string og_str = s.substr(start_idx, len);

        decoded.push_back(og_str);
        i = start_idx+len;


       }

       return decoded;
    }
};
