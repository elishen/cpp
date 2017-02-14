#include <iostream>
using namespace std;

struct Node{

	int good, bad;
	double pUp, pDown;
	int accVal;
	double price;

	Node *up, *down;

};

void path(Node* node, int level){

	// cout << level << endl; 

	node->up = NULL;
	node->down = NULL;

	if (node->good == 0){
		node->pUp = 0;
		node->pDown = 1;
	} else if (node->bad == 0){
		node->pUp = 1;
		node->pDown = 0;
	} else {
		node->pUp = (node->good * 1.0 / (node->good + node->bad));
		node->pDown = (node->bad * 1.0 / (node->good + node->bad));

		Node* up = new Node();
		node->up = up;
		up->good = node->good-1;
		up->bad = node->bad;
		up->accVal = node->accVal + 1;
		up->price = 0;
		up->pUp = -1;
		up->pDown = -1;

		Node* down = new Node();
		node->down = down;
		down->good = node->good;
		down->bad = node->bad-1;
		down->accVal = node->accVal - 1;
		down->price = 0;
		down->pUp = -1;
		down->pDown = -1;

		path(up, level+1);
		path(down, level+1);
	}
}

void print_node(Node* node, int level, int num, int denom, double p){

	for (int i=0; i<level; i++){
		cout << "    ";
	}

	cout << "(" << num << "/" << denom << ":" << p << ") " << node->accVal << ":" << node->price << endl; 

	if (node->up){
		print_node(node->up, level+1, node->good, node->bad + node->good, node->pUp);
	} 
	if (node->up){
		print_node(node->down, level+1, node->bad, node->bad  + node->good, node->pDown);
	} 

}

double price_node(Node* node){

	double price = 0;

	if (node->pUp == 1){
		price = node->accVal + 1;
	} else if (node->pDown == 1){
		price = node->accVal - 1;
	} else {
		double price_up = price_node(node->up);
		double price_down = price_node(node->down);
		price = price_up * node->pUp + price_down * node->pDown;
		//cout << price_up << " " << price_down << " " << node->pUp << " " << node->pDown << " " << price << endl; 
	}

	if (price < node->accVal){
		price = node->accVal;
	} 

	node->price = price;

	return node->price;
}

int main(){

	Node *head = new Node();

	head->good = 3;
	head->bad = 4;
	head->accVal = 0;
	head->price = 0;
	head->pUp = -1;
	head->pDown = -1;

	path(head, 0);

	price_node(head);

	print_node(head, 0, 0, 0, 0);

	return 0;

}