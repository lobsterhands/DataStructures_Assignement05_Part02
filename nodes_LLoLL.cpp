#include "nodes_LLoLL.h"
#include "cnPtrQueue.h"
#include <iostream>
using namespace std;

namespace CS3358_SP16_A5P2
{
   void Destroy_cList(CNode*& cListHead)
   {
      int count = 0;
      CNode* cNodePtr = cListHead;
      while (cListHead != 0)
      {
         cListHead = cListHead->link;
         delete cNodePtr;
         cNodePtr = cListHead;
         ++count;
      }
      cout << "Dynamic memory for " << count << " CNodes freed"
           << endl;
   }

   void Destroy_pList(PNode*& pListHead)
   {
      int count = 0;
      PNode* pNodePtr = pListHead;
      while (pListHead != 0)
      {
         pListHead = pListHead->link;
         Destroy_cList(pNodePtr->data);
         delete pNodePtr;
         pNodePtr = pListHead;
         ++count;
      }
      cout << "Dynamic memory for " << count << " PNodes freed"
           << endl;
   }

   // do depth-first traversal and print data
   void ShowAll_DF(PNode* pListHead, ostream& outs)
   {
      while (pListHead != 0)
      {
         CNode* cListHead = pListHead->data;
         while (cListHead != 0)
         {
            outs << cListHead->data << "  ";
            cListHead = cListHead->link;
         }
         pListHead = pListHead->link;
      }
   }

   // do breadth-first (level) traversal and print data
   void ShowAll_BF(PNode* pListHead, ostream& outs)
   {
      // to be implemented (part of assignment)
      // See StackQueueEG02 from Lee's example page

      // Breadth-first is a queue-based problem
      // It will use a queue of pointers to Child nodes
//
//      if (head == 0) return
      if (pListHead == 0) return;

//      create queue q of CNode*
      cnPtrQueue CNodeQueue;
      CNode *cursor = 0;
      while (pListHead != 0) {
         if (pListHead->data != 0) {
            CNodeQueue.push(pListHead->data);
         }
         pListHead = pListHead->link;
      }
      while ( ! CNodeQueue.empty() ) {
         cursor = CNodeQueue.front();
         CNodeQueue.pop();
         outs << pListHead->data << " ";
         if ( cursor->link != 0 )
            CNodeQueue.push( cursor->link );
      }

   }
}
