
#include "stdafx.h"
#include"Node.h"
#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

// set operator of priority queue so that Nodes can be sorted in min heap
struct compareNode : public binary_function <Node*, Node*, bool>
	{
	bool operator()(const Node* left, const Node* right) const
	{
		return left->element_val > right->element_val;
	}
};
/*
* merge function
* @param Input arrs to be merged
* @param Input arrs_length of arrs
* @param Output re_arr is merged array
* @param Output re_size is length of merged array
* @return function works well (0) or not (1)
*/


int merge(int *arrs[],int arrs_length[], int *re_arr, int & re_size) {
	int k = 5;
		//sizeof(arrs)/ sizeof (int*);

// build a priority queue and insert nodes form k arrays (start with first elements of each array)
	priority_queue < Node*, vector <Node*>, compareNode > pq1;

	// create nodes from the first elements of each array consisting of Node (element_val,  array_num)
	for (int i = 0; i < k; i++) {
		Node* heapNode = new Node(*(arrs[i]),i );
		pq1.push(heapNode);
		arrs_length[i]--;
		arrs[i]++;
		}
	//fill re_arr with objects from the heap

	int j =0;
	while (!pq1.empty()) {
		Node * heapNode = pq1.top();
		re_arr[j] = heapNode->element_val;
		j++;
		pq1.pop();

		int arrayNumber = heapNode->array_num;
		// delete the node if array is empty. then we don't need the node anymore. checked with an extra variable
		if (NULL == arrs_length[arrayNumber]) {
			delete heapNode;
			continue;
		}
// refill the node[k] with the next element in the array

		heapNode->element_val = *(arrs[(*heapNode).array_num]);
		pq1.push(heapNode);
		arrs_length[arrayNumber]--;
		arrs[arrayNumber]++;
	}
	return 0;
}

/*
* intersecteion function
* @param Input arrs to be computed
* @param Input arrs_length of arrs
* @param Output re_arr is intersection
* @param Output re_size is length of intersection
* @return function works well (0) or not (1)
*/


int intersect(int *arrs[], int arrs_length[], int *re_arr, int & re_size) {

// build a hash map containing all elements of the first array

	unordered_map<int,int> Map0;
	unordered_map<int, int> Map1;
	unordered_map<int, int> Map2;
	unordered_map<int, int> Map3;

	unordered_map<int,int>::iterator iter;

	for (int i = 0; i < arrs_length[0]; i++) {
		Map0[arrs[0][i]];
	}

	for (int i = 0; i < arrs_length[1]; i++) {
		Map1[arrs[1][i]];
	}
	for (int i = 0; i < arrs_length[2]; i++) {
		Map2[arrs[2][i]];
	}
	for (int i = 0; i < arrs_length[3]; i++) {
		Map3[arrs[3][i]];
	}


// check all elements of the second array if they are contained in the hash map.
	int j = 0;
	for (int i = 0; i < arrs_length[4]; i++) {
		if (Map0.count(arrs[4][i]) > 0  && Map1.count(arrs[4][i]) > 0 && Map2.count(arrs[4][i]) > 0 && Map3.count(arrs[4][i]) > 0)
		{

			re_arr[j] = arrs[4][i];
			j++;
			
		}
		re_size = j;
	}
// iterator
//	for (iter = Map1.begin(); iter != Map1.end(); iter++) {
		
//	}
		

	return 0;
}

int main() {
	//test case
	int * arrs[5];
	int arrs_length[5];
	int arr0[] = { 1, 5, 8 };
	int arr1[] = { 1, 2, 3, 5, 7, 10, 11, 15 };
	int arr2[] = { 1, 4, 5, 6 };
	int arr3[] = { 2, 5, 9, 14, 16, 19 };
	int arr4[] = { 1, 2, 4, 5, 6, 9, 9 };
	arrs[0] = arr0;
	arrs_length[0] = sizeof(arr0) / sizeof(int);
	arrs[1] = arr1;
	arrs_length[1] = sizeof(arr1) / sizeof(int);
	arrs[2] = arr2;
	arrs_length[2] = sizeof(arr2) / sizeof(int);
	arrs[3] = arr3;
	arrs_length[3] = sizeof(arr3) / sizeof(int);
	arrs[4] = arr4;
	arrs_length[4] = sizeof(arr4) / sizeof(int);
	cout << "Input:" << endl;
	for (int i = 0; i < 5; i++) {
		cout << "[";
		for (int j = 0; j < arrs_length[i] - 1; j++) {
			cout << arrs[i][j] << ", ";
		}
		cout << arrs[i][arrs_length[i] - 1] << "]" << endl;
	}
	//sum length
	int sum_length = 0;
	for (int i = 0; i < 5; i++) {
		sum_length += arrs_length[i];
	}

	//intersection manipulation
	//expected output
	//[1, 5]
	int * intersection = new int[sum_length];
	int intersect_length = sum_length;
	if (intersect(arrs, arrs_length, intersection, intersect_length) == 0) {
		cout << "Output:" << endl << "[";
		for (int i = 0; i < intersect_length - 1; i++) {
			cout << intersection[i] << ",";
		}
		cout << intersection[intersect_length - 1] << "]" << endl;
	}

	//merge manipulation
	//expected output
	//[1, 1, 1, 1, 1, 2, 2, 3, 4, 4, 5, 5, 5, 5, 5, 6, 6, 7, 8, 9, 9, 9, 10, 11, 14, 15, 16, 19]
	int * merged = new int[sum_length];
	int merge_length = sum_length;
	if (merge(arrs, arrs_length, merged, merge_length) == 0) {
		cout << "Output:" << endl << "[";
		for (int i = 0; i < merge_length - 1; i++) {
			cout << merged[i] << ",";
		}
		cout << merged[sum_length - 1] << "]" << endl;
	}

	system("PAUSE");
	return 0;
	
}
