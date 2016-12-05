#include <map> 
#include <vector> 
#include <string>
#include <algorithm>
#include <iostream> 
#include <climits> 

using namespace std;

class Node{
public: 
	string word;
	vector<Node *> children;
	int link_len;

	Node(string w): word(w), link_len(0) {}
};

typedef map<string, Node*> T_MAP_NODE; 
typedef T_MAP_NODE::iterator T_MAP_NODE_IT; 

void link_node(Node *nd){

	int nChildren = nd->children.size();
	if (nChildren ==0){
		nd->link_len = 1; 
		return; 
	}

	int max_link = 0; 
	for (int i = 0; i<nChildren; i++){
		Node* child = nd->children[i]; 

		if (child->link_len == 0){
			link_node(child);
			
		} 
		if (child->link_len > max_link){
			max_link = child->link_len; 
		}
	}
	nd->link_len = max_link + 1; 

	//cout << nd->word << " linked " << nd->link_len << endl; 
}

int longest_chain(vector<string> words){

	T_MAP_NODE map_words;

	int kWords = words.size(); 

	for (int i=0; i<kWords; i++){
		string w = words[i];
		Node *nd = new Node(w);

		map_words.emplace(w, nd);
	}

	T_MAP_NODE_IT nd_it; 

	for (nd_it = map_words.begin(); nd_it != map_words.end(); ++nd_it){

		string w = nd_it->first; 
		Node *nd = nd_it->second; 

		for (int j=0; j<w.size(); j++){
			string tmp_w = w; 
			tmp_w.erase(j, 1);

			T_MAP_NODE_IT child_it = map_words.find(tmp_w);

			if (child_it != map_words.end()){
				nd->children.push_back(child_it->second);
			}
		}

		//cout << w << " --> " ; 
		// for (int k=0; k<nd->children.size(); k++){
		// 	cout << nd->children[k]->word << " ";
		// }
		cout << endl; 
	}

	int max_chain = 0; 

	for (nd_it = map_words.begin(); nd_it != map_words.end(); ++nd_it){
		Node* nd = nd_it->second; 
		int link_len = nd->link_len; 

		if (link_len == 0){
			link_node(nd);
			link_len = nd->link_len; 
		}
		if (link_len > max_chain) {
			max_chain = link_len;	
		}
	}

	return max_chain; 

}


int main(int argc, char* argv[]){

	int n;
	cin >> n;
	vector<string> words; 

	string w; 

	for (int i = 0; i<n; i++){
		cin >> w; 
		words.push_back(w); 
	}

	int max_chain = longest_chain(words);
	cout << "Longest Chain: " << max_chain << endl; 

}