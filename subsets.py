def subsets(nums):
	subsets=[[]]
	next=[]
	for num in nums:
		for sub in subsets:
			next.append(sub+[num])
		subsets+=next
		next=[]
	return subsets
