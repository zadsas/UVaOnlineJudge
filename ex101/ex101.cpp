#include "ex101.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <list>
using namespace std;

namespace ex101
{

	int ultimate_parent(int parents[], int block)
	{
		while (parents[block] != -1) block = parents[block];
		return block;
	}

	void pile(int parents[], list<int> buckets[], int from, int to)
	{
		list<int> *origin_pile = &buckets[ultimate_parent(parents, from)];
		list<int>::iterator origin_it=origin_pile->begin();
		while(*origin_it != from) origin_it++;
		origin_pile->erase(origin_it);

		list<int> *target_pile = &buckets[ultimate_parent(parents, to)];
		list<int>::iterator target_it=target_pile->begin();
		while(*target_it != to) target_it++;
		target_pile->insert(++target_it, from);

		parents[from] = to;
	}

	void return_blocks(int parents[], list<int> buckets[], int block)
	{
		list<int> *pile = &buckets[ultimate_parent(parents, block)];
		list<int>::iterator it=pile->begin();
		while(*it != block) it++;
		it++;
		while(it != pile->end())
		{
			parents[*it]=-1;
			buckets[*it].clear();
			buckets[*it].push_front(*it);
			pile->erase(it++);
		}
	}

	bool is_legal(int parents[], int a, int b)
	{
		if (a==b) return false;
		if (ultimate_parent(parents, a)==ultimate_parent(parents, b)) return false;
		return true;
	}

	void run(){
		int n;
		string command;

		cin >> n;

		int parents[n];
		fill_n(parents, n, -1);

		list<int> buckets[n];
		for (int i = 0 ; i < n ; i++) buckets[i].push_front(i);

		cin >> command;
		while (command != "quit")
		{
			int a, b;
			string qual;

			cin >> a;
			cin >> qual;
			cin >> b;

			if (is_legal(parents, a, b))
			{
				if(command == "move")
				{
					return_blocks(parents, buckets, a);
					if (qual=="onto")
					{
						return_blocks(parents, buckets, b);
						pile(parents, buckets, a, b);
					}
					else pile(parents, buckets, a, buckets[ultimate_parent(parents, b)].back());
				}
				else if (command == "pile")
				{
					int to = b;
					if (qual=="onto") return_blocks(parents, buckets, b);
					else to = buckets[ultimate_parent(parents, b)].back();

					list<int> *origin_pile = &buckets[ultimate_parent(parents, a)];
					list<int>::iterator origin_it=origin_pile->begin();
					while(*origin_it != a) origin_it++;

					parents[*origin_it] = to;

					list<int> *target_pile = &buckets[ultimate_parent(parents, to)];
					while(origin_it != origin_pile->end())
					{
						target_pile->insert(target_pile->end(), *origin_it);
						origin_pile->erase(origin_it++);
					}

				}
			}
			cin >> command;
		}
		for (int i = 0 ; i < n ; i++)
		{
			cout << i << ":";
			list<int> l = buckets[i];
			for (list<int>::iterator it=l.begin() ; it!=l.end() ; ++it)
			{
				cout << " " << *it;
			}
			cout << endl;
		}

	}
}
