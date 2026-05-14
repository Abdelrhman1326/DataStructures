#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// insert/delete in O(log n)
// still query by index
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>