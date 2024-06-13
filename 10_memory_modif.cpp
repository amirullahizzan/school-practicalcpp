#include <iostream>

int main()
{
	// BYTE MEMORY MODIFICATION

	int iNum = -1;
	int* pINum = &iNum;

	char* pChar = (char*)&iNum; //Grab the addr, and increase by char length (1 byte)

	short* pShortFront = (short*)(pChar + 0);
	short* pShortBack = (short*)(pChar + 2);

	*pShortBack = 2160;

	//printf("%llu\n", (size_t)iNum);

	size_t iNumAddr = (size_t)pINum;
	size_t shortFrontAddr = (size_t)pShortFront;
	size_t shortBackAddr = (size_t)pShortBack;

	//printf("Front :%d (Addr : %llu[%llu])\n", *pShortFront, (size_t)pShortFront, shortFrontAddr - iNumAddr);
	//printf("Front :%d (Addr : %llu[%llu])\n", *pShortBack, (size_t)pShortBack, shortBackAddr - iNumAddr);

	/////////////////////////////////////////////////////
	//‰Û‘è
	/////////////////////////////////////////////////////

	double dNum = 0.0;
	double* dNumAddr = &dNum;
	printf("Original : %llu\n" , (size_t)dNumAddr);
	
	//char* charNumAddr = (char*)dNumAddr;

	//float* fNumAddr = (float*)((char*)dNumAddr + 0);
	float* fNumAddr = (float*)(dNumAddr )+0;
	printf("ADDR 1 * : First 4 byte %llu\n" , (size_t)dNumAddr);
	printf("Value : %.2f\n", *dNumAddr);

	//float* fNumAddr2 = (float*)((char*)(dNumAddr)+4);
	float* fNumAddr2 = (float*)(dNumAddr)+1; //Convert first, then add to prevent auto casting '1' to double
	//float* fNumAddr2Same = (float*)(charNumAddr+4);
	//float* fNumAddr2 = ((float*)dNumAddr) + 4;
	*fNumAddr2 = 56.78f;
	printf("ADDR 2 * : Second 4 byte %llu\n" , (size_t)fNumAddr2);
	//printf("ADDR 2 * : Second 4 byte %llu\n" , (size_t)fNumAddr2Same);
	printf("Value : %.2f\n", *fNumAddr2);

	printf("DIFF : %llu byte\n", (fNumAddr2 - fNumAddr) * sizeof(float));
	//dNumAddr = (double*)(12.34f);

	//printf("%llu\n" , (size_t)dNumAddr);
	//printf("%zu\n" , sizeof(float));

	system("pause");
	return EXIT_SUCCESS;
}