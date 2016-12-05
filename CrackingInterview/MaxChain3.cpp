#include <map> 
#include <list> 
#include <string>
#include <algorithm>
#include <iostream> 
#include <climits> 

using namespace std;


class Node{
public: 
	string word;
	list<Node *> lst_next;
	bool visited;

	Node(string w): word(w), visited(false){}
};

typedef map<int, list<Node*> >::iterator T_MAP_IT; 
typedef list<Node*>::iterator  T_LIST_IT; 


void print_map(map<int, list<Node*>> map_words, int min_len, int max_len){
	for (int len = min_len; len < max_len; len++){
		T_MAP_IT map_it = map_words.find(len); 
		
		// if no words of the current length len
		if (map_it == map_words.end()) continue;

		list<Node*> lst_words = map_it->second;

		for (T_LIST_IT words_it = lst_words.begin(); words_it != lst_words.end(); ++words_it){
			Node* n = *words_it;
			list<Node*> lst_next = n->lst_next; 
			cout << n->word << " => " << endl << "\t" ; 
			for (T_LIST_IT next_it = lst_next.begin(); next_it != lst_next.end(); ++next_it){
				Node* n_next = *next_it;
				cout << n_next->word << " ";
			}
			cout << endl; 
		}
	}
}

int link_node(Node* n, map<int, list<Node*>> map_words, int max_len, int cur_chain){

	int max_chain = cur_chain;
	int cur_len = n->word.size(); 

	n->visited = true; 
	T_MAP_IT map_it = map_words.find(cur_len+1); 
	if (map_it == map_words.end() ) return cur_chain; 

	list<Node*> lst_words = map_it->second;

	for (T_LIST_IT words_it = lst_words.begin(); words_it != lst_words.end(); ++words_it){
		Node* n2 = *words_it; 
		size_t found = n2->word.find(n->word); 
	
		if (found != string::npos) {
			n->lst_next.push_back(n2);
			if (!n2->visited && cur_len < max_len ) {
				int linked_len = link_node(n2, map_words, max_len, cur_chain+1);
				if (linked_len > max_chain) max_chain = linked_len; 
			}
		}
	}
	
	return max_chain;
}

int longest_chain(string* arr, int n ){

	int min_len, max_len; 
	map<int, list<Node*> > map_words; 

	min_len = INT_MAX; 
	max_len = INT_MIN; 

	if (n == 0)
		return 0;

	// put all words into a hashmap using the length as the key
	// words of the same length are stored in a list 
	// To Simplify: 
	// 		As the question states the max length is 50, 
	// 		we can use an array of list. 
	// 		using map could handle any length 
	for (int i =0; i < n; i++){
		string w = arr[i];
		Node* n = new Node(w);
		int len = w.size(); 
		T_MAP_IT it = map_words.find(len);

		if (it == map_words.end()){
			list<Node *> lst;
			lst.push_back(n);
			map_words.insert(pair<int, list<Node*> >(len, lst));
		} else {
			it->second.push_back(n);
		}

		if (len < min_len) min_len = len; 
		if (len > max_len) max_len = len;

	}

	int max_link = 1; 

	for (int len = min_len; len < max_len; len++){
		T_MAP_IT map_it = map_words.find(len); 
		
		// if no words of the current length len
		if (map_it == map_words.end()) continue;

		list<Node*> lst_words = map_it->second;

		for (T_LIST_IT words_it = lst_words.begin(); words_it != lst_words.end(); ++words_it){
			Node* n = *words_it;
			if (!n->visited)  {
				int linked_len = link_node(n, map_words,  max_len, 1);
				if (linked_len > max_link) 
					max_link = linked_len; 
			}
			n->visited=true;
		}
	}

	//print_map(map_words, min_len, max_len );

	return max_link;

}


int main(int argc, char* argv[]){

	int n;
	cin >> n;
	string w;
	string* words = new string[n];

	for (int i = 0; i<n; i++){
		cin >> w; 
		words[i] = w;
	}

	int max_chain = longest_chain(words, n);

	cout << "Longest Chain: " << max_chain << endl; 

}