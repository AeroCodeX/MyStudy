struct Range
{
	Range(int s, int e)
	{
		this->s = s;
		this->e = e;
	}
	int s;
	int e;
};
const Range NullRange = Range(0, 0);


// arr[]  : 탐색할 배열
// [s, e) : 배열 내에서 탐색할 구간
// v      : 찾을 값.
Range binaryFind(int arr[], int s, int e, int v)
{
	// 구간이 올바르지 않거나, 구간내에 v가 없는경우.
	if (e <= s) return NullRange;
	if (v < arr[s] || arr[e - 1] < v) return NullRange;

	// 구간을 절반으로 나눈다.
	int mid = (e + s) / 2;
	if (arr[mid] == v)
	{
		// mid가 답을 관통한다.
		int left = mid, right = mid;
		while (0 <= left && v <= arr[left]) left--;
		while (right < e && arr[right] <= v) right++;
		return Range(left + 1, right - 1);
	}
	else if (arr[mid] < v) return binaryFind(arr, mid + 1, e, v);
	else return binaryFind(arr, s, mid, v);
}