#include <iostream>
#include <string>
using namespace std;

class TrieNode{
    public:
    bool isEnd;
    TrieNode* children[26];

    TrieNode(){
        isEnd=false;
        for(int i =0;i<26;i++){
            children[i]=NULL;
        }

    }

};

class Trie{
    private:
    TrieNode* root;
    public:
    Trie(){
        root=new TrieNode();
    
    }
    void insert(string word){
        TrieNode* curr=root;
        for(char c:word){
            int index = c-'a';
            if(curr->children[index]==NULL){
                curr->children[index]=new TrieNode();
        }
        curr=curr->children[index];
        }
        curr->isEnd=true;
    }
    bool search(string word){
        TrieNode* curr = root;
        for(char ch:word){
            int index = ch-'a';
            if(curr->children[index]==NULL){
                return false;
            }
            curr=curr->children[index];
        }
        return curr->isEnd;
    }
    bool startsWith(string prefix){
        TrieNode* curr = root;
        for(char ch:prefix){
            int index = ch-'a';
            if(curr->children[index]==NULL){
                return false;
            }
            curr=curr->children[index];
        }
        return true;  
    }

    void deleteTrie(TrieNode* node){
        for(int i =0;i<26;i++){
            if(node->children[i]){
                deleteTrie(node->children[i]);
            }
        }
        delete node;
    }
    ~Trie(){
        deleteTrie(root);
    }

};

int main(){
    Trie trie;
    trie.insert("apple");
    cout<<trie.search("apple")<<endl; // true
    cout<<trie.search("app")<<endl;   // false
    cout<<trie.startsWith("app")<<endl; // true
    trie.insert("app");
    cout<<trie.search("app")<<endl;   // true

    return 0;
}

