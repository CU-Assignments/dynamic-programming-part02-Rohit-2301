#include <bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    if (n == 0) return 0;
    
    vector<int> hold(n, 0), sell(n, 0), cooldown(n, 0);
    hold[0] = -prices[0];

    for (int i = 1; i < n; i++) {
        hold[i] = max(hold[i - 1], cooldown[i - 1] - prices[i]);
        sell[i] = hold[i - 1] + prices[i];
        cooldown[i] = max(cooldown[i - 1], sell[i - 1]);
    }
    return max(sell[n - 1], cooldown[n - 1]);
}
