

#include "spellr.h"
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

MySpellCheckDictionary loadDictionary(char *filename);
int main(int argc, char* argv[]){
	char filename[] = "words.txt";
	MySpellCheckDictionary hashDictionary = loadDictionary(filename);
	
	// hashDictionary.printDictionary();

	if(argc > 1){
		FILE * fileToSpellCheck;
		fileToSpellCheck = fopen(argv[1], "r");

		FILE * checkedFile;
		checkedFile = fopen("spellCheckedFile.txt", "w");
		
		while(!feof(fileToSpellCheck)){
			char *word = new char[65000];
			fscanf(fileToSpellCheck,"%s", word);
			string wordstr(word);
			
			if(hashDictionary.spellCheck(wordstr)){
				fprintf(checkedFile, "%s", word);
			}
			else {
				fprintf(checkedFile, "*^*%s*^*", word);
			}
		}
	}
	
}


MySpellCheckDictionary loadDictionary(char *filename){
	MySpellCheckDictionary hashDictionary;

	FILE * dictionaryFile;
	dictionaryFile = fopen(filename, "r");

	while(!feof(dictionaryFile)){
		char *word = new char[65000];
		fscanf(dictionaryFile, "%s", word); 
		string wordStr(word);
		hashDictionary.addToDictionary(wordStr);
	}

	return hashDictionary;
}