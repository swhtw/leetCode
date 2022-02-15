// https://leetcode.com/problems/minimum-cost-for-tickets/
#include "Utility.h"

int mincostTickets(vector<int>& days, vector<int>& costs) {
	days.push_back(INT_MAX);
	vector<int> minCost(days.size(), INT_MAX);
	for (int i = minCost.size() - 1; i >= 0; --i)
	{
		if (i == minCost.size() - 1)
		{
			minCost[i] = 0;
		}
		else
		{
			for (int j = i + 1; j < minCost.size(); ++j)
			{
				if (days[j - 1] - days[i] < 1 && minCost[j] + costs[0] < minCost[i])
				{
					minCost[i] = minCost[j] + costs[0];
				}
				if (days[j - 1] - days[i] < 7 && minCost[j] + costs[1] < minCost[i])
				{
					minCost[i] = minCost[j] + costs[1];
				}
				if (days[j - 1] - days[i] < 30 && minCost[j] + costs[2] < minCost[i])
				{
					minCost[i] = minCost[j] + costs[2];
				}
				if (days[j - 1] - days[i] >= 30)
				{
					break;
				}
			}
		}
	}
	return minCost[0];
}