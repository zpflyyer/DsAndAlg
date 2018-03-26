# Basic

It's the thinking that matters, not the recollection and senseless coding.

  - Basic sorting/searching and other basic mechanism.
  - Make things more complicated when combination these basic algorithms to solve advanced problem.
  - Concern to Advanced Math and Probability Theory approaches

## what and why asymptotic analysis
Although there're many factors about the execution time ( and space usage ) of an algorithm, for two given algorithms with the same input size, if they run on the same machine, the most principal factor will be the input size. Here're something to pay attention to:
 * When we talk about that one algorithms is faster than another, we ignored other factors except input size and the input size is large enough. In short, we need to judge which one is the high-order infinity of another, the L'Opida Rule will be quite useful here.
 * Since inputs may vary a lot ( for example, the order of the original array play a as decisive as the algorithm  role in the execution time ),  we can not directly give the result of asymptotic analysis for an explicit input case. Therefore when we talk the complexity of an algorithm, we usually indicate the worst complexity. 
 * In addition to the average complexity, we still need to know in what input conditions will the algorithm get the worst and best execution time respectively, though only the worst performance matters in most time.
 * It's not easy to estimate the average complexity since it involves probabilistic arguments and often assumptions about the distribution of inputs that may be difficult to justify. So Probability Theory is also important.

Shortcomings asymptotic analysis
* ignore small size inputs.
* implementation complexity.
* Worse case versus average case
  generally we may choose the one which has the best average case performance, but not always, for some mission-critical or life-threatening reason, we should never choose those with an unacceptable worst case performance even its average case performance is pretty good.
### Big O notation
https://en.wikipedia.org/wiki/Big_O_notation#Family_of_Bachmann.E2.80.93Landau_notations

## sorting
| Plugin | Key Point | Complexity Analysis | Best  | Worst  | Average |
| ------ | ------ | ------ | ------ | ------ | ------ |
| quick sort | Quick sort is a up-to-down solution, it's the partition what matters most in this algo, we need use an integer to track number of elements which is bigger than the pivot and place the new found element to the proper position | T(n) = T(k) + T(n-k) + a*n | happens when the pivot always partition the array into two balance part, that is, T(n) = 2(T/2) + a*n = n*T(1) + a*n*㏒₂n| happens when the pivot is always the least element.  k=1, T(n) = nT(1) + a*(n+2)*(n-1)/2, T(n)=O(n²) | 