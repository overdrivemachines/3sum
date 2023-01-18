#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector<int>> result;
  unordered_map<int, vector<pair<int, int>>> umap;
  unordered_map<int, vector<pair<int, int>>>::iterator umapit;
  bool flag;

  int sum;

  // -1, 0, 1, 2, -1, -4

  for (long unsigned int i = 0; i < nums.size(); i++) {
    for (long unsigned int j = i + 1; j < nums.size(); j++) {
      sum = nums[i] + nums[j];
      umap[sum].push_back({i, j});
      // cout << nums[i] << ":" << nums[j] << " ";
    }
  }

  // values inside the pair are indexes of nums
  //
  // umap  3: {2,3}              3 = nums[2]+nums[3]
  // umap -4: {1,5}             -4 = nums[1]+nums[5]
  // umap -5: {0,5}{4,5}        -5 = nums[0]+nums[5] = nums[4]+nums[5]
  // umap -2: {0,4}{3,5}
  // umap  1: {0,3}{1,2}{3,4}
  // umap -3: {2,5}
  // umap  0: {0,2}{2,4}
  // umap  2: {1,3}
  // umap -1: {0,1}{1,4}

  // print umap
  // for (auto x : umap) {
  //   cout << "umap " << x.first << ": ";
  //   for (auto y : x.second)
  //     cout << "{" << y.first << "," << y.second << "}";
  //   cout << "\n";
  // }

  // return result;

  // For each element find the complementing pair
  int element;
  int complement;
  for (long unsigned int i = 0; i < nums.size(); i++) {
    element = nums[i];
    complement = (-1) * element;

    // cout << "nums[" << i << "]=" << element << ": ";

    umapit = umap.find(complement);

    if (umapit == umap.end()) {
      // cout << "not found";
    }
    else {
      // There are pairs of numbers that complement the current element
      // Iterating through the vector umapit->second
      for (auto x : umapit->second) {
        // x is a pair containing the indexes of nums
        if (!((i == x.first) || (i == x.second))) {
          // cout << "{indexes:" << x.first << "," << x.second << "} ";

          vector<int> triplet = {nums[i], nums[x.first], nums[x.second]};
          sort(triplet.begin(), triplet.end());

          // check if triplet exists in the results vector before inserting it
          flag = false;
          for (auto v : result) {
            if (v == triplet)
              flag = true;
          }

          if (flag == false)
            result.push_back(triplet);
        }
      }
    }
    // cout << "\n";


  }


  return result;

}

// Print a vector of vector of ints
void printv(vector<vector<int>> result) {
  string output = "";
  for (vector<int> v : result) {
    output += "[";
    for (int i : v) {
      // output.pop_back();
      output = output + std::to_string(i) + ",";
    }
    if (v.size() > 0)
      output.pop_back();
    output += "] ";
  }

  cout << output << "\n";
}

int main(int argc, char const *argv[]) {

  vector<int> nums = { -1, 0, 1, 2, -1, -4};

  // vector<vector<int>> result = { {3, 6}, {6, 78}, {4, 7}, {4}, {}};
  vector<vector<int>> result = threeSum(nums);
  printv(result);
  return 0;
}
