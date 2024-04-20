#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Trie structure
struct Trie
{
    struct Trie *children[26];
    int fullWord;
};

// Inserts the word to the trie structure
void insert(struct Trie *pTrie, char *word)
{
    struct Trie *curr = pTrie;
    for (int i = 0; i < strlen(word); i++) {

        if (word[i] < 'a' || word[i] > 'z') {
            return;
    }

        int index = word[i] - 'a';
        
        if (curr->children[index] == NULL){
            curr->children[index] = (struct Trie *)malloc(sizeof(struct Trie));
            curr->children[index]->fullWord = 0;
            
            for (int j = 0; j < 26; j++){
                curr->children[index]->children[j] = NULL;
            }
        }
        
        curr = curr->children[index];
    }
    
    curr->fullWord += 1;
}

// computes the number of occurrences of the word
int numberOfOccurances(struct Trie *pTrie, char *word)
{
    struct Trie *curr = pTrie;
    
    for (int i = 0; i < strlen(word); i++){
        int index = word[i] - 'a';
        
        if (curr->children[index] == NULL){
            return 0;
        }
        
        curr = curr->children[index];
    }
    
    if (curr->fullWord > 0)
        return curr->fullWord;

    return 0; 

    if (curr->fullWord){
        return 1;
    }
    else{
        return 0;
    }
}

// deallocate the trie structure
struct Trie *deallocateTrie(struct Trie *pTrie)
{
    if (pTrie == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < 26; i++) {
        if (pTrie->children[i] != NULL) {
            pTrie->children[i] = deallocateTrie(pTrie->children[i]);
        }
    }
    
    free(pTrie);
      
    return NULL;
}

// Initializes a trie structure
struct Trie *createTrie()
{
    struct Trie *root = (struct Trie *)malloc(sizeof(struct Trie));
    root->fullWord = 0;
    
    for (int i = 0; i < 26; i++){
        root->children[i] = NULL;
    }
    
    return root;
}

// this function will return number of words in the dictionary,
// and read all the words in the dictionary to the structure words
int readDictionary(char *filename, char **pInWords)
{
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 0;
    }
    
    int numWords = 0;
    char word[256];
    
    while (fgets(word, sizeof(word), file)) {
        // Remove newline character from the word5
        word[strcspn(word, "\n")] = '\0';
        
        // Allocate memory for the word and copy it
        pInWords[numWords] = (char *)malloc(strlen(word) + 1);
        strcpy(pInWords[numWords], word);
        
        numWords++;
    }
    
    fclose(file);
    
    return numWords;
}

int main(void)
{
	char *inWords[256];
	
	//read the number of the words in the dictionary
	int numWords = readDictionary("dictionary.txt", inWords);
	for (int i=0;i<numWords;++i)
	{
		printf("%s\n",inWords[i]);
	}
	
	struct Trie *pTrie = createTrie();
	for (int i=0;i<numWords;i++)
	{
		insert(pTrie, inWords[i]);
	}
	// parse lineby line, and insert each word to the trie data structure
	char *pWords[] = {"notaword", "ucf", "no", "note", "corg"};
	for (int i=0;i<5;i++)
	{
		printf("\t%s : %d\n", pWords[i], numberOfOccurances(pTrie, pWords[i]));
	}
	pTrie = deallocateTrie(pTrie);
	if (pTrie != NULL)
		printf("There is an error in this program\n");
	return 0;
}