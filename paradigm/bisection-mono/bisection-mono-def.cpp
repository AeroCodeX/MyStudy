struct Range{ int s, int e };
Range bisection(int x, bool isLeftward)
{
	return (isLeftWard ? bisection_min(x) : bisection_max(x));
}
Range bisection_min(int x);
Range bisection_max(int x);