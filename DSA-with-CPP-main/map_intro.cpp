#include<iostream>
#include <map>
#include <unordered_map>

using namespace std;

int main(){

    // creation 
    unordered_map<string,int> m;
    
    //insertion
    //1
    pair<string,int> p = make_pair("babbar",3);
    m.insert(p);


    //2
    pair<string,int> p2("love",2);
    m.insert(p2);

    //3
    m["mera"] = 1;

 
    //search
    cout<<m["babbar"]<<endl;
    cout<<m.at("love")<<endl;

    //size
    cout<<m.size()<<endl;

    //to check presence
    cout<<m.count("bro")<<endl;

    //access
    for(auto i : m){
        cout<<i.first << " "<<i.second<<endl;
    }

    //iterator
    unordered_map<string,int>::iterator it= m.begin();
    while(it != m.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }
    return 0;
}