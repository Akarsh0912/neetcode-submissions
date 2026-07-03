class Solution {
public:

    string encode(vector<string>& strs) {
    string res = "";

    for (string s : strs) {
        res += to_string(s.size()) + "#" + s;
    }

    return res;
}

    vector<string> decode(string s) {
        vector<string> result;

    int i = 0;

    while (i < s.size()) {

        // Find '#'
        int j = i;
        while (s[j] != '#')
            j++;

        // Extract length
        int len = stoi(s.substr(i, j - i));

        // Move to first character of the string
        j++;

        // Extract the string
        result.push_back(s.substr(j, len));

        // Move to next encoded string
        i = j + len;
    }

    return result;
    }
};
