

#include "spellr.h"
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
	FILE * in;
	in = fopen("words.txt","r");
	MySpellCheckDictionary dic;
	while(!feof(in)){
		char * temp;
		fscanf(in,"%s", temp);
		
		string str(temp);
		
		dic.addToDictionary(str);
		//dic.printDictionary();
	}
	fclose(in);
	cout<<"its still working"<<endl<<endl;
	
	cout<<dic.spellCheck("THIS");
	
}