#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        unordered_set<char> row1={'q','w','e','r','t','y','u','i','o','p'};
        unordered_set<char> row2={'a','s','d','f','g','h','j','k','l'};
        unordered_set<char> row3={'z','x','c','v','b','n','m'};

        vector<string> result;

        for(const string & word: words){
            unordered_set<char>* currentRow = nullptr;
            char firstChar = tolower(word[0]);
        
            if (row1.find(firstChar)!=row1.end()){
                currentRow= &row1;
            }
            else if (row2.find(firstChar)!=row2.end()){
                currentRow=&row2;
            }
            else if(row3.find(firstChar)!=row3.end()){
                currentRow=&row3;
            }
            bool isValid = true;
            for(char c: word){
                char lowerChar= tolower(c);
                if (currentRow->find(lowerChar)==currentRow->end()){
                    isValid = false;
                    break;
                }
            }
            if(isValid){
                result.push_back(word);
            }
        }
        return result;
    }
};
