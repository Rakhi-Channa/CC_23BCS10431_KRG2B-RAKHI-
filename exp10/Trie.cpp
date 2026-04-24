#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    vector<Node*>links = vector<Node*>(26, NULL);
    int countEnd = 0;
    int countPrefix = 0;

    bool containsKey(char ch){
        return links[ch-'a']!=NULL;
    }

    Node* get(char ch){
        return links[ch-'a'];
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    void increaseEnd(){
        countEnd++;
    }

    void increasePrefix(){
        countPrefix++;
    }

    void deleteEnd(){
        countEnd--;
    }

    void reducePrefix(){
        countPrefix--;
    }

    int getCountEnd(){
        return countEnd;
    }

    int getCountPrefix(){
        return countPrefix;
    }
};

class Trie{
private:
    Node* root;

public:
    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
            node->increasePrefix();
        }
        node->increaseEnd();
    }

    int countWordsEqualTo(string word){
        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
            }
            else{
                return 0;
            }
        }

        return node->getCountEnd();
    }

    int countWordsStartingWith(string prefix){
        Node* node = root;
        for(int i=0; i<prefix.size(); i++){
            if(node->containsKey(prefix[i])){
                node = node->get(prefix[i]);
            }
            else{
                return 0;
            }
        }
        return node->getCountPrefix();
    }

    void erase(string word){

        if(countWordsEqualTo(word) == 0) return;

        Node* node = root;
        for(int i=0; i<word.size(); i++){
            if(node->containsKey(word[i])){
                node = node->get(word[i]);
                node->reducePrefix();
            }
            else{
                return;
            }
        }
        node->deleteEnd();
    }
};
