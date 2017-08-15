最近做的动态规划总结：
最主要的是要考虑的是状态转化，确定之后，考虑下边界初始化，就可以写出code

1.从上楼梯问题入手：每次可以跳1阶或者2阶，给n，找出多少跳法
对于当前n,要么从n-1阶过来，要么从n-2台阶过来
也就是f(n) = f(n-1) + f(n-2)
虽然递归的思路也可以解决，但是考虑效率的问题还是花空间记录下

2.给一个数组，求最大连续子数组的和
对于当前的数考虑最大和，dp[i]记录的是以a[i]结尾的最大和
dp[i] = max(dp[i-1] + a[i], a[i])  有可能存在负数的情况
那么对于整个数组的最大连续子数组的和： sum = max(dp[0],dp[1],dp[2]...dp[n-1])
code:
dp[0] = a[0];
for(int i = 1; i < n; i++){
	if(dp[i-1] > 0) {
		dp[i] = dp[i-1] + a[i];
	} else {
		dp[i] = a[i];
	}
}
int sum = 0;
for(int i = 0; i < n; i++){
	sum = max(sum, dp[i]);
}
return sum;
这里为了节省空间，使用一个变量滚动记录减少dp的使用
具体如下：
int sumhere = a[0], summax = a[0];
for(int i = 1; i < len; i++){
	if(sumhere > 0){
		sumhere += a[i];
	} else {
		sumhere = a[i];
	}
	summax = max(summax, sumhere);
}
return summax;

3.给一个数组，求最大连续递增数组的个数
类比上题，dp[i]记录的是以a[i]结尾的连续递增数组的个数
if(a[i] > a[i-1]) 
	dp[i] = dp[i-1] + 1
else    
	dp[i] = 1
同样为了节省空间，使用一个变量尽量记录即可

4.给定一个数组，求其中最大连续数组的乘积
因为是乘积，有两种情况，负负得正，正正为正
对于数字a[i], 不确定其正负情况，就需要比较这两种情况的最大值
pos[i] = max(pos[i-1] * a[i], max(neg[i-1] * a[i], a[i]))
neg[i] = min(pos[i-1] * a[i], min(neg[i-1] * a[i], a[i]))
同样为了节省空间，使用两个变量滚动记录即可


