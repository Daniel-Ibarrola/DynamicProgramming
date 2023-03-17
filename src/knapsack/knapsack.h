//
// Created by daniel on 17/03/23.
//

#ifndef DYNAMICPROGRAMMING_KNAPSACK_H
#define DYNAMICPROGRAMMING_KNAPSACK_H

#include <cassert>
#include <string>
#include <vector>

using table = std::vector<std::vector<int>>;

class InvalidMethodError : public std::exception
{
public:
    [[nodiscard]] const char* what() const noexcept override {
        return "Invalid method";
    }
};


struct Item
{
    int weight;
    int profit;

    Item(int weight_, int profit_)
        : weight {weight_}, profit {profit_}
    {

    }
};


class Knapsack
{
private:
    int m_capacity;
    std::vector<Item> m_items;

    int maxProfitRec(int currentWeight, int item);
    int maxProfitMem(int currentWeight, int item, table& profits);
    int maxProfitDP();

public:

    Knapsack(int capacity, const std::vector<Item>& items)
        : m_capacity {capacity}, m_items {items}
    {

    }

    int maxProfit(const std::string& method);

};

int knapsack(int capacity, const std::vector<int>& weights, const std::vector<int>& profits);

#endif //DYNAMICPROGRAMMING_KNAPSACK_H
