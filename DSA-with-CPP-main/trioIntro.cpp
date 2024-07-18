#include<iostream>

using namespace std;

class TrioNode{
    public:
    char data ;
    TrioNode* children[26];

    TrioNode(char data){
        this->data = data;
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
    }
    bool isTerminal = false;
};

class Trie{
    public:
    TrioNode* root;
    

    Trie(){
        root = new TrioNode('\0');
    }   
    void insertUtil(TrioNode* root,string word){
        if(word.length() == 0){
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'A';
        TrioNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];

    }
    else{
        child = new TrioNode(word[0]);
        root->children[index] = child;
    }

    insertUtil(child,word.substr(1));
    }

    void insertWord(string word){
        insertUtil(root,word);
    }
    bool searchUtil(TrioNode* root,string word){
        if(word.length() == 0){
            return root->isTerminal;
        }

        int index = word[0] - 'A';
        TrioNode* child;
        if(root->children[index] != NULL){
            child = root->children[index];
        }
        else{
            return false;
        }
        return searchUtil(child,word.substr(1));
    }
    bool search(string word){
        return searchUtil(root,word);
    }
    void removeUtil(TrioNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'A';
        TrioNode* child;
        if (root->children[index] != NULL) {
            child = root->children[index];
        }
        else {
            cout<<"Word not present in the Trie\n";
            return;
        }

        removeUtil(child, word.substr(1));
    }

    void removeWord(string word) {
        removeUtil(root, word);
    }
    
};

int main(){
    Trie *t = new Trie;
    t->insertWord("HELLO");
    cout<<"present or Not "<<t->search("HELLO")<<endl;
    t->removeWord("HELLO");
    cout<<"present or Not "<<t->search("HELLO")<<endl;
    return 0;
}