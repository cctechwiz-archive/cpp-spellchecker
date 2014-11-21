//

#include <unordered_set>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;



typedef unordered_set<string> HashSet;
typedef HashSet::const_iterator it;

class MySpellCheckDictionary{
    public:
		string name;
		HashSet words;
		void addToDictionary(string);
		bool spellCheck(string);
		vector<string> autoCorrect(string);
		void printDictionary();
	private:
		string toLowerCase(string s);
};





void MySpellCheckDictionary::addToDictionary(string s){
    words.insert(s);
}

bool MySpellCheckDictionary::spellCheck(string s){
	s=toLowerCase(s);
	it got = words.find(s);
	if(got!=words.end()){
        return true;
    }
    return false;
}

vector<string> MySpellCheckDictionary::autoCorrect(string s){
	if(spellCheck(s)){
		return {s};
	}
	else{
		//here's where we run the crazy code used to create lists based on values

	}
}
	
void MySpellCheckDictionary::printDictionary(){
	for(it itr = words.begin(); itr != words.end(); itr++){
		cout<<*itr<<endl;
		
	}

}
	
string MySpellCheckDictionary::toLowerCase(string s){
	transform(s.begin(),s.end(),s.begin(), ::tolower);
	return s;
}


