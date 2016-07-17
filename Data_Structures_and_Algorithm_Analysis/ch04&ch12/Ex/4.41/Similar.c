int similar(BinaryTree T1, BinaryTree T2){
	if(T1==NULL || T2==NULL)
		return T1==NULL && T2==NULL;
	else
		return similar(T1->Left, T2->Left) && similar(T1->Right, T2->Right);
}