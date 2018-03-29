// https://www.hackerrank.com/contests/rookierank-4/challenges/height-and-total-height-of-a-bst#include <bits/stdc++.h>

#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

typedef struct node{
	int val;
	int height;
	struct node* left;
	struct node* right;
}node;

int max_and_total_height(node *root,int *total,int *maximum){
	if(root==NULL)
		return -1;
	root->height=1+max(max_and_total_height(root->left,total,maximum),max_and_total_height(root->right,total,maximum));
	if(root->height>*maximum)
		*maximum=root->height;
	if(root->height!=-1 && root->height!=0)
		*total+=root->height;
	return root->height;
}

node* newnode(int val){
	node *n=(node *)malloc(sizeof(node));
	n->val=val;
	n->left=n->right=NULL;
    return n;
}

node *insert(node *root,int val){
	if(root==NULL)
		return newnode(val);
	if(root->val>val)
		root->left=insert(root->left,val);
	else if(root->val<val)
		root->right=insert(root->right,val);
    else{}
        
	return root;
}

/*
 * Complete the function below.
 */
vector<int> heightAndTotalHeight(vector<int> arr) {
    // Write your code here.
	node *root=NULL;
	for(int i=0;i<arr.size();i++){
		root=insert(root,arr[i]);
	}

	int max=0,total=0;
	int x=max_and_total_height(root,&total,&max);
	vector<int>res;
	res.push_back(max);
	res.push_back(total);
    return res;
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int arr_size;
    cin >> arr_size;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string arr_str_temp;
    getline(cin, arr_str_temp);

    vector<string> arr_str = split_string(arr_str_temp);

    vector<int> arr(arr_size);
    for (int arr_i = 0; arr_i < arr_size; arr_i++) {
        int arr_item = stoi(arr_str[arr_i]);

        arr[arr_i] = arr_item;
    }

    vector<int> result = heightAndTotalHeight(arr);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
