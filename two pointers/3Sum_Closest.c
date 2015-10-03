int comp (const void*a,const void*b) {    
	return *(int*)a-*(int*)b;
}

int abs_v (int a) {	
	if (a < 0)
		return -a;
	else
		return a;
}

int threeSumClosest (int* nums, int numsSize, int target) {
	int i, l, r;    
	int closet_sum = 0x1FFFFFFF;        
	qsort(nums, numsSize,sizeof(int), comp);        
	for (i = 0; i < numsSize-2; i++) {        
		if (i > 0 && nums[i] == nums[i-1])            
			continue;        
		l = i+1;        
		r = numsSize-1;                
		while (l < r) {            
			int sum = nums[i] + nums[l] + nums[r];                
			if (sum == target)                
				return sum;            
			if (abs_v(sum-target) < abs_v(closet_sum -target)) {                
				closet_sum = sum;            
			}            
			if (sum > target)                
				r--;            
			else                 
				l++;        
		}    
	}        
	return closet_sum;
}