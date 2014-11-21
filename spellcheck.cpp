

#include "spellr.h"
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

MySpellCheckDictionary loadDictionary(char* dictionaryName);

int main(int argc, char* argv[]){
	char dictfile[] = "words.txt";
	MySpellCheckDictionary hashDictionary = loadDictionary(dictfile);
	
	hashDictionary.printDictionary();
	
	// if(argc > 1){
		// FILE * fileToSpellCheck;
		// fileToSpellCheck = fopen(argv[1], "r");
		
		// FILE * checkedFile;
		// char fileOutputName[] = "checked_%s", argv[1];
		// checkedFile = fopen(fileOutputName, "w");
		
		// while(!feof(fileToSpellCheck)){
			// char * word;
			// fscanf(fileToSpellCheck,"%s", word);
			// string wordstr(word);
			
			// if(hashDictionary.spellCheck(wordstr)){
				// fprintf(checkedFile, "%s", word);
			// }
			// else {
				// fprintf(checkedFile, "*^*%s*^*", word);
			// }
		// }
	// }
	
	
	
}

MySpellCheckDictionary loadDictionary(char* dictionaryName){
	MySpellCheckDictionary hashDictionary;
	
	FILE * dictionaryOfTheEnglishLanguage;
	cout<<dictionaryName<<"***"<<endl;
	dictionaryOfTheEnglishLanguage = fopen(dictionaryName,"r");
	
	while(!feof(dictionaryOfTheEnglishLanguage)){
		char * word;
		fscanf(dictionaryOfTheEnglishLanguage,"%s", word);
		string wordStr(word);
		hashDictionary.addToDictionary(wordStr);
	}
	
	fclose(dictionaryOfTheEnglishLanguage);
	
	return hashDictionary;
}



	// FILE * in;
	// in = fopen("words.txt","r");
	// MySpellCheckDictionary dic;
	// while(!feof(in)){
		// char * temp;
		// fscanf(in,"%s", temp);
		
		// string str(temp);
		
		// dic.addToDictionary(str);
	// }
	// fclose(in);