//q.1
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    vector<int> v;
    char ch;
    int val;
    stringstream ss(str);
    vector<int>::iterator it = v.begin();
    ss >> val;
    while(ss >> ch){
        it = v.insert(it, val);
        it++;
        ss >> val;
    }
    it = v.insert(it, val);
    return v;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}

//q.2
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    vector<int> v;
    int size, erase, left, right, val;
    cin >> size;
    vector<int>::iterator it = v.begin();
    for(int i =0; i < size; i++){
        cin >> val;
        it = v.insert(it, val);
        it++;
    }
    cin >> erase;
    v.erase(v.begin() + erase - 1);
    cin >> left >> right;
    for(int i = left; i < right; i++){
        v.erase(v.begin() + left - 1);
    }
    cout << v.size() << endl;
    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}

//q.3
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int find_index(const vector<int> &array, int size, int val){
    int left = 0;
    int right = size - 1;
    while(left <= right){
        int mid = (left + right)/2;
        if(array[mid] >= val){
            if(mid == 0){
                return mid;
            }
            else if(array[mid - 1] < val){
                return mid;
            }
            else{
                right = mid - 1;
            }
        }
        else{
            left = mid + 1;
        } 
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int size, query, arrayVal, val;
    cin >> size;
    vector<int> array;
    vector<int>::iterator it = array.begin();
    for(int i =0; i < size; i++){
        cin >> arrayVal;
        it = array.insert(it, arrayVal);
        it++;
    }
    cin >> query;
    for(int i = 0; i < query; i++){
        cin >> val;
        int index = find_index(array, size, val);
        if(index == -1){
            cout << "All the numbers in the array smaller then " << val << endl;
        }
        else if(array[index] == val){
            cout << "Yes " << index + 1 << endl;
        }
        else if(array[index] != val){
            cout << "No " << index + 1 << endl;
        }
        else{
            cout << "wrong" << endl;
        }
    }
    return 0;
}

//q.4
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    set<int> s;
    int queries, type, val;
    cin >> queries;
    for(; queries > 0; queries--){
        cin >> type >> val;
        switch(type){
            case 1:
                s.insert(val);
                break;
            case 2:
                s.erase(val);
                break;
            case 3:
                if(s.find(val) == s.end()){
                    cout << "No" << endl;
                }
                else{
                    cout << "Yes" << endl;
                }
                break;
        }
    }
    return 0;
}

//q.5
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    map<string, int> marks;
    int queries;
    int type;
    string name;
    //istream in;
    cin >> queries;
    for(int i = 0; i < queries; i++){
        cin >> type >> name;
        switch(type){
            case 1:
                int mark;
                cin >> mark;
                marks[name] += mark;
                break;
            case 2:
                marks[name] = 0;
                break;
            case 3:
                cout << marks[name] <<endl;
                break;
        }
    }
    return 0;
}

//q.6
#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    int first = 0;
    int last = k - 1;
    int max = arr[first];
    do{
        if(first > 0 && max != arr[first -1]){
            if(arr[last] > max){
                max = arr[last];
            }
        }
        else{
            max = arr[first];
            for(int i = first + 1; i <= last; i++){
                if(arr[i] > max){
                    max = arr[i];
                }
            }
        }
        cout << max << " ";
        first++;
        last++;
    }
    while(last < n);
    cout << endl;
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}