//

#include <unordered_set>
#include <string>
#include <cstdio>
#include <vector>

#include <iostream>
using namespace std;



typedef unordered_set<string> HashSet;
typedef HashSet::const_iterator it;

class dictionary{
    public:
	HashSet words;
    void populate(vector<string>);
    void addToDictionary(string);
    bool spellCheck(string);
    vector<string> autoCorrect(string);
	
};

void dictionary::populate(vector<string> s){
    for(int i=0;i<s.size();i++){
        words.insert(s[i]);//wtf, how do you populate an unordered_set??????
    }

}

void dictionary::addToDictionary(string s){
    //HOW DO YOU POPULATE AN UNORDERED SET
    words.insert(s);
}

bool dictionary::spellCheck(string s){
	it got = words.find(s);
	if(got!=words.end()){
        return false;
    }
    return true;
}

vector<string> dictionary::autoCorrect(string s){
	if(spellCheck(s)){
		return {s};
	}
	else{
		//here's where we run the crazy code used to create lists based on values

	}

}

