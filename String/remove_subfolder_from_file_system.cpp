//1233. Remove Sub-Folders from the Filesystem

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<string> removeSubfolders(vector<string>& folder) {
    vector<string>ans;

    for(const auto &f:folder){       //here const use because we don't want any changes in folder by mistake
        if(ans.empty()){
            ans.push_back(f);
        }

        else{
            const string& prev= ans.back();  //Used const because we want this prev reference string don't change f.
            
            if(f.find(prev)==0 && f.size()>prev.size() && f[prev.size()]=='/'){
                continue;
            }
            
            else{
                ans.push_back(f);
            }
        }
    }
    
    return ans;
}


int main(){
    vector<string> folder={"/a","/a/b","/c/d","/c/d/e","/c/f"};
    
    for(string&s:removeSubfolders(folder)){
        cout<<'"'<<s<<'"'<<" ";
    }
     
    return 0;
}