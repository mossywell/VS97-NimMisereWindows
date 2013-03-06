// File name: Combination.h

// Function Combination
// Return Values:
//	OK		 - All went well
//	NOMEMORY - not enough memory
//	BADINPUT - A combination was attempted with R > N
//	OVERFLOW - The calculation overflowed
//
UINT MyCombination(UINT N, UINT R, UINT *pResult)
{
	UINT *pStartOfArray,
		 *pEndOfArray,
		 *pVar, *pVar2;

	UINT i = 999, j = 999, jcopy = 999;
	bool bDone = false;
	bool bKeepGoing = false;
	double dTemp = 999.0;	

	// Check it's a valid combination
	if(R > N)
	{
		return (BADINPUT);
	}

	// R==0 and R==1 don't need much work
	switch (R)
	{
	case 0:
		*pResult = 1;
		break;

	case 1:
		*pResult = N;
		break;

	default:
		R=(R > (N - R) ? (N - R) : R);
		
		// Allocate memory for the array of N - R
		// elements of UINTs
		if((pStartOfArray = (UINT *) new UINT[R]) == NULL)
		{
			return(NOMEMORY);
		}

		// Point pEnd to the array element beyond the 
		// end of the array
		pEndOfArray = pStartOfArray + R;

		// Set up a temporary variable pointer starting
		// off by equalling pStartOfArray
		pVar = pStartOfArray;

		//Initialise the new array
		while(pVar < pEndOfArray)
		{
			*pVar++ = N--;
		}

		// Start to divide the array elements
		for(j = R; j >= 2; j--)
		{
			for(bDone = false, pVar = pStartOfArray; pVar < pEndOfArray && bDone == false; pVar++)
			{
				if((*pVar) % j == 0)
				{
					*pVar /= j;
					bDone = true;
				}
			}
			// Here's where we check to see if it failed to divide. If it did fail
			// we'll have to use a blunderbuss approach to get rig of j.
			if(bDone == false)
			{
				// Make a copy of j so that we don't change j
				jcopy = j;
				// Loop whilst i <= jcopy
				for(i = 2; i <= jcopy; i++)
				{
					bKeepGoing = true;
					while(bKeepGoing && jcopy != 1)
					{
						// Go through the array and try dividing each one by i
						bKeepGoing = false;
						for(pVar2 = pStartOfArray; pVar2 < pEndOfArray && jcopy != 1; pVar2++)
						{
							// If jcopy and *pVar both divide by i then go ahead
							// and divide them. Seeing as it worked, we'll set
							// the bKeepGoing flag to true so that we can have
							// another go using the same i.
							if(jcopy % i == 0 && *pVar2 % i == 0)
							{
								jcopy /= i;
								*pVar2 /= i;
								bKeepGoing = true;
							}
						}
					}
				}
			}		
		}

		// Multiply all the remaining elements together to get the result
		for(*pResult = 1, pVar = pStartOfArray; pVar < pEndOfArray; pVar++)
		{
			*pResult *= (*pVar);
		}

		// Just make sure we've not overflowed our UINTs
		dTemp = (double) *pResult;
		for(pVar = pStartOfArray; pVar < pEndOfArray; pVar++)
		{
			dTemp /= (double) *pVar;
		}
		if(dTemp != 1.0)
		{
			return(OVERFLOW);
		}

		delete pStartOfArray;

		break;
	}
	return (OK);
}
