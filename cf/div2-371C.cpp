#include<bits/stdc++.h>

using namespace std;

typedef struct node{
	multiset<long long> e;
	struct node* left;
	struct node* right;
}node;

#define gi(x) cin>>x
#define ll long long
#define LEVELS 18

long long int read_int(){
	char r;
	bool start=false,neg=false;
	long long int ret=0;
	while(true){
		r=getchar();
		if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
			continue;
		}
		if((r-'0'<0 || r-'0'>9) && r!='-' && start){
			break;
		}
		if(start)ret*=10;
		start=true;
		if(r=='-')neg=true;
		else ret+=r-'0';
	}
	if(!neg)
		return ret;
	else
		return -ret;
}

inline void writeLongLong (long long n)
{
    char buffer[sizeof(n) * 8 * 3 / 10 + 3];  // 3 digits per 10 bits + two extra and space for terminating zero. 
    int index = sizeof(buffer)-1;
    int end = index;
    buffer[index--] = 0;
    do {
       buffer[index--] = (n % 10) + '0';
       n /= 10;
    } while(n);
    puts(&buffer[index+1]);
}

node* initialiseTree(node* head, int curr){
	if( curr > LEVELS )
		return NULL;
	head = new node;
	head->left = initialiseTree(head->left, curr+1);
	head->right = initialiseTree(head->right, curr+1);
	
	return head;
}

void addElement( node* head, ll ele, ll curr){
	if( (curr / 10) == 0 ){
		multiset<ll> t;
		if( curr & 1){
			t = (head->right->e);
			t.insert(ele);
			head->right->e = t;
		}
		else{
			t = (head->left->e);
			t.insert(ele);
			head->left->e = t;
		}
		return;
	}
	int rem = curr % 10;
	curr /= 10;
	if( rem & 1)
		addElement(head->right, ele, curr);
	else
		addElement(head->left, ele, curr);
}

void removeElement(node* head, ll ele, ll curr){
	if( (curr/10) == 0 ){
		if( curr & 1){
			multiset<ll> t = head->right->e;
			//if( t.find(ele) != t.end() )
				t.erase(t.equal_range(ele).first);
			head->right->e = t;
		}
		else{
			multiset<ll> t = head->left->e;
			//if( t.find(ele) != t.end())
				t.erase( t.equal_range(ele).first);
			head->left->e = t;
		
		}
		return;
	}
	int rem = curr % 10;
	curr /= 10;
	if( rem & 1)
		removeElement(head->right, ele, curr);	
	else
		removeElement( head->left, ele, curr);
}

ll countElement(node* head, ll ele, ll curr){
	if( (curr / 10) == 0 ){
		node* n;
		ll ans=0;
		multiset<ll> t;

		if( curr & 1){
			t = head->right->e;
			ans = t.size();
			n = head->right->left;
		}
		else{
			t = head->left->e;
			ans = t.size();
			n = head->left->left;
		}
		while( n ){
			t = n->e;
			ans += t.size();
			n = n->left;
		}
		return ans;
	}	
	int rem = curr % 10;
	curr /= 10;
	if( rem & 1 )
		return countElement(head->right, ele, curr);
	else
		return countElement(head->left, ele, curr);
}

int main(void){
	ll t;
	cin>>t;
	
	node* head = NULL;
	head = initialiseTree(head, 0);

	while(t--){
		char ch;
		ll ele;
		cin>>ch;
		ele = read_int();
		switch( ch ){
			case '+': addElement(head, ele,ele);
				break;
			case '-': removeElement(head, ele, ele);
				break;
			case '?': ll res = countElement(head, ele, ele);
				writeLongLong(res);
	//			printf("\n");
				break;
		}
	}
	return 0;
}
