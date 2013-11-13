#include "ex103.h"
#include <iostream>
#include <vector>
#include <algorithm> //sort
using namespace std;

namespace ex103
{
	void work(vector< vector<int> > box_dims) {
		cout << "--Vector" << endl;
		for(vector< vector<int> >::iterator it=box_dims.begin() ; it!=box_dims.end() ; ++it) {
			vector<int> v = *it;
			for(vector<int>::iterator it2=v.begin() ; it2!=v.end() ; ++it2)
				cout << " " << *it2;

			cout<<endl;
		}
	}

	bool vector_sort(vector<int> a, vector<int> b) {
		vector<int>::iterator a_it = a.begin();
		vector<int>::iterator b_it = b.begin();
		while(a_it != a.end()) {
			if(*b_it <= *a_it) return false;
			a_it++;
			b_it++;
		}
		return true;
	}

	void run() {
		int n_boxes, dims;
		while(cin >> n_boxes) {
			cin >> dims;

			//Read and order vectors
			vector< vector<int> > box_dims;
			for(int i=0 ; i<n_boxes ; i++) {
				vector<int> tmp_vector;
				for(int j=0 ; j<dims ; j++) {
					int tmp_value;
					cin >> tmp_value;
					tmp_vector.push_back(tmp_value);
				}
				sort(tmp_vector.begin(), tmp_vector.end()); //sort dimensions of each vector
				box_dims.push_back(tmp_vector);
			}
			sort(box_dims.begin(), box_dims.end(), vector_sort);

			work(box_dims);
		}
	}
}
