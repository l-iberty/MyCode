H = merge(H1,H2)
3 < 6
return merge1(H1,H2)
	   H1->Right = merge(H1->Right,H2)
	   			   8 > 6
	   			   return merge1(H2,H1->Right)
	   			          H2->Right = merge(H2->Right,H1->Right)
	   			          			  7 < 8
	   			          			  return merge1(H2->Right,H1->Right)
	   			          			  		 H2->Right->Right = merge(H2->Right->Right,H1->Right)
	   			          			  		 					18 > 8
	   			          			  		 					return merge1(H1->Right,H2->Right->Right)
	   			          			  		 						   H1->Right->Right = merge(H1->Right->Right,H2->Right->Right)
	   			          			  		 						   					  H1->Right->Right == NULL
	   			          			  		 						   					  return H2->Right->Right
	   			          			  		 						   // H1->Right->Right = H2->Right->Right

	   			          			  		 						   H1->Right->Left->Npl = 0,
	   			          			  		 						   H1->Right->Right->Npl = 0
	   			          			  		 						   0 < 0 is False

	   			          			  		 						   H1->Right->Npl = 0 + 1 = 1
	   			          			  		 						   return H1->Right
			  		 						 // H2->Right->Right = H1->Right

			  		 						 H2->Right->Left->Npl = 0,
			  		 						 H2->Right->Right->Npl = 1
			  		 						 0 < 1 is True
			  		 						 swapChildren(H2->Right)

			  		 						 H2->Right->Npl = 0 + 1 = 1(Left child and right child have been swapped.)
			  		 						 return H2->Right
			  		 	  // H2->Right = H2->Right

			  		 	  H2->Left->Npl = 1,
			  		 	  H2->Right->Npl = 1
			  		 	  1 < 1 is False

			  		 	  H2->Npl = 1 + 1 = 2
			  		 	  return H2
   // H1->Right = H2

   H1->Left->Npl = 1,
   H1->Right->Npl = 2
   1 < 2 is True
   swapChildren(H1)

   H1->Npl = 1 + 1 = 3(Left child and right child have been swapped.)
   return H1
// H = H1

如果H2只有一个节点6:
H = merge(H1,H2)
3 < 6
return merge1(H1,H2)
	   H1->Right = merge(H1->Right,H2)
	   			   8 > 6
	   			   return merge1(H2,H1->Right)
	   			   		  H2->Left == NULL
	   			   		  H2->Left = H1->Right

	   			   		  return H2
	   // H1->Right = H2

	   H1->Left->Npl = 1,
	   H1->Right->Npl = 0
	   1 < 0 is False

	   H1 = 0 + 1 = 1
	   return H1
H = H1