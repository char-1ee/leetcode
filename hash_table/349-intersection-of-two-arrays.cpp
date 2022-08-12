// This is a Facebook interview question.
// They ask for the intersection, which has a trivial solution using a hash or a set.

// Then they ask you to solve it under these constraints:
// O(n) time and O(1) space (the resulting array of intersections is not taken into consideration).
// You are told the lists are sorted.

// Cases to take into consideration include:
// duplicates, negative values, single value lists, 0's, and empty list arguments.
// Other considerations might include
// sparse arrays.

#include <bits/stdc++.h>
using namespace std;

vector<int> intersections(vector<int>& nums1, vector<int>& nums2) {
    vector<int> res;
    int p1 = 0, p2 = 0;
    while (p1 < nums1.size() && p2 < nums2.size()) {
        int n1 = nums1[p1];
        int n2 = nums2[p2];
        if (nums1[p1] == nums2[p2]) {
            res.push_back(nums1[p1]);
            while (nums1[p1] == n1) p1++;
            while (nums2[p2] == n2) p2++;

        } else if (nums1[p1] > nums2[p2]) {
            while (nums2[p2] == n2) p2++;
        } else { // < 
            while (nums1[p1] == n1) p1++;
        }
    }
    return res;
}

void Test(const char* testName, vector<int> nums1, vector<int> nums2, vector<int> expected) {
    printf("%s: ", testName);
    vector<int> res = intersections(nums1, nums2);
    if (res == expected) {
        printf("Passed.\n");
    } else {
        printf("FAILED\n");
    }
}

// Positives
void Test1() {
    vector<int> n1 = {4, 5, 9};
    vector<int> n2 = {4, 4, 8, 9, 9};
    vector<int> res = {4, 9};
    Test("Test 1", n1, n2, res);
}

// Empty lists
void Test2() {
    vector<int> n1 = {};
    vector<int> n2 = {};
    vector<int> res = {};
    Test("Test 2", n1, n2, res);
}

// Single value lists
void Test3() {
    vector<int> n1 = {0};
    vector<int> n2 = {2};
    vector<int> res = {};
    Test("Test 3", n1, n2, res);
}

// Negatives
void Test4() {
    vector<int> n1 = {-5, -3, -1, 0, 2, 4, 5};
    vector<int> n2 = {-3, -2, 1, 4, 8};
    vector<int> res = {-3, 4};
    Test("Test 4", n1, n2, res);
}

// Duplicates
void Test5() {
    vector<int> n1 = {8, 8, 8, 8, 8, 8, 8};
    vector<int> n2 = {8, 8, 8};
    vector<int> res = {8};
    Test("Test 5", n1, n2, res);
}

int main(int argc, char *argv[]) {
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}
