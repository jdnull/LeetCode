# 188 Best Time to Buy and Sell Stock IV 

Say you have an array for which the *i<sup>th</sup>* element is the price of a given stock on *day i*.

Design an algorithm to find the maximum profit. You may complete at most k transactions.

###### Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

###### Tags:
Dynamic Programming

###### My thoughts:
let `profit(t)`means the maximum profit after *t<sup>th</sup>* transactions.

> profit(t)=max{profit(t-1), profit(t-1)+t<sub>i</sub> where *t<sub>i</sub>*'s buy day after *t-1*'s sell day}

using another array to store the squence of transactions.