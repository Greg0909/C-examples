#include <iostream>
#include <string>

using namespace std;

struct Node_Trie
{
	Node_Trie *arr[26];
	int size;

	int getCharIndex(char a)
	{
		return a-'a';
	}
	public:
	void add(string s, int index)
	{
		++size;
		if(s.length() == index) return;

		if(arr[getCharIndex(s[index])] == NULL)
		{
			arr[getCharIndex(s[index])] = new Node_Trie();
		}
		arr[getCharIndex(s[index])]->add(s, index+1);
	}

	Node_Trie()
	{
	for(int h=0; h<26; ++h)
		arr[h]=NULL;
	size=0;
	}

	int count_Find(string s, int index)
	{
		if(s.length() == index) return size;
		if(arr[getCharIndex(s[index])] == NULL)
			return 0;
		return count_Find(s, index+1);
	}
};

int main()
{
	Node_Trie head;
	cout<<"HELP"<<endl;
	head.add("alex",0);
	head.add("abby",0);
	cout << "Count 1 for A: " << head.count_Find("A", 0) << endl;
	head.add("anon",0);
	cout << "Count 2 for A: " << head.count_Find("A", 0);
	return 0;
}