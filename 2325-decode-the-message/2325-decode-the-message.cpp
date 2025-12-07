class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char, int> table;
        int pos=0;
        for (char c: key) {
            if (table.find(c) == table.end() && c!=' ')  table[c] = pos++;
        }
        for (int i=0; i<message.length(); i++) {
            if (message[i] == ' ') continue;
            message[i] = table[message[i]] + 'a';
        }
        return message;
    }
};