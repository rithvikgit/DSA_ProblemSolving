// Gold Nuggets
// You're a seasoned prospector during the height of the Gold Rush, striking it rich in a hidden valley overflowing with gold nuggets! But these nuggets aren't your typical ore; they possess a curious property: you can split them in half (reduce their value exactly) and still mine additional nuggets from the smaller pieces. Your goal? Maximize your profit by strategically splitting nuggets to reach the richest vein of gold as quickly as possible.

// Scenario: You're a seasoned prospector during the height of the Gold Rush, striking it rich in a hidden valley overflowing with gold nuggets! But these nuggets aren't your typical ore; they possess a curious property: you can split them in half (reduce their value exactly) and still mine additional nuggets from the smaller pieces. Your goal? Maximize your profit by strategically splitting nuggets to reach the richest vein of gold as quickly as possible.

// Challenge:

// You're presented with an array nums representing the values of your found nuggets (positive integers between 1 and 10^7). You can halve any nugget in your pile (reduce its value to exactly half) in a single operation. This halved nugget still counts as part of your gold stash. Your mission is to minimize the number of splitting operations you need to perform to reduce the total value of your gold by at least half. Remember, the faster you reach this threshold, the more profitable your expedition!

// Bonus Objective:

// Efficiency is Gold: Develop a cunning mining algorithm that identifies the optimal splitting strategy, even for vast goldfields (large nums arrays). Can you strike the balance between maximizing profit and minimizing effort?

// Input/Output Format:

// Input:
// An array nums containing the values of your gold nuggets.

// Output:
// Return a single integer representing the minimum number of splitting operations needed to reach the profit target (reduce the total gold value by at least half).

// Examples:
// Input:
// 5 19 8 1 (Nuggets in your prospector's pan)

// Output:
// 3 (Following a specific splitting strategy, you can reach the target in 3 operations)

// Input:
// 3 8 20 (Another gold-filled vein)

// Output:
// 3 (Similarly, with the right approach, you can achieve the profit goal in 3 operations)

// Constraints:
// 1 <= n <= 10^5 (Number of gold nuggets in your pile)
// 1 <= nums[i] <= 10^7 (Individual nugget value)

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int min_split_operations(vector<int>& nums) {
    // Step 1: Sort the array in descending order
    sort(nums.begin(), nums.end(), greater<int>());
    
    // Step 2: Initialize variables
    int total_gold = accumulate(nums.begin(), nums.end(), 0);
    int target_gold = total_gold / 2;
    int operations = 0;
    
    // Step 3: Iterate through the sorted array and split nuggets
    for (int nugget : nums) {
        while (nugget > target_gold) {
            nugget /= 2;
            operations++;
            total_gold -= nugget;
        }
        
        if (total_gold <= target_gold) {
            break;
        }
    }
    
    // Step 4: Return the count of splitting operations
    return operations;
}

int main() {
    // Test cases
    vector<int> nums1 = {5, 19, 8, 1};
    cout << min_split_operations(nums1) << endl; // Output: 3
    
    vector<int> nums2 = {3, 8, 20};
    cout << min_split_operations(nums2) << endl; // Output: 3
    
    return 0;
}
