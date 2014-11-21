

#include "spellr.h"
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

MySpellCheckDictionary loadDictionary(char *filename);
void checkSpellingOfInputFile(char *filename, MySpellCheckDictionary dictionary);

int main(int argc, char* argv[]){
	char filename[] = "words.txt";
	MySpellCheckDictionary hashDictionary = loadDictionary(filename);
	
	// hashDictionary.printDictionary();

	if(argc > 1){
		checkSpellingOfInputFile(argv[1], hashDictionary);	
	} else {
		cout << "Usage: " << argv[0] << " <fileToSpellCheck>" << endl;
		cout << "This will output a file named 'spellCheckedFile.txt' ";
		cout << "with the misspelled words identified." << endl;
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

void checkSpellingOfInputFile(char *filename, MySpellCheckDictionary dictionary){
	FILE * fileToSpellCheck;
	fileToSpellCheck = fopen(filename, "r");

	FILE * checkedFile;
	checkedFile = fopen("spellCheckedFile.txt", "w");
	
	while(!feof(fileToSpellCheck)){
		char *word = new char[65000];
		fscanf(fileToSpellCheck,"%s", word);
		string wordstr(word);
		
		if(dictionary.spellCheck(wordstr)){
			fprintf(checkedFile, "%s ", word);
		}
		else {
			fprintf(checkedFile, "*%s* ", word);
		}
	}
}