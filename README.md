# Basic

It's the thinking that matters, not the recollection and senseless coding.

  - Basic sorting/searching and other basic mechanism.
  - Make things more complicated when combination these basic algorithms to solve advanced problem.
  - Concern to Advanced Math and Probability Theory approaches

## asymptotic analysis
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

## Algorithms
### sorting
| Plugin | Key Point | Complexity Analysis | Best  | Worst  | Average |
| ------ | ------ | ------ | ------ | ------ | ------ |
| quick sort | Quick sort is a up-to-down solution, it's the partition what matters most in this algo, we need use an integer to track number of elements which is bigger than the pivot and place the new found element to the proper position | T(n) = T(k) + T(n-k) + a*n | happens when the pivot always partition the array into two balance part, that is, T(n) = 2(T/2) + a*n = n*T(1) + a*n*㏒₂n| happens when the pivot is always the largest element in an increase order sort.  k=1, T(n) = nT(1) + a*(n+2)*(n-1)/2, T(n)=O(n²) | 
| merge sort | an easy sort algo with no critical operation | Always nLog₂n | nLog₂n | nLog₂n | nLog₂n |

## DataStructure
### singleLinkedList
1. singleLinkedList vs array:
	+ advantage
		+ LL has more efficient insertion and deletion(O(1)); 
		+ dynamic size.
	+ disadvantage
		+ worse efficienet access (O(n));
		+ without **cache locality**;
		+ single node has a large space because of the pointer, but since LL size is dynamic, which will get one more bonus.
	+ storage area
		+ generally, array is allocated memory on Data section (global array) or Stack section (local array), sinlgeLinkedList is allocated dynamically (during run-time).
		+ in fact, a **dynamic array** can be created on heap by using pointer, which take advatanges of both random access and  dynamic size like this: 
        ```
        int * dynArr = (int *)malloc(sizeof(int)*arrSize);
        ```
        And a linkedList can be created on stack/data area in embedded systems, since malloc()  is costly in terms of time complexity.
        Meanwhile,  we can simmulate linkedList on an array but it is obviously different from a real linkedList.
2. Operation on SingleLinkedList:
    + [look at how to swap nodes: A great idea handle all situations.](https://github.com/zpflyyer/DsAndAlg/commit/f28e3ff2140648ef8ad7f08e964910dc53cece28)
        