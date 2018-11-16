struct Range{ int s, int e };
Range bisection(int x, bool isLeftward)
{
	if (isLeftward)
	{	// left-ward
		return bisection_min(x);
	}
	else
	{	// right-ward
		return bisection_max(x);
	}
}
Range bisection_min(int x);
Range bisection_max(int x);