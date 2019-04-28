#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename T>
using ordered_set=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

int main()
{
    ordered_set<int>s;
    s.insert(1);
    s.insert(3);
    cout << s.order_of_key(2) << '\n'; //Number of element in s less than 2
    cout << *s.find_by_order(0) << '\n'; //Print 0'th smallest number
    return 0;
}
