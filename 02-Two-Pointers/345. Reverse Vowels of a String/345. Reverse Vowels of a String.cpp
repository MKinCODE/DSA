1class Solution {
2public:
3    bool isVowel(char ch) {
4        ch = toupper(ch);
5        return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
6    }
7    string reverseVowels(string s) {
8        string vowel=;
9        vector<int> temp;
10        for(int i=0; i<s.length(); i++){
11            char ch = s[i];
12            if(isVowel(ch)){
13                temp.push_back(i);
14                vowel+=ch;
15            }
16        }
17        if(vowel.empty()) return s;
18        reverse(vowel.begin(),vowel.end());
19
20        for(int i=0; i<vowel.size(); i++){
21            s[temp[i]]=vowel[i];
22        }
23
24        return s;
25
26    }
27};