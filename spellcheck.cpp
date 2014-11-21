

#include "spellr.h"
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

void loadDictionary();

int main(int argc, char* argv[]){
	loadDictionary();
	
	// hashDictionary.printDictionary();
	
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

void loadDictionary(){
	MySpellCheckDictionary hashDictionary;

	FILE * in;
	in = fopen("words.txt", "r");

	while(!feof(in)){
		char * temp;
		fscanf(in, "%s", temp); //Discovered that this is throwing 'std::bad_alloc'
		string str(temp);
		hashDictionary.addToDictionary(str);
	}

	fclose(in);
}