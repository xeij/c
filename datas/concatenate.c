void concatenate(string1, string2, result)
char string1[], string2[], result[];
{
	int i,j;
	for(i=0; string1[i] != '\0'; ++i)
		result[i] = string[i];

	for(j=0; string2[j] != '\0'; ++j)
		result[i+j] = string2[j];

	result[i + j] = '\0';

}
