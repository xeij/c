void scalar_multiply(matrix, scalar)
int matrix[3][5];
int scalar;
{
	int row, column;
	for(row =0; row<3; ++row)
		for(column = 0; column<5; ++column)
			matrix[row][column] *= scalar;
}

void display_matrix(matrix)
	int matrix[3][5];
{
	int row, column;
	for(row=0; row<3; ++row){
		for(column=0; column<5; ++column)
			printf("%5d", matrix[row][column]);
		printf("\n");
	}
}

main() {
	static int sample_matrix[3][5] = {
		{6, 16, 55, 13, 12},
		{12, 15, 0, 2 ,25},
		{-2, 0, 2, 55, 12}
	};

	printf("Original matrix: \n");
	display_matrix(sample_matrix);

	scalar_multiply(sample_matrix, 2);

	printf("\nMultiplied by 2:\n");
	display_matrix(sample_matrix);

	scalar_multply(sample_matrix, -1);

	printf("\nMultiplied by 1:\n");
	display_matrix(sample_matrix);

}
