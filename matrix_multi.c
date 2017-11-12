 
int main()
{
    int mat1[3][3],mat2[3][3];
    int res[3][3];	
	int i, j, k;
	
	printf("Enter the element of 1st (3*3)array for multiplication :");
	for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
          scanf("%d",&mat1[i][j]);
          
    printf("Enter the element of 2nd (3*3)array for multiplication :");
	for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
          scanf("%d",&mat2[i][j]);
		        
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            res[i][j] = 0;
            for (k = 0; k < 3; k++)
                res[i][j] += mat1[i][k]*mat2[k][j];
        }
    }
	printf("Result matrix is :\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
           printf("%d ", res[i][j]);
        printf("\n");
    }
 
    return 0;
}

