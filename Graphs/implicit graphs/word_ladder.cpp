#include<unordered_set>
#include<string>
#include<queue>
using namespace std;
//for optimal we have to use two way bfs.
//this is not optimal yet good approach for begginer
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> us(wordList.begin(),wordList.end());
        if(!us.count(endWord)) return 0;

        queue<string> q;
        q.push(beginWord);
        unordered_set<string> seen;
        seen.insert(beginWord);
        int nwords=1;
        string choices="abcdefghijklmnopqrstuvwxyz";
        int l=beginWord.length();
        while(!q.empty()){
            int length = q.size();
            for(int i=0; i<length; i++){
                string current = q.front();
                q.pop();

                if(current==endWord) return nwords;

                for(int pos=0; pos<l; pos++){
                    for(char letter:choices){
                        if(letter == current[pos]) continue;
                        string transformated=current;
                        transformated[pos]=letter;
                        if(us.count(transformated) && !seen.count(transformated)){
                            q.push(transformated);
                            seen.insert(transformated);
                        }
                    }
                }
            }
            nwords++;
        }
        return 0;
    }
};