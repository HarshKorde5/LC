


/*
Given an integer n, return a counter function. This counter function initially returns n and then returns 1 more than the previous value every subsequent time it is called (n, n + 1, n + 2, etc).
*/

/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {
    return function() {
        return n++;
    };
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */


console.log(createCounter(10));



/**
 * what is the benefit of returning nested function instead of just an incremented value?
Answer:
This is a good example of closure.

One benefit of returning a nested function instead of just an incremented value is that it allows you to create multiple independent counters, each with its own internal state, without having to create a separate function for each one.

A closure is a function that has access to variables in its outer (enclosing) function's scope chain.
In this code, the inner function that is returned by the "createCounter" function is a closure, and it has access to the "n" variable in the outer "createCounter" function's scope.


 * 
 */