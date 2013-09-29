#include "ex102.h"
#include <iostream>
#include <algorithm> //sort, next_permutation, copy
#include <cmath> //pow
using namespace std;

namespace ex102
{
	unsigned int calculate_movs(char bin_config[3], int n_bottles[][3]) {
		unsigned int movs = 0;
		for(int i = 0 ; i < 3 ; i++) {
			if (bin_config[i] == 'B') movs += (n_bottles[i][1]+n_bottles[i][2]);
			else if (bin_config[i] == 'G') movs += (n_bottles[i][0]+n_bottles[i][2]);
			else movs += (n_bottles[i][0]+n_bottles[i][1]);
		}
		return movs;
	}

	void work(int n_bottles[][3]) {
		char tmp_bins[] = {'B', 'G', 'C'};
		sort(tmp_bins, tmp_bins+3);

		unsigned int min_movs = pow(2.0, 32)-1;
		char final_conf[3];

		do {
			unsigned int movs = calculate_movs(tmp_bins, n_bottles);
			if (movs < min_movs) {
				min_movs = movs;
				copy(tmp_bins, tmp_bins+3, final_conf);
			}
		} while(next_permutation(tmp_bins, tmp_bins+3));

		cout << final_conf[0] << final_conf[1] << final_conf[2] << " " << min_movs << endl;
	}

	void run() {
		int n_bottles[3][3]; //brown, green, and clear bottles
		while(cin>>n_bottles[0][0]){
			for(int i=0 ; i<3 ; i++){
				int j = 0;
				if(i==0) j = 1;
				while(j<3){
					cin >> n_bottles[i][j];
					j++;
				}
			}
			work(n_bottles);
		}
	}
}
