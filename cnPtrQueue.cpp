#include "cnPtrQueue.h"
#include <cassert>
using namespace std;

namespace CS3358_SP16_A5P2
{
   // to be implemented (part of assignment)
    cnPtrQueue::cnPtrQueue(): numItems(0) {
       cout << "Constructor" << endl;
   }

    bool cnPtrQueue::empty() const
    {
        cout << "Empty" << endl;

        if (numItems == 0) {
            return true;
        }
        return false;
    }

    cnPtrQueue::size_type cnPtrQueue::size() const {
        cout << "Size" << endl;

        return numItems;
    }

    CNode* cnPtrQueue::front() {
        cout << "Front" << endl;

        CNode *front = 0;

        // This front pointer needs to ... point to the front.

        return front;
    }


    void cnPtrQueue::push(CNode* cnPtr) {
        cout << "Push" << endl;

        // Shove stuff onto the queue
    }

    void cnPtrQueue::pop() {
        cout << "Pop" << endl;

        // Pop stuff off the queue (FIFO style)
    }







}
