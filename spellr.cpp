//


#include <unordered_set>
#include <string>
#include <cstdio>
using namespace std

#declare int DEVIATE=2;

std::unordered_set<string> HashSet;

class dictionary{
	HashSet words;
	void populate(string[]);
	void addToDictionary(string);
	bool spellCheck(string);
	
	string[] autoCorrect(string);
}

void dictionary::populate(string[] s){
	for(int i=0;i<s.length;i++){
		words.insert(s[i]);//wtf, how do you populate an unordered_set??????
	}
	
}

void dictionary::addToDictionary(string s){
	//HOW DO YOU POPULATE AN UNORDERED SET
	words.insert(s)
}

bool dictionary::spellCheck(string s){
	if(words.find(s)!=unordered_set::end){
		return true;
	}
	return false;
}

string[] dictionary::autoCorrect(string s){
	if(spellCheck(s)){
		return {s};
	}
	else{
		//here's where we run the crazy code used to create lists based on values
	
	}
}





