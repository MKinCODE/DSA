#include<string>
#include<unordered_set>
#include<queue>
using namespace std;
class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> us(bank.begin(),bank.end());
        if(us.find(endGene)==us.end()) return -1;

        queue<string> q;
        q.push(startGene);
        unordered_set<string> seen;
        seen.insert(startGene);
        int mutations=0;
        string choices="ACGT";
        while(!q.empty()){
            int length=q.size();
            for(int i=0; i<length; i++){
            string currentGene=q.front();
            q.pop();

            if (currentGene==endGene) return mutations;

            for(int pos=0; pos<8; pos++){
                for(char letter:choices){
                    string mutatedGene = currentGene;
                    mutatedGene[pos]=letter;

                    if(us.count(mutatedGene) && !seen.count(mutatedGene)){
                        q.push(mutatedGene);
                        seen.insert(mutatedGene);
                    }
                }
            }
            }
            mutations++;
        }
        return -1;
    }
};