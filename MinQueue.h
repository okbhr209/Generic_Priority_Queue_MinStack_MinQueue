
#ifndef MINQUEUE_H
#define MINQUEUE_H
#include "MinStack.h"
using namespace std;

/*
Implementation of a Queue data structure that
supports insertion at the back of the queue,
removal from the front and get Minimum element
currently in the queue all in amortized O(1) time.
*/
template<class T>
class MinQueue
{
    public:
        //Push x to the rear of the queue
        void push(T x);
        //remove element from the front
        void pop();
        //get element currently at front of queue
        T top();
        //get smallest element currently in the queue
        T getMin();
        //check if the queue is empty
        bool empty()
        {
            return (input.empty() && output.empty());
        }
        //number of elements currently in the queue
        int size()
        {
            return input.size() + output.size();
        }

    private:
        //minStacks used to simulate the minQueue
        MinStack<T> input, output;
        /*
          aux function that transfer elements from
          input stack to output stack.
        */
        void fillFront();
};

template<class T>
void MinQueue<T> :: push(T x)
{
    input.push(x);
}

template<class T>
void MinQueue<T> :: pop()
{
    //no action if queue is empty.
    if(empty() ){
        throw new exception() ;
    }

        // return;

    /*
      element at top of Front represents the head
      element of the queue.
    */
    if(output.empty())
       fillFront();

    output.pop();
}

template<class T>
void MinQueue<T> :: fillFront()
{
     /*
       Transfer the contents of input Stack
       to output stack.
     */
     while(!input.empty())
       {
           output.push(input.top());
           input.pop();
       }
}

template<class T>
T MinQueue<T> :: top()
{
    //if queue is empty throw an exception.
    if( empty() )
        throw *new exception;

    if(output.empty())
      fillFront();

    return output.top();
}

template<class T>
T MinQueue<T> :: getMin()
{
    //if queue is empty throw an exception.
    if( empty() )
        throw *new exception;

    /*
       The elements of the queue are divided into
       the two stacks, so min of the queue is
       min(min of input, min of output).
    */

    if(output.empty())
        return input.getMin();

    else if(input.empty())
        return output.getMin();

    else return min(input.getMin(), output.getMin());
}

#endif // MINQUEUE_
