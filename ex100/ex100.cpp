#include "ex100.h"
#include <iostream>
#include <algorithm>
using namespace std;

namespace ex100
{
	int get_cycle(unsigned int p)
	{
		int c = 1;
		while (p!=1)
		{
			c++;
			if (p%2) p = p*3 + 1;
			else p = p/2;
		}
		return c;
	}

	void run(){
		unsigned int i,j;
		while(cin >> i)
		{
			cin >> j;
			cout << i << " " << j << " ";
			if(j<i) swap(i,j);

			int max_cycle = -1;
			while(i<=j)
			{
				int c = get_cycle(i);
				if (c > max_cycle)
				{
					max_cycle=c;
				}
				i++;
			}
			cout << max_cycle << endl;
		}
	}
}
