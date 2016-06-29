# The analysis of full permutation
> * Take "arr = {1,2,3}" as an example:

	call perm({1,2,3},0,2):
	j=begin=0,end=2, j: 0->2...
		j=0:
			swap(arr[begin],arr[j]),begin=0,j=0,so arr={1,2,3}
			call perm(arr,1,2):{
				j=begin=1,end=2, j: 1->2...
				j=1:
					sawp(arr[begin],arr[j]),begin=1,j=1,so arr={1,2,3}
					call perm(arr,2,2): 2=2, so <<{1,2,3}
					swap(arr[begin],arr[j]), begin=1,j=1,so arr={1,2,3}
				j=2:
					swap(arr[begin],arr[j]),begin=1,j=2,so arr={1,3,2}
					call perm(arr,2,2): 2=2, so <<{1,3,2}
					swap(arr[begin],arr[j]),begin=1,j=2,so arr={1,2,3}
			}
			swap(arr[begin],arr[j]),begin=0,j=0,so arr={1,2,3}
		j=1:
			swap(arr[begin],arr[j]),begin=0,j=1,so arr={2,1,3}
			call perm(arr,1,2):{
				j=begin=1,end=2, j: 1->2...
				j=1:
					swap(arr[begin],arr[j]),begin=1,j=1,so arr={2,1,3}
					call perm(arr,2,2): 2=2, so <<{2,1,3}
					swap(arr[begin],arr[j]),begin=1,j=1,so arr={2,1,3}
				j=2:
					swap(arr[begin],arr[j]),begin=1,j=2,so arr={2,3,1}
					call perm(arr,2,2): 2=2, so <<{2,3,1}
					swap(arr[begin],arr[j]),begin=1,j=2,so arr={2,1,3}
			}
			swap(arr[begin],arr[j]),begin=0,j=1,so arr={1,2,3}
		j=2:
			swap(arr[begin],arr[j]),begin=0,j=2,so arr={3,2,1}
			call perm(arr,1,2):{
				j=begin=1,end=2, j: 1->2...
				j=1:
					swap(arr[begin],arr[j]),begin=1,j=1,so arr={3,2,1}
					call perm(arr,2,2): 2=2, so <<{3,2,1}
					swap(arr[begin],arr[j]),begin=1,j=1,so arr={3,2,1}
				j=2:
					swap(arr[begin],arr[j]),begin=1,j=2,so arr={3,1,2}
					call perm(arr,2,2): 2=2, so <<{3,1,2}
					swap(arr[begin],arr[j]),begin=1,j=2,so arr={3,2,1}
			}
			swap(arr[begin],arr[j]),begin=0,j=2,so arr={1,2,3}