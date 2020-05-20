#include <stack>
using namespace std;

void concatena_piles(stack<int> &p, stack<int> &q, stack<int> &concatp);
/* Pre: p = P i q = Q i concatp es buida */
/* Post: concatp conte a dalt els elements de P en 
   el mateix ordre, i a sota els elements de Q en el mateix
   ordre */
